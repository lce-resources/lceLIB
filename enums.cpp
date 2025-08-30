#include "enums.hpp"
#include "processor.hpp"

#include <algorithm>

namespace lce {
    DIMENSION intToDim(const char number) {
        switch (number) {
            case 0:
                return DIMENSION::NETHER;
            case 1:
                return DIMENSION::OVERWORLD;
            case 2:
                return DIMENSION::END;
            default:
                return DIMENSION::NONE;
        }
    }


    int getChunkWorldBounds(const WORLDSIZE worldSize) {
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


    std::string worldSizeToString(const WORLDSIZE worldSize) {
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


    std::string biomeScaleToString(const BIOMESCALE biomeScale) {
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


    std::string fileTypeToString(const FILETYPE type) {
        switch (type) {
            case FILETYPE::STRUCTURE:
                return "STRUCTURE";
            case FILETYPE::VILLAGE:
                return "VILLAGE";
            case FILETYPE::DATA_MAPPING:
                return "DATA_MAPPING";
            case FILETYPE::MAP:
                return "MAP";
            case FILETYPE::OLD_REGION_NETHER:
                return "OLD_REGION_NETHER";
            case FILETYPE::OLD_REGION_OVERWORLD:
                return "OLD_REGION_OVERWORLD";
            case FILETYPE::OLD_REGION_END:
                return "OLD_REGION_END";
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


lce::WORLDSIZE lce::strToWorldSize(const std::string& worldSize) {
    if (worldSize == "CLASSIC") {
        return WORLDSIZE::CLASSIC;
    }
    if (worldSize == "SMALL") {
        return WORLDSIZE::SMALL;
    }
    if (worldSize == "MEDIUM") {
        return WORLDSIZE::MEDIUM;
    }
    if (worldSize == "LARGE") {
        return WORLDSIZE::LARGE;
    }
    return WORLDSIZE::CLASSIC;
}




lce::BIOMESCALE lce::strToBiomeScale(const std::string& biomeScale) {
    if (biomeScale == "SMALL") {
        return BIOMESCALE::SMALL;
    }
    if (biomeScale == "MEDIUM") {
        return BIOMESCALE::MEDIUM;
    }
    if (biomeScale == "LARGE") {
        return BIOMESCALE::LARGE;
    }
    return BIOMESCALE::SMALL;
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
