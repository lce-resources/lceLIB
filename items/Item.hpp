#pragma once

#ifdef INCLUDE_QT
#include <QDebug>
#endif
#include <ostream>
#include "lce/processor.hpp"
#include "lce/items/enums.hpp"

namespace lce {

    using namespace items;

    class ItemState {
    public:
        u16 m_id;
        u8 m_data;
        u8 m_typeAndArmor;
        u8 m_enchantability;
        bool m_damageable;
        u8 m_myItemCount = 0;
        u8 m_myContainerIndex = 0;
        // I can fit 7 more bits

        constexpr ItemState(c_u16 id, c_u8 dataTag,
             const ItemType itemType, const ItemEquipSlot armorType, c_bool damageable, c_u8 enchantability) noexcept
            : m_id(id), m_data(dataTag), m_enchantability(enchantability), m_damageable(damageable) {
            m_typeAndArmor = static_cast<u8>(static_cast<int>(itemType) << 4 | static_cast<int>(armorType));
        }

        constexpr ItemState(c_u16 id, c_u8 dataTag) noexcept
            : ItemState(id, dataTag, ItemType::NONE, ItemEquipSlot::NONE, false, 1) {}

        constexpr ItemState() noexcept : ItemState(0, 0, ItemType::ItemBlock, ItemEquipSlot::NONE, false, 1) {}

        // Accessors
        MU ND constexpr u16           getID()         const noexcept { return m_id; }
        MU ND constexpr u8            getDataTag()    const noexcept { return m_data; }
        MU ND constexpr ItemType      getItemType()   const noexcept { return static_cast<ItemType>(m_typeAndArmor >> 4); }
        MU ND constexpr ItemEquipSlot getArmorType()  const noexcept { return static_cast<ItemEquipSlot>(m_typeAndArmor & 0x0F); }
        MU ND constexpr bool          isDamageable()  const noexcept { return m_damageable; }
        MU ND constexpr u8            getCost()       const noexcept { return m_enchantability; }
        MU ND constexpr i32           getCount()      const noexcept { return m_myItemCount; }
        MU ND constexpr u32           getContainerIndex() const noexcept { return m_myContainerIndex; }

        MU constexpr void setData(c_u8 dataIn) noexcept { m_data = dataIn; }

        MU constexpr void setItemCount(c_u8 itemCount) noexcept { m_myItemCount = itemCount; }

        MU constexpr void setContainerIndex(c_u8 containerIndex) noexcept { m_myContainerIndex = containerIndex; }

        MU ND constexpr ItemState getStateFromMeta(c_u8 meta) const noexcept {
            ItemState theState = *this;
            theState.m_data = meta;
            return theState;
        }

        MU constexpr void setStateFromMeta(const u8 theData) { m_data = theData; }

        // Equality checks ID & dataTag
        constexpr bool operator==(const ItemState &other) const noexcept {
            return m_id == other.m_id && m_data == other.m_data;
        }

        constexpr bool operator<(const ItemState &other) const noexcept {
            if (m_id != other.m_id) return m_id < other.m_id;
            return m_data < other.m_data;
        }

        constexpr bool operator>(const ItemState &other) const noexcept {
            if (m_id != other.m_id) return m_id > other.m_id;
            return m_data > other.m_data;
        }

        friend std::ostream& operator<<(std::ostream& out, const ItemState& item) {
            out << "ItemState("
                << std::to_string(item.m_id)
                << ", "
                << std::to_string(item.m_data)
                << ", "
                << std::to_string(item.m_myItemCount)
                << ")";
            return out;
        }

        MU ItemState split(const i32 count) noexcept {
            const i32 splitCount = std::min(count, static_cast<i32>(m_myItemCount));
            ItemState splitItem(*this);
            splitItem.m_myItemCount = static_cast<u8>(splitCount);
            m_myItemCount -= splitCount;
            return splitItem;
        }

    };


    class Item : public ItemState {
        const char* m_name;
        const char* m_identifier;
    public:

        consteval Item() noexcept : m_name(""), m_identifier("") {}

        // Full constructor
        consteval Item(c_u16 id, c_u8 dataTag, const ItemType type,
                       const char* itemName, const char* identifier, c_bool damageable,
                       const ItemEquipSlot armorType, c_u8 enchantability) noexcept
            : ItemState(id, dataTag, type, armorType, damageable, enchantability),
            m_name(itemName), m_identifier(identifier) {}

        // Constructor (id, dataTag, type, name, identifier, damageable)
        consteval Item(c_u16 id, c_u8 dataTag, const ItemType type,
                       const char* itemName, const char* identifier, c_bool damageable) noexcept
            : Item(id, dataTag, type, itemName, identifier, damageable, ItemEquipSlot::NONE, 1) {}

        // Constructor (id, dataTag, type, name, identifier, damageable, enchantability)
        consteval Item(c_u16 id, c_u8 dataTag, const ItemType type,
                       const char* itemName, const char* identifier, c_bool damageable, c_u8 enchantability) noexcept
            : Item(id, dataTag, type, itemName, identifier, damageable, ItemEquipSlot::NONE, enchantability) {}

        // Constructor (id, dataTag, type, name, identifier, enchantability)
        consteval Item(c_u16 id, c_u8 dataTag, const ItemType type,
                       const char* itemName, const char* identifier, c_u8 enchantability) noexcept
            : Item(id, dataTag, type, itemName, identifier, false, ItemEquipSlot::NONE, enchantability) {}

        // Constructor (id, dataTag, type, name, identifier, armorType, enchantability)
        consteval Item(c_u16 id, c_u8 dataTag, const ItemType type,
                       const char* itemName, const char* identifier,
                       const ItemEquipSlot armorType, c_u8 enchantability) noexcept
            : Item(id, dataTag, type, itemName, identifier, false, armorType, enchantability) {}

        // Constructor (id, dataTag, name, identifier)
        consteval Item(c_u16 id, c_u8 dataTag, const char* itemName, const char* identifier) noexcept
            : Item(id, dataTag, ItemType::ItemBlock, itemName, identifier, false, ItemEquipSlot::NONE, 1) {}

        // Constructor (id, dataTag, type, name, identifier)
        consteval Item(c_u16 id, c_u8 dataTag, const ItemType type,
               const char* itemName, const char* identifier) noexcept
            : Item(id, dataTag, type, itemName, identifier, false, ItemEquipSlot::NONE, 1) {}


        // Accessor functions
        MU ND constexpr const char* getName()                   const noexcept { return m_name; }
        MU ND constexpr const char* getIdentifier()             const noexcept { return m_identifier; }
        MU ND constexpr ItemState   getState()                  const noexcept { return *this; }
        MU ND constexpr ItemState   getStateFromMeta(c_u8 meta) const {
            ItemState theState = getState();
            theState.setData(meta);
            return theState;
        }

        // Equality checks ID & dataTag
        constexpr bool operator==(const ItemState &other) const noexcept {
            return getID() == other.getID() && getDataTag() == other.getDataTag();
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
