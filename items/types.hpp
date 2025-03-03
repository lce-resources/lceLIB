#pragma once

#include "Item.hpp"


namespace lce::items {

    class Armor : public Item {
    public:
        constexpr Armor(c_int id,  const char* itemName,  const char* ident, const ItemEquipSlot slot,
              c_i8 materialEnchantability)
            : Item(id, 0, ItemType::ItemArmor, itemName, ident, true, slot, materialEnchantability) {}
    };


    class Sword : public Item {
    public:
        constexpr Sword(c_int id, const char* itemName, const char* ident, const ToolMaterials materialEnchantability)
            : Item(id, 0, ItemType::ItemSword, itemName, ident, true, materialEnchantability) {}
    };

    class Tool : public Item {
    public:
        constexpr Tool(c_int id, const char* itemName, const char* ident, c_i8 materialEnchantability)
            : Item(id, 0, ItemType::ItemTool, itemName, ident, true, materialEnchantability) {}
    };

}