#pragma once

#include "lce/blocks/block.hpp"
#include "lce/blocks/blocks.hpp"
#include "lce/include/RegistryNamespaced.hpp"


namespace lce::registry {

    class MU BlockRegistry {
    public:
        BlockRegistry();

    private:

        RegistryNamespaced<lce::blocks::Block> REGISTRY;
        std::unordered_multimap<int, const lce::blocks::Block*> idToBlock;
        bool isSetup = false;

        void addBlock(const lce::blocks::Block* blockIn);
        void setUpBlocks();
        MU void setup();

        lce::blocks::Block const* p_getBlock(int id, int data) const;
        lce::blocks::Block const* p_getBlockFromID(int id) const;
        lce::blocks::Block const* p_getBlockFromName(const std::string& name) const;

        static BlockRegistry& getInstance() {
            static BlockRegistry instance;
            return instance;
        }

    public:
        MU static lce::blocks::Block const* getBlock(int id, int data);
        MU static lce::blocks::Block const* getBlockFromID(int id);
        MU static lce::blocks::Block const* getBlockFromName(const std::string& name);
    };


}