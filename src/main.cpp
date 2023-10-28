#include "main.h"
#include <iostream>
#include <filesystem>
#include <algorithm>

namespace fs = std::filesystem;

int main(int argc, char *argv[]) {

	if (!fs::exists(Main::file_path_prefix)) {
		std::cout << "Could not find '" + Main::file_path_prefix + "'. You are not running this from the build directory. Aborting..." << "\n";
		// State that we've cancelled the operation.
		return ECANCELED;
	}

	for (const auto& file : fs::directory_iterator(Main::file_path_prefix)) {
		/* Is this a folder that we want to ignore? */
		if (std::find(Main::folders_to_ignore.begin(), Main::folders_to_ignore.end(), file.path().filename().string()) != Main::folders_to_ignore.end()) {
			std::cout << "Ignoring folder: " + file.path().filename().string() + "\n";
			continue;
		}

		/* Is this a file that we want to ignore? */
		if (std::find(Main::files_to_ignore.begin(), Main::files_to_ignore.end(), file.path().filename().string()) != Main::files_to_ignore.end()) {
			std::cout << "Ignoring file: " + file.path().filename().string() + "\n";
			continue;
		}

		std::cout << "Generating code from: " << file.path().filename().string() << "\n";
	}
	return 0;
}
