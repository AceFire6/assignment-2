#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "volimage.h"


int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Image base name required as first argument!" << std::endl;
        return 0;
    }
    VolImage volImage;
    volImage.readImages(std::string(argv[1]));

    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << std::endl;
    }

    return 0;
}
