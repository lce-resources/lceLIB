#include "lce/include/picture.hpp"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION

#include <cstring>
#include <iostream>
#include <string>

#include "lce/include/stb_image.hpp"
#include "lce/include/stb_image_write.hpp"


static void resizeBilinear(c_u8* src, u8* dst, c_u32 srcWidth, c_u32 srcHeight,
                           c_u32 dstWidth, c_u32 dstHeight, c_u32 channels) {
    c_float xRatio = static_cast<float>(srcWidth) / static_cast<float>(dstWidth);
    c_float yRatio = static_cast<float>(srcHeight) / static_cast<float>(dstHeight);
    for (u32 y = 0; y < dstHeight; y++) {
        for (u32 x = 0; x < dstWidth; x++) {
            c_u32 xL = static_cast<int>(static_cast<float>(x) * xRatio);
            c_u32 yT = static_cast<int>(static_cast<float>(y) * yRatio);
            c_u32 xR = std::min(xL + 1, srcWidth - 1);
            c_u32 yB = std::min(yT + 1, srcHeight - 1);

            c_float xDiff = (static_cast<float>(x) * xRatio) - static_cast<float>(xL);
            c_float yDiff = (static_cast<float>(y) * yRatio) - static_cast<float>(yT);

            for (u32 c = 0; c < channels; c++) {
                c_float topLeft = src[(yT * srcWidth + xL) * channels + c];
                c_float topRight = src[(yT * srcWidth + xR) * channels + c];
                c_float bottomLeft = src[(yB * srcWidth + xL) * channels + c];
                c_float bottomRight = src[(yB * srcWidth + xR) * channels + c];

                c_float top = topLeft + xDiff * (topRight - topLeft);
                c_float bottom = bottomLeft + xDiff * (bottomRight - bottomLeft);
                c_float value = top + yDiff * (bottom - top);

                dst[(y * dstWidth + x) * channels + c] = static_cast<u8>(value);
            }
        }
    }
}


Picture::~Picture() { delete[] m_data; }


void Picture::allocate(c_i32 width, c_i32 height, c_i32 channels) {
    delete[] m_data;

    m_width = width;
    m_height = height;
    m_channels = channels;
    m_size = m_width * m_height * m_channels;
    m_data = new u8[static_cast<size_t>(m_size)];

    memset(m_data, 0, m_size);
}


void Picture::allocate(c_i32 channels) {
    delete[] m_data;
    m_channels = channels;
    m_size = m_width * m_height * m_channels;
    m_data = new u8[static_cast<size_t>(m_size)];

    memset(m_data, 0, m_size);
}


Picture::Picture(c_i32 width, c_i32 height) : m_width(width), m_height(height) {
    m_data = nullptr;
    allocate(4);
}


Picture::Picture(c_i32 width, c_i32 height, c_i32 channels) : Picture(width, height) {
    m_data = nullptr;
    allocate(channels);
}


MU void Picture::drawPixel(const unsigned char* rgb, c_i32 xIn, c_i32 yIn) const {
    std::memcpy(&m_data[static_cast<size_t>(getIndex(xIn, yIn) * m_channels)], rgb, m_channels);
}


MU bool Picture::drawBox(c_i32 sX, c_i32 sY, c_i32 eX, c_i32 eY,
                      c_u8 red, c_u8 green, c_u8 blue) const {

    if (sX > m_width || sY > m_height) { return false; }
    if (eX > m_width || eY > m_height) { return false; }
    if (eX < sX || eY < sY) { return false; }

    for (i32 xIter = sX; xIter < eX; xIter++) {
        c_u32 index = getIndex(xIter, sY) * m_channels;
        m_data[index] = red;
        m_data[index + 1] = green;
        m_data[index + 2] = blue;
        if (m_channels == 4) { m_data[index + 3] = 255; }
    }

    c_u32 rowSize = (eX - sX) * m_channels;
    c_u32 firstRowIndex = getIndex(sX, sY) * m_channels;
    for (i32 yIter = sY + 1; yIter < eY; yIter++) {
        c_u32 index = getIndex(sX, yIter) * m_channels;
        std::memcpy(&m_data[index], &m_data[firstRowIndex], rowSize);
    }
    return true;
}
void Picture::fillColor(c_u8 red, c_u8 green, c_u8 blue) const {
    for (i32 xIter = 0; xIter < m_width; xIter++) {
        c_i32 index = getIndex(xIter, 0) * m_channels;
        m_data[index] = red;
        m_data[index + 1] = green;
        m_data[index + 2] = blue;
        if (m_channels == 4) { m_data[index + 3] = 255; }
    }

    c_i32 rowSize = (m_width) *m_channels;
    for (uint32_t yIter = 0; yIter < m_height; yIter++) {
        // c_u32 index = getIndex(0, yIter) * m_channels;
        std::memcpy(&m_data[rowSize * yIter], &m_data[0], rowSize);
    }
}
/**
* IMPORTANT: both images will have the same RGB size!
* @param picture
* @param sX
* @param sY
*/
void Picture::getSubImage(Picture& picture, c_i32 sX, c_i32 sY) const {
    if (!isValid() || sX > m_width || sY > m_height) { return; }

    picture.allocate(m_channels);
    c_i32 rowSize = picture.m_width * m_channels;
    for (i32 yIter = 0; yIter < picture.m_height; yIter++) {
        c_i32 indexIn = (sX + (sY + yIter) * m_width) * m_channels;
        c_i32 indexOut = yIter * picture.m_width * picture.m_channels;
        std::memcpy(&picture.m_data[indexOut], &m_data[indexIn], rowSize);
    }
}


/**
 * IMPORTANT: both images must have the same size for RGB!
 * @param picToPlace
 * @param sX
 * @param sY
 */
MU void Picture::placeSubImage(Picture const* picToPlace, c_i32 sX, c_i32 sY) const {
    if (!isValid() || sX >= m_width || sY >= m_height) { return; }

    c_i32 widthInput = std::min(picToPlace->m_width, m_width - sX);
    c_i32 heightInput = std::min(picToPlace->m_height, m_height - sY);
    c_i32 rowSizeInput = widthInput * m_channels;

    for (i32 yIter = 0; yIter < heightInput; yIter++) {
        c_i32 indexOut = ((sY + yIter) * m_width + sX) * m_channels;
        c_i32 indexIn = (yIter * picToPlace->m_width) * m_channels;

        std::memcpy(&m_data[indexOut], &picToPlace->m_data[indexIn], rowSizeInput);
    }
}


void Picture::placeAndStretchSubImage(Picture const* picToPlace, c_i32 sX, c_i32 sY, c_i32 tX, c_i32 tY) const {
    if (!isValid() || sX >= m_width || sY >= m_height || !picToPlace->isValid()) {
        return;
    }

    // Allocate memory for the resized sub-image
    auto* resizedSubImage = new u8[tX * tY * m_channels];
    resizeBilinear(picToPlace->m_data, resizedSubImage, picToPlace->m_width,
                   picToPlace->m_height, tX, tY, m_channels);

    // Calculate bounds for placement
    c_i32 eX = std::min(sX + tX, m_width);
    c_i32 eY = std::min(sY + tY, m_height);
    c_i32 widthInput = eX - sX;
    c_i32 heightInput = eY - sY;

    // Place the resized sub-image into the main image
    for (i32 yIter = 0; yIter < heightInput; yIter++) {
        c_i32 indexOut = ((sY + yIter) * this->m_width + sX) * m_channels;
        c_i32 indexIn = (yIter * tX) * m_channels;
        std::memcpy(&this->m_data[indexOut], &resizedSubImage[indexIn], widthInput * m_channels);
    }

    delete[] resizedSubImage;
}



void Picture::loadFromFile(const char* filename) {
    delete[] m_data;
    m_data = stbi_load(filename, &m_width, &m_height, &m_channels, 0);
    m_size = m_width * m_height * m_channels;
}


void Picture::saveWithName(const std::string& filename) const {
    stbi_write_png(filename.c_str(),
                   m_width,
                   m_height,
                   m_channels,
                   m_data,
                   0);
}