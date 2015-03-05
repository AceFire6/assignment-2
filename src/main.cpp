#include <iostream>
#include <string>


int main(int argc, char *argv[]) {
	std::string imageBase = "mri_raws/%s.%s";
	if (argc >= 2) {
		imageBase = std::sprintf(imageBase.c_str(), argv[1]);
	} else {
		std::cout << "Need an image base name as an argument!" << std::endl;
		return 1;
	}


	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << std::endl;
	}

	return 0;
}
