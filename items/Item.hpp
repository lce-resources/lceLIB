#pragma once

#include <ostream>

#ifdef INCLUDE_QT
#include <QDebug>
#endif

#include "lce/processor.hpp"
#include "lce/items/enums.hpp"

namespace lce {
    using namespace items;

    class ItemState {
    public:
        u16 id;
        u8 data;
        ItemType itemType : 4;
        ItemEquipSlot armorType : 4;
        u8 enchantability;
        bool damageable;
        // I can fit 7 more bits


        constexpr ItemState(c_u16 id, c_u8 dataTag,
             const ItemType itemType, const ItemEquipSlot armorType, c_bool damageable, c_u8 enchantability)
            : id(id), data(dataTag), itemType(itemType), armorType(armorType),
                enchantability(enchantability), damageable(damageable) {}

        constexpr ItemState(c_u16 id, c_u8 dataTag)
            : ItemState(id, dataTag, ItemType::NONE, ItemEquipSlot::NONE, false, 1) {}

        constexpr ItemState() : ItemState(0, 0, ItemType::ItemBlock, ItemEquipSlot::NONE, false, 1) {}

        // Accessors
        MU ND constexpr u16  getID()         const { return id; }
        MU ND constexpr u8   getDataTag()    const { return data; }
        MU ND constexpr u8   getItemType()   const { return static_cast<u8>(itemType); }
        MU ND constexpr u8   getArmorType()  const { return static_cast<u8>(armorType); }
        MU ND constexpr bool isDamageable()  const { return damageable; }
        MU ND constexpr i8   getCost()       const { return enchantability; }


        MU ND constexpr ItemState getStateFromMeta(c_u8 meta) const {
            return {id, meta, itemType, armorType, damageable, enchantability}; }


        // Equality checks ID & dataTag
        constexpr bool operator==(const ItemState &other) const {
            return id == other.id && data == other.data;
        }

    };


    class Item : ItemState {
        const char* name;
        const char* identifier;
    public:

        constexpr Item() : name(""), identifier("") {
            static_assert(std::is_constant_evaluated(), "Block must be constructed in a constexpr context!");
        }

        // Full constructor
        constexpr Item(c_u16 id, c_u8 dataTag, const ItemType type,
                       const char* itemName, const char* identifier, c_bool damageable,
                       const ItemEquipSlot armorType, c_i8 enchantability)
            : ItemState(id, dataTag, type, armorType, damageable, enchantability),
            name(itemName), identifier(identifier) {
            static_assert(std::is_constant_evaluated(), "Block must be constructed in a constexpr context!");
        }

        // Constructor (id, dataTag, type, name, identifier, damageable)
        constexpr Item(c_u16 id, c_u8 dataTag, const ItemType type,
                       const char* itemName, const char* identifier, c_bool damageable)
            : Item(id, dataTag, type, itemName, identifier, damageable, ItemEquipSlot::NONE, 1) {
            static_assert(std::is_constant_evaluated(), "Block must be constructed in a constexpr context!");
        }

        // Constructor (id, dataTag, type, name, identifier, damageable, enchantability)
        constexpr Item(c_u16 id, c_u8 dataTag, const ItemType type,
                       const char* itemName, const char* identifier, c_bool damageable, c_u8 enchantability)
            : Item(id, dataTag, type, itemName, identifier, damageable, ItemEquipSlot::NONE, enchantability) {
            static_assert(std::is_constant_evaluated(), "Block must be constructed in a constexpr context!");
        }

        // Constructor (id, dataTag, type, name, identifier, enchantability)
        constexpr Item(c_u16 id, c_u8 dataTag, const ItemType type,
                       const char* itemName, const char* identifier, c_u8 enchantability)
            : Item(id, dataTag, type, itemName, identifier, false, ItemEquipSlot::NONE, enchantability) {
            static_assert(std::is_constant_evaluated(), "Block must be constructed in a constexpr context!");
        }

        // Constructor (id, dataTag, type, name, identifier, armorType, enchantability)
        constexpr Item(c_u16 id, c_u8 dataTag, const ItemType type,
                       const char* itemName, const char* identifier,
                       const ItemEquipSlot armorType, c_u8 enchantability)
            : Item(id, dataTag, type, itemName, identifier, false, armorType, enchantability) {
            static_assert(std::is_constant_evaluated(), "Block must be constructed in a constexpr context!");
        }

        // Constructor (id, dataTag, name, identifier)
        constexpr Item(c_u16 id, c_u8 dataTag, const char* itemName, const char* identifier)
            : Item(id, dataTag, ItemType::ItemBlock, itemName, identifier, false, ItemEquipSlot::NONE, 1) {
            static_assert(std::is_constant_evaluated(), "Block must be constructed in a constexpr context!");
        }

        // Constructor (id, dataTag, type, name, identifier)
        constexpr Item(c_u16 id, c_u8 dataTag, const ItemType type,
               const char* itemName, const char* identifier)
            : Item(id, dataTag, type, itemName, identifier, false, ItemEquipSlot::NONE, 1) {
            static_assert(std::is_constant_evaluated(), "Block must be constructed in a constexpr context!");
        }


        // Accessor functions
        MU ND constexpr const char* getName()                   const { return name; }
        MU ND constexpr const char* getIdentifier()             const { return identifier; }
        MU ND constexpr ItemState   getState()                  const { return {id, data, itemType, armorType, damageable, enchantability}; }
        MU ND constexpr ItemState   getStateFromMeta(c_u8 meta) const { return {id, meta, itemType, armorType, damageable, enchantability}; }

        // Equality checks ID & dataTag
        constexpr bool operator==(const ItemState &other) const {
            return id == other.id && data == other.data;
        }

        // Operator overloads
        friend std::ostream& operator<<(std::ostream& out, const Item& item) {
            out << item.getName();
            return out;
        }

#ifdef INCLUDE_QT
        friend QDebug operator<<(QDebug out, const Item& item) {
            out.nospace() << QString::fromStdString(item.getName());
            return out.nospace();
        }
#endif
    };

}
