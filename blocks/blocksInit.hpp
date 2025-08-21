#pragma once

#include "block.hpp"

#include "lce/processor.hpp"
#include "lce/titleUpdate.hpp"


namespace lce {



    template<const Block& newer, const Block& older>
    consteval void make_pair_checked() {
        static_assert(older.getTU() < newer.getTU(), "TU must strictly decrease");
    }


    struct BlocksInit {
#define DEFINE MU static constexpr auto
        
        DEFINE AIR = Block(TU_BASE, 0, 0, "air");
        DEFINE STONE = Block(TU_BASE, 1, 0, "stone");
        DEFINE GRANITE = Block(TU31, 1, 1, "stone");
        DEFINE POLISHED_GRANITE = Block(TU31, 1, 2, "stone");
        DEFINE DIORITE = Block(TU31, 1, 3, "stone");
        DEFINE POLISHED_DIORITE = Block(TU31, 1, 4, "stone");
        DEFINE ANDESITE = Block(TU31, 1, 5, "stone");
        DEFINE POLISHED_ANDESITE = Block(TU31, 1, 6, "stone");
        DEFINE GRASS = Block(TU_BASE, 2, 0, "grass");
        DEFINE DIRT = Block(TU_BASE, 3, 0, "dirt");
        DEFINE COARSE_DIRT = Block(TU31, 3, 1, "dirt");
        DEFINE PODZOL = Block(TU31, 3, 2, "dirt");
        DEFINE COBBLESTONE = Block(TU_BASE, 4, 0, "cobblestone");
        DEFINE OAK_WOOD_PLANK = Block(TU_BASE, 5, 0, "planks");
        DEFINE SPRUCE_WOOD_PLANK = Block(TU09, 5, 1, "planks");
        DEFINE BIRCH_WOOD_PLANK = Block(TU09, 5, 2, "planks");
        DEFINE JUNGLE_WOOD_PLANK = Block(TU12, 5, 3, "planks");
        DEFINE ACACIA_WOOD_PLANK = Block(TU25, 5, 4, "planks");
        DEFINE DARK_OAK_WOOD_PLANK = Block(TU25, 5, 5, "planks");
        DEFINE OAK_SAPLING = Block(TU_BASE, 6, 0, "sapling");
        DEFINE SPRUCE_SAPLING = Block(TU_BASE, 6, 1, "sapling");
        DEFINE BIRCH_SAPLING = Block(TU_BASE, 6, 2, "sapling");
        DEFINE JUNGLE_SAPLING = Block(TU12, 6, 3, "sapling");
        DEFINE ACACIA_SAPLING = Block(TU31, 6, 4, "sapling");
        DEFINE DARK_OAK_SAPLING = Block(TU31, 6, 5, "sapling");
        DEFINE BEDROCK = Block(TU_BASE, 7, 0, "bedrock");
        DEFINE FLOWING_WATER = Block(TU_BASE, 8, 0, "flowing_water");
        DEFINE STILL_WATER = Block(TU_BASE, 9, 0, "water");
        DEFINE FLOWING_LAVA = Block(TU_BASE, 10, 0, "flowing_lava");
        DEFINE STILL_LAVA = Block(TU_BASE, 11, 0, "lava");
        DEFINE SAND = Block(TU_BASE, 12, 0, "sand");
        DEFINE RED_SAND = Block(TU31, 12, 1, "sand");
        DEFINE GRAVEL = Block(TU_BASE, 13, 0, "gravel");
        DEFINE GOLD_ORE = Block(TU_BASE, 14, 0, "gold_ore");
        DEFINE IRON_ORE = Block(TU_BASE, 15, 0, "iron_ore");
        DEFINE COAL_ORE = Block(TU_BASE, 16, 0, "coal_ore");
        DEFINE OAK_WOOD = Block(TU_BASE, 17, 0, "log");
        DEFINE SPRUCE_WOOD = Block(TU_BASE, 17, 1, "log");
        DEFINE BIRCH_WOOD = Block(TU_BASE, 17, 2, "log");
        DEFINE JUNGLE_WOOD = Block(TU12, 17, 3, "log");
        DEFINE OAK_LEAVES = Block(TU_BASE, 18, 0, "leaves");
        DEFINE SPRUCE_LEAVES = Block(TU_BASE, 18, 1, "leaves");
        DEFINE BIRCH_LEAVES = Block(TU_BASE, 18, 2, "leaves");
        DEFINE JUNGLE_LEAVES = Block(TU12, 18, 3, "leaves");
        DEFINE SPONGE = Block(TU31, 19, 0, "sponge");
        DEFINE WET_SPONGE = Block(TU31, 19, 1, "sponge");
        DEFINE GLASS = Block(TU_BASE, 20, 0, "glass");
        DEFINE LAPIS_LAZULI_ORE = Block(TU_BASE, 21, 0, "lapis_ore");
        DEFINE LAPIS_LAZULI_BLOCK = Block(TU_BASE, 22, 0, "lapis_block");
        DEFINE DISPENSER = Block(TU_BASE, 23, 0, "dispenser");
        DEFINE SANDSTONE = Block(TU_BASE, 24, 0, "sandstone");
        DEFINE CHISELED_SANDSTONE = Block(TU09, 24, 1, "sandstone");
        DEFINE CUT_SANDSTONE = Block(TU09, 24, 2, "sandstone");
        DEFINE SMOOTH_SANDSTONE = Block(TU09, 24, 2, "sandstone");
        DEFINE NOTE_BLOCK = Block(TU_BASE, 25, 0, "noteblock");
        DEFINE BED_BLOCK = Block(TU_BASE, 26, 0, "bed");
        DEFINE POWERED_RAIL = Block(TU_BASE, 27, 0, "golden_rail");
        DEFINE DETECTOR_RAIL = Block(TU_BASE, 28, 0, "detector_rail");
        DEFINE STICKY_PISTON = Block(TU03, 29, 0, "sticky_piston");
        DEFINE COBWEB = Block(TU_BASE, 30, 0, "web");
        DEFINE TALL_GRASS_SHRUB = Block(TU_BASE, 31, 0, "tallgrass"); // idk if this is TU_BASE
        DEFINE TALL_GRASS_GRASS = Block(TU_BASE, 31, 1, "tallgrass"); // idk if this is TU_BASE
        DEFINE TALL_GRASS_FERN = Block(TU_BASE, 31, 2, "tallgrass"); // idk if this is TU_BASE
        DEFINE DEAD_BUSH = Block(TU_BASE, 32, 0, "deadbush");
        DEFINE PISTON = Block(TU03, 33, 0, "piston");
        DEFINE PISTON_HEAD = Block(TU03, 34, 0, "piston_head");
        DEFINE WHITE_WOOL = Block(TU_BASE, 35, 0, "wool");
        DEFINE ORANGE_WOOL = Block(TU_BASE, 35, 1, "wool");
        DEFINE MAGENTA_WOOL = Block(TU_BASE, 35, 2, "wool");
        DEFINE LIGHT_BLUE_WOOL = Block(TU_BASE, 35, 3, "wool");
        DEFINE YELLOW_WOOL = Block(TU_BASE, 35, 4, "wool");
        DEFINE LIME_WOOL = Block(TU_BASE, 35, 5, "wool");
        DEFINE PINK_WOOL = Block(TU_BASE, 35, 6, "wool");
        DEFINE GRAY_WOOL = Block(TU_BASE, 35, 7, "wool");
        DEFINE LIGHT_GRAY_WOOL = Block(TU_BASE, 35, 8, "wool");
        DEFINE CYAN_WOOL = Block(TU_BASE, 35, 9, "wool");
        DEFINE PURPLE_WOOL = Block(TU_BASE, 35, 10, "wool");
        DEFINE BLUE_WOOL = Block(TU_BASE, 35, 11, "wool");
        DEFINE BROWN_WOOL = Block(TU_BASE, 35, 12, "wool");
        DEFINE GREEN_WOOL = Block(TU_BASE, 35, 13, "wool");
        DEFINE RED_WOOL = Block(TU_BASE, 35, 14, "wool");
        DEFINE BLACK_WOOL = Block(TU_BASE, 35, 15, "wool");

        DEFINE DANDELION = Block(TU_BASE, 37, 0, "yellow_flower");
        DEFINE POPPY = Block(TU_BASE, 38, 0, "red_flower");

        DEFINE BLUE_ORCHID = Block(TU31, 38, 1, "red_flower");
        DEFINE ALLIUM = Block(TU31, 38, 2, "red_flower");
        DEFINE AZURE_BLUET = Block(TU31, 38, 3, "red_flower");
        DEFINE RED_TULIP = Block(TU31, 38, 4, "red_flower");
        DEFINE ORANGE_TULIP = Block(TU31, 38, 5, "red_flower");
        DEFINE WHITE_TULIP = Block(TU31, 38, 6, "red_flower");
        DEFINE PINK_TULIP = Block(TU31, 38, 7, "red_flower");
        DEFINE OXEYE_DAISY = Block(TU31, 38, 8, "red_flower");
        DEFINE CORNFLOWER = Block(TU88, 38, 9, "red_flower");
        DEFINE LILY_OF_THE_VALLEY = Block(TU88, 38, 10, "red_flower");

        DEFINE BROWN_MUSHROOM = Block(TU_BASE, 39, 0, "brown_mushroom");
        DEFINE RED_MUSHROOM = Block(TU_BASE, 40, 0, "red_mushroom");
        DEFINE GOLD_BLOCK = Block(TU_BASE, 41, 0, "gold_block");
        DEFINE IRON_BLOCK = Block(TU_BASE, 42, 0, "iron_block");

        DEFINE DOUBLE_OLD_STONE_SLAB = Block(TU_BASE, 43, 0, "double_stone_slab");
        DEFINE DOUBLE_SANDSTONE_SLAB = Block(TU_BASE, 43, 1, "double_stone_slab");
        DEFINE DOUBLE_PETRIFIED_OAK_SLAB = Block(TU_BASE, 43, 2, "double_stone_slab");
        DEFINE DOUBLE_COBBLESTONE_SLAB = Block(TU_BASE, 43, 3, "double_stone_slab");
        DEFINE DOUBLE_BRICK_SLAB = Block(TU05, 43, 4, "double_stone_slab");
        DEFINE DOUBLE_STONE_BRICK_SLAB = Block(TU05, 43, 5, "double_stone_slab");
        DEFINE DOUBLE_NETHER_BRICK_SLAB = Block(TU09, 43, 6, "double_stone_slab");
        DEFINE DOUBLE_QUARTZ_SLAB = Block(TU14, 43, 7, "double_stone_slab");

        DEFINE SMOOTH_STONE = Block(TU88, 43, 8, "double_stone_slab");
        DEFINE SMOOTH_SANDSTONE_1_14 = Block(TU88, 43, 9, "double_stone_slab");
        DEFINE SMOOTH_QUARTZ = Block(TU88, 43, 10, "double_stone_slab");

        DEFINE DOUBLE_TILE_QUARTZ_SLAB = Block(TU14, 43, 15, "double_stone_slab");

        DEFINE LOWER_STONE_SLAB = Block(TU_BASE, 44, 0, "stone_slab");
        DEFINE LOWER_SANDSTONE_SLAB = Block(TU_BASE, 44, 1, "stone_slab");
        DEFINE LOWER_PETRIFIED_OAK_SLAB = Block(TU_BASE, 44, 2, "stone_slab");
        DEFINE LOWER_COBBLESTONE_SLAB = Block(TU_BASE, 44, 3, "stone_slab");
        DEFINE LOWER_BRICK_SLAB = Block(TU05, 44, 4, "stone_slab");
        DEFINE LOWER_STONE_BRICK_SLAB = Block(TU05, 44, 5, "stone_slab");
        DEFINE LOWER_NETHER_BRICK_SLAB = Block(TU09, 44, 6, "stone_slab");
        DEFINE LOWER_QUARTZ_SLAB = Block(TU14, 44, 7, "stone_slab");

        DEFINE UPPER_STONE_SLAB = Block(TU_BASE, 44, 8, "stone_slab");
        DEFINE UPPER_SANDSTONE_SLAB = Block(TU_BASE, 44, 9, "stone_slab");
        DEFINE UPPER_PETRIFIED_OAK_SLAB = Block(TU_BASE, 44, 10, "stone_slab");
        DEFINE UPPER_COBBLESTONE_SLAB = Block(TU_BASE, 44, 11, "stone_slab");
        DEFINE UPPER_BRICKS_SLAB = Block(TU05, 44, 12, "stone_slab");
        DEFINE UPPER_STONE_BRICK_SLAB = Block(TU05, 44, 13, "stone_slab");
        DEFINE UPPER_NETHER_BRICK_SLAB = Block(TU09, 44, 14, "stone_slab");
        DEFINE UPPER_QUARTZ_SLAB = Block(TU14, 44, 15, "stone_slab");

        DEFINE BRICKS = Block(TU05, 45, 0, "brick_block");
        DEFINE TNT = Block(TU_BASE, 46, 0, "tnt");
        DEFINE BOOKSHELF = Block(TU_BASE, 47, 0, "bookshelf");
        DEFINE MOSS_STONE = Block(TU_BASE, 48, 0, "mossy_cobblestone");
        DEFINE OBSIDIAN = Block(TU_BASE, 49, 0, "obsidian");
        DEFINE TORCH = Block(TU_BASE, 50, 0, "torch");
        DEFINE FIRE = Block(TU_BASE, 51, 0, "fire");
        DEFINE MONSTER_SPAWNER = Block(TU_BASE, 52, 0, "mob_spawner");
        DEFINE OAK_WOOD_STAIRS = Block(TU_BASE, 53, 0, "oak_stairs");
        DEFINE CHEST = Block(TU_BASE, 54, 0, "chest");
        DEFINE REDSTONE_WIRE = Block(TU_BASE, 55, 0, "redstone_wire");
        DEFINE DIAMOND_ORE = Block(TU_BASE, 56, 0, "diamond_ore");
        DEFINE DIAMOND_BLOCK = Block(TU_BASE, 57, 0, "diamond_block");
        DEFINE CRAFTING_TABLE = Block(TU_BASE, 58, 0, "crafting_table");
        DEFINE WHEAT_CROPS = Block(TU_BASE, 59, 0, "wheat");
        DEFINE FARMLAND = Block(TU_BASE, 60, 0, "farmland");
        DEFINE FURNACE = Block(TU_BASE, 61, 0, "furnace");
        DEFINE BURNING_FURNACE = Block(TU_BASE, 62, 0, "lit_furnace");
        DEFINE STANDING_SIGN_BLOCK = Block(TU_BASE, 63, 0, "standing_sign");
        DEFINE OAK_DOOR_BLOCK = Block(TU_BASE, 64, 0, "wooden_door");
        DEFINE LADDER = Block(TU_BASE, 65, 0, "ladder");
        DEFINE RAIL = Block(TU_BASE, 66, 0, "rail");
        DEFINE COBBLESTONE_STAIRS = Block(TU_BASE, 67, 0, "stone_stairs");
        DEFINE WALL_MOUNTED_SIGN_BLOCK = Block(TU_BASE, 68, 0, "wall_sign");
        DEFINE LEVER = Block(TU_BASE, 69, 0, "lever");
        DEFINE STONE_PRESSURE_PLATE = Block(TU_BASE, 70, 0, "stone_pressure_plate");
        DEFINE IRON_DOOR_BLOCK = Block(TU_BASE, 71, 0, "iron_door");
        DEFINE WOODEN_PRESSURE_PLATE = Block(TU_BASE, 72, 0, "wooden_pressure_plate");
        DEFINE REDSTONE_ORE = Block(TU_BASE, 73, 0, "redstone_ore");
        DEFINE GLOWING_REDSTONE_ORE = Block(TU_BASE, 74, 0, "lit_redstone_ore");
        DEFINE OFF_REDSTONE_TORCH = Block(TU_BASE, 75, 0,  "unlit_redstone_torch");
        DEFINE ON_REDSTONE_TORCH = Block(TU_BASE, 76, 0, "redstone_torch");
        DEFINE STONE_BUTTON = Block(TU_BASE, 77, 0, "stone_button");
        DEFINE SNOW = Block(TU_BASE, 78, 0, "snow_layer");
        DEFINE ICE = Block(TU_BASE, 79, 0, "ice");
        DEFINE SNOW_BLOCK = Block(TU_BASE, 80, 0, "snow");
        DEFINE CACTUS = Block(TU_BASE, 81, 0, "cactus");
        DEFINE CLAY_BLOCK = Block(TU_BASE, 82, 0, "clay");
        DEFINE SUGAR_CANES = Block(TU_BASE, 83, 0, "reeds");
        DEFINE JUKEBOX = Block(TU_BASE, 84, 0, "jukebox");
        DEFINE OAK_FENCE = Block(TU_BASE, 85, 0, "fence");
        DEFINE CARVED_PUMPKIN = Block(TU_BASE, 86, 0, "pumpkin");
        DEFINE NETHERRACK = Block(TU_BASE, 87, 0, "netherrack");
        DEFINE SOUL_SAND = Block(TU_BASE, 88, 0, "soul_sand");
        DEFINE GLOWSTONE = Block(TU_BASE, 89, 0, "glowstone");
        DEFINE NETHER_PORTAL = Block(TU_BASE, 90, 0, "portal");
        DEFINE JACK_O_LANTERN = Block(TU_BASE, 91, 0, "lit_pumpkin");
        DEFINE CAKE = Block(TU_BASE, 92, 0, "cake");
        DEFINE OFF_REDSTONE_REPEATER_BLOCK = Block(TU_BASE, 93, 0, "unpowered_repeater");
        DEFINE ON_REDSTONE_REPEATER_BLOCK = Block(TU_BASE, 94, 0, "powered_repeater");

        DEFINE WHITE_STAINED_GLASS = Block(TU25, 95, 0, "stained_glass");
        DEFINE ORANGE_STAINED_GLASS = Block(TU25, 95, 1, "stained_glass");
        DEFINE MAGENTA_STAINED_GLASS = Block(TU25, 95, 2, "stained_glass");
        DEFINE LIGHT_BLUE_STAINED_GLASS = Block(TU25, 95, 3, "stained_glass");
        DEFINE YELLOW_STAINED_GLASS = Block(TU25, 95, 4, "stained_glass");
        DEFINE LIME_STAINED_GLASS = Block(TU25, 95, 5, "stained_glass");
        DEFINE PINK_STAINED_GLASS = Block(TU25, 95, 6, "stained_glass");
        DEFINE GRAY_STAINED_GLASS = Block(TU25, 95, 7, "stained_glass");
        DEFINE LIGHT_GRAY_STAINED_GLASS = Block(TU25, 95, 8, "stained_glass");
        DEFINE CYAN_STAINED_GLASS = Block(TU25, 95, 9, "stained_glass");
        DEFINE PURPLE_STAINED_GLASS = Block(TU25, 95, 10, "stained_glass");
        DEFINE BLUE_STAINED_GLASS = Block(TU25, 95, 11, "stained_glass");
        DEFINE BROWN_STAINED_GLASS = Block(TU25, 95, 12, "stained_glass");
        DEFINE GREEN_STAINED_GLASS = Block(TU25, 95, 13, "stained_glass");
        DEFINE RED_STAINED_GLASS = Block(TU25, 95, 14, "stained_glass");
        DEFINE BLACK_STAINED_GLASS = Block(TU25, 95, 15, "stained_glass");

        DEFINE WOODEN_TRAPDOOR = Block(TU_BASE, 96, 0, "trapdoor");
        DEFINE STONE_MONSTER_EGG = Block(TU05, 97, 0, "monster_egg");
        DEFINE COBBLESTONE_MONSTER_EGG = Block(TU05, 97, 1, "monster_egg");
        DEFINE STONE_BRICK_MONSTER_EGG = Block(TU05, 97, 2, "monster_egg");
        DEFINE MOSSY_STONE_MONSTER_EGG = Block(TU31, 97, 3, "monster_egg");
        DEFINE CRACKED_STONE_BRICK_MONSTER_EGG = Block(TU31, 97, 4, "monster_egg");
        DEFINE CHISELED_STONE_BRICK_MONSTER_EGG = Block(TU31, 97, 5, "monster_egg");

        DEFINE STONE_BRICKS = Block(TU05, 98, 0, "stonebrick");
        DEFINE MOSSY_STONE_BRICKS = Block(TU05, 98, 1, "stonebrick");
        DEFINE CRACKED_STONE_BRICKS = Block(TU05, 98, 2, "stonebrick");
        DEFINE CHISELED_STONE_BRICKS = Block(TU12, 98, 3, "stonebrick");
        DEFINE BROWN_MUSHROOM_BLOCK = Block(TU05, 99, 0, "brown_mushroom_block");
        DEFINE RED_MUSHROOM_BLOCK = Block(TU05, 100, 0, "red_mushroom_block");
        DEFINE IRON_BARS = Block(TU05, 101, 0, "iron_bars");
        DEFINE GLASS_PANE = Block(TU05, 102, 0, "glass_pane");
        DEFINE MELON_BLOCK = Block(TU05, 103, 0, "melon_block");
        DEFINE PUMPKIN_STEM = Block(TU05, 104, 0, "pumpkin_stem");
        DEFINE MELON_STEM = Block(TU05, 105, 0, "melon_stem");
        DEFINE VINES = Block(TU05, 106, 0, "vine");
        DEFINE OAK_FENCE_GATE = Block(TU05, 107, 0, "fence_gate");
        DEFINE BRICK_STAIRS = Block(TU05, 108, 0, "brick_stairs");
        DEFINE STONE_BRICK_STAIRS = Block(TU05, 109, 0, "stone_brick_stairs");

        DEFINE MYCELIUM = Block(TU07, 110, 0, "mycelium");
        DEFINE LILY_PAD = Block(TU07, 111, 0, "waterlily");
        DEFINE NETHER_BRICK_BLOCK = Block(TU07, 112, 0, "nether_brick");
        DEFINE NETHER_BRICK_FENCE = Block(TU07, 113, 0, "nether_brick_fence");
        DEFINE NETHER_BRICK_STAIRS = Block(TU07, 114, 0, "nether_brick_stairs");
        DEFINE NETHER_WART = Block(TU07, 115, 0, "nether_wart");
        DEFINE ENCHANTMENT_TABLE = Block(TU07, 116, 0, "enchanting_table");
        DEFINE BREWING_STAND = Block(TU07, 117, 0, "brewing_stand");
        DEFINE CAULDRON = Block(TU07, 118, 0, "cauldron");
        DEFINE END_PORTAL = Block(TU07, 119, 0, "end_portal");
        DEFINE END_PORTAL_FRAME = Block(TU07, 120, 0, "end_portal_frame");
        DEFINE END_STONE = Block(TU07, 121, 0, "end_stone");

        DEFINE DRAGON_EGG = Block(TU09, 122, 0, "dragon_egg");

        DEFINE INACTIVE_REDSTONE_LAMP = Block(TU12, 123, 0, "redstone_lamp");
        DEFINE ACTIVE_REDSTONE_LAMP = Block(TU12, 124, 0, "lit_redstone_lamp");

        DEFINE DOUBLE_OAK_WOOD_SLAB = Block(TU_BASE, 125, 0, "double_wooden_slab");
        DEFINE DOUBLE_SPRUCE_WOOD_SLAB = Block(TU09, 125, 1, "double_wooden_slab");
        DEFINE DOUBLE_BIRCH_WOOD_SLAB = Block(TU09, 125, 2, "double_wooden_slab");
        DEFINE DOUBLE_JUNGLE_WOOD_SLAB = Block(TU12, 125, 3, "double_wooden_slab");
        DEFINE DOUBLE_ACACIA_WOOD_SLAB = Block(TU25, 125, 4, "double_wooden_slab");
        DEFINE DOUBLE_DARK_OAK_WOOD_SLAB = Block(TU25, 125, 5, "double_wooden_slab");

        DEFINE LOWER_OAK_WOOD_SLAB = Block(TU_BASE, 126, 0, "wooden_slab");
        DEFINE LOWER_SPRUCE_WOOD_SLAB = Block(TU09, 126, 1, "wooden_slab");
        DEFINE LOWER_BIRCH_WOOD_SLAB = Block(TU09, 126, 2, "wooden_slab");
        DEFINE LOWER_JUNGLE_WOOD_SLAB = Block(TU12, 126, 3, "wooden_slab");
        DEFINE LOWER_ACACIA_WOOD_SLAB = Block(TU25, 126, 4, "wooden_slab");
        DEFINE LOWER_DARK_OAK_WOOD_SLAB = Block(TU25, 126, 5, "wooden_slab");

        DEFINE UPPER_OAK_WOOD_SLAB = Block(TU_BASE, 126, 8, "wooden_slab");
        DEFINE UPPER_SPRUCE_WOOD_SLAB = Block(TU09, 126, 9, "wooden_slab");
        DEFINE UPPER_BIRCH_WOOD_SLAB = Block(TU09, 126, 10, "wooden_slab");
        DEFINE UPPER_JUNGLE_WOOD_SLAB = Block(TU12, 126, 11, "wooden_slab");
        DEFINE UPPER_ACACIA_WOOD_SLAB = Block(TU25, 126, 12, "wooden_slab");
        DEFINE UPPER_DARK_OAK_WOOD_SLAB = Block(TU25, 126, 13, "wooden_slab");

        DEFINE COCOA = Block(TU12, 127, 0, "cocoa");
        DEFINE SANDSTONE_STAIRS = Block(TU09, 128, 0, "sandstone_stairs");
        DEFINE EMERALD_ORE = Block(TU14, 129, 0, "emerald_ore");
        DEFINE ENDER_CHEST = Block(TU14, 130, 0, "ender_chest");
        DEFINE TRIPWIRE_HOOK = Block(TU14, 131, 0, "tripwire_hook");
        DEFINE TRIPWIRE = Block(TU14, 132, 0, "tripwire");
        DEFINE EMERALD_BLOCK = Block(TU14, 133, 0, "emerald_block");
        DEFINE SPRUCE_WOOD_STAIRS = Block(TU09, 134, 0, "spruce_stairs");
        DEFINE BIRCH_WOOD_STAIRS = Block(TU09, 135, 0, "birch_stairs");
        DEFINE JUNGLE_WOOD_STAIRS = Block(TU12, 136, 0, "jungle_stairs");
        DEFINE COMMAND_BLOCK = Block(TU19, 137, 0, "command_block");
        DEFINE BEACON = Block(TU19, 138, 0, "beacon");


        DEFINE COBBLESTONE_WALL = Block(TU14, 139, 0, "cobblestone_wall");
        DEFINE MOSSY_COBBLESTONE_WALL = Block(TU14, 139, 1, "cobblestone_wall");
        DEFINE BRICK_WALL = Block(TU88, 139, 2, "brick_wall");
        DEFINE STONE_BRICK_WALL = Block(TU88, 139, 3, "stone_brick_wall");
        DEFINE MOSSY_STONE_BRICK_WALL = Block(TU88, 139, 4, "mossy_stone_brick_wall");
        DEFINE ANDESITE_WALL = Block(TU88, 139, 5, "andesite_wall");
        DEFINE DIORITE_WALL = Block(TU88, 139, 6, "diorite_wall");
        DEFINE GRANITE_WALL = Block(TU88, 139, 7, "granite_wall");
        DEFINE SANDSTONE_WALL = Block(TU88, 139, 8, "sandstone_wall");
        DEFINE RED_SANDSTONE_WALL = Block(TU88, 139, 9, "red_sandstone_wall");
        DEFINE NETHER_BRICK_WALL = Block(TU88, 139, 10, "nether_brick_wall");
        DEFINE RED_NETHER_BRICK_WALL = Block(TU88, 139, 11, "red_nether_brick_wall");
        DEFINE END_STONE_BRICK_WALL = Block(TU88, 139, 12, "end_stone_brick_wall");
        DEFINE PRISMARINE_WALL = Block(TU88, 139, 13, "prismarine_wall");

        DEFINE FLOWER_POT = Block(TU14, 140, 0, "flower_pot");

        // NEW
        DEFINE POTTED_POPPY = Block(TU14, 140, 1, "flower_pot");
        DEFINE POTTED_DANDELION = Block(TU14, 140, 2, "flower_pot");
        DEFINE POTTED_OAK_SAPLING = Block(TU14, 140, 3, "flower_pot");
        DEFINE POTTED_SPRUCE_SAPLING = Block(TU14, 140, 4, "flower_pot");
        DEFINE POTTED_BIRCH_SAPLING = Block(TU14, 140, 5, "flower_pot");
        DEFINE POTTED_JUNGLE_SAPLING = Block(TU14, 140, 6, "flower_pot");
        DEFINE POTTED_RED_MUSHROOM = Block(TU14, 140, 7, "flower_pot");
        DEFINE POTTED_BROWN_MUSHROOM = Block(TU14, 140, 8, "flower_pot");
        DEFINE POTTED_CACTUS = Block(TU14, 140, 9, "flower_pot");
        DEFINE POTTED_DEAD_BUSH = Block(TU14, 140, 10, "flower_pot");
        DEFINE POTTED_FERN = Block(TU14, 140, 11, "flower_pot");
        DEFINE POTTED_ACACIA_SAPLING = Block(TU14, 140, 12, "flower_pot");
        DEFINE POTTED_DARK_OAK_SAPLING = Block(TU14, 140, 13, "flower_pot");






        DEFINE CARROTS = Block(TU14, 141, 0, "carrots");
        DEFINE POTATOES = Block(TU14, 142, 0, "potatoes");
        DEFINE WOODEN_BUTTON = Block(TU09, 143, 0, "wooden_button");

        // TODO: expand these out (creeper, steve, skeleton, wither skeleton, zombie heads added in TU12)
        DEFINE MOB_HEAD = Block(TU12, 144, 0, "skull");

        DEFINE ANVIL = Block(TU14, 145, 0, "anvil");
        DEFINE SLIGHTLY_DAMAGED_ANVIL = Block(TU14, 145, 1, "anvil");
        DEFINE VERY_DAMAGED_ANVIL = Block(TU14, 145, 2, "anvil");
        DEFINE TRAPPED_CHEST = Block(TU19, 146, 0, "trapped_chest");
        DEFINE LIGHT_WEIGHTED_PRESSURE_PLATE = Block(TU19, 147, 0, "light_weighted_pressure_plate");
        DEFINE HEAVY_WEIGHTED_PRESSURE_PLATE = Block(TU19, 148, 0, "heavy_weighted_pressure_plate");
        DEFINE INACTIVE_REDSTONE_COMPARATOR = Block(TU19, 149, 0, "unpowered_comparator");
        DEFINE ACTIVE_REDSTONE_COMPARATOR = Block(TU19, 150, 0, "powered_comparator");
        DEFINE DAYLIGHT_SENSOR = Block(TU19, 151, 0, "daylight_detector");
        DEFINE REDSTONE_BLOCK = Block(TU19, 152, 0, "redstone_block");
        DEFINE NETHER_QUARTZ_ORE = Block(TU14, 153, 0, "quartz_ore");
        DEFINE HOPPER = Block(TU19, 154, 0, "hopper");

        DEFINE QUARTZ_BLOCK = Block(TU14, 155, 0, "quartz_block");
        DEFINE QUARTZ_CHISELED_BLOCK = Block(TU14, 155, 1, "quartz_block");

        // NEW
        DEFINE QUARTZ_PILLAR_BLOCK_1 = Block(TU14, 155, 2, "quartz_block");
        DEFINE QUARTZ_PILLAR_BLOCK_2 = Block(TU14, 155, 3, "quartz_block");
        DEFINE QUARTZ_PILLAR_BLOCK_3 = Block(TU14, 155, 4, "quartz_block");
        DEFINE SMOOTH_QUARTZ_BLOCK = Block(TU14, 155, 4, "quartz_block");

        DEFINE QUARTZ_STAIRS = Block(TU14, 156, 0, "quartz_stairs");
        DEFINE ACTIVATOR_RAIL = Block(TU19, 157, 0, "activator_rail");
        DEFINE DROPPER = Block(TU19, 158, 0, "dropper");

        DEFINE WHITE_HARDENED_CLAY = Block(TU19, 159, 0, "stained_hardened_clay");
        DEFINE ORANGE_HARDENED_CLAY = Block(TU19, 159, 1, "stained_hardened_clay");
        DEFINE MAGENTA_HARDENED_CLAY = Block(TU19, 159, 2, "stained_hardened_clay");
        DEFINE LIGHT_BLUE_HARDENED_CLAY = Block(TU19, 159, 3, "stained_hardened_clay");
        DEFINE YELLOW_HARDENED_CLAY = Block(TU19, 159, 4, "stained_hardened_clay");
        DEFINE LIME_HARDENED_CLAY = Block(TU19, 159, 5, "stained_hardened_clay");
        DEFINE PINK_HARDENED_CLAY = Block(TU19, 159, 6, "stained_hardened_clay");
        DEFINE GRAY_HARDENED_CLAY = Block(TU19, 159, 7, "stained_hardened_clay");
        DEFINE LIGHT_GRAY_HARDENED_CLAY = Block(TU19, 159, 8, "stained_hardened_clay");
        DEFINE CYAN_HARDENED_CLAY = Block(TU19, 159, 9, "stained_hardened_clay");
        DEFINE PURPLE_HARDENED_CLAY = Block(TU19, 159, 10, "stained_hardened_clay");
        DEFINE BLUE_HARDENED_CLAY = Block(TU19, 159, 11, "stained_hardened_clay");
        DEFINE BROWN_HARDENED_CLAY = Block(TU19, 159, 12, "stained_hardened_clay");
        DEFINE GREEN_HARDENED_CLAY = Block(TU19, 159, 13, "stained_hardened_clay");
        DEFINE RED_HARDENED_CLAY = Block(TU19, 159, 14, "stained_hardened_clay");
        DEFINE BLACK_HARDENED_CLAY = Block(TU19, 159, 15, "stained_hardened_clay");

        DEFINE WHITE_STAINED_GLASS_PANE = Block(TU25, 160, 0, "stained_glass_pane");
        DEFINE ORANGE_STAINED_GLASS_PANE = Block(TU25, 160, 1, "stained_glass_pane");
        DEFINE MAGENTA_STAINED_GLASS_PANE = Block(TU25, 160, 2, "stained_glass_pane");
        DEFINE LIGHT_BLUE_STAINED_GLASS_PANE = Block(TU25, 160, 3, "stained_glass_pane");
        DEFINE YELLOW_STAINED_GLASS_PANE = Block(TU25, 160, 4, "stained_glass_pane");
        DEFINE LIME_STAINED_GLASS_PANE = Block(TU25, 160, 5, "stained_glass_pane");
        DEFINE PINK_STAINED_GLASS_PANE = Block(TU25, 160, 6, "stained_glass_pane");
        DEFINE GRAY_STAINED_GLASS_PANE = Block(TU25, 160, 7, "stained_glass_pane");
        DEFINE LIGHT_GRAY_STAINED_GLASS_PANE = Block(TU25, 160, 8, "stained_glass_pane");
        DEFINE CYAN_STAINED_GLASS_PANE = Block(TU25, 160, 9, "stained_glass_pane");
        DEFINE PURPLE_STAINED_GLASS_PANE = Block(TU25, 160, 10, "stained_glass_pane");
        DEFINE BLUE_STAINED_GLASS_PANE = Block(TU25, 160, 11, "stained_glass_pane");
        DEFINE BROWN_STAINED_GLASS_PANE = Block(TU25, 160, 12, "stained_glass_pane");
        DEFINE GREEN_STAINED_GLASS_PANE = Block(TU25, 160, 13, "stained_glass_pane");
        DEFINE RED_STAINED_GLASS_PANE = Block(TU25, 160, 14, "stained_glass_pane");
        DEFINE BLACK_STAINED_GLASS_PANE = Block(TU25, 160, 15, "stained_glass_pane");

        DEFINE ACACIA_LEAVES = Block(TU31, 161, 0, "leaves2");
        DEFINE DARK_OAK_LEAVES = Block(TU31, 161, 1, "leaves2");

        // NEW
        DEFINE ACACIA_LEAVES_PERSISTENT = Block(TU31, 161, 4, "leaves2");
        DEFINE DARK_OAK_LEAVES_PERSISTENT = Block(TU31, 161, 5, "leaves2");


        DEFINE ACACIA_WOOD = Block(TU25, 162, 0, "log2");
        DEFINE DARK_OAK_WOOD = Block(TU25, 162, 1, "log2");
        DEFINE ACACIA_WOOD_STAIRS = Block(TU25, 163, 0, "acacia_stairs");
        DEFINE DARK_OAK_WOOD_STAIRS = Block(TU25, 164, 0, "dark_oak_stairs");
        DEFINE SLIME_BLOCK = Block(TU31, 165, 0, "slime");
        DEFINE BARRIER = Block(TU31, 166, 0, "barrier");
        DEFINE IRON_TRAPDOOR = Block(TU25, 167, 0, "iron_trapdoor");
        DEFINE PRISMARINE = Block(TU31, 168, 0, "prismarine");
        DEFINE PRISMARINE_BRICKS = Block(TU31, 168, 1, "prismarine");
        DEFINE DARK_PRISMARINE = Block(TU31, 168, 2, "prismarine");
        DEFINE SEA_LANTERN = Block(TU31, 169, 0, "sea_lantern");
        DEFINE HAY_BALE = Block(TU19, 170, 0, "hay_block");

        DEFINE WHITE_CARPET = Block(TU14, 171, 0, "carpet");
        DEFINE ORANGE_CARPET = Block(TU14, 171, 1, "carpet");
        DEFINE MAGENTA_CARPET = Block(TU14, 171, 2, "carpet");
        DEFINE LIGHT_BLUE_CARPET = Block(TU14, 171, 3, "carpet");
        DEFINE YELLOW_CARPET = Block(TU14, 171, 4, "carpet");
        DEFINE LIME_CARPET = Block(TU14, 171, 5, "carpet");
        DEFINE PINK_CARPET = Block(TU14, 171, 6, "carpet");
        DEFINE GRAY_CARPET = Block(TU14, 171, 7, "carpet");
        DEFINE LIGHT_GRAY_CARPET = Block(TU14, 171, 8, "carpet");
        DEFINE CYAN_CARPET = Block(TU14, 171, 9, "carpet");
        DEFINE PURPLE_CARPET = Block(TU14, 171, 10, "carpet");
        DEFINE BLUE_CARPET = Block(TU14, 171, 11, "carpet");
        DEFINE BROWN_CARPET = Block(TU14, 171, 12, "carpet");
        DEFINE GREEN_CARPET = Block(TU14, 171, 13, "carpet");
        DEFINE RED_CARPET = Block(TU14, 171, 14, "carpet");
        DEFINE BLACK_CARPET = Block(TU14, 171, 15, "carpet");

        // also known as terracotta
        DEFINE HARDENED_CLAY = Block(TU19, 172, 0, "hardened_clay");
        DEFINE BLOCK_OF_COAL = Block(TU19, 173, 0, "coal_block");
        DEFINE PACKED_ICE = Block(TU31, 174, 0, "packed_ice");

        DEFINE SUNFLOWER = Block(TU31, 175, 0, "double_plant");
        DEFINE LILAC = Block(TU31, 175, 1, "double_plant");
        DEFINE DOUBLE_TALLGRASS = Block(TU31, 175, 2, "double_plant");
        DEFINE LARGE_FERN = Block(TU31, 175, 3, "double_plant");
        DEFINE ROSE_BUSH = Block(TU31, 175, 4, "double_plant");
        DEFINE PEONY = Block(TU31, 175, 5, "double_plant");

        DEFINE FREE_STANDING_BANNER = Block(TU43, 176, 0, "standing_banner");
        DEFINE WALL_MOUNTED_BANNER = Block(TU43, 177, 0, "wall_banner");
        DEFINE INVERTED_DAYLIGHT_SENSOR = Block(TU19, 178, 0, "daylight_detector_inverted");

        DEFINE RED_SANDSTONE = Block(TU31, 179, 0, "red_sandstone");
        DEFINE CHISELED_RED_SANDSTONE = Block(TU31, 179, 1, "red_sandstone");
        DEFINE CUT_RED_SANDSTONE = Block(TU31, 179, 2, "red_sandstone");
        // NEW
        DEFINE SMOOTH_RED_SANDSTONE = Block(TU31, 179, 3, "red_sandstone");

        DEFINE RED_SANDSTONE_STAIRS = Block(TU31, 180, 0, "red_sandstone_stairs");

        DEFINE DOUBLE_RED_SANDSTONE_SLAB = Block(TU88, 181, 0, "double_stone_slab2");
        DEFINE DOUBLE_SMOOTH_RED_SANDSTONE_SLAB = Block(TU88, 181, 1, "double_stone_slab2");
        DEFINE DOUBLE_POLISHED_ANDESITE_SLAB = Block(TU88, 181, 2, "double_stone_slab2");
        DEFINE DOUBLE_ANDESITE_SLAB = Block(TU88, 181, 3, "double_stone_slab2");
        DEFINE DOUBLE_DIORITE_SLAB = Block(TU88, 181, 4, "double_stone_slab2");
        DEFINE DOUBLE_POLISHED_DIORITE_SLAB = Block(TU88, 181, 5, "double_stone_slab2");
        DEFINE DOUBLE_GRANITE_SLAB = Block(TU88, 181, 6, "double_stone_slab2");
        DEFINE DOUBLE_POLISHED_GRANITE_SLAB = Block(TU88, 181, 7, "double_stone_slab2");

        DEFINE LOWER_RED_SANDSTONE_SLAB = Block(TU88, 182, 0, "double_stone_slab2");
        DEFINE LOWER_SMOOTH_RED_SANDSTONE_SLAB = Block(TU88, 182, 1, "double_stone_slab2");
        DEFINE LOWER_POLISHED_ANDESITE_SLAB = Block(TU88, 182, 2, "double_stone_slab2");
        DEFINE LOWER_ANDESITE_SLAB = Block(TU88, 182, 3, "double_stone_slab2");
        DEFINE LOWER_DIORITE_SLAB = Block(TU88, 182, 4, "double_stone_slab2");
        DEFINE LOWER_POLISHED_DIORITE_SLAB = Block(TU88, 182, 5, "double_stone_slab2");
        DEFINE LOWER_GRANITE_SLAB = Block(TU88, 182, 6, "double_stone_slab2");
        DEFINE LOWER_POLISHED_GRANITE_SLAB = Block(TU88, 182, 7, "double_stone_slab2");

        DEFINE UPPER_RED_SANDSTONE_SLAB = Block(TU88, 182, 8, "double_stone_slab2");
        DEFINE UPPER_SMOOTH_RED_SANDSTONE_SLAB = Block(TU88, 182, 9, "double_stone_slab2");
        DEFINE UPPER_POLISHED_ANDESITE_SLAB = Block(TU88, 182, 10, "double_stone_slab2");
        DEFINE UPPER_ANDESITE_SLAB = Block(TU88, 182, 11, "double_stone_slab2");
        DEFINE UPPER_DIORITE_SLAB = Block(TU88, 182, 12, "double_stone_slab2");
        DEFINE UPPER_POLISHED_DIORITE_SLAB = Block(TU88, 182, 13, "double_stone_slab2");
        DEFINE UPPER_GRANITE_SLAB = Block(TU88, 182, 14, "double_stone_slab2");
        DEFINE UPPER_POLISHED_GRANITE_SLAB = Block(TU88, 182, 15, "double_stone_slab2");





        DEFINE SPRUCE_FENCE_GATE = Block(TU25, 183, 0, "spruce_fence_gate");
        DEFINE BIRCH_FENCE_GATE = Block(TU25, 184, 0, "birch_fence_gate");
        DEFINE JUNGLE_FENCE_GATE = Block(TU25, 185, 0, "jungle_fence_gate");
        DEFINE DARK_OAK_FENCE_GATE = Block(TU25, 186, 0, "dark_oak_fence_gate");
        DEFINE ACACIA_FENCE_GATE = Block(TU25, 187, 0, "acacia_fence_gate");
        DEFINE SPRUCE_FENCE = Block(TU25, 188, 0, "spruce_fence");
        DEFINE BIRCH_FENCE = Block(TU25, 189, 0,  "birch_fence");
        DEFINE JUNGLE_FENCE = Block(TU25, 190, 0, "jungle_fence");
        DEFINE DARK_OAK_FENCE = Block(TU25, 191, 0, "dark_oak_fence");
        DEFINE ACACIA_FENCE = Block(TU25, 192, 0, "acacia_fence");
        DEFINE SPRUCE_DOOR_BLOCK = Block(TU25, 193, 0, "spruce_door");
        DEFINE BIRCH_DOOR_BLOCK = Block(TU25, 194, 0, "birch_door");
        DEFINE JUNGLE_DOOR_BLOCK = Block(TU25, 195, 0, "jungle_door");
        DEFINE ACACIA_DOOR_BLOCK = Block(TU25, 196, 0, "acacia_door");
        DEFINE DARK_OAK_DOOR_BLOCK = Block(TU25, 197, 0, "dark_oak_door");

        DEFINE END_ROD = Block(TU46, 198, 0, "end_rod");
        DEFINE CHORUS_PLANT = Block(TU46, 199, 0, "chorus_plant");
        DEFINE CHORUS_FLOWER = Block(TU46, 200, 0, "chorus_flower");
        DEFINE PURPUR_BLOCK = Block(TU46, 201, 0, "purpur_block");
        DEFINE PURPUR_PILLAR = Block(TU46, 202, 0, "purpur_pillar");
        DEFINE PURPUR_STAIRS = Block(TU46, 203, 0, "purpur_stairs");

        DEFINE DOUBLE_PURPUR_SLAB = Block(TU46, 204, 0, "purpur_double_slab");
        DEFINE DOUBLE_MOSSY_STONE_BRICK_SLAB = Block(TU88, 204, 1, "purpur_double_slab");
        DEFINE DOUBLE_SMOOTH_QUARTZ_SLAB = Block(TU88, 204, 2, "purpur_double_slab");
        DEFINE DOUBLE_STONE_SLAB = Block(TU88, 204, 3, "purpur_double_slab");
        DEFINE DOUBLE_CUT_SANDSTONE_SLAB = Block(TU88, 204, 4, "purpur_double_slab");
        DEFINE DOUBLE_CUT_RED_SANDSTONE_SLAB = Block(TU88, 204, 5, "purpur_double_slab");
        DEFINE DOUBLE_END_STONE_BRICK_SLAB = Block(TU88, 204, 6, "purpur_double_slab");

        DEFINE LOWER_PURPUR_SLAB = Block(TU46, 205, 0, "purpur_slab");
        DEFINE LOWER_MOSSY_STONE_BRICK_SLAB = Block(TU88, 205, 1, "");
        DEFINE LOWER_SMOOTH_QUARTZ_SLAB = Block(TU88, 205, 2, "");
        // DEFINE LOWER_STONE_SLAB = Block(TU88, 205, 3, "");
        DEFINE LOWER_CUT_SANDSTONE_SLAB = Block(TU88, 205, 4, "");
        DEFINE LOWER_CUT_RED_SANDSTONE_SLAB = Block(TU88, 205, 5, "");
        DEFINE LOWER_END_STONE_BRICK_SLAB = Block(TU88, 205, 6, "");

        DEFINE UPPER_PURPUR_SLAB = Block(TU46, 205, 8, "purpur_slab");
        DEFINE UPPER_MOSSY_STONE_BRICK_SLAB = Block(TU88, 205, 9, "");
        DEFINE UPPER_SMOOTH_QUARTZ_SLAB = Block(TU88, 205, 10, "");
        // DEFINE UPPER_STONE_SLAB = Block(TU88, 205, 11, "");
        DEFINE UPPER_CUT_SANDSTONE_SLAB = Block(TU88, 205, 12, "");
        DEFINE UPPER_CUT_RED_SANDSTONE_SLAB = Block(TU88, 205, 13, "");



        DEFINE END_STONE_BRICKS = Block(TU43, 206, 0, "end_bricks");
        DEFINE BEETROOT_BLOCK = Block(TU43, 207, 0, "beetroots");
        DEFINE GRASS_PATH = Block(TU43, 208, 0, "grass_path");
        DEFINE END_GATEWAY = Block(TU46, 209, 0, "end_gateway");
        DEFINE REPEATING_COMMAND_BLOCK = Block(TU_UNKNOWN, 210, 0, "repeating_command_block");
        DEFINE CHAIN_COMMAND_BLOCK = Block(TU_UNKNOWN, 211, 0, "chain_command_block");
        DEFINE FROSTED_ICE = Block(TU43, 212, 0, "frosted_ice");
        DEFINE MAGMA_BLOCK = Block(TU43, 213, 0, "magma");
        DEFINE NETHER_WART_BLOCK = Block(TU43, 214, 0, "nether_wart_block");
        DEFINE RED_NETHER_BRICK = Block(TU43, 215, 0, "red_nether_brick");
        DEFINE BONE_BLOCK = Block(TU43, 216, 0, "bone_block");
        DEFINE STRUCTURE_VOID = Block(TU_UNKNOWN, 217, 0, "structure_void");
        DEFINE OBSERVER = Block(TU54, 218, 0, "observer");

        DEFINE WHITE_SHULKER_BOX = Block(TU53, 219, 0, "white_shulker_box");
        DEFINE ORANGE_SHULKER_BOX = Block(TU53, 220, 0, "orange_shulker_box");
        DEFINE MAGENTA_SHULKER_BOX = Block(TU53, 221, 0, "magenta_shulker_box");
        DEFINE LIGHT_BLUE_SHULKER_BOX = Block(TU53, 222, 0, "light_blue_shulker_box");
        DEFINE YELLOW_SHULKER_BOX = Block(TU53, 223, 0, "yellow_shulker_box");
        DEFINE LIME_SHULKER_BOX = Block(TU53, 224, 0, "lime_shulker_box");
        DEFINE PINK_SHULKER_BOX = Block(TU53, 225, 0, "pink_shulker_box");
        DEFINE GRAY_SHULKER_BOX = Block(TU53, 226, 0, "gray_shulker_box");
        DEFINE LIGHT_GRAY_SHULKER_BOX = Block(TU53, 227, 0, "silver_shulker_box");
        DEFINE CYAN_SHULKER_BOX = Block(TU53, 228, 0, "cyan_shulker_box");
        DEFINE PURPLE_SHULKER_BOX = Block(TU53, 229, 0, "purple_shulker_box");
        DEFINE BLUE_SHULKER_BOX = Block(TU53, 230, 0, "blue_shulker_box");
        DEFINE BROWN_SHULKER_BOX = Block(TU53, 231, 0, "brown_shulker_box");
        DEFINE GREEN_SHULKER_BOX = Block(TU53, 232, 0, "green_shulker_box");
        DEFINE RED_SHULKER_BOX = Block(TU53, 233, 0, "red_shulker_box");
        DEFINE BLACK_SHULKER_BOX = Block(TU53, 234, 0, "black_shulker_box");

        DEFINE WHITE_GLAZED_TERRACOTTA = Block(TU53, 235, 0, "white_glazed_terracotta");
        DEFINE ORANGE_GLAZED_TERRACOTTA = Block(TU53, 236, 0, "orange_glazed_terracotta");
        DEFINE MAGENTA_GLAZED_TERRACOTTA = Block(TU53, 237, 0, "magenta_glazed_terracotta");
        DEFINE LIGHT_BLUE_GLAZED_TERRACOTTA = Block(TU53, 238, 0, "light_blue_glazed_terracotta");
        DEFINE YELLOW_GLAZED_TERRACOTTA = Block(TU53, 239, 0, "yellow_glazed_terracotta");
        DEFINE LIME_GLAZED_TERRACOTTA = Block(TU53, 240, 0, "lime_glazed_terracotta");
        DEFINE PINK_GLAZED_TERRACOTTA = Block(TU53, 241, 0, "pink_glazed_terracotta");
        DEFINE GRAY_GLAZED_TERRACOTTA = Block(TU53, 242, 0, "gray_glazed_terracotta");
        DEFINE LIGHT_GRAY_GLAZED_TERRACOTTA = Block(TU53, 243, 0, "light_gray_glazed_terracotta");
        DEFINE CYAN_GLAZED_TERRACOTTA = Block(TU53, 244, 0, "cyan_glazed_terracotta");
        DEFINE PURPLE_GLAZED_TERRACOTTA = Block(TU53, 245, 0, "purple_glazed_terracotta");
        DEFINE BLUE_GLAZED_TERRACOTTA = Block(TU53, 246, 0, "blue_glazed_terracotta");
        DEFINE BROWN_GLAZED_TERRACOTTA = Block(TU53, 247, 0, "brown_glazed_terracotta");
        DEFINE GREEN_GLAZED_TERRACOTTA = Block(TU53, 248, 0, "green_glazed_terracotta");
        DEFINE RED_GLAZED_TERRACOTTA = Block(TU53, 249, 0, "red_glazed_terracotta");
        DEFINE BLACK_GLAZED_TERRACOTTA = Block(TU53, 250, 0, "black_glazed_terracotta");

        DEFINE WHITE_CONCRETE = Block(TU53, 251, 0, "concrete");
        DEFINE ORANGE_CONCRETE = Block(TU53, 251, 1, "concrete");
        DEFINE MAGENTA_CONCRETE = Block(TU53, 251, 2, "concrete");
        DEFINE LIGHT_BLUE_CONCRETE = Block(TU53, 251, 3, "concrete");
        DEFINE YELLOW_CONCRETE = Block(TU53, 251, 4, "concrete");
        DEFINE LIME_CONCRETE = Block(TU53, 251, 5, "concrete");
        DEFINE PINK_CONCRETE = Block(TU53, 251, 6, "concrete");
        DEFINE GRAY_CONCRETE = Block(TU53, 251, 7, "concrete");
        DEFINE LIGHT_GRAY_CONCRETE = Block(TU53, 251, 8, "concrete");
        DEFINE CYAN_CONCRETE = Block(TU53, 251, 9, "concrete");
        DEFINE PURPLE_CONCRETE = Block(TU53, 251, 10, "concrete");
        DEFINE BLUE_CONCRETE = Block(TU53, 251, 11, "concrete");
        DEFINE BROWN_CONCRETE = Block(TU53, 251, 12, "concrete");
        DEFINE GREEN_CONCRETE = Block(TU53, 251, 13, "concrete");
        DEFINE RED_CONCRETE = Block(TU53, 251, 14, "concrete");
        DEFINE BLACK_CONCRETE = Block(TU53, 251, 15, "concrete");

        DEFINE WHITE_CONCRETE_POWDER = Block(TU53, 252, 0, "concrete_powder");
        DEFINE ORANGE_CONCRETE_POWDER = Block(TU53, 252, 1, "concrete_powder");
        DEFINE MAGENTA_CONCRETE_POWDER = Block(TU53, 252, 2, "concrete_powder");
        DEFINE LIGHT_BLUE_CONCRETE_POWDER = Block(TU53, 252, 3, "concrete_powder");
        DEFINE YELLOW_CONCRETE_POWDER = Block(TU53, 252, 4, "concrete_powder");
        DEFINE LIME_CONCRETE_POWDER = Block(TU53, 252, 5, "concrete_powder");
        DEFINE PINK_CONCRETE_POWDER = Block(TU53, 252, 6, "concrete_powder");
        DEFINE GRAY_CONCRETE_POWDER = Block(TU53, 252, 7, "concrete_powder");
        DEFINE LIGHT_GRAY_CONCRETE_POWDER = Block(TU53, 252, 8, "concrete_powder");
        DEFINE CYAN_CONCRETE_POWDER = Block(TU53, 252, 9, "concrete_powder");
        DEFINE PURPLE_CONCRETE_POWDER = Block(TU53, 252, 10, "concrete_powder");
        DEFINE BLUE_CONCRETE_POWDER = Block(TU53, 252, 11, "concrete_powder");
        DEFINE BROWN_CONCRETE_POWDER = Block(TU53, 252, 12, "concrete_powder");
        DEFINE GREEN_CONCRETE_POWDER = Block(TU53, 252, 13, "concrete_powder");
        DEFINE RED_CONCRETE_POWDER = Block(TU53, 252, 14, "concrete_powder");
        DEFINE BLACK_CONCRETE_POWDER = Block(TU53, 252, 15, "concrete_powder");

        DEFINE STRUCTURE_BLOCK = Block(TU_UNKNOWN, 255, 0, "structure_block");

        // Aquatic Stuff
        DEFINE CONDUIT = Block(TU69, 256, 0, "conduit");
        DEFINE UNKNOWN_PUMP = Block(TU69, 257, 0, "pumpkin");
        DEFINE KELP = Block(TU69, 258, 0, "kelp");

        DEFINE CORAL_BLOCK = Block(TU69, 259, 0, "_4");
        DEFINE PURPLE_SHULKER_BOX2 = Block(TU88, 260, 0, "purple_shulker_box");

        DEFINE CORAL = Block(TU69, 263, 0, "_5");
        DEFINE CORAL_FAN = Block(TU69, 264, 0, "_6");
        DEFINE CORAL_FAN_DEAD = Block(TU69, 265, 0, "_7");
        DEFINE CORAL_FAN_WALL1 = Block(TU69, 266, 0, "_8");
        DEFINE CORAL_FAN_WALL2 = Block(TU69, 267, 0, "_9");
        DEFINE CORAL_FAN_WALL3 = Block(TU69, 268, 0, "_10");
        DEFINE DRIED_KELP_BLOCK = Block(TU69, 269, 0, "_11");
        DEFINE SEAGRASS = Block(TU69, 270, 0, "_12");
        DEFINE SEAPICKLE = Block(TU69, 271, 0, "_13");
        DEFINE BUBBLE_COLUMN = Block(TU69, 272, 0, "bubble_column");
        DEFINE BLUE_ICE = Block(TU69, 273, 0, "blue_ice");
        DEFINE SPRUCE_TRAPDOOR = Block(TU69, 274, 0, "spruce_trapdoor");
        DEFINE BIRCH_TRAPDOOR = Block(TU69, 275, 0, "birch_trapdoor");
        DEFINE JUNGLE_TRAPDOOR = Block(TU69, 276, 0, "jungle_trapdoor");
        DEFINE ACACIA_TRAPDOOR = Block(TU69, 277, 0, "acacia_trapdoor");
        DEFINE DARK_OAK_TRAPDOOR = Block(TU69, 278, 0, "dark_oak_trapdoor");
        DEFINE TURTLE_EGG = Block(TU69, 279, 0, "turtle_egg");
        DEFINE PRISMARINE_STAIRS = Block(TU69, 291, 0, "prismarine_stairs");
        DEFINE PRISMARINE_BRICK_STAIRS = Block(TU69, 292, 0, "prismarine_brick_stairs");
        DEFINE DARK_PRISMARINE_STAIRS = Block(TU69, 293, 0, "dark_prismarine_stairs");
        DEFINE STRIPPED_SPRUCE_LOG = Block(TU69, 295, 0, "stripped_spruce_log");
        DEFINE STRIPPED_BIRCH_LOG = Block(TU69, 296, 0, "stripped_birch_log");
        DEFINE STRIPPED_JUNGLE_LOG = Block(TU69, 297, 0, "stripped_jungle_log");
        DEFINE STRIPPED_ACACIA_LOG = Block(TU69, 298, 0, "stripped_acacia_log");
        DEFINE STRIPPED_DARK_OAK_LOG = Block(TU69, 299, 0, "stripped_dark_oak_log");
        DEFINE STRIPPED_OAK_LOG = Block(TU69, 300, 0, "stripped_oak_log");
        DEFINE ACACIA_PRESSURE_PLATE = Block(TU69, 301, 0, "acacia_pressure_plate");
        DEFINE BIRCH_PRESSURE_PLATE = Block(TU69, 302, 0, "birch_pressure_plate");
        DEFINE DARK_OAK_PRESSURE_PLATE = Block(TU69, 303, 0, "dark_oak_pressure_plate");
        DEFINE JUNGLE_PRESSURE_PLATE = Block(TU69, 304, 0, "jungle_pressure_plate");
        DEFINE SPRUCE_PRESSURE_PLATE = Block(TU69, 305, 0, "spruce_pressure_plate");
        DEFINE ACACIA_BUTTON = Block(TU69, 306, 0, "acacia_button");
        DEFINE BIRCH_BUTTON = Block(TU69, 307, 0, "birch_button");
        DEFINE DARK_OAK_BUTTON = Block(TU69, 308, 0, "dark_oak_button");
        DEFINE JUNGLE_BUTTON = Block(TU69, 309, 0, "jungle_button");
        DEFINE SPRUCE_BUTTON = Block(TU69, 310, 0, "spruce_button");

        // todo 8 DIFFERENT SLAB VARIANTS
        DEFINE DOUBLE_PRISMARINE_SLAB = Block(TU69, 311, 0, "_41");
        DEFINE DOUBLE_PRISMARINE_BRICK_SLAB = Block(TU69, 311, 1, "_41");
        DEFINE DOUBLE_DARK_PRISMARINE_SLAB = Block(TU69, 311, 2, "_41");
        DEFINE DOUBLE_MOSSY_COBBLESTONE_SLAB = Block(TU69, 311, 3, "_41");
        DEFINE DOUBLE_SMOOTH_SANDSTONE_SLAB = Block(TU69, 311, 4, "_41");
        DEFINE DOUBLE_RED_NETHER_BRICK_SLAB = Block(TU69, 311, 5, "_41");
        
        DEFINE LOWER_PRISMARINE_SLAB = Block(TU69, 312, 0, "_41");
        DEFINE LOWER_PRISMARINE_BRICK_SLAB = Block(TU69, 312, 1, "_41");
        DEFINE LOWER_DARK_PRISMARINE_SLAB = Block(TU69, 312, 2, "_41");
        DEFINE LOWER_MOSSY_COBBLESTONE_SLAB = Block(TU69, 312, 3, "_41");
        DEFINE LOWER_SMOOTH_SANDSTONE_SLAB = Block(TU69, 312, 4, "_41");
        DEFINE LOWER_RED_NETHER_BRICK_SLAB = Block(TU69, 312, 5, "_41");
        
        DEFINE UPPER_PRISMARINE_SLAB = Block(TU69, 312, 8, "_41");
        DEFINE UPPER_PRISMARINE_BRICK_SLAB = Block(TU69, 312, 9, "_41");
        DEFINE UPPER_DARK_PRISMARINE_SLAB = Block(TU69, 312, 10, "_41");
        DEFINE UPPER_MOSSY_COBBLESTONE_SLAB = Block(TU69, 312, 11, "_41");
        DEFINE UPPER_SMOOTH_SANDSTONE_SLAB = Block(TU69, 312, 12, "_41");
        DEFINE UPPER_RED_NETHER_BRICK_SLAB = Block(TU69, 312, 13, "_41");
        
        DEFINE OAK_WOOD_Y = Block(TU69, 313, 0, "_43");
        DEFINE SPRUCE_WOOD_Y = Block(TU69, 313, 1, "_43");
        DEFINE BIRCH_WOOD_Y = Block(TU69, 313, 2, "_43");
        DEFINE JUNGLE_WOOD_Y = Block(TU69, 313, 3, "_43");
        DEFINE ACACIA_WOOD_Y = Block(TU69, 313, 4, "_43");
        DEFINE DARK_OAK_WOOD_Y = Block(TU69, 313, 5, "_43");
        
        DEFINE STRIPPED_OAK_WOOD_Y = Block(TU69, 313, 0, "_43");
        DEFINE STRIPPED_SPRUCE_WOOD_Y = Block(TU69, 313, 1, "_43");
        DEFINE STRIPPED_BIRCH_WOOD_Y = Block(TU69, 313, 2, "_43");
        DEFINE STRIPPED_JUNGLE_WOOD_Y = Block(TU69, 313, 3, "_43");
        DEFINE STRIPPED_ACACIA_WOOD_Y = Block(TU69, 313, 4, "_43");
        DEFINE STRIPPED_DARK_OAK_WOOD_Y = Block(TU69, 313, 5, "_43");

        // TODO: these need a lot of cleanup sigh!
        DEFINE BIRCH_WOOD_2 = Block(TU69, 314, 0, "birch_wood");
        DEFINE JUNGLE_WOOD_2 = Block(TU69, 315, 0, "jungle_wood");
        DEFINE ACACIA_WOOD_2 = Block(TU69, 316, 0, "acacia_wood");
        DEFINE DARK_OAK_WOOD_2 = Block(TU69, 317, 0, "dark_oak_wood");
        DEFINE OAK_WOOD_2 = Block(TU69, 318, 0, "oak_wood");


        DEFINE BAMBOO = Block(TU83, 319, 0, "bamboo");
        DEFINE SCAFFOLDING = Block(TU83, 320, 0, "scaffolding");
        DEFINE BAMBOO_SAPLING = Block(TU83, 321, 0, "bamboo_sapling");

        // DEFINE SMOOTH_STONE = Block(TU88, 322, 0, "smooth_stone");
        DEFINE STONE_STAIRS = Block(TU88, 323, 0, "stone_stairs");
        DEFINE MOSSY_COBBLESTONE_STAIRS = Block(TU88, 324, 0, "mossy_cobblestone_stairs");
        DEFINE ANDESITE_STAIRS = Block(TU88, 325, 0, "andesite_stairs");
        DEFINE DIORITE_STAIRS = Block(TU88, 326, 0, "diorite_stairs");
        DEFINE GRANITE_STAIRS = Block(TU88, 327, 0, "granite_stairs");
        DEFINE POLISHED_ANDESITE_STAIRS = Block(TU88, 328, 0, "polished_andesite_stairs");
        DEFINE POLISHED_DIORITE_STAIRS = Block(TU88, 329, 0, "polished_diorite_stairs");
        DEFINE POLISHED_GRANITE_STAIRS = Block(TU88, 330, 0, "polished_granite_stairs");
        DEFINE SMOOTH_QUARTZ_STAIRS = Block(TU88, 331, 0, "smooth_quartz_stairs");
        DEFINE MOSSY_STONE_BRICK_STAIRS = Block(TU88, 332, 0, "mossy_stone_brick_stairs");
        DEFINE SMOOTH_SANDSTONE_STAIRS = Block(TU88, 333, 0, "smooth_sandstone_stairs");
        DEFINE SMOOTH_RED_SANDSTONE_STAIRS = Block(TU88, 334, 0, "smooth_red_sandstone_stairs");
        DEFINE RED_NETHER_BRICK_STAIRS = Block(TU88, 335, 0, "red_nether_brick_stairs");
        DEFINE END_STONE_BRICK_STAIRS = Block(TU88, 336, 0, "end_stone_brick_stairs");
        DEFINE SPRUCE_SIGN = Block(TU88, 337, 0, "spruce_sign");
        DEFINE BIRCH_SIGN = Block(TU88, 338, 0, "birch_sign");
        DEFINE ACACIA_SIGN = Block(TU88, 339, 0, "acacia_sign");
        DEFINE JUNGLE_SIGN = Block(TU88, 340, 0, "jungle_sign");
        DEFINE DARK_OAK_SIGN = Block(TU88, 341, 0, "dark_oak_sign");
        DEFINE SPRUCE_WALL_SIGN = Block(TU88, 342, 0, "spruce_wall_sign");
        DEFINE BIRCH_WALL_SIGN = Block(TU88, 343, 0, "birch_wall_sign");
        DEFINE ACACIA_WALL_SIGN = Block(TU88, 344, 0, "acacia_wall_sign");
        DEFINE JUNGLE_WALL_SIGN = Block(TU88, 345, 0, "jungle_wall_sign");
        DEFINE DARK_OAK_WALL_SIGN = Block(TU88, 346, 0, "dark_oak_wall_sign");

        DEFINE LECTERN = Block(TU90, 348, 0, "lectern");
        DEFINE LANTERN = Block(TU90, 349, 0, "lantern");

        DEFINE LOOM = Block(TU90, 350, 0, "loom");
        DEFINE COMPOSTER = Block(TU91, 351, 0, "composter");
        DEFINE BLAST_FURNACE = Block(TU91, 352, 0, "blast_furnace");
        DEFINE BELL = Block(TU91, 354, 0, "bell");
        DEFINE SMOKER = Block(TU91, 355, 0, "smoker");
        DEFINE FLETCHING_TABLE = Block(TU91, 357, 0, "fletching_table");
        DEFINE SMITHING_TABLE = Block(TU91, 358, 0, "smithing_table");
        DEFINE GRINDSTONE = Block(TU91, 359, 0, "grindstone");
        DEFINE STONE_CUTTER = Block(TU91, 360, 0, "stonecutter");
        DEFINE CAMPFIRE = Block(TU91, 361, 0, "campfire");
        DEFINE BARREL = Block(TU91, 362, 0, "barrel");
        DEFINE SWEET_BERRY_BUSH = Block(TU91, 363, 0, "sweet_berry_bush");
        DEFINE CARTOGRAPHY_TABLE = Block(TU91, 364, 0, "cartography_table");

#undef DEFINE
    };
}