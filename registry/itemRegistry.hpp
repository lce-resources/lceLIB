#pragma once

#include "lce/include/RegistryNamespaced.hpp"
#include "lce/items/Item.hpp"

namespace lce::registry {

    class MU ItemRegistry {
        static RegistryNamespaced<Item> REGISTRY;
        static std::unordered_multimap<int, const Item*> idToItem;
        static bool isSetup;

        static ItemRegistry s_instance;

        static void addItem(const Item* itemIn);
        static void setUpItems();
        MU static void setup();

        static Item const* p_getItem(int id, int data);
        static Item const* p_getItemFromID(int id);
        static Item const* p_getItemFromName(const std::string& name);
        static Item const* p_getItemFromIdentifier(const std::string& identifier);

        ItemRegistry();
    public:

        MU static Item const* getItem(int id, int data);
        MU static Item const* getItemFromID(int id);
        MU static Item const* getItemFromName(const std::string& name);
        MU static Item const* getItemFromIdentifier(const std::string& identifier);
    };
}
