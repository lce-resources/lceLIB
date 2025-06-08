#pragma once


#include <cstdint>
#include <string>


enum class Endian {
    Big,
    Little,
    Native = std::endian::native == std::endian::big ? Big : Little
};


namespace lce {

    enum class CONSOLE : int8_t {
        NONE = 0,
        XBOX360 = 1,
        XBOX1 = 2,
        PS3 = 3,
        RPCS3 = 4,
        VITA = 5,
        PS4 = 6,
        WIIU = 7,
        SWITCH = 8,
        WINDURANGO = 9,
    };


    enum class DIMENSION : int8_t {
        NETHER = -1,
        HELL = NETHER,
        OVERWORLD = 0,
        END = 1,
        NONE = 2
    };


    enum class BIOMESCALE : int8_t {
        SMALL = 0,
        MEDIUM = 1,
        LARGE = 2
    };


    enum class WORLDSIZE : int8_t {
        CLASSIC = 0,
        SMALL = 1,
        MEDIUM = 2,
        LARGE = 3,
        INF = 4
    };





    enum class FILETYPE : uint8_t {
        NONE,                   // NONE
        STRUCTURE,              // data/
        VILLAGE,                // data/
        DATA_MAPPING,           // data/
        MAP,                    // data/
        OLD_REGION_NETHER,      // ...
        OLD_REGION_OVERWORLD,   // ...
        OLD_REGION_END,         // ...
        OLD_REGION_ANY,
        PLAYER,                 // ...
        LEVEL,                  // ...
        GRF,                    // ...
        NEW_REGION_NETHER,      // ...
        NEW_REGION_OVERWORLD,   // ...
        NEW_REGION_END,         // ...
        NEW_REGION_ANY,
        ENTITY_NETHER,          // ...
        ENTITY_OVERWORLD,       // ...
        ENTITY_END,             // ...
        ENTITY_ANY


        // PS_PARAM_SFO,
        // PS_PARAM_PFD,
        // PS_ICON0_PNG,
        // PS_KEYSTONE,
    };


    [[maybe_unused]] extern std::string consoleToStr(CONSOLE console);

    [[maybe_unused]] extern const char* consoleToCStr(CONSOLE console);

    [[maybe_unused]] extern bool isConsoleNewGen(CONSOLE console);

    [[maybe_unused]] extern bool isXbox(CONSOLE console);

    [[maybe_unused]] extern CONSOLE strToConsole(const std::string& inputStr);

    [[maybe_unused]] extern DIMENSION intToDim(char number);

    [[maybe_unused]] extern Endian getConsoleEndian(CONSOLE console);

    [[maybe_unused]] extern int getChunkWorldBounds(WORLDSIZE worldSize);

    [[maybe_unused]] extern std::string worldSizeToString(WORLDSIZE worldSize);

    [[maybe_unused]] extern std::string biomeScaleToString(BIOMESCALE biomeScale);

    [[maybe_unused]] extern std::string fileTypeToString(FILETYPE type);
}

enum class EnumAxis : int8_t {
    Y = 0,
    X = 1,
    Z = 2,
};

enum class EnumFacing : int8_t {
    DOWN = 0,
    UP = 1,
    NORTH = 2,
    SOUTH = 3,
    WEST = 4,
    EAST = 5,
};

static constexpr EnumFacing FACING_HORIZONTAL[4] = {
        EnumFacing::NORTH,
        EnumFacing::EAST,
        EnumFacing::SOUTH,
        EnumFacing::WEST,
};

static constexpr EnumFacing FACING_VERTICAL[2] = {
        EnumFacing::UP,
        EnumFacing::DOWN,
};

[[maybe_unused]] extern std::string facingToString(EnumFacing facing);

[[maybe_unused]] extern EnumAxis getAxis(EnumFacing facing);

[[maybe_unused]] extern EnumFacing getOppositeFacing(EnumFacing facing);

[[maybe_unused]] extern int getFrontOffsetX(EnumFacing facing);

[[maybe_unused]] extern int getFrontOffsetY(EnumFacing facing);

[[maybe_unused]] extern int getFrontOffsetZ(EnumFacing facing);