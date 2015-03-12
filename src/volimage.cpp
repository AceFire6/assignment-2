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
        numImages = 0;
    }


    VolImage::~VolImage() {
        for (unsigned char ** slice: slices) {
            for (int row = 0; row < height; ++row) {
                delete [] slice[row];
            }
            delete [] slice;
        }
    }

    int VolImage::getImageCount() {
        return numImages;
    }


    bool VolImage::readImages(std::string baseName) {
        std::string imageFile = baseName;
        std::string imageDat = imageFile + ".dat";

        std::ifstream inFile(imageDat);
        std::string line;


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

        slices.resize((unsigned int)numImages);
        std::string fileName;
        for (int imageNum = 0; imageNum < numImages; ++imageNum) {
            fileName = imageFile + std::to_string(imageNum) + ".raw";
            std::ifstream rawFile(fileName, std::ios::binary);

            if (rawFile.is_open()) {
                unsigned char **imageBytes = new unsigned char *[height];

                for (int row = 0; row < height; ++row) {
                    unsigned char *rowBytes = new unsigned char[width];
                    rawFile.read(reinterpret_cast<char *>(rowBytes), width);
                    imageBytes[row] = rowBytes;
                }

                rawFile.close();
                slices[imageNum] = imageBytes;
            } else {
                std::cout << "Couldn't open file " << fileName << std::endl;
                return false;
            }
        }

        return true;
    }


    void VolImage::diffmap(int sliceI, int sliceJ, std::string output_prefix) {
        unsigned char ** diffSlice = new unsigned char * [height];
        for (int row = 0; row < height; ++row) {
            unsigned char * diffRow = new unsigned char [width];
            for (int col = 0; col < width; ++col) {
                diffRow[col] = (unsigned char)(abs(slices[sliceI][row][col] - slices[sliceJ][row][col])/2);
            }
            diffSlice[row] = diffRow;
        }

        writeRawFile(output_prefix, 0, diffSlice);
    }


    void VolImage::extract(int sliceId, std::string output_prefix) {
        unsigned char ** slice = slices[sliceId];
        writeRawFile(output_prefix, sliceId, slice);
    }


    int VolImage::volImageSize() {
        int size = 0;
        int pointerSize = sizeof(unsigned char *);

        size = height * width;
        size += height * pointerSize;
        size *= numImages;

        return size;
    }


    void VolImage::writeRawFile(std::string baseName, int sliceIndex, unsigned char **slice) {
        std::string datFilename = baseName + ".dat";
        std::string rawFilename = baseName + std::to_string(sliceIndex) + ".raw";

        std::ofstream outFile(datFilename, std::ios::out);
        outFile << width << " " << height << " " << 1;
        outFile.close();

        outFile.open(rawFilename, std::ios::out | std::ios::binary);
        for (int row = 0; row < height; ++row) {
            outFile.write((char *)slice[row], width);
        }
        outFile.close();
    }
}
