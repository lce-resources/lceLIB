#pragma once

#include <string>
#include <utility>
#ifdef INCLUDE_QT
#include <QDebug>
#endif

#include "lce/processor.hpp"
#include "lce/items/enums.hpp"


namespace lce::items {

    class Item {
        const std::string name;
        const std::string identifier;
        c_u16 id{};
        c_u8 dataTag{};
        const EntityEquipSlot armorType = EntityEquipSlot::NONE;
        c_i8 enchantability = 1;
        const ItemType type{};
        c_bool damageable{};

    public:
        Item() = default;
        Item(c_u16 id, c_u8 dataTag, const ItemType type, std::string itemName,
             std::string identifier, c_bool damageable, EntityEquipSlot const armorType,
             c_i8 enchantability)
            : name(std::move(itemName)), identifier(std::move(identifier)), id(id), dataTag(dataTag),
              armorType(armorType), enchantability(enchantability), type(type), damageable(damageable) {}

        Item(c_u16 id, c_u8 dataTag, const ItemType type, std::string itemName,
             std::string identifier, c_bool damageable = false)
            : Item(id, dataTag, type, std::move(itemName), std::move(identifier), damageable,
                   EntityEquipSlot::NONE, 1) {}
        Item(c_u16 id, c_u8 dataTag, const ItemType type, std::string itemName,
             std::string identifier, c_bool damageable, c_i8 enchantability)
            : Item(id, dataTag, type, std::move(itemName), std::move(identifier), damageable, EntityEquipSlot::NONE,
                   enchantability) {}
        Item(c_u16 id, c_u8 dataTag, const ItemType type, std::string itemName,
             std::string identifier, c_i8 enchantability)
            : Item(id, dataTag, type, std::move(itemName), std::move(identifier), false, EntityEquipSlot::NONE,
                   enchantability) {}
        Item(c_u16 id, c_u8 dataTag, const ItemType type, std::string itemName,
             std::string identifier, const EntityEquipSlot armorType, c_i8 enchantability)
            : Item(id, dataTag, type, std::move(itemName), std::move(identifier), false, armorType, enchantability) {}
        Item(c_u16 id, c_u8 dataTag, std::string itemName, std::string identifier)
            : Item(id, dataTag, ItemType::ItemBlock, std::move(itemName), std::move(identifier), false,
                   EntityEquipSlot::NONE, 1) {}


        ND uint16_t getID() const { return id; }
        ND uint8_t getDataTag() const { return dataTag; }
        ND ItemType getItemType() const { return type; }
        ND std::string getName() const { return name; }
        ND std::string getIdentifier() const { return identifier; }
        ND bool isDamageable() const { return damageable; }
        ND EntityEquipSlot getArmorType() const { return armorType; }
        ND int8_t getCost() const { return enchantability; }

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
