#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Image base name required as first argument!" << std::endl;
        return 0;
    }

    std::string imageFile = "mri_raw/" + std::string(argv[1]);
    std::string imageDat = imageFile + ".data";

    std::ifstream inFile(imageDat);
    std::string line;

    int width = 0, height = 0, numImages = 0;
    if (inFile.is_open()) {
        while (std::getline(inFile, line)) {
            std::istringstream ss(line);
            ss >> width >> std::ws >> height >> std::ws >> numImages;
        }
    }
    std::cout << width << " " << height << numImages << std::endl;
    std::cout << imageDat << "\t" << imageFile << std::endl;

    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << std::endl;
    }

    return 0;
}
