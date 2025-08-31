#pragma once

#include <algorithm>
#include <cstdint>
#include <stdexcept>
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
        SHADPS4 = 10,
    };

    [[maybe_unused]] static constexpr bool is_console_none(CONSOLE console) {
        return console == CONSOLE::NONE;
    }

    [[maybe_unused]] static constexpr bool is_xbox360_family(CONSOLE console) {
        return console == CONSOLE::XBOX360;
    }

    [[maybe_unused]] static constexpr bool is_xbox1_family(CONSOLE console) {
        return console == CONSOLE::XBOX1 || console == CONSOLE::WINDURANGO;
    }

    [[maybe_unused]] static constexpr bool is_ps3_family(CONSOLE console) {
        return console == CONSOLE::PS3 || console == CONSOLE::RPCS3;
    }

    [[maybe_unused]] static constexpr bool is_psvita_family(CONSOLE console) {
        return console == CONSOLE::VITA;
    }

    [[maybe_unused]] static constexpr bool is_ps4_family(CONSOLE console) {
        return console == CONSOLE::PS4 || console == CONSOLE::SHADPS4;
    }

    [[maybe_unused]] static constexpr bool is_wiiu_family(CONSOLE console) {
        return console == CONSOLE::WIIU;
    }

    [[maybe_unused]] static constexpr bool is_switch_family(CONSOLE console) {
        return console == CONSOLE::SWITCH;
    }



    static std::string consoleToStr(const CONSOLE console) {
        switch (console) {
            case CONSOLE::XBOX360: return "xbox360";
            case CONSOLE::PS3: return "ps3";
            case CONSOLE::RPCS3: return "rpcs3";
            case CONSOLE::WIIU: return "wiiu";
            case CONSOLE::VITA: return "vita";
            case CONSOLE::SWITCH: return "switch";
            case CONSOLE::PS4: return "ps4";
            case CONSOLE::SHADPS4: return "shadps4";
            case CONSOLE::XBOX1: return "xbox1";
            case CONSOLE::WINDURANGO: return "windurango";
            case CONSOLE::NONE:
            default: return "NONE";
        }
    }


    [[maybe_unused]] static const char * consoleToCStr(const CONSOLE console) {
        static std::string str;
        str = consoleToStr(console);
        return str.c_str();
    }


    [[maybe_unused]] static CONSOLE strToConsole(const std::string &inputStr) {
        std::string str = inputStr;
        std::ranges::transform(str, str.begin(),
                               [](const unsigned char c) { return std::tolower(c); });

        if (str == "xbox360") { return CONSOLE::XBOX360; }
        if (str == "ps3" || str == "playstation3") { return CONSOLE::PS3; }
        if (str == "rpcs3") { return CONSOLE::RPCS3; }
        if (str == "wiiu") { return CONSOLE::WIIU; }
        if (str == "vita" || str == "psvita") { return CONSOLE::VITA; }
        if (str == "switch") { return CONSOLE::SWITCH; }
        if (str == "ps4" || str == "playstation4") { return CONSOLE::PS4; }
        if (str == "shadps4") { return CONSOLE::SHADPS4; }
        if (str == "xbox1" || str == "xboxone") { return CONSOLE::XBOX1; }
        if (str == "windurango") { return CONSOLE::WINDURANGO; }
        return CONSOLE::NONE;
    }


    [[maybe_unused]] static constexpr Endian getConsoleEndian(const CONSOLE console) {
        if (console == CONSOLE::NONE) {
            throw std::runtime_error("CONSOLE::NONE should not be passed to \"getConsoleEndian\"");
        }

        if (is_xbox360_family(console) ||
            is_ps3_family(console) ||
            is_wiiu_family(console)) {
            return Endian::Big;
        } else if (
                is_psvita_family(console) ||
                is_ps4_family(console) ||
                is_switch_family(console) ||
                is_xbox1_family(console)) {
            return Endian::Little;
        }

        throw std::runtime_error("\"getConsoleEndian\" encountered an unhandled case!");
    }

    [[maybe_unused]] static constexpr bool isConsoleNewGen(const CONSOLE console) {
        return is_ps4_family(console) ||
               is_switch_family(console) ||
               is_xbox1_family(console);
    }

    [[maybe_unused]] static bool is_any_xbox(const CONSOLE console) {
        return is_xbox360_family(console) || is_xbox1_family(console);
    }

    static bool isXbox(const CONSOLE console) { return is_any_xbox(console); }


}
