#pragma once

#include "lce/blocks/block.hpp"
#include "lce/include/RegistryNamespaced.hpp"

namespace lce::registry {

    class MU BlockRegistry {
        static RegistryNamespaced<Block> REGISTRY;
        static std::unordered_multimap<int, const Block*> idToBlock;
        static bool isSetup;

        static BlockRegistry s_instance;

        static void addBlock(const Block* blockIn);
        static void setUpBlocks();
        MU static void setup();

        BlockRegistry();

    public:
        MU static Block const* getBlock(int id, int data);
        MU static Block const* getBlockFromID(int id);
        MU static Block const* getBlockFromName(const std::string& name);
        MU static Block const* getBlockExact(int id, int data);

        template <class F>
        MU static void forEachBlock(F&& fn) {
            for (const auto& kv : idToBlock) fn(kv.second);
        }
    };

}
