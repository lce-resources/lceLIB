#include "lce/include/picture.hpp"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION

#include "lce/include/stb_image.h"
#include "lce/include/stb_image_write.h"


static void resizeBilinear(const uint8_t* src, uint8_t* dst, unsigned int srcWidth, unsigned int srcHeight, unsigned int dstWidth, unsigned int dstHeight, unsigned int channels) {
    float xRatio = static_cast<float>(srcWidth) / static_cast<float>(dstWidth);
    float yRatio = static_cast<float>(srcHeight) / static_cast<float>(dstHeight);
    for (unsigned int y = 0; y < dstHeight; y++) {
        for (unsigned int x = 0; x < dstWidth; x++) {
            unsigned int xL = static_cast<int>(static_cast<float>(x) * xRatio);
            unsigned int yT = static_cast<int>(static_cast<float>(y) * yRatio);
            unsigned int xR = std::min(xL + 1, srcWidth - 1);
            unsigned int yB = std::min(yT + 1, srcHeight - 1);

            float xDiff = (static_cast<float>(x) * xRatio) - static_cast<float>(xL);
            float yDiff = (static_cast<float>(y) * yRatio) - static_cast<float>(yT);

            for (unsigned int c = 0; c < channels; c++) {
                float topLeft = src[(yT * srcWidth + xL) * channels + c];
                float topRight = src[(yT * srcWidth + xR) * channels + c];
                float bottomLeft = src[(yB * srcWidth + xL) * channels + c];
                float bottomRight = src[(yB * srcWidth + xR) * channels + c];

                float top = topLeft + xDiff * (topRight - topLeft);
                float bottom = bottomLeft + xDiff * (bottomRight - bottomLeft);
                float value = top + yDiff * (bottom - top);

                dst[(y * dstWidth + x) * channels + c] = static_cast<uint8_t>(value);
            }
        }
    }
}


void Picture::placeAndStretchSubImage(Picture const* picToPlace, c_u32 startX, c_u32 startY,
                                      c_u32 targetWidth, c_u32 targetHeight) const {
    if (!isValid() || startX >= myWidth || startY >= myHeight || !picToPlace->isValid()) {
        return;
    }

    // Allocate memory for the resized subimage
    auto* resizedSubImage = new uint8_t[targetWidth * targetHeight * myRGBSize];
    resizeBilinear(picToPlace->myData, resizedSubImage, picToPlace->myWidth,
                   picToPlace->myHeight, targetWidth, targetHeight, myRGBSize);

    // Calculate bounds for placement
    c_u32 endX = std::min(startX + targetWidth, myWidth);
    c_u32 endY = std::min(startY + targetHeight, myHeight);
    c_u32 widthInput = endX - startX;
    c_u32 heightInput = endY - startY;

    // Place the resized subimage into the main image
    for (u32 yIter = 0; yIter < heightInput; yIter++) {
        c_u32 indexOut = ((startY + yIter) * this->myWidth + startX) * myRGBSize;
        c_u32 indexIn = (yIter * targetWidth) * myRGBSize;
        std::memcpy(&this->myData[indexOut], &resizedSubImage[indexIn], widthInput * myRGBSize);
    }

    delete[] resizedSubImage;
}



void Picture::loadFromFile(const char* filename) {
    int x,y,n;
    delete[] myData;
    myData = stbi_load(filename, &x, &y, &n, 0);
    myWidth = x;
    myHeight = y;
    myRGBSize = n;
}


void Picture::saveWithName(const std::string& filename) const {
    stbi_write_png(filename.c_str(),
                   static_cast<int>(myWidth),
                   static_cast<int>(myHeight),
                   static_cast<int>(myRGBSize),
                   myData,
                   0);
}