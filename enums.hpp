#pragma once

#include <algorithm>
#include <cstdint>
#include <string>


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
        NONE,             // NONE
        STRUCTURE,        // data/
        VILLAGE,          // data/
        DATA_MAPPING,     // data/
        MAP,              // data/
        REGION_NETHER,    // ...
        REGION_OVERWORLD, // ...
        REGION_END,       // ...
        PLAYER,           // ...
        LEVEL,            // ...
        GRF,              // ...
        ENTITY_NETHER,    // ...
        ENTITY_OVERWORLD, // ...
        ENTITY_END,       // ...

        // PS_PARAM_SFO,
        // PS_PARAM_PFD,
        // PS_ICON0_PNG,
        // PS_KEYSTONE,
    };


    [[maybe_unused]] static std::string consoleToStr(const CONSOLE console) {
        switch (console) {
            case CONSOLE::XBOX360:
                return "xbox360";
            case CONSOLE::PS3:
                return "ps3";
            case CONSOLE::RPCS3:
                return "rpcs3";
            case CONSOLE::WIIU:
                return "wiiu";
            case CONSOLE::VITA:
                return "vita";
            case CONSOLE::SWITCH:
                return "switch";
            case CONSOLE::PS4:
                return "ps4";
            case CONSOLE::XBOX1:
                return "xbox1";
            case CONSOLE::NONE:
            default:
                return "NONE";
        }
    }


    [[maybe_unused]] static const char* consoleToCStr(const CONSOLE console) {
        static std::string str;
        str = consoleToStr(console);
        return str.c_str();
    }


    [[maybe_unused]] static bool isConsoleNewGen(const CONSOLE console) {
        return console == CONSOLE::PS4 ||
               console == CONSOLE::SWITCH ||
               console == CONSOLE::XBOX1;
    }


    [[maybe_unused]] static CONSOLE strToConsole(const std::string& inputStr) {
        std::string str = inputStr;
        std::transform(str.begin(), str.end(), str.begin(),
                       [](unsigned char c){ return std::tolower(c); });

        if (str == "xbox360") {
            return CONSOLE::XBOX360;
        } else if (str == "ps3" || str == "playstation3") {
            return CONSOLE::PS3;
        } else if (str == "rpcs3") {
            return CONSOLE::RPCS3;
        } else if (str == "wiiu") {
            return CONSOLE::WIIU;
        } else if (str == "vita" || str == "psvita") {
            return CONSOLE::VITA;
        } else if (str == "switch") {
            return CONSOLE::SWITCH;
        } else if (str == "ps4" || str == "playstation4") {
            return CONSOLE::PS4;
        } else if (str == "xbox1" || str == "xboxone") {
            return CONSOLE::XBOX1;
        } else {
            return CONSOLE::NONE;
        }
    }


    [[maybe_unused]] static lce::DIMENSION intToDim(const char number) {
        switch(number) {
            case 0:
                return lce::DIMENSION::NETHER;
            case 1:
                return lce::DIMENSION::OVERWORLD;
            case 2:
                return lce::DIMENSION::END;
            default:
                return lce::DIMENSION::NONE;
        }
    }


    [[maybe_unused]] static bool consoleIsBigEndian(const CONSOLE console) {
        switch (console) {
            case CONSOLE::NONE:
            case CONSOLE::XBOX360:
            case CONSOLE::PS3:
            case CONSOLE::RPCS3:
            case CONSOLE::WIIU:
            default:
                return true;
            case CONSOLE::VITA:
            case CONSOLE::PS4:
            case CONSOLE::SWITCH:
                return false;
        }
    }


    [[maybe_unused]] static int getChunkWorldBounds(const WORLDSIZE worldSize) {
        switch (worldSize) {
            case WORLDSIZE::CLASSIC:
            default:
                return 27;
            case WORLDSIZE::SMALL:
                return 32;
            case WORLDSIZE::MEDIUM:
                return 96;
            case WORLDSIZE::LARGE:
                return 160;
        }
    }


    [[maybe_unused]] static std::string worldSizeToString(const WORLDSIZE worldSize) {
        switch (worldSize) {
            case WORLDSIZE::CLASSIC:
            default:
                return "CLASSIC";
            case WORLDSIZE::SMALL:
                return "SMALL";
            case WORLDSIZE::MEDIUM:
                return "MEDIUM";
            case WORLDSIZE::LARGE:
                return "LARGE";
        }
    }


    [[maybe_unused]] static std::string biomeScaleToString(const BIOMESCALE biomeScale) {
        switch (biomeScale) {
            case BIOMESCALE::SMALL:
                return "SMALL";
            case BIOMESCALE::MEDIUM:
                return "MEDIUM";
            case BIOMESCALE::LARGE:
                return "LARGE";
            default:
                return "NONE";
        }
    }


    [[maybe_unused]] static std::string fileTypeToString(const FILETYPE type) {
        switch (type) {
            case FILETYPE::STRUCTURE:
                return "STRUCTURE";
            case FILETYPE::VILLAGE:
                return "VILLAGE";
            case FILETYPE::DATA_MAPPING:
                return "DATA_MAPPING";
            case FILETYPE::MAP:
                return "MAP";
            case FILETYPE::REGION_NETHER:
                return "REGION_NETHER";
            case FILETYPE::REGION_OVERWORLD:
                return "REGION_OVERWORLD";
            case FILETYPE::REGION_END:
                return "REGION_END";
            case FILETYPE::PLAYER:
                return "PLAYER";
            case FILETYPE::LEVEL:
                return "LEVEL";
            case FILETYPE::GRF:
                return "GRF";
            case FILETYPE::ENTITY_NETHER:
                return "ENTITY_NETHER";
            case FILETYPE::ENTITY_OVERWORLD:
                return "ENTITY_OVERWORLD";
            case FILETYPE::ENTITY_END:
                return "ENTITY_END";
            case FILETYPE::NONE:
            default:
                return "NONE";
        }
    }


}