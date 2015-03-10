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
    MLLJET001::VolImage volImage;
    volImage.readImages(std::string(argv[1]));

    bool dFlag = false;
    int imageI = 0;
    int imageJ = 0;
    std::string outputFilenameD;

    bool xFlag = false;
    int sliceIndex = 0;
    std::string outputFilenameX;

    std::cout << "Number of images: " << volImage.getImageCount() << std::endl;
    std::cout << "Number of bytes required: " << volImage.volImageSize() << std::endl;

    if (argc > 2) {
        for (int i = 2; i < argc; i++) {
            if ((std::string(argv[i]) == "-d") && !xFlag) {
                if (argc < 6 || argv[i + 1][0] == '-' || argv[i + 2][0] == '-') {
                    std::cout << "Too few arguments after -d!" << std::endl;
                    return 0;
                }
                dFlag = true;
                imageI = atoi(argv[i + 1]);
                imageJ = atoi(argv[i + 2]);
                outputFilenameD = std::string(argv[i + 3]);
                i += 4;
            }

            if ((std::string(argv[i]) == "-x") && !dFlag) {
                if (argc < 5 || argv[i + 1][0] == '-') {
                    std::cout << "Too few arguments after -x!" << std::endl;
                    return 0;
                }
                xFlag = true;
                sliceIndex = atoi(argv[i + 1]);
                outputFilenameX = std::string(argv[i + 2]);
                i += 3;
            }
        }
        std::cout << dFlag << " " << imageI << " " << imageJ << " " << outputFilenameD << std::endl;
        std::cout << xFlag << " " << sliceIndex << " " << outputFilenameX << std::endl;
        if (xFlag) {
            volImage.extract(sliceIndex, outputFilenameX);
        }
    }

    return 0;
}
