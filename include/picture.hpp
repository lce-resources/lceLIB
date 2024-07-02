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

    void allocate(c_u32 rgbSize) {
        delete[] myData;
        myRGBSize = rgbSize;
        myAllocatedSize = myWidth * myHeight * myRGBSize;
        myData = new uint8_t[static_cast<size_t>(myAllocatedSize)];

        memset(myData, 0, myAllocatedSize);
    }

    Picture(c_u32 width, c_u32 height) : myWidth(width), myHeight(height) {
        myData = nullptr;
        allocate(4);
    }

    Picture(c_u32 width, c_u32 height, c_u32 rgbSize) : Picture(width, height) {
        myData = nullptr;
        allocate(rgbSize);
    }

    MU explicit Picture(const int size) : Picture(size, size) {}

    MU Picture() = default;

    ~Picture() { delete[] myData; }

    MU ND uint32_t getWidth() const { return myWidth; }
    MU ND uint32_t getHeight() const { return myHeight; }
    ND uint32_t getIndex(c_u32 xIn, c_u32 yIn) const { return xIn + yIn * myHeight; }

    MU ND bool isValid() const {
        return !(myData == nullptr || myWidth == 0 || myHeight == 0);
    }

    MU void drawPixel(const unsigned char* rgb, c_u32 xIn, c_u32 yIn) const {
        c_u32 index = getIndex(xIn, yIn);
        std::memcpy(&myData[static_cast<size_t>(index * myRGBSize)], rgb, myRGBSize);
    }

    MU ND bool drawBox(c_u32 startX, c_u32 startY,
                       c_u32 endX, c_u32 endY,
                       c_u8 red, c_u8 green, c_u8 blue) const {

        if (startX > myWidth || startY > myHeight) { return false; }
        if (endX > myWidth || endY > myHeight) { return false; }
        if (endX < startX || endY < startY) { return false; }

        for (uint32_t xIter = startX; xIter < endX; xIter++) {
            c_u32 index = getIndex(xIter, startY) * myRGBSize;
            myData[index] = red;
            myData[index + 1] = green;
            myData[index + 2] = blue;
            if (myRGBSize == 4) {
                myData[index + 3] = 255;
            }
        }

        c_u32 rowSize = (endX - startX) * myRGBSize;
        c_u32 firstRowIndex = getIndex(startX, startY) * myRGBSize;
        for (uint32_t yIter = startY + 1; yIter < endY; yIter++) {
            c_u32 index = getIndex(startX, yIter) * myRGBSize;
            std::memcpy(&myData[index], &myData[firstRowIndex], rowSize);
        }
        return true;
    }

    MU void fillColor(c_u8 red, c_u8 green, c_u8 blue) const {
        for (uint32_t xIter = 0; xIter < myWidth; xIter++) {
            c_u32 index = getIndex(xIter, 0) * myRGBSize;
            myData[index] = red;
            myData[index + 1] = green;
            myData[index + 2] = blue;
            if (myRGBSize == 4) {
                myData[index + 3] = 255;
            }
        }

        c_u32 rowSize = (myWidth) * myRGBSize;
        for (uint32_t yIter = 0; yIter < myHeight; yIter++) {
            c_u32 index = getIndex(0, yIter) * myRGBSize;
            std::memcpy(&myData[index], &myData[0], rowSize);
        }
    }


    /**
     * IMPORTANT: both images will have the same RGB size!
     * @param picture
     * @param startX
     * @param startY
     */
    MU void getSubImage(Picture& picture, c_u32 startX, c_u32 startY) const {
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
    MU void placeSubImage(Picture const* picToPlace, c_u32 startX, c_u32 startY) const {
        if (!isValid() || startX >= myWidth || startY >= myHeight) {
            return;
        }

        c_u32 widthInput = std::min(picToPlace->myWidth, myWidth - startX);
        c_u32 heightInput = std::min(picToPlace->myHeight, myHeight - startY);
        c_u32 rowSizeInput = widthInput * myRGBSize;

        for (uint32_t yIter = 0; yIter < heightInput; yIter++) {
            c_u32 indexOut = ((startY + yIter) * this->myWidth + startX) * myRGBSize;
            c_u32 indexIn = (yIter * picToPlace->myWidth) * myRGBSize;

            std::memcpy(&this->myData[indexOut],
                   &picToPlace->myData[indexIn],
                   rowSizeInput);
        }
    }


    void loadFromFile(const char* filename);
    void saveWithName(std::string filename, const std::string& directory) const;
};