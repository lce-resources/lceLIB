#pragma once

#include "lce/processor.hpp"
#include <cstdint>


namespace lce::blocks::ids {

    enum BlockID : uint16_t {
        AIR_ID = 0,
        STONE_ID = 1,
        GRASS_ID = 2,
        DIRT_ID = 3,
        COBBLESTONE_ID = 4,
        OAK_WOOD_PLANK_ID = 5,
        OAK_SAPLING_ID = 6,
        BEDROCK_ID = 7,
        FLOWING_WATER_ID = 8,
        STILL_WATER_ID = 9,
        FLOWING_LAVA_ID = 10,
        STILL_LAVA_ID = 11,
        SAND_ID = 12,
        GRAVEL_ID = 13,
        GOLD_ORE_ID = 14,
        IRON_ORE_ID = 15,
        COAL_ORE_ID = 16,
        OAK_WOOD_ID = 17,
        OAK_LEAVES_ID = 18,
        SPONGE_ID = 19,
        GLASS_ID = 20,
        LAPIS_LAZULI_ORE_ID = 21,
        LAPIS_LAZULI_BLOCK_ID = 22,
        DISPENSER_ID = 23,
        SANDSTONE_ID = 24,
        NOTE_BLOCK_ID = 25,
        BED_BLOCK_ID = 26,
        POWERED_RAIL_ID = 27,
        DETECTOR_RAIL_ID = 28,
        STICKY_PISTON_ID = 29,
        COBWEB_ID = 30,
        TALL_GRASS_SHRUB_ID = 31,
        DEAD_BUSH_ID = 32,
        PISTON_ID = 33,
        PISTON_HEAD_ID = 34,
        WOOL_ID = 35,
        DANDELION_ID = 37,
        POPPY_ID = 38,
        BROWN_MUSHROOM_ID = 39,
        RED_MUSHROOM_ID = 40,
        GOLD_BLOCK_ID = 41,
        IRON_BLOCK_ID = 42,
        DOUBLE_STONE_SLAB_ID = 43,
        STONE_SLAB_ID = 44,
        BRICKS_ID = 45,
        TNT_ID = 46,
        BOOKSHELF_ID = 47,
        MOSS_STONE_ID = 48,
        OBSIDIAN_ID = 49,
        TORCH_ID = 50,
        FIRE_ID = 51,
        MONSTER_SPAWNER_ID = 52,
        OAK_WOOD_STAIRS_ID = 53,
        CHEST_ID = 54,
        REDSTONE_WIRE_ID = 55,
        DIAMOND_ORE_ID = 56,
        DIAMOND_BLOCK_ID = 57,
        CRAFTING_TABLE_ID = 58,
        WHEAT_CROPS_ID = 59,
        FARMLAND_ID = 60,
        FURNACE_ID = 61,
        BURNING_FURNACE_ID = 62,
        STANDING_SIGN_BLOCK_ID = 63,
        OAK_DOOR_BLOCK_ID = 64,
        LADDER_ID = 65,
        RAIL_ID = 66,
        COBBLESTONE_STAIRS_ID = 67,
        WALL_MOUNTED_SIGN_BLOCK_ID = 68,
        LEVER_ID = 69,
        STONE_PRESSURE_PLATE_ID = 70,
        IRON_DOOR_BLOCK_ID = 71,
        WOODEN_PRESSURE_PLATE_ID = 72,
        REDSTONE_ORE_ID = 73,
        GLOWING_REDSTONE_ORE_ID = 74,
        OFF_REDSTONE_TORCH_ID = 75,
        ON_REDSTONE_TORCH_ID = 76,
        STONE_BUTTON_ID = 77,
        SNOW_ID = 78,
        ICE_ID = 79,
        SNOW_BLOCK_ID = 80,
        CACTUS_ID = 81,
        CLAY_BLOCK_ID = 82,
        SUGAR_CANES_ID = 83,
        JUKEBOX_ID = 84,
        OAK_FENCE_ID = 85,
        CARVED_PUMPKIN_ID = 86,
        NETHERRACK_ID = 87,
        SOUL_SAND_ID = 88,
        GLOWSTONE_ID = 89,
        NETHER_PORTAL_ID = 90,
        JACK_O_LANTERN_ID = 91,
        CAKE_BLOCK_ID = 92,
        OFF_REDSTONE_REPEATER_BLOCK_ID = 93,
        ON_REDSTONE_REPEATER_BLOCK_ID = 94,
        STAINED_GLASS_ID = 95,
        WOODEN_TRAPDOOR_ID = 96,
        STONE_MONSTER_EGG_ID = 97,
        STONE_BRICKS_ID = 98,
        BROWN_MUSHROOM_BLOCK_ID = 99,
        RED_MUSHROOM_BLOCK_ID = 100,
        IRON_BARS_ID = 101,
        GLASS_PANE_ID = 102,
        MELON_BLOCK_ID = 103,
        PUMPKIN_STEM_ID = 104,
        MELON_STEM_ID = 105,
        VINES_ID = 106,
        OAK_FENCE_GATE_ID = 107,
        BRICK_STAIRS_ID = 108,
        STONE_BRICK_STAIRS_ID = 109,
        MYCELIUM_ID = 110,
        LILY_PAD_ID = 111,
        NETHER_BRICK_BLOCK_ID = 112,
        NETHER_BRICK_FENCE_ID = 113,
        NETHER_BRICK_STAIRS_ID = 114,
        NETHER_WART_ID = 115,
        ENCHANTMENT_TABLE_ID = 116,
        BREWING_STAND_ID = 117,
        CAULDRON_ID = 118,
        END_PORTAL_ID = 119,
        END_PORTAL_FRAME_ID = 120,
        END_STONE_ID = 121,
        DRAGON_EGG_ID = 122,
        INACTIVE_REDSTONE_LAMP_ID = 123,
        ACTIVE_REDSTONE_LAMP_ID = 124,
        DOUBLE_OAK_WOOD_SLAB_ID = 125,
        OAK_WOOD_SLAB_ID = 126,
        COCOA_ID = 127,
        SANDSTONE_STAIRS_ID = 128,
        EMERALD_ORE_ID = 129,
        ENDER_CHEST_ID = 130,
        TRIPWIRE_HOOK_ID = 131,
        TRIPWIRE_ID = 132,
        EMERALD_BLOCK_ID = 133,
        SPRUCE_WOOD_STAIRS_ID = 134,
        BIRCH_WOOD_STAIRS_ID = 135,
        JUNGLE_WOOD_STAIRS_ID = 136,
        COMMAND_BLOCK_ID = 137,
        BEACON_ID = 138,
        COBBLESTONE_WALL_ID = 139,
        FLOWER_POT_ID = 140,
        CARROTS_ID = 141,
        POTATOES_ID = 142,
        WOODEN_BUTTON_ID = 143,
        MOB_HEAD_ID = 144,
        ANVIL_ID = 145,
        TRAPPED_CHEST_ID = 146,
        LIGHT_WEIGHTED_PRESSURE_PLATE_ID = 147,
        HEAVY_WEIGHTED_PRESSURE_PLATE_ID = 148,
        INACTIVE_REDSTONE_COMPARATOR_ID = 149,
        ACTIVE_REDSTONE_COMPARATOR_ID = 150,
        DAYLIGHT_SENSOR_ID = 151,
        REDSTONE_BLOCK_ID = 152,
        NETHER_QUARTZ_ORE_ID = 153,
        HOPPER_ID = 154,
        QUARTZ_BLOCK_ID = 155,
        QUARTZ_STAIRS_ID = 156,
        ACTIVATOR_RAIL_ID = 157,
        DROPPER_ID = 158,
        STAINED_HARDENED_CLAY_ID = 159,
        STAINED_GLASS_PANE_ID = 160,
        ACACIA_LEAVES_ID = 161,
        ACACIA_WOOD_ID = 162,
        ACACIA_WOOD_STAIRS_ID = 163,
        DARK_OAK_WOOD_STAIRS_ID = 164,
        SLIME_BLOCK_ID = 165,
        BARRIER_ID = 166,
        IRON_TRAPDOOR_ID = 167,
        PRISMARINE_ID = 168,
        SEA_LANTERN_ID = 169,
        HAY_BALE_ID = 170,
        CARPET_ID = 171,
        HARDENED_CLAY_ID = 172,
        BLOCK_OF_COAL_ID = 173,
        PACKED_ICE_ID = 174,
        DOUBLE_PLANT_ID = 175,
        FREE_STANDING_BANNER_ID = 176,
        WALL_MOUNTED_BANNER_ID = 177,
        INVERTED_DAYLIGHT_SENSOR_ID = 178,
        RED_SANDSTONE_ID = 179,
        RED_SANDSTONE_STAIRS_ID = 180,
        DOUBLE_RED_SANDSTONE_SLAB_ID = 181,
        RED_SANDSTONE_SLAB_ID = 182,
        SPRUCE_FENCE_GATE_ID = 183,
        BIRCH_FENCE_GATE_ID = 184,
        JUNGLE_FENCE_GATE_ID = 185,
        DARK_OAK_FENCE_GATE_ID = 186,
        ACACIA_FENCE_GATE_ID = 187,
        SPRUCE_FENCE_ID = 188,
        BIRCH_FENCE_ID = 189,
        JUNGLE_FENCE_ID = 190,
        DARK_OAK_FENCE_ID = 191,
        ACACIA_FENCE_ID = 192,
        SPRUCE_DOOR_BLOCK_ID = 193,
        BIRCH_DOOR_BLOCK_ID = 194,
        JUNGLE_DOOR_BLOCK_ID = 195,
        ACACIA_DOOR_BLOCK_ID = 196,
        DARK_OAK_DOOR_BLOCK_ID = 197,
        END_ROD_ID = 198,
        CHORUS_PLANT_ID = 199,
        CHORUS_FLOWER_ID = 200,
        PURPUR_BLOCK_ID = 201,
        PURPUR_PILLAR_ID = 202,
        PURPUR_STAIRS_ID = 203,
        PURPUR_DOUBLE_SLAB_ID = 204,
        PURPUR_SLAB_ID = 205,
        END_STONE_BRICKS_ID = 206,
        BEETROOT_BLOCK_ID = 207,
        GRASS_PATH_ID = 208,
        END_GATEWAY_ID = 209,
        REPEATING_COMMAND_BLOCK_ID = 210,
        CHAIN_COMMAND_BLOCK_ID = 211,
        FROSTED_ICE_ID = 212,
        MAGMA_BLOCK_ID = 213,
        NETHER_WART_BLOCK_ID = 214,
        RED_NETHER_BRICK_ID = 215,
        BONE_BLOCK_ID = 216,
        STRUCTURE_VOID_ID = 217,
        OBSERVER_ID = 218,
        WHITE_SHULKER_BOX_ID = 219,
        ORANGE_SHULKER_BOX_ID = 220,
        MAGENTA_SHULKER_BOX_ID = 221,
        LIGHT_BLUE_SHULKER_BOX_ID = 222,
        YELLOW_SHULKER_BOX_ID = 223,
        LIME_SHULKER_BOX_ID = 224,
        PINK_SHULKER_BOX_ID = 225,
        GRAY_SHULKER_BOX_ID = 226,
        LIGHT_GRAY_SHULKER_BOX_ID = 227,
        CYAN_SHULKER_BOX_ID = 228,
        PURPLE_SHULKER_BOX_ID = 229,
        BLUE_SHULKER_BOX_ID = 230,
        BROWN_SHULKER_BOX_ID = 231,
        GREEN_SHULKER_BOX_ID = 232,
        RED_SHULKER_BOX_ID = 233,
        BLACK_SHULKER_BOX_ID = 234,
        WHITE_GLAZED_TERRACOTTA_ID = 235,
        ORANGE_GLAZED_TERRACOTTA_ID = 236,
        MAGENTA_GLAZED_TERRACOTTA_ID = 237,
        LIGHT_BLUE_GLAZED_TERRACOTTA_ID = 238,
        YELLOW_GLAZED_TERRACOTTA_ID = 239,
        LIME_GLAZED_TERRACOTTA_ID = 240,
        PINK_GLAZED_TERRACOTTA_ID = 241,
        GRAY_GLAZED_TERRACOTTA_ID = 242,
        LIGHT_GRAY_GLAZED_TERRACOTTA_ID = 243,
        CYAN_GLAZED_TERRACOTTA_ID = 244,
        PURPLE_GLAZED_TERRACOTTA_ID = 245,
        BLUE_GLAZED_TERRACOTTA_ID = 246,
        BROWN_GLAZED_TERRACOTTA_ID = 247,
        GREEN_GLAZED_TERRACOTTA_ID = 248,
        RED_GLAZED_TERRACOTTA_ID = 249,
        BLACK_GLAZED_TERRACOTTA_ID = 250,
        CONCRETE_ID = 251,
        CONCRETE_POWDER_ID = 252,
        STRUCTURE_BLOCK_ID = 255,
        CONDUIT_ID = 256,
        PUMPKIN_ID = 257,
        KELP_ID = 258,            // has data
        CORAL_BLOCK_ID = 259,     // 0-4 + 8-12
        CORAL_ID = 263,           // 0-4 + 8-12
        CORAL_FAN_ID = 264,       // 0-4, upper?
        CORAL_FAN_DEAD_ID = 265,  // 0-4, upper?
        CORAL_FAN_WALL1_ID = 266, // u2 direction, u2 type (4)
        CORAL_FAN_WALL2_ID = 267, // u2 direction, u2 type (4)
        CORAL_FAN_WALL3_ID = 268, // u2 direction, u2 type (2)
        DRIED_KELP_BLOCK_ID = 269,
        SEAGRASS_ID = 270,      // data=1:upper, data=2:lower, data=0:seagrass
        SEAPICKLE_ID = 271,     // waterlogged=data&8, count=data&3+1
        BUBBLE_COLUMN_ID = 272, // waterlogged = !(data * 8)
        BLUE_ICE_ID = 273,
        SPRUCE_TRAPDOOR_ID = 274,
        BIRCH_TRAPDOOR_ID = 275,
        JUNGLE_TRAPDOOR_ID = 276,
        ACACIA_TRAPDOOR_ID = 277,
        DARK_OAK_TRAPDOOR_ID = 278,
        TURTLE_EGG_ID_ID = 279, // eggs = (data & 3) + 1, hatch = data >> 2
        PRISMARINE_STAIRS_ID = 291,
        PRISMARINE_BRICK_STAIRS_ID = 292,
        DARK_PRISMARINE_STAIRS_ID = 293,
        STRIPPED_SPRUCE_LOG_ID = 295,
        STRIPPED_BIRCH_LOG_ID = 296,
        STRIPPED_JUNGLE_LOG_ID = 297,
        STRIPPED_ACACIA_LOG_ID = 298,
        STRIPPED_DARK_0AK_LOG_ID = 299,
        STRIPPED_OAK_LOG_ID = 300,
        ACACIA_PRESSURE_PLATE_ID = 301,   // powered = data & 1
        BIRCH_PRESSURE_PLATE_ID = 302,    // powered = data & 1
        DARK_OAK_PRESSURE_PLATE_ID = 303, // powered = data & 1
        JUNGLE_PRESSURE_PLATE_ID = 304,   // powered = data & 1
        SPRUCE_PRESSURE_PLATE_ID = 305,   // powered = data & 1
        ACACIA_BUTTON_ID = 306,
        BIRCH_BUTTON_ID = 307,
        DARK_OAK_BUTTON_ID = 308,
        JUNGLE_BUTTON_ID = 309,
        SPRUCE_BUTTON_ID = 310,
        DOUBLE_PRISMARINE_SLAB_ID = 311, // data=1: brick, data=2:dark, else: regular
        PRISMARINE_SLAB_ID = 312, // top = data & 8, data&7=1:brick, data&7=2:dark, data&7else:reg
        SPRUCE_WOOD_2_ID = 313, // added "_2"
        BIRCH_WOOD_2_ID = 314, // added "_2"
        JUNGLE_WOOD_2_ID = 315, // added "_2"
        ACACIA_WOOD_2_ID = 316, // added "_2"
        DARK_OAK_WOOD_2_ID = 317, // added "_2"
        OAK_WOOD_2_ID = 318, // added "_2"
    };

    ND static bool isLiquidBlock(c_int id) {
        return id == STILL_WATER_ID || id == STILL_LAVA_ID ||
               id == FLOWING_WATER_ID || id == FLOWING_LAVA_ID;
    }

    ND static bool isWaterMaterial(c_int id) {
        return id == STILL_WATER_ID || id == FLOWING_WATER_ID;
    }

    ND static bool isLavaMaterial(c_int id) {
        return id == STILL_LAVA_ID || id == FLOWING_LAVA_ID;
    }

    ND static bool isSolidBlock(c_int id) {
        switch (id) {
            case AIR_ID:
            case OAK_SAPLING_ID:
            case FLOWING_WATER_ID:
            case STILL_WATER_ID:
            case FLOWING_LAVA_ID:
            case STILL_LAVA_ID:
            case POWERED_RAIL_ID:
            case DETECTOR_RAIL_ID:
            case TALL_GRASS_SHRUB_ID:
            case DEAD_BUSH_ID:
            case DANDELION_ID:
            case POPPY_ID:
            case BROWN_MUSHROOM_ID:
            case RED_MUSHROOM_ID:
            case TORCH_ID:
            case FIRE_ID:
            case REDSTONE_WIRE_ID:
            case WHEAT_CROPS_ID:
            case LADDER_ID:
            case RAIL_ID:
            case LEVER_ID:
            case OFF_REDSTONE_TORCH_ID:
            case ON_REDSTONE_TORCH_ID:
            case STONE_BUTTON_ID:
            case SNOW_ID:
            case SUGAR_CANES_ID:
            case NETHER_PORTAL_ID:
            case OFF_REDSTONE_REPEATER_BLOCK_ID:
            case ON_REDSTONE_REPEATER_BLOCK_ID:
            case PUMPKIN_STEM_ID:
            case MELON_STEM_ID:
            case VINES_ID:
            case LILY_PAD_ID:
            case NETHER_WART_ID:
            case END_PORTAL_ID:
            case COCOA_ID:
            case TRIPWIRE_HOOK_ID:
            case TRIPWIRE_ID:
            case FLOWER_POT_ID:
            case CARROTS_ID:
            case POTATOES_ID:
            case WOODEN_BUTTON_ID:
            case MOB_HEAD_ID:
            case INACTIVE_REDSTONE_COMPARATOR_ID:
            case ACTIVE_REDSTONE_COMPARATOR_ID:
            case ACTIVATOR_RAIL_ID:
            case CARPET_ID:
            case DOUBLE_PLANT_ID:
            case END_ROD_ID:
            case CHORUS_PLANT_ID:
            case CHORUS_FLOWER_ID:
            case BEETROOT_BLOCK_ID:
            case END_GATEWAY_ID:
            case STRUCTURE_VOID_ID:
            case KELP_ID:
            case BUBBLE_COLUMN_ID:
            case ACACIA_BUTTON_ID:
            case BIRCH_BUTTON_ID:
            case DARK_OAK_BUTTON_ID:
            case JUNGLE_BUTTON_ID:
            case SPRUCE_BUTTON_ID:
                return false;

            default:
                return true;
        }
    }

    [[gnu::noinline]] ND static bool isFullBlock(c_int id) {
        switch (id) {
            case STONE_ID:
            case GRASS_ID:
            case DIRT_ID:
            case COBBLESTONE_ID:
            case OAK_WOOD_PLANK_ID:
            case BEDROCK_ID:
            case SAND_ID:
            case GRAVEL_ID:
            case GOLD_ORE_ID:
            case IRON_ORE_ID:
            case COAL_ORE_ID:
            case OAK_WOOD_ID:
            case OAK_LEAVES_ID:
            case SPONGE_ID:
            case LAPIS_LAZULI_ORE_ID:
            case LAPIS_LAZULI_BLOCK_ID:
            case DISPENSER_ID:
            case SANDSTONE_ID:
            case NOTE_BLOCK_ID:
            case WOOL_ID:
            case GOLD_BLOCK_ID:
            case IRON_BLOCK_ID:
            case DOUBLE_STONE_SLAB_ID:
            case BRICKS_ID:
            case TNT_ID:
            case BOOKSHELF_ID:
            case MOSS_STONE_ID:
            case OBSIDIAN_ID:
            case DIAMOND_ORE_ID:
            case DIAMOND_BLOCK_ID:
            case CRAFTING_TABLE_ID:
            case FURNACE_ID:
            case BURNING_FURNACE_ID:
            case REDSTONE_ORE_ID:
            case GLOWING_REDSTONE_ORE_ID:
            case SNOW_BLOCK_ID:
            case CLAY_BLOCK_ID:
            case JUKEBOX_ID:
            case CARVED_PUMPKIN_ID:
            case NETHERRACK_ID:
            case SOUL_SAND_ID:
            case GLOWSTONE_ID:
            case JACK_O_LANTERN_ID:
            case STONE_MONSTER_EGG_ID:
            case STONE_BRICKS_ID:
            case BROWN_MUSHROOM_BLOCK_ID:
            case RED_MUSHROOM_BLOCK_ID:
            case MELON_BLOCK_ID:
            case MYCELIUM_ID:
            case NETHER_BRICK_BLOCK_ID:
            case END_STONE_ID:
            case INACTIVE_REDSTONE_LAMP_ID:
            case ACTIVE_REDSTONE_LAMP_ID:
            case DOUBLE_OAK_WOOD_SLAB_ID:
            case EMERALD_ORE_ID:
            case EMERALD_BLOCK_ID:
            case COMMAND_BLOCK_ID:
            case REDSTONE_BLOCK_ID:
            case NETHER_QUARTZ_ORE_ID:
            case QUARTZ_BLOCK_ID:
            case DROPPER_ID:
            case STAINED_HARDENED_CLAY_ID:
            case ACACIA_LEAVES_ID:
            case ACACIA_WOOD_ID:
            case PRISMARINE_ID:
            case SEA_LANTERN_ID:
            case HAY_BALE_ID:
            case HARDENED_CLAY_ID:
            case BLOCK_OF_COAL_ID:
            case PACKED_ICE_ID:
            case RED_SANDSTONE_ID:
            case DOUBLE_RED_SANDSTONE_SLAB_ID:
            case PURPUR_BLOCK_ID:
            case PURPUR_PILLAR_ID:
            case PURPUR_DOUBLE_SLAB_ID:
            case END_STONE_BRICKS_ID:
            case REPEATING_COMMAND_BLOCK_ID:
            case CHAIN_COMMAND_BLOCK_ID:
            case MAGMA_BLOCK_ID:
            case NETHER_WART_BLOCK_ID:
            case RED_NETHER_BRICK_ID:
            case BONE_BLOCK_ID:
            case OBSERVER_ID:
            case WHITE_GLAZED_TERRACOTTA_ID:
            case ORANGE_GLAZED_TERRACOTTA_ID:
            case MAGENTA_GLAZED_TERRACOTTA_ID:
            case LIGHT_BLUE_GLAZED_TERRACOTTA_ID:
            case YELLOW_GLAZED_TERRACOTTA_ID:
            case LIME_GLAZED_TERRACOTTA_ID:
            case PINK_GLAZED_TERRACOTTA_ID:
            case GRAY_GLAZED_TERRACOTTA_ID:
            case LIGHT_GRAY_GLAZED_TERRACOTTA_ID:
            case CYAN_GLAZED_TERRACOTTA_ID:
            case PURPLE_GLAZED_TERRACOTTA_ID:
            case BLUE_GLAZED_TERRACOTTA_ID:
            case BROWN_GLAZED_TERRACOTTA_ID:
            case GREEN_GLAZED_TERRACOTTA_ID:
            case RED_GLAZED_TERRACOTTA_ID:
            case BLACK_GLAZED_TERRACOTTA_ID:
            case CONCRETE_ID:
            case CONCRETE_POWDER_ID:
            case STRUCTURE_BLOCK_ID:

            case BLUE_ICE_ID:
            case DRIED_KELP_BLOCK_ID:
            case STRIPPED_SPRUCE_LOG_ID:
            case STRIPPED_BIRCH_LOG_ID:
            case STRIPPED_JUNGLE_LOG_ID:
            case STRIPPED_ACACIA_LOG_ID:
            case STRIPPED_DARK_0AK_LOG_ID:
            case STRIPPED_OAK_LOG_ID:
            case DOUBLE_PRISMARINE_SLAB_ID:
            case SPRUCE_WOOD_2_ID:
            case BIRCH_WOOD_2_ID:
            case JUNGLE_WOOD_2_ID:
            case ACACIA_WOOD_2_ID:
            case DARK_OAK_WOOD_2_ID:
            case OAK_WOOD_2_ID:
                return true;

            default:
                return false;
        }
    }

    [[gnu::noinline]] ND static bool isFullyOpaqueBlock(c_int id) {
        switch(id) {
            case OAK_LEAVES_ID:
            case TNT_ID:
            case GLOWSTONE_ID:
            case ACACIA_LEAVES_ID:
            case SEA_LANTERN_ID:
                return false;

            case STICKY_PISTON_ID:
            case PISTON_ID:
            case MONSTER_SPAWNER_ID:
            case HOPPER_ID:
            case SLIME_BLOCK_ID:
            case BARRIER_ID:
                return true;

            default:
                return isFullBlock(id);
        }
    }

    ND static bool isLeavesBlock(c_int id) {
        return id == OAK_LEAVES_ID || id == ACACIA_LEAVES_ID;
    }

    ND static bool isReplaceableBlock(c_int id) {
        switch (id) {
            case AIR_ID:
            case TALL_GRASS_SHRUB_ID:
            case DEAD_BUSH_ID:
            case FIRE_ID:
            case SNOW_ID:
            case VINES_ID:
            case DOUBLE_PLANT_ID:
            case STRUCTURE_VOID_ID:
                return true;

            default:
                return isLiquidBlock(id);
        }
    }

}