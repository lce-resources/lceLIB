#pragma once

#include <utility>

#include "lce/blocks/mapcolors.hpp"
#include "lce/processor.hpp"
#include "lce/titleUpdate.hpp"


namespace lce {


    class BlockState {
    public:
        u16 id;         // block ID
        u8 dataTag;    // block data value

        constexpr BlockState(c_u16 id, c_u8 dataTag) : id(id), dataTag(dataTag) {}

        // Accessors
        MU ND constexpr u16 getID()      const { return id; }
        MU ND constexpr u8  getDataTag() const { return dataTag; }

        // Equality checks ID & dataTag
        constexpr bool operator==(const BlockState &other) const {
            return id == other.id && dataTag == other.dataTag;
        }

        MU ND BlockState getStateFromMeta(c_u32 meta) const { return {id, static_cast<uint8_t>(meta)}; }
        MU ND BlockState getStateFromMeta(c_int meta) const { return {id, static_cast<uint8_t>(meta)}; }
    };


    class Block : BlockState {
        MU blocks::MapColor mapColor{};  // optional map color
        const char*         name = nullptr; // block name (string literal)
        MU const int        titleUpdate{};

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
        // 1) Minimal constructor: (TU, id, dataTag)
        MU constexpr Block(const TU titleUpdate, c_u16 blockID, c_u8 data)
            : BlockState(blockID, data)
            , mapColor(blocks::MapColor::NONE)
            , name("")
            , titleUpdate(titleUpdate.value()) {
#ifndef _MSC_VER
            static_assert(std::is_constant_evaluated(), "Block must be constructed in a constexpr context!");
#endif
        }

        // 2) (TU, id, dataTag, name)
        constexpr Block(const TU titleUpdate, c_u16 blockID, c_u8 data, const char* blockName)
            : BlockState(blockID, data)
            , mapColor(blocks::MapColor::NONE)
            , name(blockName)
            , titleUpdate(titleUpdate.value()) {
#ifndef _MSC_VER
            static_assert(std::is_constant_evaluated(), "Block must be constructed in a constexpr context!");
#endif
        }
        Block(const Block&) = delete;
        Block& operator=(const Block&) = delete;

        // Accessors
        MU ND constexpr u16              getID()           const { return id; }
        MU ND constexpr u8               getDataTag()      const { return dataTag; }
        MU ND constexpr const char*      getName()         const { return name; }
        MU ND constexpr blocks::MapColor getMapColor()     const { return mapColor; }
        MU ND constexpr BlockState       getState()        const { return {id, dataTag}; }
        MU ND constexpr BlockState       getDefaultState() const { return {id, dataTag}; }
        MU ND constexpr int              getTU()           const { return titleUpdate; }

        // Equality checks ID & dataTag
        constexpr bool operator==(const BlockState &other) const {
            return id == other.id && dataTag == other.dataTag;
        }

        MU ND constexpr BlockState getStateFromMeta(c_u32 meta) const { return {id, static_cast<uint8_t>(meta)}; }
        MU ND constexpr BlockState getStateFromMeta(c_int meta) const { return {id, static_cast<uint8_t>(meta)}; }
    };


}