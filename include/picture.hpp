#pragma once

#include "picture.hpp"
#include "lce/processor.hpp"


class Picture {
    uint32_t myAllocatedSize = 0;
public:
    uint32_t myRGBSize = 4;
    uint32_t myWidth = 0;
    uint32_t myHeight = 0;

    /// goes left to right, top to bottom I think
    uint8_t* myData = nullptr;

    MU Picture() = default;
    Picture(c_u32 width, c_u32 height);
    Picture(c_u32 width, c_u32 height, c_u32 rgbSize);
    MU explicit Picture(const int size) : Picture(size, size) {}
    ~Picture();

    void allocate(c_u32 width, c_u32 height, c_u32 rgbSize);
    void allocate(c_u32 rgbSize);

    MU ND uint32_t getWidth() const { return myWidth; }
    MU ND uint32_t getHeight() const { return myHeight; }
    ND uint32_t getIndex(c_u32 xIn, c_u32 yIn) const { return xIn + yIn * myHeight; }
    MU ND bool isValid() const { return !(myData == nullptr || myWidth == 0 || myHeight == 0); }
    MU void drawPixel(const unsigned char* rgb, c_u32 xIn, c_u32 yIn) const;
    MU ND bool drawBox(c_u32 startX, c_u32 startY, c_u32 endX, c_u32 endY, c_u8 red, c_u8 green, c_u8 blue) const;
    MU void fillColor(c_u8 red, c_u8 green, c_u8 blue) const;
    MU void getSubImage(Picture& picture, c_u32 startX, c_u32 startY) const;
    MU void placeSubImage(Picture const* picToPlace, c_u32 startX, c_u32 startY) const;
    void placeAndStretchSubImage(Picture const* picToPlace, c_u32 startX, c_u32 startY,
        c_u32 targetWidth, c_u32 targetHeight) const;
    void loadFromFile(const char* filename);
    void saveWithName(const std::string& filename) const;
};