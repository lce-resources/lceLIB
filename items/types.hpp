#pragma once

#include "Item.hpp"


namespace lce::items {

    class Armor : public Item {
    public:
        Armor(c_int id, const std::string& itemName, const std::string& ident, const EntityEquipSlot slot,
              c_i8 materialEnchantability)
            : Item(id, 0, ItemType::ItemArmor, itemName, ident, slot, materialEnchantability) {}
    };

    class Skull : public Item {
    public:
        Skull(c_int id, c_int dataTag, std::string itemName, std::string ident)
            : Item(id, dataTag, ItemType::ItemSkull, std::move(itemName), std::move(ident)) {}
    };

    class Sword : public Item {
    public:
        Sword(c_int id, std::string itemName, std::string ident, const ToolMaterials materialEnchantability)
            : Item(id, 0, ItemType::ItemSword, std::move(itemName), std::move(ident), true, materialEnchantability) {}
    };

    class Tool : public Item {
    public:
        Tool(c_int id, std::string itemName, std::string ident, c_i8 materialEnchantability)
            : Item(id, 0, ItemType::ItemTool, std::move(itemName), std::move(ident), true, materialEnchantability) {}
    };

    class Trident : public Item {
    public:
        Trident(c_int id, c_int dataTag, std::string itemName, std::string ident)
            : Item(id, dataTag, ItemType::ItemTrident, std::move(itemName), std::move(ident)) {}
    };

}