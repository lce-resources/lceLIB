#pragma once

#include "picture.hpp"
#include "lce/processor.hpp"


/// goes left -> right, top -> bottom
class Picture {
public:
    MU i32 m_size = 0;
    u8* m_data = nullptr;
    i32 m_channels = 4;
    i32 m_width = 0;
    i32 m_height = 0;

    MU Picture() = default;
    Picture(i32 width, i32 height);
    Picture(i32 width, i32 height, i32 channels);
    MU explicit Picture(c_i32 size) : Picture(size, size) {}
    ~Picture();

    void allocate(i32 width, i32 height, i32 channels);
    void allocate(i32 channels);

    MU ND i32 width() const { return m_width; }
    MU ND i32 height() const { return m_height; }


    ND i32 getIndex(i32 x, i32 y) const { return x + y * m_height; }
    MU ND bool isValid() const { return !(m_data == nullptr || m_width == 0 || m_height == 0 || m_channels == 0); }

    MU void drawPixel(const unsigned char* rgb, i32 xIn, i32 yIn) const;
    MU ND bool drawBox(i32 sX, i32 sY, i32 eX, i32 eY, u8 red, u8 green, u8 blue) const;
    MU void fillColor(u8 red, u8 green, u8 blue) const;
    MU void getSubImage(Picture& picture, i32 sX, i32 sY) const;
    MU void placeSubImage(Picture const* picToPlace, i32 sX, i32 sY) const;
    void placeAndStretchSubImage(Picture const* picToPlace, i32 sX, i32 sY, i32 tX, i32 tH) const;
    void loadFromFile(const char* filename);
    void saveWithName(const std::string& filename) const;
};
