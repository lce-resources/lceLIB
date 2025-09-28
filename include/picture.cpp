#include "lce/include/picture.hpp"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION

#include <cstring>
#include <string>
#include <cmath>

#include "lce/include/stb_image.hpp"
#include "lce/include/stb_image_write.hpp"


static inline u8 clamp_to_u8(float v) {
    if (v <= 0.f) return 0;
    if (v >= 255.f) return 255;
    return static_cast<u8>(std::lround(v));
}

// Channel-aware, alpha-safe bilinear resize (srcCh may differ from dstCh).
static void resizeBilinear(c_u8* src, u8* dst,
                           c_u32 srcWidth, c_u32 srcHeight,
                           c_u32 dstWidth, c_u32 dstHeight,
                           c_u32 srcCh, c_u32 dstCh)
{
    const bool srcHasAlpha = (srcCh == 4 || srcCh == 2);

    auto fetchRGBA = [&](u32 sx, u32 sy, float& R, float& G, float& B, float& A) {
        const u8* p = src + (static_cast<size_t>(sy) * srcWidth + sx) * srcCh;
        switch (srcCh) {
            case 4: // RGBA
                R = p[0]; G = p[1]; B = p[2]; A = p[3];
                break;
            case 3: // RGB
                R = p[0]; G = p[1]; B = p[2]; A = 255.f;
                break;
            case 2: // GA (gray + alpha)
                R = G = B = p[0]; A = p[1];
                break;
            case 1: // G (gray)
                R = G = B = p[0]; A = 255.f;
                break;
            default: // Fallback: use first 3 (or repeat) + opaque alpha
                R = p[0];
                G = (srcCh > 1 ? p[1] : p[0]);
                B = (srcCh > 2 ? p[2] : p[0]);
                A = (srcCh > 3 ? static_cast<float>(p[3]) : 255.f);
                break;
        }
        // Premultiply to avoid halos during interpolation if source has alpha
        if (srcHasAlpha) {
            const float a = A / 255.f;
            R *= a; G *= a; B *= a;
        }
    };

    const float xRatio = static_cast<float>(srcWidth)  / static_cast<float>(dstWidth);
    const float yRatio = static_cast<float>(srcHeight) / static_cast<float>(dstHeight);

    for (u32 y = 0; y < dstHeight; ++y) {
        const float sy = static_cast<float>(y) * yRatio;
        const u32 yT = static_cast<u32>(sy);
        const u32 yB = std::min(yT + 1, srcHeight - 1);
        const float yDiff = sy - static_cast<float>(yT);

        for (u32 x = 0; x < dstWidth; ++x) {
            const float sx = static_cast<float>(x) * xRatio;
            const u32 xL = static_cast<u32>(sx);
            const u32 xR = std::min(xL + 1, srcWidth - 1);
            const float xDiff = sx - static_cast<float>(xL);

            // Fetch four neighbors as premultiplied RGBA
            float r00, g00, b00, a00; fetchRGBA(xL, yT, r00, g00, b00, a00);
            float r10, g10, b10, a10; fetchRGBA(xR, yT, r10, g10, b10, a10);
            float r01, g01, b01, a01; fetchRGBA(xL, yB, r01, g01, b01, a01);
            float r11, g11, b11, a11; fetchRGBA(xR, yB, r11, g11, b11, a11);

            // Bilinear on premultiplied channels
            const float rTop = r00 + xDiff * (r10 - r00);
            const float gTop = g00 + xDiff * (g10 - g00);
            const float bTop = b00 + xDiff * (b10 - b00);
            const float aTop = a00 + xDiff * (a10 - a00);

            const float rBot = r01 + xDiff * (r11 - r01);
            const float gBot = g01 + xDiff * (g11 - g01);
            const float bBot = b01 + xDiff * (b11 - b01);
            const float aBot = a01 + xDiff * (a11 - a01);

            float r = rTop + yDiff * (rBot - rTop);
            float g = gTop + yDiff * (gBot - gTop);
            float b = bTop + yDiff * (bBot - bTop);
            float a = aTop + yDiff * (aBot - aTop);

            // Unpremultiply back to straight alpha space for output
            float up = (a > 0.f) ? (255.f / a) : 0.f;
            float Ru = (srcHasAlpha ? r * up : r);
            float Gu = (srcHasAlpha ? g * up : g);
            float Bu = (srcHasAlpha ? b * up : b);

            // Pack to dst (handle any dstCh 1/2/3/4)
            u8* out = dst + (static_cast<size_t>(y) * dstWidth + x) * dstCh;
            switch (dstCh) {
                case 4: // RGBA
                    out[0] = clamp_to_u8(Ru);
                    out[1] = clamp_to_u8(Gu);
                    out[2] = clamp_to_u8(Bu);
                    out[3] = clamp_to_u8(a);
                    break;
                case 3: // RGB (drop alpha)
                    out[0] = clamp_to_u8(Ru);
                    out[1] = clamp_to_u8(Gu);
                    out[2] = clamp_to_u8(Bu);
                    break;
                case 2: { // GA (luma + alpha)
                    // Luma from *unpremultiplied* RGB
                    float Y = 0.2126f * Ru + 0.7152f * Gu + 0.0722f * Bu;
                    out[0] = clamp_to_u8(Y);
                    out[1] = clamp_to_u8(a);
                    break;
                }
                case 1: { // G (luma)
                    float Y = 0.2126f * Ru + 0.7152f * Gu + 0.0722f * Bu;
                    out[0] = clamp_to_u8(Y);
                    break;
                }
                default: { // Fallback: write first min(dstCh,3) and alpha if present
                    const u32 n = std::min<u32>(dstCh, 3);
                    if (n >= 1) out[0] = clamp_to_u8(Ru);
                    if (n >= 2) out[1] = clamp_to_u8(Gu);
                    if (n >= 3) out[2] = clamp_to_u8(Bu);
                    if (dstCh >= 4) out[3] = clamp_to_u8(a);
                    break;
                }
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


MU Picture::Picture(c_i32 width, c_i32 height, c_i32 channels) : Picture(width, height) {
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


void Picture::placeAndStretchSubImage(Picture const* picToPlace,
                                      c_i32 sX, c_i32 sY, c_i32 tX, c_i32 tY) const {
    if (!isValid() || sX >= m_width || sY >= m_height || !picToPlace->isValid()) {
        return;
    }

    // Allocate memory for the resized sub-image in *destination* format
    const u32 dstCh = static_cast<u32>(this->m_channels);
    auto* resizedSubImage = new u8[static_cast<size_t>(tX) * static_cast<size_t>(tY) * dstCh];

    // Resize + convert channels as needed (e.g., RGBA -> RGB)
    resizeBilinear(picToPlace->m_data, resizedSubImage,
                   static_cast<u32>(picToPlace->m_width),
                   static_cast<u32>(picToPlace->m_height),
                   static_cast<u32>(tX), static_cast<u32>(tY),
                   static_cast<u32>(picToPlace->m_channels),
                   dstCh);

    // Calculate bounds for placement
    const i32 eX = std::min(sX + tX, m_width);
    const i32 eY = std::min(sY + tY, m_height);
    const i32 widthInput  = eX - sX;
    const i32 heightInput = eY - sY;

    // Blit the resized sub-image into the destination
    for (i32 yIter = 0; yIter < heightInput; ++yIter) {
        const size_t indexOut = (static_cast<size_t>(sY + yIter) * m_width + sX) * dstCh;
        const size_t indexIn  = (static_cast<size_t>(yIter) * tX) * dstCh;
        std::memcpy(&this->m_data[indexOut], &resizedSubImage[indexIn],
                    static_cast<size_t>(widthInput) * dstCh);
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