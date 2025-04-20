#pragma once

#include <cstdint>


namespace lce {
    namespace items {
        /// 10 item types, requires 4 bits
        enum class ItemType : int8_t {
            NONE = 0,
            ItemArmor = 1,
            ItemBlock = 2,
            ItemBow = 3,
            ItemElytra = 4,
            ItemFishingRod = 5,
            ItemSkull = 6,
            ItemSword = 7,
            ItemTool = 8,
            ItemTrident = 9
        };

        /// represents what armor slots are allowed for a specific item
        /// 5 equipment slots, requires 3 bits.
        enum class ItemEquipSlot : int8_t {
            NONE = 0,
            FEET = 1,
            LEGS = 2,
            CHEST = 3,
            HEAD = 4,
        };

        /// represents enchantability for a specific armor material
        enum ArmorMaterials : int8_t {
            ARMOR_LEATHER = 15,
            ARMOR_CHAIN = 12,
            ARMOR_IRON = 9,
            ARMOR_GOLD = 25,
            ARMOR_DIAMOND = 10,
        };

        /// represents enchantability for a specific tool material
        enum ToolMaterials : int8_t {
            TOOL_WOOD = 15,
            TOOL_STONE = 5,
            TOOL_IRON = 14,
            TOOL_DIAMOND = 10,
            TOOL_GOLD = 22,
        };
    }
}