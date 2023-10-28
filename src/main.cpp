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
		if (file_name != "channel.h") {
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

		bool in_scope = false;

		while (std::getline(file, line)) {

			/* If the line is a comment, ignore it. */
			if(line.rfind('/', 0) == 0 || line.rfind(" *", 0) == 0 || line.rfind('*', 0) == 0) {
				continue;
			}

			std::string temp_line = line;
			temp_line.erase(std::remove_if(temp_line.begin(), temp_line.end(), isspace), temp_line.end());
			temp_line.erase(std::remove(temp_line.begin(), temp_line.end(), '\t'), temp_line.end());

			const std::string& temp_line_with_spacing = line;

			if(!in_scope) {
				if (temp_line.rfind("enum", 0) != std::string::npos) {
					in_scope = true;

					std::string enum_name = temp_line_with_spacing;
					enum_name.erase(0,5);
					enum_name = Main::tokenize(enum_name, " ")[0];

					file_lines.emplace_back("UENUM(BlueprintType)");

					/* Does the enum declare what type of enum it is?
					 * If not, we force it to uint8.
					 */
					if (temp_line.find(':') == std::string::npos) {
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
				}
			} else {
				if (line.find('}') != std::string::npos) {
					file_lines.emplace_back("};");
					file_lines.emplace_back(""); // Just a blank line, cause separation after each scope.
					in_scope = false;
					continue;
				}

				file_lines.emplace_back(temp_line_with_spacing);
			}
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
