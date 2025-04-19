#pragma once

#include "lce/include/RegistryNamespaced.hpp"
#include "lce/items/Item.hpp"


namespace lce::registry {

    class MU ItemRegistry {
        static RegistryNamespaced<Item> REGISTRY;
        static std::unordered_multimap<int, const Item*> idToItem;
        static bool isSetup;

        static void addItem(const Item* itemIn);
        static void setUpItems();

        static Item const* p_getItem(int id, int data);
        static Item const* p_getItemFromID(int id);
        static Item const* p_getItemFromName(const std::string& name);

    public:
        ItemRegistry() = delete;

        MU static void setup();
        MU static Item const* getItem(int id, int data);
        MU static Item const* getItemFromID(int id);
        MU static Item const* getItemFromName(const std::string& name);
    };


}