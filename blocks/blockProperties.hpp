#pragma once

#include "lce/blocks/blockID.hpp"
#include "lce/processor.hpp"


namespace lce::blocks {

    MU ND static bool isLiquidBlock(c_int id) {
        return id == STILL_WATER_ID || id == STILL_LAVA_ID ||
               id == FLOWING_WATER_ID || id == FLOWING_LAVA_ID;
    }

    MU ND static bool isWaterMaterial(c_int id) {
        return id == STILL_WATER_ID || id == FLOWING_WATER_ID;
    }

    MU ND static bool isLavaMaterial(c_int id) {
        return id == STILL_LAVA_ID || id == FLOWING_LAVA_ID;
    }

    MU ND static bool isSolidBlock(c_int id) {
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

    MU ND static bool isFullBlock(c_int id) {
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

    MU ND static bool blocksMovement(c_int id) {
        if (id == COBWEB_ID) { return false; }
        return isSolidBlock(id);
    }

    [[gnu::noinline]] MU ND static bool hasLightOpacity(c_int id) {
        switch (id) {
            case FLOWING_WATER_ID:
            case STILL_WATER_ID:
            case OAK_LEAVES_ID:
            case COBWEB_ID:
            case FARMLAND_ID:
            case ICE_ID:
            case ACACIA_LEAVES_ID:
            case GRASS_PATH_ID:
            case FROSTED_ICE_ID:
                return true;
            default:
                return isFullBlock(id);
        }
    }

    [[gnu::noinline]] MU ND static bool isFullyOpaqueBlock(c_int id) {
        switch (id) {
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

    MU ND static bool isLeavesBlock(c_int id) {
        return id == OAK_LEAVES_ID || id == ACACIA_LEAVES_ID;
    }

    MU ND static bool isAirOrLeavesBlock(c_int id) {
        return id == AIR_ID || id == OAK_LEAVES_ID || id == ACACIA_LEAVES_ID;
    }

    /// return GRASS_ID || DIRT_ID || FARMLAND_ID
    MU ND static bool isGrassOrDirtOrFarmland(c_int id) {
        return id == GRASS_ID || id == DIRT_ID || id == FARMLAND_ID;
    }


    MU ND static bool isReplaceableBlock(c_int id) {
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





