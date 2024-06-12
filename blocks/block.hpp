#pragma once

#include <string>
#include <utility>
#include <vector>
#ifdef INCLUDE_QT
#include <QDebug>
#endif

#include "lce/processor.hpp"
#include "lce/blocks/mapcolors.hpp"
#include "lce/include/RegistryNamespaced.hpp"


namespace lce::blocks {

    class Block {

        static RegistryNamespaced<Block> REGISTRY;

        const std::string identifier;
        const uint16_t id{};
        const MapColor mapColor{};
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

        Block(const uint16_t id, std::string identifier) : id(id),
             identifier(std::move(identifier)), mapColor(MapColor::NONE) {
            REGISTRY.registerValue(id, identifier, this);
        }

        Block(const uint16_t id, std::string identifier, MapColor mapColor) : id(id),
            identifier(std::move(identifier)), mapColor(mapColor) {
            REGISTRY.registerValue(id, identifier, this);
        }

        MU ND uint16_t getID() const { return id; }
        MU ND std::string getIdentifier() const { return identifier; }
        MU ND MapColor getMapColor() const { return mapColor; }
    };




}