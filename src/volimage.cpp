#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>

#include "volimage.h"

namespace MLLJET001 {
    VolImage::VolImage() {
        width = 0;
        height = 0;
    }


    VolImage::~VolImage() {

    }


    bool VolImage::readImages(std::string baseName) {
        std::string imageFile = "/home/acefire6/ClionProjects/assignment-2/build/mri_raws/" + baseName;
        std::string imageDat = imageFile + ".dat";

        std::ifstream inFile(imageDat);
        std::string line;

        unsigned int numImages = 0;
        if (inFile.is_open()) {
            while (std::getline(inFile, line)) {
                std::istringstream ss(line);
                ss >> width >> std::ws >> height >> std::ws >> numImages;
            }
            inFile.close();
        } else {
            inFile.close();
            std::cout << "File not found!" << std::endl;
            return false;
        }
        std::cout << "Width: " << width << " Height: " << height << " Num Images: " << numImages << std::endl;


        slices.resize(numImages);
        std::string fileName;
        for (int imageNum = 0; imageNum < numImages; ++imageNum) {
            fileName = imageFile + std::to_string(imageNum) + ".raw";
            std::ifstream rawFile(fileName, std::ios::binary);

            if (rawFile.is_open()) {
                unsigned char **imageBytes = new unsigned char *[height];

                for (int row = 0; row < height; ++row) {
                    unsigned char *rowBytes = new unsigned char[width];

                    rawFile.seekg(row * width);
                    rawFile.read(reinterpret_cast<char *>(rowBytes), width);
                    imageBytes[row] = rowBytes;
                    delete[] rowBytes;
                }

                rawFile.close();
                slices[imageNum] = imageBytes;
                delete[] imageBytes;
            } else {
                std::cout << "Couldn't open file " << fileName << std::endl;
                return false;
            }
        }

        return true;
    }


    void VolImage::diffmap(int sliceI, int sliceJ, std::string output_prefix) {

    }


    void VolImage::extract(int sliceId, std::string output_prefix) {

    }


    int VolImage::volImageSize() {
        return 0;
    }
}
