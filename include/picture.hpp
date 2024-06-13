#pragma once

#include <cstddef>
#include <cstring>
#include <iostream>
#include <string>

#include "lce/include/picture.hpp"
#include "lce/processor.hpp"


class Picture {
    uint32_t myAllocatedSize = 0;
public:
    uint32_t myRGBSize = 4;
    uint32_t myWidth = 0;
    uint32_t myHeight = 0;

    /// goes left to right, top to bottom I think
    uint8_t* myData = nullptr;

    void allocate(const uint32_t rgbSize) {
        delete[] myData;
        myRGBSize = rgbSize;
        myAllocatedSize = myWidth * myHeight * myRGBSize;
        myData = new uint8_t[static_cast<size_t>(myAllocatedSize)];

        memset(myData, 0, myAllocatedSize);
    }

    Picture(const uint32_t width, const uint32_t height) : myWidth(width), myHeight(height) {
        myData = nullptr;
        allocate(4);
    }

    Picture(const uint32_t width, const uint32_t height, const uint32_t rgbSize) : Picture(width, height) {
        myData = nullptr;
        allocate(rgbSize);
    }

    MU explicit Picture(const int size) : Picture(size, size) {}

    MU Picture() = default;

    ~Picture() { delete[] myData; }

    MU ND uint32_t getWidth() const { return myWidth; }
    MU ND uint32_t getHeight() const { return myHeight; }
    ND uint32_t getIndex(const uint32_t xIn, const uint32_t yIn) const { return xIn + yIn * myHeight; }

    MU ND bool isValid() const {
        return !(myData == nullptr || myWidth == 0 || myHeight == 0);
    }

    MU void drawPixel(const unsigned char* rgb, const uint32_t xIn, const uint32_t yIn) const {
        const uint32_t index = getIndex(xIn, yIn);
        memcpy(&myData[static_cast<size_t>(index * myRGBSize)], rgb, myRGBSize);
    }

    MU ND bool drawBox(const uint32_t startX, const uint32_t startY,
                       const uint32_t endX, const uint32_t endY,
                       const uint8_t red, const uint8_t green, const uint8_t blue) const {

        if (startX > myWidth || startY > myHeight) { return false; }
        if (endX > myWidth || endY > myHeight) { return false; }
        if (endX < startX || endY < startY) { return false; }

        for (uint32_t xIter = startX; xIter < endX; xIter++) {
            const uint32_t index = getIndex(xIter, startY) * myRGBSize;
            myData[index] = red;
            myData[index + 1] = green;
            myData[index + 2] = blue;
            if (myRGBSize == 4) {
                myData[index + 3] = 255;
            }
        }

        const uint32_t rowSize = (endX - startX) * myRGBSize;
        const uint32_t firstRowIndex = getIndex(startX, startY) * myRGBSize;
        for (uint32_t yIter = startY + 1; yIter < endY; yIter++) {
            const uint32_t index = getIndex(startX, yIter) * myRGBSize;
            memcpy(&myData[index], &myData[firstRowIndex], rowSize);
        }
        return true;
    }

    MU void fillColor(const uint8_t red, const uint8_t green, const uint8_t blue) const {
        for (uint32_t xIter = 0; xIter < myWidth; xIter++) {
            const uint32_t index = getIndex(xIter, 0) * myRGBSize;
            myData[index] = red;
            myData[index + 1] = green;
            myData[index + 2] = blue;
            if (myRGBSize == 4) {
                myData[index + 3] = 255;
            }
        }

        const uint32_t rowSize = (myWidth) * myRGBSize;
        for (uint32_t yIter = 0; yIter < myHeight; yIter++) {
            const uint32_t index = getIndex(0, yIter) * myRGBSize;
            memcpy(&myData[index], &myData[0], rowSize);
        }
    }


    /**
     * IMPORTANT: both images will have the same RGB size!
     * @param picture
     * @param startX
     * @param startY
     */
    MU void getSubImage(Picture& picture, const uint32_t startX, const uint32_t startY) const {
        if (!isValid() || startX > myWidth || startY > myHeight) { return; }

        picture.allocate(myRGBSize);
        const uint32_t rowSize = picture.myWidth * myRGBSize;
        for (uint32_t yIter = 0; yIter < picture.myHeight; yIter++) {
            const uint32_t indexIn = (startX + (startY + yIter) * myWidth) * myRGBSize;
            const uint32_t indexOut = yIter * picture.myWidth * picture.myRGBSize;
            memcpy(&picture.myData[indexOut], &this->myData[indexIn], rowSize);
        }
    }


    /**
     * IMPORTANT: both images must have the same size for RGB!
     * @param picToPlace
     * @param startX
     * @param startY
     */
    MU void placeSubImage(Picture const* picToPlace, const uint32_t startX, const uint32_t startY) const {
        if (!isValid() || startX >= myWidth || startY >= myHeight) {
            return;
        }

        const uint32_t widthInput = std::min(picToPlace->myWidth, myWidth - startX);
        const uint32_t heightInput = std::min(picToPlace->myHeight, myHeight - startY);
        const uint32_t rowSizeInput = widthInput * myRGBSize;

        for (uint32_t yIter = 0; yIter < heightInput; yIter++) {
            const uint32_t indexOut = ((startY + yIter) * this->myWidth + startX) * myRGBSize;
            const uint32_t indexIn = (yIter * picToPlace->myWidth) * myRGBSize;

            memcpy(&this->myData[indexOut],
                   &picToPlace->myData[indexIn],
                   rowSizeInput);
        }
    }


    void loadFromFile(const char* filename);
    void saveWithName(std::string filename, const std::string& directory) const;
};