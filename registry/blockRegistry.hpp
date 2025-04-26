#pragma once

#include "lce/blocks/block.hpp"
#include "lce/include/RegistryNamespaced.hpp"


namespace lce::registry {

    class MU BlockRegistry {
    public:
        BlockRegistry();

    private:

        RegistryNamespaced<Block> REGISTRY;
        std::unordered_multimap<int, const Block*> idToBlock;
        bool isSetup = false;

        void addBlock(const Block* blockIn);
        void setUpBlocks();

        Block const* p_getBlock(int id, int data) const;
        Block const* p_getBlockFromID(int id) const;
        Block const* p_getBlockFromName(const std::string& name) const;

        static BlockRegistry& getInstance() {
            static BlockRegistry instance;
            return instance;
        }

    public:
        MU void setup();
        MU static Block const* getBlock(int id, int data);
        MU static Block const* getBlockFromID(int id);
        MU static Block const* getBlockFromName(const std::string& name);
    };


}