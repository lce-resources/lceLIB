#pragma once


#include "lce/include/RegistryNamespaced.hpp"
#include "lce/include/picture.hpp"


class TextureMap {

    Picture terrainTexture;

    void add(int theID, uint32_t theX, uint32_t theY);

public:
    RegistryNamespaced<Picture> BLOCK_TEXTURES;

    void setup();

};
