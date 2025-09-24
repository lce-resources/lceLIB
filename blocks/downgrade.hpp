// ---------- compat_final_map.hpp ----------
#pragma once
#include "block.hpp"
#include "blocksInit.hpp"
#include "lce/registry/blockRegistry.hpp"
#include <array>
#include <unordered_map>
#include <mutex>
#include <memory>

// You should already have something like this (compile-time pairs):
// namespace lce::compat { inline constexpr auto DOWNGRADES = build_downgrades(); }

namespace lce::compat {

    using BI = lce::BlocksInit;
    
    struct DowngradePair {
        lce::BlockState newer;
        lce::BlockState older;
    };
    
    template<const lce::Block& NEWER, const lce::Block& OLDER>
    consteval DowngradePair make_pair_checked() {
        static_assert(OLDER.getTU() <= NEWER.getTU(), "TU must strictly decrease");
        return { NEWER.getState(), OLDER.getState() };
    }
    
    consteval auto build_downgrades() {
        return std::to_array<DowngradePair>({
            // ################ TU BASE #################
            /*
                BI::AIR
                BI::STONE
                BI::GRASS
                BI::DIRT
                BI::COBBLESTONE
                BI::OAK_WOOD_PLANK
                BI::OAK_SAPLING
                BI::SPRUCE_SAPLING
                BI::BIRCH_SAPLING
                BI::BEDROCK
                BI::FLOWING_WATER
                BI::STILL_WATER
                BI::FLOWING_LAVA
                BI::STILL_LAVA
                BI::SAND
                BI::GRAVEL
                BI::GOLD_ORE
                BI::IRON_ORE
                BI::COAL_ORE
                BI::OAK_WOOD
                BI::SPRUCE_WOOD
                BI::BIRCH_WOOD
                BI::OAK_LEAVES
                BI::SPRUCE_LEAVES
                BI::BIRCH_LEAVES
                BI::GLASS
                BI::LAPIS_LAZULI_ORE
                BI::LAPIS_LAZULI_BLOCK
                BI::DISPENSER
                BI::SANDSTONE
                BI::NOTE_BLOCK
                BI::BED_BLOCK
                BI::POWERED_RAIL
                BI::DETECTOR_RAIL
                BI::COBWEB
                BI::TALL_GRASS_SHRUB
                BI::TALL_GRASS_GRASS
                BI::TALL_GRASS_FERN
                BI::DEAD_BUSH
                BI::WHITE_WOOL
                BI::ORANGE_WOOL
                BI::MAGENTA_WOOL
                BI::LIGHT_BLUE_WOOL
                BI::YELLOW_WOOL
                BI::LIME_WOOL
                BI::PINK_WOOL
                BI::GRAY_WOOL
                BI::LIGHT_GRAY_WOOL
                BI::CYAN_WOOL
                BI::PURPLE_WOOL
                BI::BLUE_WOOL
                BI::BROWN_WOOL
                BI::GREEN_WOOL
                BI::RED_WOOL
                BI::BLACK_WOOL
                BI::DANDELION
                BI::POPPY
                BI::BROWN_MUSHROOM
                BI::RED_MUSHROOM
                BI::GOLD_BLOCK
                BI::IRON_BLOCK
                BI::DOUBLE_STONE_SLAB
                BI::DOUBLE_SANDSTONE_SLAB
                BI::DOUBLE_WOODEN_SLAB
                BI::DOUBLE_COBBLESTONE_SLAB
                BI::STONE_SLAB
                BI::SANDSTONE_SLAB
                BI::WOODEN_SLAB
                BI::COBBLESTONE_SLAB
                BI::UPPER_STONE_SLAB
                BI::UPPER_SANDSTONE_SLAB
                BI::UPPER_WOODEN_SLAB
                BI::UPPER_COBBLESTONE_SLAB
                BI::TNT
                BI::BOOKSHELF
                BI::MOSS_STONE
                BI::OBSIDIAN
                BI::TORCH
                BI::FIRE
                BI::MONSTER_SPAWNER
                BI::OAK_WOOD_STAIRS
                BI::CHEST
                BI::REDSTONE_WIRE
                BI::DIAMOND_ORE
                BI::DIAMOND_BLOCK
                BI::CRAFTING_TABLE
                BI::WHEAT_CROPS
                BI::FARMLAND
                BI::FURNACE
                BI::BURNING_FURNACE
                BI::STANDING_SIGN_BLOCK
                BI::OAK_DOOR_BLOCK
                BI::LADDER
                BI::RAIL
                BI::COBBLESTONE_STAIRS
                BI::WALL_MOUNTED_SIGN_BLOCK
                BI::LEVER
                BI::STONE_PRESSURE_PLATE
                BI::IRON_DOOR_BLOCK
                BI::WOODEN_PRESSURE_PLATE
                BI::REDSTONE_ORE
                BI::GLOWING_REDSTONE_ORE
                BI::OFF_REDSTONE_TORCH
                BI::ON_REDSTONE_TORCH
                BI::STONE_BUTTON
                BI::SNOW
                BI::ICE
                BI::SNOW_BLOCK
                BI::CACTUS
                BI::CLAY_BLOCK
                BI::SUGAR_CANES
                BI::JUKEBOX
                BI::OAK_FENCE
                BI::PUMPKIN
                BI::NETHERRACK
                BI::SOUL_SAND
                BI::GLOWSTONE
                BI::NETHER_PORTAL
                BI::JACK_O_LANTERN
                BI::CAKE_BLOCK
                BI::OFF_REDSTONE_REPEATER_BLOCK
                BI::ON_REDSTONE_REPEATER_BLOCK
                BI::WOODEN_TRAPDOOR
                BI::DOUBLE_OAK_WOOD_SLAB
                BI::OAK_WOOD_SLAB
                BI::UPPER_OAK_WOOD_SLAB
                */
        
            // ################ TU3 #################
            make_pair_checked<BI::STICKY_PISTON, BI::OAK_WOOD_PLANK>(),
            make_pair_checked<BI::PISTON, BI::OAK_WOOD_PLANK>(),
            make_pair_checked<BI::PISTON_HEAD, BI::AIR>(),
        
        
            // ################ TU5 #################
            make_pair_checked<BI::STONE_BRICKS, BI::COBBLESTONE>(),
            make_pair_checked<BI::MOSSY_STONE_BRICKS, BI::COBBLESTONE>(),
            make_pair_checked<BI::CRACKED_STONE_BRICKS, BI::COBBLESTONE>(),
            make_pair_checked<BI::RED_MUSHROOM_BLOCK, BI::RED_WOOL>(),
            make_pair_checked<BI::IRON_BARS, BI::OAK_FENCE>(),
            make_pair_checked<BI::GLASS_PANE, BI::GLASS>(),
            make_pair_checked<BI::MELON_BLOCK, BI::CARVED_PUMPKIN>(),
            make_pair_checked<BI::PUMPKIN_STEM, BI::DEAD_BUSH>(),
            make_pair_checked<BI::MELON_STEM, BI::DEAD_BUSH>(),
            make_pair_checked<BI::VINES, BI::AIR>(),
            make_pair_checked<BI::OAK_FENCE_GATE, BI::OAK_FENCE>(),
            make_pair_checked<BI::BRICK_STAIRS, BI::COBBLESTONE_STAIRS>(),
            make_pair_checked<BI::STONE_BRICK_STAIRS, BI::COBBLESTONE_STAIRS>(),
            make_pair_checked<BI::BROWN_MUSHROOM_BLOCK, BI::BROWN_WOOL>(),
            make_pair_checked<BI::DOUBLE_BRICK_SLAB, BI::DOUBLE_OLD_STONE_SLAB>(),
            make_pair_checked<BI::DOUBLE_STONE_BRICK_SLAB, BI::DOUBLE_OLD_STONE_SLAB>(),
            make_pair_checked<BI::LOWER_BRICK_SLAB, BI::DOUBLE_OLD_STONE_SLAB>(),
            make_pair_checked<BI::LOWER_STONE_BRICK_SLAB, BI::DOUBLE_OLD_STONE_SLAB>(),
            make_pair_checked<BI::UPPER_BRICKS_SLAB, BI::UPPER_STONE_SLAB>(),
            make_pair_checked<BI::UPPER_STONE_BRICK_SLAB, BI::UPPER_STONE_SLAB>(),
            make_pair_checked<BI::BRICKS, BI::RED_WOOL>(),
            make_pair_checked<BI::STONE_MONSTER_EGG, BI::STONE>(),
            make_pair_checked<BI::COBBLESTONE_MONSTER_EGG, BI::COBBLESTONE>(),
            make_pair_checked<BI::STONE_BRICK_MONSTER_EGG, BI::COBBLESTONE>(),
        
        
            // ################ TU7 #################
            make_pair_checked<BI::MYCELIUM, BI::GRASS>(),
            make_pair_checked<BI::LILY_PAD, BI::AIR>(),
            make_pair_checked<BI::NETHER_BRICK_BLOCK, BI::BRICKS>(),
            make_pair_checked<BI::NETHER_BRICK_FENCE, BI::OAK_FENCE>(),
            make_pair_checked<BI::NETHER_BRICK_STAIRS, BI::OAK_WOOD_STAIRS>(),
            make_pair_checked<BI::NETHER_WART, BI::AIR>(),
            make_pair_checked<BI::ENCHANTMENT_TABLE, BI::BOOKSHELF>(),
            make_pair_checked<BI::BREWING_STAND, BI::COBBLESTONE>(),
            make_pair_checked<BI::CAULDRON, BI::IRON_BLOCK>(),
            make_pair_checked<BI::END_PORTAL, BI::BLACK_WOOL>(),
            make_pair_checked<BI::END_PORTAL_FRAME, BI::GREEN_WOOL>(),
            make_pair_checked<BI::END_STONE, BI::STONE>(),
        
        
            // ################ TU9 #################
            make_pair_checked<BI::SPRUCE_WOOD_PLANK, BI::OAK_WOOD_PLANK>(),
            make_pair_checked<BI::BIRCH_WOOD_PLANK, BI::OAK_WOOD_PLANK>(),
            make_pair_checked<BI::CHISELED_SANDSTONE, BI::SANDSTONE>(),
            make_pair_checked<BI::SMOOTH_SANDSTONE, BI::SANDSTONE>(),
            make_pair_checked<BI::DOUBLE_NETHER_BRICK_SLAB, BI::NETHER_BRICK_BLOCK>(),
            make_pair_checked<BI::LOWER_NETHER_BRICK_SLAB, BI::NETHER_BRICK_BLOCK>(),
            make_pair_checked<BI::UPPER_NETHER_BRICK_SLAB, BI::NETHER_BRICK_BLOCK>(),
            make_pair_checked<BI::DRAGON_EGG, BI::DIAMOND_BLOCK>(),
            make_pair_checked<BI::DOUBLE_SPRUCE_WOOD_SLAB, BI::DOUBLE_OAK_WOOD_SLAB>(),
            make_pair_checked<BI::DOUBLE_BIRCH_WOOD_SLAB, BI::DOUBLE_OAK_WOOD_SLAB>(),
            make_pair_checked<BI::LOWER_SPRUCE_WOOD_SLAB, BI::LOWER_OAK_WOOD_SLAB>(),
            make_pair_checked<BI::LOWER_BIRCH_WOOD_SLAB, BI::LOWER_OAK_WOOD_SLAB>(),
            make_pair_checked<BI::UPPER_SPRUCE_WOOD_SLAB, BI::UPPER_OAK_WOOD_SLAB>(),
            make_pair_checked<BI::UPPER_BIRCH_WOOD_SLAB, BI::UPPER_OAK_WOOD_SLAB>(),
            make_pair_checked<BI::WOODEN_BUTTON, BI::LEVER>(),
            make_pair_checked<BI::SANDSTONE_STAIRS, BI::SANDSTONE>(),
            make_pair_checked<BI::SPRUCE_WOOD_STAIRS, BI::OAK_WOOD_STAIRS>(),
            make_pair_checked<BI::BIRCH_WOOD_STAIRS, BI::OAK_WOOD_STAIRS>(),
        
        
            // ################ TU12 #################
            make_pair_checked<BI::JUNGLE_WOOD_PLANK, BI::OAK_WOOD_PLANK>(),
            make_pair_checked<BI::JUNGLE_SAPLING, BI::OAK_SAPLING>(),
            make_pair_checked<BI::JUNGLE_WOOD, BI::OAK_WOOD>(),
            make_pair_checked<BI::JUNGLE_LEAVES, BI::OAK_LEAVES>(),
            make_pair_checked<BI::CHISELED_STONE_BRICKS, BI::STONE_BRICKS>(),
            make_pair_checked<BI::INACTIVE_REDSTONE_LAMP, BI::GLOWSTONE>(),
            make_pair_checked<BI::ACTIVE_REDSTONE_LAMP, BI::GLOWSTONE>(),
            make_pair_checked<BI::DOUBLE_JUNGLE_WOOD_SLAB, BI::DOUBLE_OAK_WOOD_SLAB>(),
            make_pair_checked<BI::LOWER_JUNGLE_WOOD_SLAB, BI::LOWER_OAK_WOOD_SLAB>(),
            make_pair_checked<BI::UPPER_JUNGLE_WOOD_SLAB, BI::UPPER_OAK_WOOD_SLAB>(),
            make_pair_checked<BI::MOB_HEAD, BI::WHITE_WOOL>(),
            make_pair_checked<BI::COCOA, BI::BROWN_WOOL>(),
            make_pair_checked<BI::JUNGLE_WOOD_STAIRS, BI::OAK_WOOD_STAIRS>(),
        
        
        
            // ################ TU14 #################
            make_pair_checked<BI::EMERALD_ORE, BI::DIAMOND_ORE>(),
            make_pair_checked<BI::ENDER_CHEST, BI::CHEST>(),
            make_pair_checked<BI::TRIPWIRE_HOOK, BI::AIR>(),
            make_pair_checked<BI::TRIPWIRE, BI::AIR>(),
            make_pair_checked<BI::EMERALD_BLOCK, BI::DIAMOND_BLOCK>(),
            make_pair_checked<BI::COBBLESTONE_WALL, BI::COBBLESTONE>(),
            make_pair_checked<BI::MOSSY_COBBLESTONE_WALL, BI::MOSS_STONE>(),
            
            make_pair_checked<BI::WHITE_CARPET, BI::AIR>(),
            make_pair_checked<BI::ORANGE_CARPET, BI::AIR>(),
            make_pair_checked<BI::MAGENTA_CARPET, BI::AIR>(),
            make_pair_checked<BI::LIGHT_BLUE_CARPET, BI::AIR>(),
            make_pair_checked<BI::YELLOW_CARPET, BI::AIR>(),
            make_pair_checked<BI::LIME_CARPET, BI::AIR>(),
            make_pair_checked<BI::PINK_CARPET, BI::AIR>(),
            make_pair_checked<BI::GRAY_CARPET, BI::AIR>(),
            make_pair_checked<BI::LIGHT_GRAY_CARPET, BI::AIR>(),
            make_pair_checked<BI::CYAN_CARPET, BI::AIR>(),
            make_pair_checked<BI::PURPLE_CARPET, BI::AIR>(),
            make_pair_checked<BI::BLUE_CARPET, BI::AIR>(),
            make_pair_checked<BI::BROWN_CARPET, BI::AIR>(),
            make_pair_checked<BI::GREEN_CARPET, BI::AIR>(),
            make_pair_checked<BI::RED_CARPET, BI::AIR>(),
            make_pair_checked<BI::BLACK_CARPET, BI::AIR>(),

            make_pair_checked<BI::FLOWER_POT, BI::AIR>(),
            make_pair_checked<BI::CARROTS, BI::WHEAT_CROPS>(),
            make_pair_checked<BI::POTATOES, BI::WHEAT_CROPS>(),
            make_pair_checked<BI::ANVIL, BI::IRON_BLOCK>(),
            make_pair_checked<BI::SLIGHTLY_DAMAGED_ANVIL, BI::IRON_BLOCK>(),
            make_pair_checked<BI::VERY_DAMAGED_ANVIL, BI::IRON_BLOCK>(),
            make_pair_checked<BI::NETHER_QUARTZ_ORE, BI::NETHERRACK>(),
            make_pair_checked<BI::QUARTZ_BLOCK, BI::STONE_BRICKS>(),
            make_pair_checked<BI::QUARTZ_CHISELED_BLOCK, BI::CHISELED_STONE_BRICKS>(),
            make_pair_checked<BI::QUARTZ_PILLAR_BLOCK_1, BI::CRACKED_STONE_BRICKS>(),
            make_pair_checked<BI::QUARTZ_PILLAR_BLOCK_2, BI::CRACKED_STONE_BRICKS>(),
            make_pair_checked<BI::QUARTZ_PILLAR_BLOCK_3, BI::CRACKED_STONE_BRICKS>(),
            make_pair_checked<BI::QUARTZ_STAIRS, BI::COBBLESTONE_STAIRS>(),
            make_pair_checked<BI::DOUBLE_QUARTZ_SLAB, BI::DOUBLE_STONE_BRICK_SLAB>(),
            make_pair_checked<BI::LOWER_QUARTZ_SLAB, BI::LOWER_STONE_BRICK_SLAB>(),
            make_pair_checked<BI::UPPER_QUARTZ_SLAB, BI::UPPER_STONE_BRICK_SLAB>(),
        
        
            // ################ TU19 #################
            make_pair_checked<BI::COMMAND_BLOCK, BI::ORANGE_WOOL>(),
            make_pair_checked<BI::BEACON, BI::GLASS>(),
            make_pair_checked<BI::TRAPPED_CHEST, BI::CHEST>(),
            make_pair_checked<BI::LIGHT_WEIGHTED_PRESSURE_PLATE, BI::STONE_PRESSURE_PLATE>(),
            make_pair_checked<BI::HEAVY_WEIGHTED_PRESSURE_PLATE, BI::STONE_PRESSURE_PLATE>(),
            make_pair_checked<BI::INACTIVE_REDSTONE_COMPARATOR, BI::OFF_REDSTONE_REPEATER_BLOCK>(),
            make_pair_checked<BI::ACTIVE_REDSTONE_COMPARATOR, BI::ON_REDSTONE_REPEATER_BLOCK>(),
            make_pair_checked<BI::DAYLIGHT_SENSOR, BI::LOWER_OAK_WOOD_SLAB>(),
            make_pair_checked<BI::REDSTONE_BLOCK, BI::RED_WOOL>(),
            make_pair_checked<BI::HOPPER, BI::DISPENSER>(),
            make_pair_checked<BI::ACTIVATOR_RAIL, BI::POWERED_RAIL>(),
            make_pair_checked<BI::DROPPER, BI::DISPENSER>(),

            make_pair_checked<BI::WHITE_HARDENED_CLAY, BI::WHITE_WOOL>(),
            make_pair_checked<BI::ORANGE_HARDENED_CLAY, BI::ORANGE_WOOL>(),
            make_pair_checked<BI::MAGENTA_HARDENED_CLAY, BI::MAGENTA_WOOL>(),
            make_pair_checked<BI::LIGHT_BLUE_HARDENED_CLAY, BI::LIGHT_BLUE_WOOL>(),
            make_pair_checked<BI::YELLOW_HARDENED_CLAY, BI::YELLOW_WOOL>(),
            make_pair_checked<BI::LIME_HARDENED_CLAY, BI::LIME_WOOL>(),
            make_pair_checked<BI::PINK_HARDENED_CLAY, BI::PINK_WOOL>(),
            make_pair_checked<BI::GRAY_HARDENED_CLAY, BI::GRAY_WOOL>(),
            make_pair_checked<BI::LIGHT_GRAY_HARDENED_CLAY, BI::LIGHT_GRAY_WOOL>(),
            make_pair_checked<BI::CYAN_HARDENED_CLAY, BI::CYAN_WOOL>(),
            make_pair_checked<BI::PURPLE_HARDENED_CLAY, BI::PURPLE_WOOL>(),
            make_pair_checked<BI::BLUE_HARDENED_CLAY, BI::BLUE_WOOL>(),
            make_pair_checked<BI::BROWN_HARDENED_CLAY, BI::BROWN_WOOL>(),
            make_pair_checked<BI::GREEN_HARDENED_CLAY, BI::GREEN_WOOL>(),
            make_pair_checked<BI::RED_HARDENED_CLAY, BI::RED_WOOL>(),
            make_pair_checked<BI::BLACK_HARDENED_CLAY, BI::BLACK_WOOL>(),

            make_pair_checked<BI::HAY_BALE, BI::YELLOW_WOOL>(),
            make_pair_checked<BI::HARDENED_CLAY, BI::WHITE_WOOL>(),
            make_pair_checked<BI::BLOCK_OF_COAL, BI::IRON_BLOCK>(),
            make_pair_checked<BI::INVERTED_DAYLIGHT_SENSOR, BI::LOWER_OAK_WOOD_SLAB>(),


            // ################ TU25 #################
            make_pair_checked<BI::WHITE_STAINED_GLASS, BI::GLASS>(),
            make_pair_checked<BI::ORANGE_STAINED_GLASS, BI::GLASS>(),
            make_pair_checked<BI::MAGENTA_STAINED_GLASS, BI::GLASS>(),
            make_pair_checked<BI::LIGHT_BLUE_STAINED_GLASS, BI::GLASS>(),
            make_pair_checked<BI::YELLOW_STAINED_GLASS, BI::GLASS>(),
            make_pair_checked<BI::LIME_STAINED_GLASS, BI::GLASS>(),
            make_pair_checked<BI::PINK_STAINED_GLASS, BI::GLASS>(),
            make_pair_checked<BI::GRAY_STAINED_GLASS, BI::GLASS>(),
            make_pair_checked<BI::LIGHT_GRAY_STAINED_GLASS, BI::GLASS>(),
            make_pair_checked<BI::CYAN_STAINED_GLASS, BI::GLASS>(),
            make_pair_checked<BI::PURPLE_STAINED_GLASS, BI::GLASS>(),
            make_pair_checked<BI::BLUE_STAINED_GLASS, BI::GLASS>(),
            make_pair_checked<BI::BROWN_STAINED_GLASS, BI::GLASS>(),
            make_pair_checked<BI::GREEN_STAINED_GLASS, BI::GLASS>(),
            make_pair_checked<BI::RED_STAINED_GLASS, BI::GLASS>(),
            make_pair_checked<BI::BLACK_STAINED_GLASS, BI::GLASS>(),

            make_pair_checked<BI::WHITE_STAINED_GLASS_PANE, BI::GLASS_PANE>(),
            make_pair_checked<BI::ORANGE_STAINED_GLASS_PANE, BI::GLASS_PANE>(),
            make_pair_checked<BI::MAGENTA_STAINED_GLASS_PANE, BI::GLASS_PANE>(),
            make_pair_checked<BI::LIGHT_BLUE_STAINED_GLASS_PANE, BI::GLASS_PANE>(),
            make_pair_checked<BI::YELLOW_STAINED_GLASS_PANE, BI::GLASS_PANE>(),
            make_pair_checked<BI::LIME_STAINED_GLASS_PANE, BI::GLASS_PANE>(),
            make_pair_checked<BI::PINK_STAINED_GLASS_PANE, BI::GLASS_PANE>(),
            make_pair_checked<BI::GRAY_STAINED_GLASS_PANE, BI::GLASS_PANE>(),
            make_pair_checked<BI::LIGHT_GRAY_STAINED_GLASS_PANE, BI::GLASS_PANE>(),
            make_pair_checked<BI::CYAN_STAINED_GLASS_PANE, BI::GLASS_PANE>(),
            make_pair_checked<BI::PURPLE_STAINED_GLASS_PANE, BI::GLASS_PANE>(),
            make_pair_checked<BI::BLUE_STAINED_GLASS_PANE, BI::GLASS_PANE>(),
            make_pair_checked<BI::BROWN_STAINED_GLASS_PANE, BI::GLASS_PANE>(),
            make_pair_checked<BI::GREEN_STAINED_GLASS_PANE, BI::GLASS_PANE>(),
            make_pair_checked<BI::RED_STAINED_GLASS_PANE, BI::GLASS_PANE>(),
            make_pair_checked<BI::BLACK_STAINED_GLASS_PANE, BI::GLASS_PANE>(),

            make_pair_checked<BI::ACACIA_WOOD_PLANK, BI::BIRCH_WOOD_PLANK>(),
            make_pair_checked<BI::DARK_OAK_WOOD_PLANK, BI::OAK_WOOD_PLANK>(),
            make_pair_checked<BI::ACACIA_WOOD, BI::BIRCH_WOOD>(),
            make_pair_checked<BI::DARK_OAK_WOOD, BI::OAK_WOOD>(),
            make_pair_checked<BI::ACACIA_WOOD_STAIRS, BI::BIRCH_WOOD_STAIRS>(),
            make_pair_checked<BI::DARK_OAK_WOOD_STAIRS, BI::OAK_WOOD_STAIRS>(),
            make_pair_checked<BI::IRON_TRAPDOOR, BI::WOODEN_TRAPDOOR>(),
            make_pair_checked<BI::DOUBLE_ACACIA_WOOD_SLAB, BI::DOUBLE_BIRCH_WOOD_SLAB>(),
            make_pair_checked<BI::DOUBLE_DARK_OAK_WOOD_SLAB, BI::DOUBLE_OAK_WOOD_SLAB>(),
            make_pair_checked<BI::LOWER_ACACIA_WOOD_SLAB, BI::LOWER_BIRCH_WOOD_SLAB>(),
            make_pair_checked<BI::LOWER_DARK_OAK_WOOD_SLAB, BI::LOWER_OAK_WOOD_SLAB>(),
            make_pair_checked<BI::UPPER_ACACIA_WOOD_SLAB, BI::UPPER_BIRCH_WOOD_SLAB>(),
            make_pair_checked<BI::UPPER_DARK_OAK_WOOD_SLAB, BI::UPPER_OAK_WOOD_SLAB>(),
            make_pair_checked<BI::SPRUCE_FENCE_GATE, BI::OAK_FENCE_GATE>(),
            make_pair_checked<BI::BIRCH_FENCE_GATE, BI::OAK_FENCE_GATE>(),
            make_pair_checked<BI::JUNGLE_FENCE_GATE, BI::OAK_FENCE_GATE>(),
            make_pair_checked<BI::DARK_OAK_FENCE_GATE, BI::OAK_FENCE_GATE>(),
            make_pair_checked<BI::ACACIA_FENCE_GATE, BI::OAK_FENCE_GATE>(),
            make_pair_checked<BI::SPRUCE_FENCE, BI::OAK_FENCE>(),
            make_pair_checked<BI::BIRCH_FENCE, BI::OAK_FENCE>(),
            make_pair_checked<BI::JUNGLE_FENCE, BI::OAK_FENCE>(),
            make_pair_checked<BI::DARK_OAK_FENCE, BI::OAK_FENCE>(),
            make_pair_checked<BI::ACACIA_FENCE, BI::OAK_FENCE>(),
            make_pair_checked<BI::SPRUCE_DOOR_BLOCK, BI::OAK_DOOR_BLOCK>(),
            make_pair_checked<BI::BIRCH_DOOR_BLOCK, BI::OAK_DOOR_BLOCK>(),
            make_pair_checked<BI::JUNGLE_DOOR_BLOCK, BI::OAK_DOOR_BLOCK>(),
            make_pair_checked<BI::ACACIA_DOOR_BLOCK, BI::OAK_DOOR_BLOCK>(),
            make_pair_checked<BI::DARK_OAK_DOOR_BLOCK, BI::OAK_DOOR_BLOCK>(),
        

            // ################ TU31 #################
            make_pair_checked<BI::GRANITE, BI::STONE>(),
            make_pair_checked<BI::POLISHED_GRANITE, BI::STONE>(),
            make_pair_checked<BI::DIORITE, BI::STONE>(),
            make_pair_checked<BI::POLISHED_DIORITE, BI::STONE>(),
            make_pair_checked<BI::ANDESITE, BI::STONE>(),
            make_pair_checked<BI::POLISHED_ANDESITE, BI::STONE>(),
            make_pair_checked<BI::COARSE_DIRT, BI::DIRT>(),
            make_pair_checked<BI::PODZOL, BI::DIRT>(),
            make_pair_checked<BI::ACACIA_SAPLING, BI::OAK_SAPLING>(),
            make_pair_checked<BI::DARK_OAK_SAPLING, BI::OAK_SAPLING>(),
            make_pair_checked<BI::RED_SAND, BI::SAND>(),
            make_pair_checked<BI::SPONGE, BI::GOLD_BLOCK>(),
            make_pair_checked<BI::WET_SPONGE, BI::GOLD_BLOCK>(),
            make_pair_checked<BI::BLUE_ORCHID, BI::POPPY>(),
            make_pair_checked<BI::ALLIUM, BI::POPPY>(),
            make_pair_checked<BI::AZURE_BLUET, BI::POPPY>(),
            make_pair_checked<BI::RED_TULIP, BI::POPPY>(),
            make_pair_checked<BI::ORANGE_TULIP, BI::POPPY>(),
            make_pair_checked<BI::WHITE_TULIP, BI::POPPY>(),
            make_pair_checked<BI::PINK_TULIP, BI::POPPY>(),
            make_pair_checked<BI::OXEYE_DAISY, BI::POPPY>(),
            make_pair_checked<BI::MOSSY_STONE_MONSTER_EGG, BI::MOSSY_STONE_BRICKS>(),
            make_pair_checked<BI::CRACKED_STONE_BRICK_MONSTER_EGG, BI::CRACKED_STONE_BRICKS>(),
            make_pair_checked<BI::CHISELED_STONE_BRICK_MONSTER_EGG, BI::CHISELED_STONE_BRICKS>(),
            make_pair_checked<BI::ACACIA_LEAVES, BI::BIRCH_LEAVES>(),
            make_pair_checked<BI::DARK_OAK_LEAVES, BI::OAK_LEAVES>(),
            make_pair_checked<BI::SLIME_BLOCK, BI::LIME_WOOL>(),
            make_pair_checked<BI::BARRIER, BI::AIR>(),
            make_pair_checked<BI::PRISMARINE, BI::BRICKS>(),
            make_pair_checked<BI::PRISMARINE_BRICKS, BI::BRICKS>(),
            make_pair_checked<BI::DARK_PRISMARINE, BI::BRICKS>(),
            make_pair_checked<BI::SEA_LANTERN, BI::GLOWSTONE>(),
            make_pair_checked<BI::PACKED_ICE, BI::ICE>(),
            make_pair_checked<BI::SUNFLOWER, BI::WHITE_WOOL>(), // todo FIND SOMETHING BETTER
            make_pair_checked<BI::LILAC, BI::ORANGE_WOOL>(), // todo FIND SOMETHING BETTER
            make_pair_checked<BI::DOUBLE_TALLGRASS, BI::TALL_GRASS_GRASS>(),
            make_pair_checked<BI::LARGE_FERN, BI::TALL_GRASS_FERN>(),
            make_pair_checked<BI::ROSE_BUSH, BI::RED_WOOL>(), // todo FIND SOMETHING BETTER
            make_pair_checked<BI::PEONY, BI::BLUE_WOOL>(), // todo FIND SOMETHING BETTER
            make_pair_checked<BI::RED_SANDSTONE, BI::SANDSTONE>(),
            make_pair_checked<BI::CHISELED_RED_SANDSTONE, BI::CHISELED_SANDSTONE>(),
            make_pair_checked<BI::SMOOTH_RED_SANDSTONE, BI::SMOOTH_SANDSTONE>(),
            make_pair_checked<BI::RED_SANDSTONE_STAIRS, BI::SANDSTONE_STAIRS>(),


        
        
            // ################ TU43 #################
            make_pair_checked<BI::FREE_STANDING_BANNER, BI::AIR>(),
            make_pair_checked<BI::WALL_MOUNTED_BANNER, BI::AIR>(),
            make_pair_checked<BI::END_STONE_BRICKS, BI::STONE_BRICKS>(),
            make_pair_checked<BI::BEETROOT_BLOCK, BI::CARROTS>(),
            make_pair_checked<BI::GRASS_PATH, BI::GRAVEL>(),
            make_pair_checked<BI::FROSTED_ICE, BI::ICE>(),
            make_pair_checked<BI::MAGMA_BLOCK, BI::STILL_LAVA>(),
            make_pair_checked<BI::NETHER_WART_BLOCK, BI::NETHERRACK>(),
            make_pair_checked<BI::RED_NETHER_BRICK, BI::NETHER_BRICK_BLOCK>(),
            make_pair_checked<BI::BONE_BLOCK, BI::IRON_BLOCK>(),
 
        
            // ################ TU46 #################
            make_pair_checked<BI::END_ROD, BI::IRON_BARS>(),
            make_pair_checked<BI::CHORUS_PLANT, BI::DIRT>(),
            make_pair_checked<BI::CHORUS_FLOWER, BI::POTTED_CACTUS>(),
            make_pair_checked<BI::PURPUR_BLOCK, BI::QUARTZ_BLOCK>(),
            make_pair_checked<BI::PURPUR_PILLAR, BI::QUARTZ_PILLAR_BLOCK_1>(),
            make_pair_checked<BI::PURPUR_STAIRS, BI::QUARTZ_STAIRS>(),
            make_pair_checked<BI::DOUBLE_PURPUR_SLAB, BI::DOUBLE_QUARTZ_SLAB>(),
            make_pair_checked<BI::LOWER_PURPUR_SLAB, BI::LOWER_QUARTZ_SLAB>(),
            make_pair_checked<BI::END_GATEWAY, BI::BLACK_WOOL>(),
        
        
            // ################ TU53 #################
            make_pair_checked<BI::WHITE_SHULKER_BOX, BI::CHEST>(),
            make_pair_checked<BI::ORANGE_SHULKER_BOX, BI::CHEST>(),
            make_pair_checked<BI::MAGENTA_SHULKER_BOX, BI::CHEST>(),
            make_pair_checked<BI::LIGHT_BLUE_SHULKER_BOX, BI::CHEST>(),
            make_pair_checked<BI::YELLOW_SHULKER_BOX, BI::CHEST>(),
            make_pair_checked<BI::LIME_SHULKER_BOX, BI::CHEST>(),
            make_pair_checked<BI::PINK_SHULKER_BOX, BI::CHEST>(),
            make_pair_checked<BI::GRAY_SHULKER_BOX, BI::CHEST>(),
            make_pair_checked<BI::LIGHT_GRAY_SHULKER_BOX, BI::CHEST>(),
            make_pair_checked<BI::CYAN_SHULKER_BOX, BI::CHEST>(),
            make_pair_checked<BI::PURPLE_SHULKER_BOX, BI::CHEST>(),
            make_pair_checked<BI::BLUE_SHULKER_BOX, BI::CHEST>(),
            make_pair_checked<BI::BROWN_SHULKER_BOX, BI::CHEST>(),
            make_pair_checked<BI::GREEN_SHULKER_BOX, BI::CHEST>(),
            make_pair_checked<BI::RED_SHULKER_BOX, BI::CHEST>(),
            make_pair_checked<BI::BLACK_SHULKER_BOX, BI::CHEST>(),
            make_pair_checked<BI::WHITE_GLAZED_TERRACOTTA, BI::WHITE_WOOL>(),
            make_pair_checked<BI::ORANGE_GLAZED_TERRACOTTA, BI::ORANGE_WOOL>(),
            make_pair_checked<BI::MAGENTA_GLAZED_TERRACOTTA, BI::MAGENTA_WOOL>(),
            make_pair_checked<BI::LIGHT_BLUE_GLAZED_TERRACOTTA, BI::LIGHT_BLUE_WOOL>(),
            make_pair_checked<BI::YELLOW_GLAZED_TERRACOTTA, BI::YELLOW_WOOL>(),
            make_pair_checked<BI::LIME_GLAZED_TERRACOTTA, BI::LIME_WOOL>(),
            make_pair_checked<BI::PINK_GLAZED_TERRACOTTA, BI::PINK_WOOL>(),
            make_pair_checked<BI::GRAY_GLAZED_TERRACOTTA, BI::GRAY_WOOL>(),
            make_pair_checked<BI::LIGHT_GRAY_GLAZED_TERRACOTTA, BI::LIGHT_GRAY_WOOL>(),
            make_pair_checked<BI::CYAN_GLAZED_TERRACOTTA, BI::CYAN_WOOL>(),
            make_pair_checked<BI::PURPLE_GLAZED_TERRACOTTA, BI::PURPLE_WOOL>(),
            make_pair_checked<BI::BLUE_GLAZED_TERRACOTTA, BI::BLUE_WOOL>(),
            make_pair_checked<BI::BROWN_GLAZED_TERRACOTTA, BI::BROWN_WOOL>(),
            make_pair_checked<BI::GREEN_GLAZED_TERRACOTTA, BI::GREEN_WOOL>(),
            make_pair_checked<BI::RED_GLAZED_TERRACOTTA, BI::RED_WOOL>(),
            make_pair_checked<BI::BLACK_GLAZED_TERRACOTTA, BI::BLACK_WOOL>(),
            make_pair_checked<BI::WHITE_CONCRETE, BI::WHITE_WOOL>(),
            make_pair_checked<BI::ORANGE_CONCRETE, BI::ORANGE_WOOL>(),
            make_pair_checked<BI::MAGENTA_CONCRETE, BI::MAGENTA_WOOL>(),
            make_pair_checked<BI::LIGHT_BLUE_CONCRETE, BI::LIGHT_BLUE_WOOL>(),
            make_pair_checked<BI::YELLOW_CONCRETE, BI::YELLOW_WOOL>(),
            make_pair_checked<BI::LIME_CONCRETE, BI::LIME_WOOL>(),
            make_pair_checked<BI::PINK_CONCRETE, BI::PINK_WOOL>(),
            make_pair_checked<BI::GRAY_CONCRETE, BI::GRAY_WOOL>(),
            make_pair_checked<BI::LIGHT_GRAY_CONCRETE, BI::LIGHT_GRAY_WOOL>(),
            make_pair_checked<BI::CYAN_CONCRETE, BI::CYAN_WOOL>(),
            make_pair_checked<BI::PURPLE_CONCRETE, BI::PURPLE_WOOL>(),
            make_pair_checked<BI::BLUE_CONCRETE, BI::BLUE_WOOL>(),
            make_pair_checked<BI::BROWN_CONCRETE, BI::BROWN_WOOL>(),
            make_pair_checked<BI::GREEN_CONCRETE, BI::GREEN_WOOL>(),
            make_pair_checked<BI::RED_CONCRETE, BI::RED_WOOL>(),
            make_pair_checked<BI::BLACK_CONCRETE, BI::BLACK_WOOL>(),
            make_pair_checked<BI::WHITE_CONCRETE_POWDER, BI::WHITE_WOOL>(),
            make_pair_checked<BI::ORANGE_CONCRETE_POWDER, BI::ORANGE_WOOL>(),
            make_pair_checked<BI::MAGENTA_CONCRETE_POWDER, BI::MAGENTA_WOOL>(),
            make_pair_checked<BI::LIGHT_BLUE_CONCRETE_POWDER, BI::LIGHT_BLUE_WOOL>(),
            make_pair_checked<BI::YELLOW_CONCRETE_POWDER, BI::YELLOW_WOOL>(),
            make_pair_checked<BI::LIME_CONCRETE_POWDER, BI::LIME_WOOL>(),
            make_pair_checked<BI::PINK_CONCRETE_POWDER, BI::PINK_WOOL>(),
            make_pair_checked<BI::GRAY_CONCRETE_POWDER, BI::GRAY_WOOL>(),
            make_pair_checked<BI::LIGHT_GRAY_CONCRETE_POWDER, BI::LIGHT_GRAY_WOOL>(),
            make_pair_checked<BI::CYAN_CONCRETE_POWDER, BI::CYAN_WOOL>(),
            make_pair_checked<BI::PURPLE_CONCRETE_POWDER, BI::PURPLE_WOOL>(),
            make_pair_checked<BI::BLUE_CONCRETE_POWDER, BI::BLUE_WOOL>(),
            make_pair_checked<BI::BROWN_CONCRETE_POWDER, BI::BROWN_WOOL>(),
            make_pair_checked<BI::GREEN_CONCRETE_POWDER, BI::GREEN_WOOL>(),
            make_pair_checked<BI::RED_CONCRETE_POWDER, BI::RED_WOOL>(),
            make_pair_checked<BI::BLACK_CONCRETE_POWDER, BI::BLACK_WOOL>(),
        
        
            // ################ TU54 #################
            make_pair_checked<BI::OBSERVER, BI::DISPENSER>(),
        
        
            // ################ TU UNKNOWN #################
            make_pair_checked<BI::REPEATING_COMMAND_BLOCK, BI::AIR>(),
            make_pair_checked<BI::CHAIN_COMMAND_BLOCK, BI::AIR>(),
            make_pair_checked<BI::STRUCTURE_VOID, BI::AIR>(),
            make_pair_checked<BI::STRUCTURE_BLOCK, BI::AIR>(),
        
        
        
            // ################ TU69 #################
            make_pair_checked<BI::CONDUIT, BI::MOB_HEAD>(),
            make_pair_checked<BI::UNKNOWN_PUMP, BI::CARVED_PUMPKIN>(),
            make_pair_checked<BI::KELP, BI::STILL_WATER>(),
            make_pair_checked<BI::CORAL_BLOCK, BI::STILL_WATER>(),
            make_pair_checked<BI::CORAL, BI::STILL_WATER>(),
            make_pair_checked<BI::CORAL_FAN, BI::STILL_WATER>(),
            make_pair_checked<BI::CORAL_FAN_DEAD, BI::STILL_WATER>(),
            make_pair_checked<BI::CORAL_FAN_WALL1, BI::STILL_WATER>(),
            make_pair_checked<BI::CORAL_FAN_WALL2, BI::STILL_WATER>(),
            make_pair_checked<BI::CORAL_FAN_WALL3, BI::STILL_WATER>(),
            make_pair_checked<BI::DRIED_KELP_BLOCK, BI::GREEN_CONCRETE>(),
            make_pair_checked<BI::SEAGRASS, BI::STILL_WATER>(),
            make_pair_checked<BI::SEAPICKLE, BI::STILL_WATER>(),
            make_pair_checked<BI::BUBBLE_COLUMN, BI::STILL_WATER>(),
            make_pair_checked<BI::BLUE_ICE, BI::ICE>(),
            make_pair_checked<BI::SPRUCE_TRAPDOOR, BI::WOODEN_TRAPDOOR>(),
            make_pair_checked<BI::BIRCH_TRAPDOOR, BI::WOODEN_TRAPDOOR>(),
            make_pair_checked<BI::JUNGLE_TRAPDOOR, BI::WOODEN_TRAPDOOR>(),
            make_pair_checked<BI::ACACIA_TRAPDOOR, BI::WOODEN_TRAPDOOR>(),
            make_pair_checked<BI::DARK_OAK_TRAPDOOR, BI::WOODEN_TRAPDOOR>(),
            make_pair_checked<BI::TURTLE_EGG, BI::MOB_HEAD>(),
            make_pair_checked<BI::PRISMARINE_STAIRS, BI::PRISMARINE>(),
            make_pair_checked<BI::PRISMARINE_BRICK_STAIRS, BI::PRISMARINE_BRICKS>(),
            make_pair_checked<BI::DARK_PRISMARINE_STAIRS, BI::DARK_PRISMARINE>(),
            make_pair_checked<BI::STRIPPED_SPRUCE_LOG, BI::SPRUCE_WOOD>(),
            make_pair_checked<BI::STRIPPED_BIRCH_LOG, BI::BIRCH_WOOD>(),
            make_pair_checked<BI::STRIPPED_JUNGLE_LOG, BI::JUNGLE_WOOD>(),
            make_pair_checked<BI::STRIPPED_ACACIA_LOG, BI::ACACIA_WOOD>(),
            make_pair_checked<BI::STRIPPED_DARK_OAK_LOG, BI::DARK_OAK_WOOD>(),
            make_pair_checked<BI::STRIPPED_OAK_LOG, BI::OAK_WOOD>(),
            make_pair_checked<BI::ACACIA_PRESSURE_PLATE, BI::WOODEN_PRESSURE_PLATE>(),
            make_pair_checked<BI::BIRCH_PRESSURE_PLATE, BI::WOODEN_PRESSURE_PLATE>(),
            make_pair_checked<BI::DARK_OAK_PRESSURE_PLATE, BI::WOODEN_PRESSURE_PLATE>(),
            make_pair_checked<BI::JUNGLE_PRESSURE_PLATE, BI::WOODEN_PRESSURE_PLATE>(),
            make_pair_checked<BI::SPRUCE_PRESSURE_PLATE, BI::WOODEN_PRESSURE_PLATE>(),
            make_pair_checked<BI::ACACIA_BUTTON, BI::WOODEN_BUTTON>(),
            make_pair_checked<BI::BIRCH_BUTTON, BI::WOODEN_BUTTON>(),
            make_pair_checked<BI::DARK_OAK_BUTTON, BI::WOODEN_BUTTON>(),
            make_pair_checked<BI::JUNGLE_BUTTON, BI::WOODEN_BUTTON>(),
            make_pair_checked<BI::SPRUCE_BUTTON, BI::WOODEN_BUTTON>(),

            make_pair_checked<BI::OAK_WOOD_Y, BI::OAK_WOOD>(),
            make_pair_checked<BI::SPRUCE_WOOD_Y, BI::SPRUCE_WOOD>(),
            make_pair_checked<BI::BIRCH_WOOD_Y, BI::BIRCH_WOOD>(),
            make_pair_checked<BI::JUNGLE_WOOD_Y, BI::JUNGLE_WOOD>(),
            make_pair_checked<BI::ACACIA_WOOD_Y, BI::ACACIA_WOOD>(),
            make_pair_checked<BI::DARK_OAK_WOOD_Y, BI::DARK_OAK_WOOD>(),

            make_pair_checked<BI::OAK_WOOD_Y2, BI::OAK_WOOD>(),
            make_pair_checked<BI::SPRUCE_WOOD_Y2, BI::SPRUCE_WOOD>(),
            make_pair_checked<BI::BIRCH_WOOD_Y2, BI::BIRCH_WOOD>(),
            make_pair_checked<BI::JUNGLE_WOOD_Y2, BI::JUNGLE_WOOD>(),
            make_pair_checked<BI::ACACIA_WOOD_Y2, BI::ACACIA_WOOD>(),
            make_pair_checked<BI::DARK_OAK_WOOD_Y2, BI::DARK_OAK_WOOD>(),



        
        
            // ################ TU83 #################
            make_pair_checked<BI::BAMBOO, BI::SUGAR_CANES>(),
            make_pair_checked<BI::SCAFFOLDING, BI::OAK_WOOD_PLANK>(),
            make_pair_checked<BI::BAMBOO_SAPLING, BI::SUGAR_CANES>(),
        
        
        
        
            // ################ TU88 #################
            make_pair_checked<BI::CORNFLOWER, BI::POPPY>(),
            make_pair_checked<BI::LILY_OF_THE_VALLEY, BI::POPPY>(),
            make_pair_checked<BI::DOUBLE_SMOOTH_SANDSTONE_SLAB, BI::DOUBLE_SANDSTONE_SLAB>(),
            make_pair_checked<BI::DOUBLE_SMOOTH_QUARTZ_SLAB, BI::QUARTZ_BLOCK>(),
            make_pair_checked<BI::BRICK_WALL, BI::COBBLESTONE_WALL>(),
            make_pair_checked<BI::STONE_BRICK_WALL, BI::COBBLESTONE_WALL>(),
            make_pair_checked<BI::MOSSY_STONE_BRICK_WALL, BI::COBBLESTONE_WALL>(),
            make_pair_checked<BI::ANDESITE_WALL, BI::COBBLESTONE_WALL>(),
            make_pair_checked<BI::DIORITE_WALL, BI::COBBLESTONE_WALL>(),
            make_pair_checked<BI::GRANITE_WALL, BI::COBBLESTONE_WALL>(),
            make_pair_checked<BI::SANDSTONE_WALL, BI::COBBLESTONE_WALL>(),
            make_pair_checked<BI::RED_SANDSTONE_WALL, BI::COBBLESTONE_WALL>(),
            make_pair_checked<BI::NETHER_BRICK_WALL, BI::COBBLESTONE_WALL>(),
            make_pair_checked<BI::RED_NETHER_BRICK_WALL, BI::COBBLESTONE_WALL>(),
            make_pair_checked<BI::END_STONE_BRICK_WALL, BI::COBBLESTONE_WALL>(),
            make_pair_checked<BI::PRISMARINE_WALL, BI::COBBLESTONE_WALL>(),
            make_pair_checked<BI::DOUBLE_RED_SANDSTONE_SLAB, BI::RED_SANDSTONE>(),
            make_pair_checked<BI::DOUBLE_SMOOTH_RED_SANDSTONE_SLAB, BI::SMOOTH_RED_SANDSTONE>(),
            make_pair_checked<BI::DOUBLE_POLISHED_ANDESITE_SLAB, BI::POLISHED_ANDESITE>(),
            make_pair_checked<BI::DOUBLE_ANDESITE_SLAB, BI::ANDESITE>(),
            make_pair_checked<BI::DOUBLE_DIORITE_SLAB, BI::DIORITE>(),
            make_pair_checked<BI::DOUBLE_POLISHED_DIORITE_SLAB, BI::POLISHED_DIORITE>(),
            make_pair_checked<BI::DOUBLE_GRANITE_SLAB, BI::GRANITE>(),
            make_pair_checked<BI::DOUBLE_POLISHED_GRANITE_SLAB, BI::POLISHED_GRANITE>(),
            make_pair_checked<BI::LOWER_RED_SANDSTONE_SLAB, BI::RED_SANDSTONE>(),
            make_pair_checked<BI::LOWER_SMOOTH_RED_SANDSTONE_SLAB, BI::SMOOTH_RED_SANDSTONE>(),
            make_pair_checked<BI::LOWER_POLISHED_ANDESITE_SLAB, BI::POLISHED_ANDESITE>(),
            make_pair_checked<BI::LOWER_ANDESITE_SLAB, BI::ANDESITE>(),
            make_pair_checked<BI::LOWER_DIORITE_SLAB, BI::DIORITE>(),
            make_pair_checked<BI::LOWER_POLISHED_DIORITE_SLAB, BI::POLISHED_DIORITE>(),
            make_pair_checked<BI::LOWER_GRANITE_SLAB, BI::GRANITE>(),
            make_pair_checked<BI::LOWER_POLISHED_GRANITE_SLAB, BI::POLISHED_GRANITE>(),
            make_pair_checked<BI::UPPER_RED_SANDSTONE_SLAB, BI::RED_SANDSTONE>(),
            make_pair_checked<BI::UPPER_SMOOTH_RED_SANDSTONE_SLAB, BI::SMOOTH_RED_SANDSTONE>(),
            make_pair_checked<BI::UPPER_POLISHED_ANDESITE_SLAB, BI::POLISHED_ANDESITE>(),
            make_pair_checked<BI::UPPER_ANDESITE_SLAB, BI::ANDESITE>(),
            make_pair_checked<BI::UPPER_DIORITE_SLAB, BI::DIORITE>(),
            make_pair_checked<BI::UPPER_POLISHED_DIORITE_SLAB, BI::POLISHED_DIORITE>(),
            make_pair_checked<BI::UPPER_GRANITE_SLAB, BI::GRANITE>(),
            make_pair_checked<BI::UPPER_POLISHED_GRANITE_SLAB, BI::POLISHED_GRANITE>(),
            make_pair_checked<BI::PURPLE_SHULKER_BOX2, BI::PURPLE_SHULKER_BOX>(),
            make_pair_checked<BI::SMOOTH_STONE, BI::STONE>(),
            make_pair_checked<BI::STONE_STAIRS, BI::COBBLESTONE_STAIRS>(),
            make_pair_checked<BI::MOSSY_COBBLESTONE_STAIRS, BI::MOSS_STONE>(),
            make_pair_checked<BI::ANDESITE_STAIRS, BI::ANDESITE>(),
            make_pair_checked<BI::DIORITE_STAIRS, BI::DIORITE>(),
            make_pair_checked<BI::GRANITE_STAIRS, BI::GRANITE>(),
            make_pair_checked<BI::POLISHED_ANDESITE_STAIRS, BI::POLISHED_ANDESITE>(),
            make_pair_checked<BI::POLISHED_DIORITE_STAIRS, BI::POLISHED_DIORITE>(),
            make_pair_checked<BI::POLISHED_GRANITE_STAIRS, BI::POLISHED_GRANITE>(),
            make_pair_checked<BI::SMOOTH_QUARTZ_STAIRS, BI::QUARTZ_BLOCK>(),
            make_pair_checked<BI::MOSSY_STONE_BRICK_STAIRS, BI::MOSS_STONE>(),
            make_pair_checked<BI::SMOOTH_SANDSTONE_STAIRS, BI::SMOOTH_SANDSTONE>(),
            make_pair_checked<BI::SMOOTH_RED_SANDSTONE_STAIRS, BI::SMOOTH_RED_SANDSTONE>(),
            make_pair_checked<BI::RED_NETHER_BRICK_STAIRS, BI::RED_NETHER_BRICK>(),
            make_pair_checked<BI::END_STONE_BRICK_STAIRS, BI::END_STONE_BRICKS>(),
            make_pair_checked<BI::SPRUCE_SIGN, BI::STANDING_SIGN_BLOCK>(),
            make_pair_checked<BI::BIRCH_SIGN, BI::STANDING_SIGN_BLOCK>(),
            make_pair_checked<BI::ACACIA_SIGN, BI::STANDING_SIGN_BLOCK>(),
            make_pair_checked<BI::JUNGLE_SIGN, BI::STANDING_SIGN_BLOCK>(),
            make_pair_checked<BI::DARK_OAK_SIGN, BI::STANDING_SIGN_BLOCK>(),
            make_pair_checked<BI::SPRUCE_WALL_SIGN, BI::WALL_MOUNTED_SIGN_BLOCK>(),
            make_pair_checked<BI::BIRCH_WALL_SIGN, BI::WALL_MOUNTED_SIGN_BLOCK>(),
            make_pair_checked<BI::ACACIA_WALL_SIGN, BI::WALL_MOUNTED_SIGN_BLOCK>(),
            make_pair_checked<BI::JUNGLE_WALL_SIGN, BI::WALL_MOUNTED_SIGN_BLOCK>(),
            make_pair_checked<BI::DARK_OAK_WALL_SIGN, BI::WALL_MOUNTED_SIGN_BLOCK>(),
        
        
            // ################ TU90 #################
            make_pair_checked<BI::LECTERN, BI::BOOKSHELF>(),
            make_pair_checked<BI::LANTERN, BI::TORCH>(),
            make_pair_checked<BI::LOOM, BI::CRAFTING_TABLE>(),
        
        
        
            // ################ TU91 #################
            make_pair_checked<BI::COMPOSTER, BI::OAK_WOOD>(),
            make_pair_checked<BI::BLAST_FURNACE, BI::FURNACE>(),
            make_pair_checked<BI::BELL, BI::GOLD_BLOCK>(),
            make_pair_checked<BI::SMOKER, BI::FURNACE>(),
            make_pair_checked<BI::FLETCHING_TABLE, BI::CRAFTING_TABLE>(),
            make_pair_checked<BI::SMITHING_TABLE, BI::CRAFTING_TABLE>(),
            make_pair_checked<BI::GRINDSTONE, BI::ANVIL>(),
            make_pair_checked<BI::STONE_CUTTER, BI::CRAFTING_TABLE>(),
            make_pair_checked<BI::CAMPFIRE, BI::FURNACE>(),
            make_pair_checked<BI::BARREL, BI::CHEST>(),
            make_pair_checked<BI::SWEET_BERRY_BUSH, BI::BEETROOT_BLOCK>(),
            make_pair_checked<BI::CARTOGRAPHY_TABLE, BI::CRAFTING_TABLE>(),
        });
    }
    inline constexpr auto DOWNGRADES = build_downgrades();



    struct FinalMap {
        static constexpr int MAX_ID = 512;        // bump if needed
        static constexpr int STATES_PER_ID = 16;  // dataTag is 0..15
        using Enc = uint16_t;                     // fits (MAX_ID*16-1) <= 8191

        std::array<Enc, MAX_ID * STATES_PER_ID> map{};
    };

    constexpr FinalMap::Enc pack(BlockState s) {
        return FinalMap::Enc(s.getID() * FinalMap::STATES_PER_ID + (s.getDataTag() & 0xF));
    }
    constexpr BlockState unpack(FinalMap::Enc e) {
        return { static_cast<uint16_t>(e / FinalMap::STATES_PER_ID),
                static_cast<uint8_t >(e % FinalMap::STATES_PER_ID) };
    }

    inline FinalMap build_final_map_for_TU(int targetTU) {
        using FM = FinalMap;
        FM out;

        // 1) Identity default for all indices
        for (uint16_t id = 0; id < FM::MAX_ID; ++id)
            for (uint8_t d = 0; d < FM::STATES_PER_ID; ++d) {
                const auto idx = pack({id, d});
                out.map[idx] = idx;
            }

        const auto AIR_ENC = pack(lce::BlocksInit::AIR.getState());

        // 2) Precompute family oldest (min TU + canonical) AND per-state TU
        struct FamilyInfo { bool has; int minTU; FM::Enc canon; };
        std::array<FamilyInfo, FM::MAX_ID> fam{};
        for (auto& f : fam) f = FamilyInfo{false, INT_MAX, AIR_ENC};

        std::array<int, FM::MAX_ID * FM::STATES_PER_ID> stateTU;
        stateTU.fill(INT_MAX);

        for (uint16_t id = 0; id < FM::MAX_ID; ++id) {
            int minTU = INT_MAX;
            FM::Enc canon = AIR_ENC;
            bool has = false;

            for (uint8_t d = 0; d < FM::STATES_PER_ID; ++d) {
                if (const lce::Block* b = lce::registry::BlockRegistry::getBlockExact(id, d)) {
                    if (b->getDataTag() != d) continue;
                    has = true;
                    const int tu = b->getTU();
                    const auto idx = pack(b->getState());
                    stateTU[idx] = tu;
                    if (tu < minTU) { minTU = tu; canon = idx; }
                }
            }
            fam[id] = FamilyInfo{ has, has ? minTU : INT_MAX, has ? canon : AIR_ENC };
        }

        // 3) Build one-step edges from your DOWNGRADES (skip self-loops)
        std::unordered_map<FM::Enc, FM::Enc> next;
        next.reserve(2048);
        for (const auto& p : lce::compat::DOWNGRADES) {
            const auto a = pack(p.newer);
            const auto b = pack(p.older);
            if (a != b) next.emplace(a, b);
        }

        // 4) Resolver: follow edges while TU too new; fall back to family canon; otherwise AIR
        std::unordered_map<FM::Enc, FM::Enc> memo;
        memo.reserve(4096);

        auto resolve = [&](FM::Enc start, auto&& self) -> FM::Enc {
            if (auto it = memo.find(start); it != memo.end()) return it->second;

            FM::Enc cur = start;
            for (int guard = 0; guard < 32; ++guard) {
                const auto curTU = stateTU[cur];
                if (curTU != INT_MAX && curTU <= targetTU) { memo[start] = cur; return cur; }

                if (auto it = next.find(cur); it != next.end()) {
                    const auto nxt = it->second;
                    if (nxt == cur) { memo[start] = AIR_ENC; return AIR_ENC; } // paranoia
                    cur = nxt;
                    continue;
                }

                // No explicit rule from here → try the family's canonical oldest state
                const auto st  = unpack(cur);
                const auto fid = st.getID();
                const auto canon = fam[fid].canon;

                if (canon != cur) { cur = canon; continue; }

                // We're at canonical and still too new / or family not allowed → AIR
                memo[start] = AIR_ENC; return AIR_ENC;
            }

            memo[start] = AIR_ENC; return AIR_ENC; // guard
        };

        // 5) Fill the map:
        //    - known state with TU <= target → identity (already set)
        //    - known state with TU  > target → resolve
        //    - unknown state:
        //         * if family allowed (has && minTU <= target) → identity (pass-through)
        //         * else → resolve (which will fall back or go to AIR)
        for (uint16_t id = 0; id < FM::MAX_ID; ++id) {
            const bool famAllowed = (fam[id].has && fam[id].minTU <= targetTU);
            for (uint8_t d = 0; d < FM::STATES_PER_ID; ++d) {
                const auto idx = pack({id, d});
                const int tu = stateTU[idx];

                if (tu == INT_MAX) {
                    if (!famAllowed) out.map[idx] = resolve(idx, resolve);
                    // else keep identity
                } else if (tu > targetTU) {
                    out.map[idx] = resolve(idx, resolve);
                }
                // else <= target → identity
            }
        }

        out.map[AIR_ENC] = AIR_ENC;
        return out;
    }


    inline BlockState map_state(const FinalMap& fm, BlockState s) {
        using FM = FinalMap;
        const auto idx = FM::Enc(s.getID() * FM::STATES_PER_ID + (s.getDataTag() & 0x0F));
        return unpack(fm.map[idx]);
    }

    inline std::shared_ptr<const FinalMap> get_final_map_cached(int targetTU) {
        // single, process-wide cache
        static std::mutex m;
        static std::unordered_map<int, std::shared_ptr<const FinalMap>> cache;

        // fast path
        {
            std::scoped_lock lk(m);
            auto it = cache.find(targetTU);
            if (it != cache.end()) return it->second;
        }

        // build outside lock to reduce contention
        auto built = std::make_shared<FinalMap>(build_final_map_for_TU(targetTU));

        // publish (handle benign races)
        {
            std::scoped_lock lk(m);
            auto [it, inserted] = cache.emplace(targetTU, built);
            if (!inserted) return it->second;
        }
        return built;
    }

    // Convenience: reference view (keeps a shared_ptr alive for the duration of the call site)
    inline const FinalMap& final_map(int targetTU) {
        static thread_local std::shared_ptr<const FinalMap> hold;
        hold = get_final_map_cached(targetTU);
        return *hold;
    }

    // Optional: clear cache (useful for tests/tools)
    inline void clear_final_map_cache() {
        static std::mutex m;
        static std::unordered_map<int, std::shared_ptr<const FinalMap>> cache;
        std::scoped_lock lk(m);
        cache.clear();
    }

} // namespace lce::compat