#include "lce/include/picture.hpp"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION

#include <cstring>
#include <iostream>
#include <string>

#include "lce/include/stb_image.h"
#include "lce/include/stb_image_write.h"


static void resizeBilinear(const uint8_t* src, uint8_t* dst, const unsigned int srcWidth, const unsigned int srcHeight,
                           const unsigned int dstWidth, const unsigned int dstHeight, const unsigned int channels) {
    const float xRatio = static_cast<float>(srcWidth) / static_cast<float>(dstWidth);
    std::cerr << "test";
    const float yRatio = static_cast<float>(srcHeight) / static_cast<float>(dstHeight);
    for (unsigned int y = 0; y < dstHeight; y++) {
        for (unsigned int x = 0; x < dstWidth; x++) {
            const unsigned int xL = static_cast<int>(static_cast<float>(x) * xRatio);
            const unsigned int yT = static_cast<int>(static_cast<float>(y) * yRatio);
            const unsigned int xR = std::min(xL + 1, srcWidth - 1);
            const unsigned int yB = std::min(yT + 1, srcHeight - 1);

            const float xDiff = (static_cast<float>(x) * xRatio) - static_cast<float>(xL);
            const float yDiff = (static_cast<float>(y) * yRatio) - static_cast<float>(yT);

            for (unsigned int c = 0; c < channels; c++) {
                const float topLeft = src[(yT * srcWidth + xL) * channels + c];
                const float topRight = src[(yT * srcWidth + xR) * channels + c];
                const float bottomLeft = src[(yB * srcWidth + xL) * channels + c];
                const float bottomRight = src[(yB * srcWidth + xR) * channels + c];

                const float top = topLeft + xDiff * (topRight - topLeft);
                const float bottom = bottomLeft + xDiff * (bottomRight - bottomLeft);
                const float value = top + yDiff * (bottom - top);

                dst[(y * dstWidth + x) * channels + c] = static_cast<uint8_t>(value);
            }
        }
    }
}


Picture::~Picture() { delete[] myData; }


void Picture::allocate(const uint32_t width, const uint32_t height, const uint32_t rgbSize) {
    delete[] myData;

    myWidth = width;
    myHeight = height;
    myRGBSize = rgbSize;
    myAllocatedSize = myWidth * myHeight * myRGBSize;
    myData = new uint8_t[static_cast<size_t>(myAllocatedSize)];

    memset(myData, 0, myAllocatedSize);
}


void Picture::allocate(const uint32_t rgbSize) {
    delete[] myData;
    myRGBSize = rgbSize;
    myAllocatedSize = myWidth * myHeight * myRGBSize;
    myData = new uint8_t[static_cast<size_t>(myAllocatedSize)];

    memset(myData, 0, myAllocatedSize);
}


Picture::Picture(const uint32_t width, const uint32_t height) : myWidth(width), myHeight(height) {
    myData = nullptr;
    allocate(4);
}


Picture::Picture(const uint32_t width, const uint32_t height, const uint32_t rgbSize) : Picture(width, height) {
    myData = nullptr;
    allocate(rgbSize);
}


void Picture::drawPixel(const unsigned char* rgb, const uint32_t xIn, const uint32_t yIn) const {
    std::memcpy(&myData[static_cast<size_t>(getIndex(xIn, yIn) * myRGBSize)], rgb, myRGBSize);
}


bool Picture::drawBox(const uint32_t startX, const uint32_t startY, const uint32_t endX, const uint32_t endY,
                      const uint8_t red, const uint8_t green, const uint8_t blue) const {

    if (startX > myWidth || startY > myHeight) { return false; }
    if (endX > myWidth || endY > myHeight) { return false; }
    if (endX < startX || endY < startY) { return false; }

    for (uint32_t xIter = startX; xIter < endX; xIter++) {
        c_u32 index = getIndex(xIter, startY) * myRGBSize;
        myData[index] = red;
        myData[index + 1] = green;
        myData[index + 2] = blue;
        if (myRGBSize == 4) { myData[index + 3] = 255; }
    }

    c_u32 rowSize = (endX - startX) * myRGBSize;
    c_u32 firstRowIndex = getIndex(startX, startY) * myRGBSize;
    for (uint32_t yIter = startY + 1; yIter < endY; yIter++) {
        c_u32 index = getIndex(startX, yIter) * myRGBSize;
        std::memcpy(&myData[index], &myData[firstRowIndex], rowSize);
    }
    return true;
}
void Picture::fillColor(const uint8_t red, const uint8_t green, const uint8_t blue) const {
    for (uint32_t xIter = 0; xIter < myWidth; xIter++) {
        c_u32 index = getIndex(xIter, 0) * myRGBSize;
        myData[index] = red;
        myData[index + 1] = green;
        myData[index + 2] = blue;
        if (myRGBSize == 4) { myData[index + 3] = 255; }
    }

    c_u32 rowSize = (myWidth) *myRGBSize;
    for (uint32_t yIter = 0; yIter < myHeight; yIter++) {
        // c_u32 index = getIndex(0, yIter) * myRGBSize;
        std::memcpy(&myData[rowSize * yIter], &myData[0], rowSize);
    }
}
/**
* IMPORTANT: both images will have the same RGB size!
* @param picture
* @param startX
* @param startY
*/
void Picture::getSubImage(Picture& picture, const uint32_t startX, const uint32_t startY) const {
    if (!isValid() || startX > myWidth || startY > myHeight) { return; }

    picture.allocate(myRGBSize);
    c_u32 rowSize = picture.myWidth * myRGBSize;
    for (uint32_t yIter = 0; yIter < picture.myHeight; yIter++) {
        c_u32 indexIn = (startX + (startY + yIter) * myWidth) * myRGBSize;
        c_u32 indexOut = yIter * picture.myWidth * picture.myRGBSize;
        std::memcpy(&picture.myData[indexOut], &this->myData[indexIn], rowSize);
    }
}


/**
 * IMPORTANT: both images must have the same size for RGB!
 * @param picToPlace
 * @param startX
 * @param startY
 */
void Picture::placeSubImage(Picture const* picToPlace, const uint32_t startX, const uint32_t startY) const {
    if (!isValid() || startX >= myWidth || startY >= myHeight) { return; }

    c_u32 widthInput = std::min(picToPlace->myWidth, myWidth - startX);
    c_u32 heightInput = std::min(picToPlace->myHeight, myHeight - startY);
    c_u32 rowSizeInput = widthInput * myRGBSize;

    for (uint32_t yIter = 0; yIter < heightInput; yIter++) {
        c_u32 indexOut = ((startY + yIter) * this->myWidth + startX) * myRGBSize;
        c_u32 indexIn = (yIter * picToPlace->myWidth) * myRGBSize;

        std::memcpy(&this->myData[indexOut], &picToPlace->myData[indexIn], rowSizeInput);
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