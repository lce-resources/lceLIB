#pragma once


#include "lce/include/RegistryNamespaced.hpp"
#include "lce/include/picture.hpp"


class TextureMap {

    const std::string BLOCK_TEXTURE_FILE = "lce/assets/terrain.png";
    static constexpr uint32_t BLOCK_TEXTURE_WIDTH = 256;
    static constexpr uint32_t BLOCK_TEXTURE_HEIGHT = 544;

    const std::string ITEM_TEXTURE_FILE = "lce/assets/items.png";
    static const uint32_t ITEM_TEXTURE_WIDTH = 256;
    static const uint32_t ITEM_TEXTURE_HEIGHT = 272;

    Picture blockTexture;
    Picture itemTexture;


    // RegistryNamespaced<Picture> itemRegistry;

    void addBlock(int theID, const std::string& theIdentifier, uint32_t theX, uint32_t theY);
    // void addItem(int theID, uint32_t theX, uint32_t theY);

    void setupBlocks();
    // void setupItems();

public:
    RegistryNamespaced<Picture> blockRegistry;

    void setup();
    Picture const* getBlockFromID(int id);
    // Picture const* getItemByID(int id);

};
