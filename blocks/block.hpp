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

    class Block;
    static RegistryNamespaced<Block> REGISTRY;


    class Block {


        const uint16_t id{};
        const uint8_t dataTag{};
        const MapColor mapColor{};

        const std::string identifier;
        const lce::items::Item* item;
        /*
         const int lightOpacity;
         const bool translucent;
         const int lightValue;

         const float blockHardness{};
         const bool needsRandomTick;
         const bool isBlockContainer;
         const Material blockMaterial;
         */

    public:

        /// id, dataTag, identifier
        Block(const uint16_t id, uint8_t dataTag, const std::string& identifier)
            : id(id), dataTag(dataTag), identifier(identifier),
              item(nullptr), mapColor(MapColor::NONE) {
            if (dataTag == 0) { REGISTRY.registerValue(id, identifier, this);
            }
        }

        /// id, dataTag, identifier, item
        Block(const uint16_t id, uint8_t dataTag,
              const std::string& identifier, const lce::items::Item* item)
            : id(id), dataTag(dataTag), identifier(identifier), item(item) {
            if (dataTag == 0) { REGISTRY.registerValue(id, identifier, this);
            }
        }

        /// id, dataTag, identifier, item, mapColor
        Block(const uint16_t id, uint8_t dataTag, const std::string& identifier,
              const lce::items::Item* item, MapColor mapColor) : id(id), dataTag(dataTag),
             identifier(identifier), item(item), mapColor(mapColor) {
            if (dataTag == 0) { REGISTRY.registerValue(id, identifier, this);
            }
        }

        MU ND uint16_t getID() const { return id; }
        MU ND std::string getIdentifier() const { return identifier; }
        MU ND lce::items::Item const* getItem() const { return item; }
        MU ND MapColor getMapColor() const { return mapColor; }
    };




}