#include "lce/include/picture.hpp"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION

#include "lce/include/stb_image.h"
#include "lce/include/stb_image_write.h"


void Picture::loadFromFile(const char* filename) {
    int x,y,n;
    delete[] myData;
    myData = stbi_load(filename, &x, &y, &n, 0);
    myWidth = x;
    myHeight = y;
    myRGBSize = n;
}


void Picture::saveWithName(std::string filename, const std::string& directory) const {
    filename = directory + filename;
    stbi_write_png(filename.c_str(),
                   static_cast<int>(myWidth),
                   static_cast<int>(myHeight),
                   static_cast<int>(myRGBSize), myData,
                   static_cast<int>(myWidth * myRGBSize)
    );
}