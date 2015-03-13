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
    bool xFlag = false;
    bool gFlag = false;

    int imageI = 0;
    int imageJ = 0;
    std::string outputFilename;

    std::cout << "Number of images: " << volImage.getImageCount() << std::endl;
    std::cout << "Number of bytes required for a single image: " <<
                (volImage.volImageSize() / volImage.getImageCount()) << std::endl;
    std::cout << "Number of bytes required for all " << volImage.getImageCount()
              << " images: " << volImage.volImageSize() << std::endl;

    if (argc > 2) { // Only check that there are flags if there are enough arguments to warrant it
        for (int i = 2; i < argc; i++) { // Loops through all the arguments, skipping the first two
            if ((std::string(argv[i]) == "-d")) {
                if (argc < 6 || argv[i + 1][0] == '-' || argv[i + 2][0] == '-') {
                    std::cout << "Too few arguments after -d!" << std::endl;
                    return 0;
                }
                dFlag = true;
                imageI = atoi(argv[i + 1]);
                imageJ = atoi(argv[i + 2]);
                outputFilename = std::string(argv[i + 3]);
                break;
            }

            if (std::string(argv[i]) == "-x") {
                if (argc < 5 || argv[i + 1][0] == '-') {
                    std::cout << "Too few arguments after -x!" << std::endl;
                    return 0;
                }
                xFlag = true;
                imageI = atoi(argv[i + 1]);
                outputFilename = std::string(argv[i + 2]);
                break;
            }

            if (std::string(argv[i]) == "-g") {
                if (argc < 5 || argv[i + 1][0] == '-') {
                    std::cout << "Too few arguments after -g!" << std::endl;
                    return 0;
                }
                gFlag = true;
                imageI = atoi(argv[i + 1]);
                outputFilename = std::string(argv[i + 2]);
                break;
            }
        }

        if (xFlag) {
            volImage.extract(imageI, outputFilename);
        } else if (dFlag) {
            volImage.diffmap(imageI, imageJ, outputFilename);
        } else if (gFlag) {
            volImage.rowExtract(imageI, outputFilename);
        }
    }

    return 0;
}
