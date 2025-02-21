#pragma once

#include <ostream>

#ifdef INCLUDE_QT
#include <QDebug>
#endif

#include "lce/processor.hpp"
#include "lce/items/enums.hpp"

namespace lce {

    class ItemState {
    public:
        u16 id;     // block ID
        u8 dataTag; // block data value

        constexpr ItemState(c_u16 id, c_u8 dataTag) : id(id), dataTag(dataTag) {}

        // Accessors
        MU ND constexpr u16 getID()      const { return id; }
        MU ND constexpr u8  getDataTag() const { return dataTag; }

        // Equality checks ID & dataTag
        constexpr bool operator==(const ItemState &other) const {
            return id == other.id && dataTag == other.dataTag;
        }
    };


    class Item : ItemState {
        i8 enchantability;
        bool damageable;
        items::EntityEquipSlot armorType;
        items::ItemType type;

        const char* name;
        const char* identifier;

    public:
        // Default constructor
        constexpr Item()
            : ItemState(0, 0),
            enchantability(1),
            damageable(false),
            armorType(items::EntityEquipSlot::NONE),
            type(items::ItemType::ItemBlock),
            name(""),
            identifier("") {
            static_assert(std::is_constant_evaluated(), "Block must be constructed in a constexpr context!");
        }

        // Full constructor
        constexpr Item(c_u16 id, c_u8 dataTag, const items::ItemType type,
                       const char* itemName, const char* identifier, c_bool damageable,
                       const items::EntityEquipSlot armorType, c_i8 enchantability)
            : ItemState(id, dataTag),
            enchantability(enchantability),
            damageable(damageable),
            armorType(armorType),
            type(type),
            name(itemName),
            identifier(identifier) {
            static_assert(std::is_constant_evaluated(), "Block must be constructed in a constexpr context!");
        }

        // Constructor (id, dataTag, type, name, identifier, damageable)
        constexpr Item(c_u16 id, c_u8 dataTag, const items::ItemType type,
                       const char* itemName, const char* identifier, c_bool damageable)
            : Item(id, dataTag, type, itemName, identifier, damageable,
                   items::EntityEquipSlot::NONE, 1) {}

        // Constructor (id, dataTag, type, name, identifier, damageable, enchantability)
        constexpr Item(c_u16 id, c_u8 dataTag, const items::ItemType type,
                       const char* itemName, const char* identifier, c_bool damageable, c_i8 enchantability)
            : Item(id, dataTag, type, itemName, identifier, damageable,
                   items::EntityEquipSlot::NONE, enchantability) {
            static_assert(std::is_constant_evaluated(), "Block must be constructed in a constexpr context!");
        }

        // Constructor (id, dataTag, type, name, identifier, enchantability)
        constexpr Item(c_u16 id, c_u8 dataTag, const items::ItemType type,
                       const char* itemName, const char* identifier, c_i8 enchantability)
            : Item(id, dataTag, type, itemName, identifier, false,
                   items::EntityEquipSlot::NONE, enchantability) {
            static_assert(std::is_constant_evaluated(), "Block must be constructed in a constexpr context!");
        }

        // Constructor (id, dataTag, type, name, identifier, armorType, enchantability)
        constexpr Item(c_u16 id, c_u8 dataTag, const items::ItemType type,
                       const char* itemName, const char* identifier,
                       const items::EntityEquipSlot armorType, c_i8 enchantability)
            : Item(id, dataTag, type, itemName, identifier, false, armorType, enchantability) {
            static_assert(std::is_constant_evaluated(), "Block must be constructed in a constexpr context!");
        }

        // Constructor (id, dataTag, name, identifier)
        constexpr Item(c_u16 id, c_u8 dataTag, const char* itemName, const char* identifier)
            : Item(id, dataTag, items::ItemType::ItemBlock, itemName, identifier, false,
                   items::EntityEquipSlot::NONE, 1) {
            static_assert(std::is_constant_evaluated(), "Block must be constructed in a constexpr context!");
        }

        // Constructor (id, dataTag, type, name, identifier)
        constexpr Item(c_u16 id, c_u8 dataTag, const items::ItemType type,
               const char* itemName, const char* identifier)
            : Item(id, dataTag, type, itemName, identifier, false, items::EntityEquipSlot::NONE, 1) {}


        // Accessor functions
        MU ND constexpr u16                    getID()         const { return id; }
        MU ND constexpr u8                     getDataTag()    const { return dataTag; }
        MU ND constexpr items::ItemType        getItemType()   const { return type; }
        MU ND constexpr const char*            getName()       const { return name; }
        MU ND constexpr const char*            getIdentifier() const { return identifier; }
        MU ND constexpr bool                   isDamageable()  const { return damageable; }
        MU ND constexpr items::EntityEquipSlot getArmorType()  const { return armorType; }
        MU ND constexpr int8_t                 getCost()       const { return enchantability; }

        // Equality checks ID & dataTag
        constexpr bool operator==(const ItemState &other) const {
            return id == other.id && dataTag == other.dataTag;
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
