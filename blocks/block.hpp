#pragma once

#include <string>
#include <utility>
#include <vector>
#ifdef INCLUDE_QT
#include <QDebug>
#endif

#include "lce/blocks/mapcolors.hpp"
#include "lce/items/Item.hpp"
#include "lce/processor.hpp"

#include "lce/include/RegistryNamespaced.hpp"



namespace lce::blocks {


    class Block {
        c_u16 id{};
        MU c_u8 dataTag;
        const MapColor mapColor{};

        const std::string identifier;
        const items::Item* item{};
        /*
         c_int lightOpacity;
         c_bool translucent;
         c_int lightValue;

         const float blockHardness{};
         c_bool needsRandomTick;
         c_bool isBlockContainer;
         const Material blockMaterial;
         */

    public:

        /// id, dataTag
        Block(c_u16 id, c_u8 dataTag) : id(id), dataTag(dataTag) {}

        /// id, dataTag, identifier
        Block(c_u16 id, c_u8 dataTag, std::string identifier)
            : id(id), dataTag(dataTag), mapColor(MapColor::NONE),
              identifier(std::move(identifier)) {}

        /// id, dataTag, identifier, item
        Block(c_u16 id, c_u8 dataTag, std::string identifier, const items::Item* item)
            : id(id), dataTag(dataTag), identifier(std::move(identifier)), item(item) {}

        /// id, dataTag, identifier, item, mapColor
        Block(c_u16 id, c_u8 dataTag, std::string identifier,
              const items::Item* item, const MapColor mapColor) : id(id), dataTag(dataTag),
                 mapColor(mapColor), identifier(std::move(identifier)), item(item) {}

        bool operator==(const Block &other) const {
            return id == other.id && dataTag == other.dataTag;
        }

        MU ND uint16_t getID() const { return id; }
        MU ND std::string getName() const { return identifier; }
        MU ND items::Item const* getItem() const { return item; }
        MU ND MapColor getMapColor() const { return mapColor; }
        MU ND uint8_t getDataTag() const { return dataTag; }

        MU ND Block getStateFromMeta(c_u32 meta) const { return {id, static_cast<uint8_t>(meta)}; }
        MU ND Block getStateFromMeta(c_int meta) const { return {id, static_cast<uint8_t>(meta)}; }
    };
}