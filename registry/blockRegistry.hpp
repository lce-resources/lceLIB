#pragma once

#include "lce/blocks/block.hpp"
#include "lce/blocks/blocksInit.hpp"
#include "lce/include/RegistryNamespaced.hpp"


namespace lce::registry {

    class MU BlockRegistry {
    public:
        BlockRegistry();

    private:

        RegistryNamespaced<lce::Block> REGISTRY;
        std::unordered_multimap<int, const lce::Block*> idToBlock;
        bool isSetup = false;

        void addBlock(const lce::Block* blockIn);
        void setUpBlocks();
        MU void setup();

        lce::Block const* p_getBlock(int id, int data) const;
        lce::Block const* p_getBlockFromID(int id) const;
        lce::Block const* p_getBlockFromName(const std::string& name) const;

        static BlockRegistry& getInstance() {
            static BlockRegistry instance;
            return instance;
        }

    public:
        MU static lce::Block const* getBlock(int id, int data);
        MU static lce::Block const* getBlockFromID(int id);
        MU static lce::Block const* getBlockFromName(const std::string& name);
    };


}