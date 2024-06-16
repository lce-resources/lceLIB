#pragma once

#include "lce/blocks/block.hpp"
#include "lce/blocks/blocks.hpp"
#include "lce/include/RegistryNamespaced.hpp"


namespace lce::registry {

    class BlockRegistry {
        RegistryNamespaced<lce::blocks::Block> REGISTRY;
        bool isSetup;

        void addBlock(const lce::blocks::Block& blockIn);
        void setUpBlocks();

    public:
        void setup();

        MU lce::blocks::Block const* getBlockFromID(int id);
        MU lce::blocks::Block const* getBlockFromName(const std::string& name);
    };


}