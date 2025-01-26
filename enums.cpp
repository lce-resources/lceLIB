#include "enums.hpp"


std::string lce::consoleToStr(const CONSOLE console) {
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
const char* lce::consoleToCStr(const lce::CONSOLE console) {
    static std::string str;
    str = consoleToStr(console);
    return str.c_str();
}
bool lce::isConsoleNewGen(const lce::CONSOLE console) {
    return console == CONSOLE::PS4 ||
           console == CONSOLE::SWITCH ||
           console == CONSOLE::XBOX1;
}
bool lce::isXbox(const lce::CONSOLE console) {
    return console == CONSOLE::XBOX360 || console == CONSOLE::XBOX1;
}
lce::CONSOLE lce::strToConsole(const std::string& inputStr) {
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
lce::DIMENSION lce::intToDim(const char number) {
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
bool lce::consoleIsBigEndian(const lce::CONSOLE console) {
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
int lce::getChunkWorldBounds(const lce::WORLDSIZE worldSize) {
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
std::string lce::worldSizeToString(const lce::WORLDSIZE worldSize) {
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
std::string lce::biomeScaleToString(const lce::BIOMESCALE biomeScale) {
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
std::string lce::fileTypeToString(const lce::FILETYPE type) {
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
std::string facingToString(const EnumFacing facing) {
    switch (facing) {
        case EnumFacing::NORTH:
            return "NORTH";
        case EnumFacing::SOUTH:
            return "SOUTH";
        case EnumFacing::EAST:
            return "EAST";
        case EnumFacing::WEST:
            return "WEST";
        case EnumFacing::UP:
            return "UP";
        case EnumFacing::DOWN:
            return "DOWN";
        default:
            return "NONE";
    }
}
EnumAxis getAxis(const EnumFacing facing) {
    switch (facing) {
        case EnumFacing::NORTH:
        case EnumFacing::SOUTH:
            return EnumAxis::Z;
        case EnumFacing::EAST:
        case EnumFacing::WEST:
            return EnumAxis::X;
        case EnumFacing::UP:
        case EnumFacing::DOWN:
        default:
            return EnumAxis::Y;
    }
}
EnumFacing getOppositeFacing(const EnumFacing facing) {
    switch (facing) {
        default:
        case EnumFacing::DOWN:
            return EnumFacing::UP;
        case EnumFacing::UP:
            return EnumFacing::DOWN;
        case EnumFacing::NORTH:
            return EnumFacing::SOUTH;
        case EnumFacing::SOUTH:
            return EnumFacing::NORTH;
        case EnumFacing::WEST:
            return EnumFacing::EAST;
        case EnumFacing::EAST:
            return EnumFacing::WEST;
    }
}
int getFrontOffsetY(const EnumFacing facing) {
    switch (facing) {
        case EnumFacing::DOWN:
            return -1;
        case EnumFacing::UP:
            return 1;
        default:
            return 0;
    }
}
int getFrontOffsetX(const EnumFacing facing) {
    switch (facing) {
        case EnumFacing::WEST:
            return -1;
        case EnumFacing::EAST:
            return 1;
        default:
            return 0;
    }
}
int getFrontOffsetZ(const EnumFacing facing) {
    switch (facing) {
        case EnumFacing::NORTH:
            return -1;
        case EnumFacing::SOUTH:
            return 1;
        default:
            return 0;
    }
}
