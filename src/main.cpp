#include "main.h"
#include <iostream>
#include <filesystem>
#include <algorithm>
#include <fstream>
#include <regex>

namespace fs = std::filesystem;

int main() {
	if (!fs::exists(Main::file_path_prefix)) {
		std::cout << "Could not find '" + Main::file_path_prefix + "'. You are not running this from the build directory. Aborting..." << "\n";
		// State that we've cancelled the operation.
		return ECANCELED;
	}

	std::cout << "Clearing any generated files." << "\n";

	for (const auto& file_data : fs::directory_iterator("../gencode/")) {
		std::remove(std::string("../gencode/" + file_data.path().filename().string()).c_str());
	}

	for (const auto& file_data : fs::directory_iterator(Main::file_path_prefix)) {

		const std::string& file_name = file_data.path().filename().string();
		const std::string& file_name_no_ext = file_data.path().stem().string();

		/* Is this a folder that we want to ignore? */
		if (std::find(Main::folders_to_ignore.begin(), Main::folders_to_ignore.end(), file_name) != Main::folders_to_ignore.end()) {
			std::cout << "Ignoring folder: " + file_name + "\n";
			continue;
		}

		/* Is this a file that we want to ignore? */
		if (std::find(Main::files_to_ignore.begin(), Main::files_to_ignore.end(), file_name) != Main::files_to_ignore.end()) {
			std::cout << "Ignoring file: " + file_name + "\n";
			continue;
		}

		/* This is just temp, I want to only do webhook as a test. */
		/* if (file_name != "channel.h") {
			std::cout << "Ignoring file: " + file_name + "\n";
			continue;
		}
		*/

		std::cout << "Generating code from: " << file_name << "\n";

		std::ifstream file(Main::file_path_prefix + file_name);

		/*
		if (file.is_open()) {
			std::cout << file_name + " is currently open. Aborting file..." << "\n";
			continue;
		}
		 */

		std::string line;

		const std::vector<std::string> new_struct_start_lines =
		{
			"#include \"CoreMinimal.h\"",
			"#include " + file_name_no_ext + "\".generated.h\"",
			" "
		};

		std::vector<std::string> file_lines = {};

		file_lines = Main::new_file_start_lines;

		Main::scope_type current_scope = Main::scope_type::st_none;

		std::string scope_name = "";

		/**
		 * @brief Should we add the current line to file_lines?
		 * @warning This is ONLY for classes, to make sure we don't read protected data.
		 */
		bool should_add_to_lines = false;

		uint16_t current_line = 0;

		bool in_coro_func = false;

		while (std::getline(file, line)) {

			std::string temp_line = line;
			temp_line.erase(std::remove_if(temp_line.begin(), temp_line.end(), isspace), temp_line.end());
			temp_line.erase(std::remove(temp_line.begin(), temp_line.end(), '\t'), temp_line.end());

			/* Is this a macro? */
			if(temp_line.rfind('#', 0) == 0) {
				if(temp_line.find("CORO") != std::string::npos) {
					in_coro_func = true;
					continue;
				}

				if(temp_line.find("#endif") != std::string::npos && in_coro_func) {
					in_coro_func = false;
					continue;
				}

				if(temp_line.find("#include") != std::string::npos) {
					continue;
				} else if(temp_line.find("#pragma") != std::string::npos) {
					continue;
				}

				file_lines.emplace_back(line);

			}

			/* DO NOT LET CORO CODE BE EXPORTED */
			if(in_coro_func) {
				continue;
			}

			/* If the line starts as a comment (no space before), then put the line and continue loop instantly. */
			if(line.rfind('/', 0) == 0 || line.rfind(" *", 0) == 0 || line.rfind('*', 0) == 0) {
				file_lines.emplace_back(line);
				continue;
			} else if(temp_line.rfind('/', 0) == 0 || temp_line.rfind('*', 0) == 0) { /* However, if this is an indented comment, then ignore it. */
				continue;
			}

			if(current_scope == Main::scope_type::st_none) {
				if (line.rfind("enum", 0) != std::string::npos) {
					current_scope = Main::scope_type::st_enum;

					std::string enum_name = line;
					enum_name.erase(0,5); // Removes "enum "
					enum_name = Main::tokenize(enum_name, " ")[0];

					file_lines.emplace_back("UENUM(BlueprintType)");

					/* Does the enum declare what type of enum it is?
					 * If not, we force it to uint8.
					 */
					if (line.find(':') == std::string::npos) {
						file_lines.emplace_back("enum " + enum_name + " : uint8 {");
					} else {
						std::string enum_type = Main::tokenize(temp_line, ":")[1];
						enum_type.erase(std::remove(enum_type.begin(), enum_type.end(), '{'), enum_type.end());
						enum_type = std::regex_replace(enum_type, std::regex("_t"), "");

						file_lines.emplace_back("enum " + enum_name + " : " + enum_type + " {");
					}
				} else if (line.rfind("class DPP_EXPORT", 0) != std::string::npos) {
					current_scope = Main::scope_type::st_class;

					std::string struct_name = line;
					struct_name.erase(0,17); // Removes "class DPP_EXPORT "
					struct_name = Main::tokenize(struct_name, " ")[0];

					file_lines.emplace_back("USTRUCT(BlueprintType)");

					file_lines.emplace_back("struct " + struct_name + " {");
					file_lines.emplace_back("	GENERATED_BODY()");
					file_lines.emplace_back("");

					scope_name = struct_name;
				} else if (line.rfind("struct DPP_EXPORT", 0) != std::string::npos) {
					current_scope = Main::scope_type::st_struct;

					std::string struct_name = line;
					struct_name.erase(0,18); // Removes "struct DPP_EXPORT "
					struct_name = Main::tokenize(struct_name, " ")[0];

					file_lines.emplace_back("USTRUCT(BlueprintType)");

					file_lines.emplace_back("struct " + struct_name + " {");
					file_lines.emplace_back("	GENERATED_BODY()");
					file_lines.emplace_back("");

					scope_name = struct_name;
				} else if (line.rfind("typedef", 0) != std::string::npos) {
					std::string typedef_name = line;
					typedef_name = Main::tokenize(typedef_name, "> ")[1];

					std::string new_line = line;
					new_line.erase(0,8); // Removes "typedef "

					file_lines.emplace_back("UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=\"Discord|" + typedef_name + "\")");
					file_lines.emplace_back(new_line);
					file_lines.emplace_back("");
				}
			} else {
				if (line.rfind("};", 0) == 0) {
					file_lines.emplace_back("};");
					file_lines.emplace_back(""); // Just a blank line, cause separation after each scope.
					current_scope = Main::scope_type::st_none;
					scope_name = "";
					continue;
				} else if (temp_line.rfind('}', 0) == 0 && line.find(';') == std::string::npos) { /* Make sure this isn't the end of a func */
					continue;
				}

				if(current_scope == Main::scope_type::st_class || current_scope == Main::scope_type::st_struct) {
					if(line.rfind("public:", 0) != std::string::npos) {
						should_add_to_lines = true;
					} else if(line.rfind("protected:", 0) != std::string::npos || line.rfind("private:", 0) != std::string::npos) {
						should_add_to_lines = false;
					} else {
						if(should_add_to_lines) {

							if(temp_line.find('(') != std::string::npos || temp_line.rfind("using", 0) != std::string::npos) {
								continue;
							}

							if(!temp_line.empty()) {
								file_lines.emplace_back("	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=\"Discord|" + scope_name + "\")");
								// Line needs to have words replaced (like std::string to FString)
								file_lines.emplace_back(line);
								file_lines.emplace_back("");
							}
						}
					}
				} else if(current_scope == Main::scope_type::st_enum) {
					/* Enums are fine to just take every line. */
					file_lines.emplace_back(line);
				}
			}

			current_line++;
		}

		file.close();

		/* Now, let's get writing to a new file. */

		std::ofstream new_file("../gencode/" + file_name);

		for(std::string& temp_line : file_lines) {
			for(const auto& keyword : Main::keywords_to_replace) {
				temp_line = std::regex_replace(temp_line, std::regex(keyword.first), keyword.second);
			}

			new_file << temp_line << "\n";
		}

		new_file.close();

	}
	return 0;
}
