#pragma once

#include "lce/include/RegistryNamespaced.hpp"
#include "lce/include/picture.hpp"


namespace lce::registry {

    class MU TextureRegistry {
        static bool isSetup;

        static const std::string BLOCK_TEXTURE_FILE;
        static constexpr uint32_t BLOCK_TEXTURE_WIDTH = 256;
        static constexpr uint32_t BLOCK_TEXTURE_HEIGHT = 544;

        Picture blockPicture;
        RegistryNamespaced<Picture> textureRegistry;

        void addBlock(int theID, const std::string& theIdentifier, uint32_t theX, uint32_t theY);
        void setUpTextures();

    public:
        MU ND Picture const* getBlockFromID(int id);
        MU ND Picture const* getBlockFromName(const std::string& name);

        MU void setup();
        MU void deallocate();
    };

}
