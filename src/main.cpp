#include "main.h"
#include <iostream>
#include <filesystem>
#include <algorithm>
#include <fstream>

namespace fs = std::filesystem;

int main() {
	if (!fs::exists(Main::file_path_prefix)) {
		std::cout << "Could not find '" + Main::file_path_prefix + "'. You are not running this from the build directory. Aborting..." << "\n";
		// State that we've cancelled the operation.
		return ECANCELED;
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
		if (file_name != "webhook.h") {
			std::cout << "Ignoring file: " + file_name + "\n";
			continue;
		}

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

		/**
		 * @brief Should we add the current line to file_lines?
		 * @warning This is ONLY for classes, to make sure we don't read protected data.
		 */
		bool should_add_to_lines = false;

		uint16_t current_line = 0;

		while (std::getline(file, line)) {

			std::string temp_line = line;
			temp_line.erase(std::remove_if(temp_line.begin(), temp_line.end(), isspace), temp_line.end());
			temp_line.erase(std::remove(temp_line.begin(), temp_line.end(), '\t'), temp_line.end());

			/* If the line is a comment, ignore it. */
			if(temp_line.rfind('/', 0) == 0 || temp_line.rfind(" *", 0) == 0 || temp_line.rfind('*', 0) == 0) {
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
						file_lines.emplace_back("enum class " + enum_name + " : uint8 {");
					} else {
						std::string enum_type = Main::tokenize(temp_line, ":")[1];
						enum_type.erase(std::remove(enum_type.begin(), enum_type.end(), '{'), enum_type.end());

						if(enum_type == "uint16_t") {
							file_lines.emplace_back("enum class " + enum_name + " : uint16 {");
						} else if(enum_type == "uint32_t") {
							file_lines.emplace_back("enum class " + enum_name + " : uint32 {");
						} else if(enum_type == "uint64_t") {
							file_lines.emplace_back("enum class " + enum_name + " : uint64 {");
						} else { // This is either uint8_t or something that we aren't checking.
							file_lines.emplace_back("enum class " + enum_name + " : uint8 {");
						}
					}
				} else if (line.rfind("class DPP_EXPORT", 0) != std::string::npos) {
					std::cout << "FOUND CLASS." << "\n";
					current_scope = Main::scope_type::st_class;

					std::string struct_name = line;
					struct_name.erase(0,17); // Removes "class DPP_EXPORT "
					struct_name = Main::tokenize(struct_name, " ")[0];

					file_lines.emplace_back("USTRUCT(BlueprintType)");

					file_lines.emplace_back("struct " + struct_name + " {");
					file_lines.emplace_back("	GENERATED_BODY()");
					file_lines.emplace_back("");
				}
			} else {
				if (line.find('}') != std::string::npos) {
					file_lines.emplace_back("};");
					file_lines.emplace_back(""); // Just a blank line, cause separation after each scope.
					current_scope = Main::scope_type::st_none;
					continue;
				}

				if(current_scope == Main::scope_type::st_class) {
					if(line.rfind("public:", 0) != std::string::npos) {
						should_add_to_lines = true;
					} else if(line.rfind("protected:", 0) != std::string::npos) {
						should_add_to_lines = false;
					} else if(line.rfind("private:", 0) != std::string::npos) {
						should_add_to_lines = false;
					} else {
						if(should_add_to_lines) {

							if(temp_line.find('(') != std::string::npos) {
								continue;
							}

							if(!temp_line.empty()) {
								file_lines.emplace_back("	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=\"Discord\")");
							}

							// Line needs to have words replaced (like std::string to FString)
							file_lines.emplace_back(line);
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

		for(const auto& line : file_lines) {
			new_file << line << "\n";
		}

		new_file.close();

	}
	return 0;
}
