#pragma once

#include <string>
#include <utility>
#include <vector>


namespace lce::blocks {
    class Block {
        const std::string name;
        const std::string identifier;
        const uint16_t id{};
        const uint8_t dataTag{};

        const int lightOpacity;
        const bool translucent;
        const int lightValue;

        const float blockHardness{};
        const bool needsRandomTick;
        const bool isBlockContainer;
        const Material blockMaterial;

    };


}