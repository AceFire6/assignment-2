#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>

#include "volimage.h"


VolImage::VolImage() {
    VolImage::width = 0;
    VolImage::height = 0;

    std::vector<unsigned char **> *VolImage::slices = new std::vector<unsigned char **>[0];
}

VolImage::~VolImage() {
    delete [] VolImage::slices;
}

bool VolImage::readImages(std::string baseName) {
    std::string imageFile = "/home/mlljet001/ClionProjects/assignment-2/build/mri_raws/" + baseName;
    std::string imageDat = imageFile + ".data";

    std::ifstream inFile(imageDat);
    std::string line;

    int numImages = 0;
    if (inFile.is_open()) {
        while (std::getline(inFile, line)) {
            std::istringstream ss(line);
            ss >> VolImage::width >> std::ws >> VolImage::height >> std::ws >> numImages;
        }
    } else {
        std::cout << "File not found!" << std::endl;
    }
    std::cout << "Width: " << width << " Height: " << height << " Num Images: " << numImages << std::endl;
}


void VolImage::diffmap(int sliceI, int sliceJ, std::string output_prefix) {

}


void VolImage::extract(int sliceId, std::string output_prefix) {

}


int VolImage::volImageSize() {
    return 0;
}
