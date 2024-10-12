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
        const lce::items::Item* item;
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

        /// id, dataTag, identifier
        Block(c_u16 id, u8 dataTag, std::string identifier)
            : id(id), dataTag(dataTag), mapColor(MapColor::NONE),
              identifier(std::move(identifier)), item(nullptr) {}

        /// id, dataTag, identifier, item
        Block(c_u16 id, u8 dataTag,
              std::string identifier, const lce::items::Item* item)
            : id(id), dataTag(dataTag), identifier(std::move(identifier)), item(item) {}

        /// id, dataTag, identifier, item, mapColor
        Block(c_u16 id, u8 dataTag, std::string identifier,
              const lce::items::Item* item, MapColor mapColor) : id(id), dataTag(dataTag),
                 mapColor(mapColor), identifier(std::move(identifier)), item(item) {}

        MU ND u16 getID() const { return id; }
        MU ND u8 getDataTag() const { return dataTag; }
        MU ND std::string getName() const { return identifier; }
        MU ND lce::items::Item const* getItem() const { return item; }
        MU ND MapColor getMapColor() const { return mapColor; }
        MU ND uint8_t getDataTag() const { return dataTag; }
    };




}