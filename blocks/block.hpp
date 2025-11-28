#pragma once

#include <utility>

#include "lce/blocks/mapcolors.hpp"
#include "lce/processor.hpp"
#include "lce/titleUpdate.hpp"


namespace lce {


    class BlockState {
    public:
        u16 m_id;         // block ID
        u8 m_dataTag;    // block data value

        constexpr BlockState(c_u16 id, c_u8 dataTag) : m_id(id), m_dataTag(dataTag) {}

        // Accessors
        MU ND constexpr u16 getID()      const { return m_id; }
        MU ND constexpr u8  getDataTag() const { return m_dataTag; }

        // Equality checks ID & dataTag
        constexpr bool operator==(const BlockState &other) const {
            return m_id == other.m_id && m_dataTag == other.m_dataTag;
        }

        MU ND BlockState getStateFromMeta(c_u32 meta) const { return {m_id, static_cast<uint8_t>(meta)}; }
        MU ND BlockState getStateFromMeta(c_int meta) const { return {m_id, static_cast<uint8_t>(meta)}; }
    };


    class Block : BlockState {
        MU blocks::MapColor m_mapColor{};  // optional map color
        const char*         m_name = nullptr; // block name (string literal)
        MU const int        m_titleUpdate{};

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
            , m_mapColor(blocks::MapColor::NONE)
            , m_name("")
            , m_titleUpdate(titleUpdate.value()) {
#ifndef _MSC_VER
            if !consteval {
                assert(false && "Block must be constructed in a constexpr context!");
            }
#endif
        }

        // 2) (TU, id, dataTag, name)
        constexpr Block(const TU titleUpdate, c_u16 blockID, c_u8 data, const char* blockName)
            : BlockState(blockID, data)
            , m_mapColor(blocks::MapColor::NONE)
            , m_name(blockName)
            , m_titleUpdate(titleUpdate.value()) {
#ifndef _MSC_VER
            if !consteval {
                assert(false && "Block must be constructed in a constexpr context!");
            }
#endif
        }
        Block(const Block&) = delete;
        Block& operator=(const Block&) = delete;

        // Accessors
        MU ND constexpr u16              getID()           const { return m_id; }
        MU ND constexpr u8               getDataTag()      const { return m_dataTag; }
        MU ND constexpr const char*      getName()         const { return m_name; }
        MU ND constexpr blocks::MapColor getMapColor()     const { return m_mapColor; }
        MU ND constexpr BlockState       getState()        const { return {m_id, m_dataTag}; }
        MU ND constexpr BlockState       getDefaultState() const { return {m_id, m_dataTag}; }
        MU ND constexpr int              getTU()           const { return m_titleUpdate; }

        // Equality checks ID & dataTag
        constexpr bool operator==(const BlockState &other) const {
            return m_id == other.m_id && m_dataTag == other.m_dataTag;
        }

        MU ND constexpr BlockState getStateFromMeta(c_u32 meta) const { return {m_id, static_cast<uint8_t>(meta)}; }
        MU ND constexpr BlockState getStateFromMeta(c_int meta) const { return {m_id, static_cast<uint8_t>(meta)}; }
    };
}
