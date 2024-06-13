#include "TextureMap.hpp"
#include "lce/blocks/block_ids.hpp"


void TextureMap::add(const int theID, const uint32_t theX, const uint32_t theY) {
    static constexpr uint32_t CELL = 16;
    auto* tempPic = new Picture(CELL, CELL);
    terrainTexture.getSubImage(*tempPic, CELL * theX, CELL * theY);
    BLOCK_TEXTURES.registerValue(theID, tempPic);
}


void TextureMap::setup() {

    terrainTexture.loadFromFile("lce/assets/terrain.png");
    if (terrainTexture.myWidth != 256 || terrainTexture.myHeight != 544) {
        throw std::runtime_error("failed to load lce/assets/terrain.png");
    }

    namespace ids_t = lce::blocks::ids;
    add(ids_t::AIR_ID, 0, 0); // FIX
    add(ids_t::STONE_ID, 1, 0);
    add(ids_t::GRASS_ID, 3, 0);
    add(ids_t::DIRT_ID, 2, 0);
    add(ids_t::COBBLESTONE_ID, 0, 1);
    add(ids_t::OAK_WOOD_PLANK_ID, 4, 0);
    add(ids_t::OAK_SAPLING_ID, 15, 0);
    add(ids_t::BEDROCK_ID, 1, 1);
    add(ids_t::FLOWING_WATER_ID, 0, 0); // FIX
    add(ids_t::STILL_WATER_ID, 0, 0); // FIX
    add(ids_t::FLOWING_LAVA_ID, 0, 0); // FIX
    add(ids_t::STILL_LAVA_ID, 0, 0); // FIX
    add(ids_t::SAND_ID, 2, 1);
    add(ids_t::GRAVEL_ID, 3, 1);
    add(ids_t::GOLD_ORE_ID, 0, 2);
    add(ids_t::IRON_ORE_ID, 1, 2);
    add(ids_t::COAL_ORE_ID, 2, 2);
    add(ids_t::OAK_WOOD_ID, 4, 1); // bottom(5,1)
    add(ids_t::OAK_LEAVES_ID, 0, 0);
    add(ids_t::SPONGE_ID, 0, 3); // (12,8)
    add(ids_t::GLASS_ID, 0, 0);
    add(ids_t::LAPIS_LAZULI_ORE_ID, 0, 10);
    add(ids_t::LAPIS_LAZULI_BLOCK_ID, 0, 9);
    add(ids_t::DISPENSER_ID, 11, 1);
    add(ids_t::SANDSTONE_ID, 0, 0);
    add(ids_t::NOTE_BLOCK_ID, 2, 16);
    add(ids_t::BED_ID, 0, 0);
    add(ids_t::POWERED_RAIL_ID, 0, 0);
    add(ids_t::DETECTOR_RAIL_ID, 0, 0);
    add(ids_t::STICKY_PISTON_ID, 0, 0);
    add(ids_t::COBWEB_ID, 11, 0);
    add(ids_t::DEAD_SHRUB_ID, 0, 0);
    add(ids_t::DEAD_BUSH_ID, 0, 0);
    add(ids_t::PISTON_ID, 0, 0);
    add(ids_t::PISTON_HEAD_ID, 0, 0);
    add(ids_t::WHITE_WOOL_ID, 0, 0);
    add(ids_t::DANDELION_ID, 13, 0);
    add(ids_t::POPPY_ID, 12, 0);
    add(ids_t::BROWN_MUSHROOM_ID, 13, 1);
    add(ids_t::RED_MUSHROOM_ID, 12, 1);
    add(ids_t::GOLD_BLOCK_ID, 7, 1);
    add(ids_t::IRON_BLOCK_ID, 6, 1);
    add(ids_t::DOUBLE_STONE_SLAB_ID, 0, 0);
    add(ids_t::STONE_SLAB_ID, 0, 0);
    add(ids_t::BRICKS_ID, 7, 0);
    add(ids_t::TNT_ID, 8, 0); // (9,0), (10,0)
    add(ids_t::BOOKSHELF_ID, 3, 2);
    add(ids_t::MOSS_STONE_ID, 4, 2);
    add(ids_t::OBSIDIAN_ID, 5, 2);
    add(ids_t::TORCH_ID, 0, 5);
    add(ids_t::FIRE_ID, 0, 0);
    add(ids_t::MONSTER_SPAWNER_ID, 0, 0);
    add(ids_t::OAK_WOOD_STAIRS_ID, 0, 0);
    add(ids_t::CHEST_ID, 0, 0);
    add(ids_t::REDSTONE_WIRE_ID, 0, 0);
    add(ids_t::DIAMOND_ORE_ID, 2, 3);
    add(ids_t::DIAMOND_BLOCK_ID, 8, 1);
    add(ids_t::CRAFTING_TABLE_ID, 11, 3); // (12,3), (11,2)
    add(ids_t::WHEAT_CROPS_ID, 15, 5); // (8-15,5)
    add(ids_t::FARMLAND_ID, 0, 0);
    add(ids_t::FURNACE_ID, 12, 2); // (13,2), (14,3)
    add(ids_t::BURNING_FURNACE_ID, 13, 3); // (13,2), (14,3)
    add(ids_t::STANDING_SIGN_BLOCK_ID, 0, 0);
    add(ids_t::OAK_DOOR_BLOCK_ID, 1, 5); // (1,6)
    add(ids_t::LADDER_ID, 3, 5);
    add(ids_t::RAIL_ID, 0, 0);
    add(ids_t::COBBLESTONE_STAIRS_ID, 0, 0);
    add(ids_t::WALL_MOUNTED_SIGN_BLOCK_ID, 0, 0);
    add(ids_t::LEVER_ID, 0, 0);
    add(ids_t::STONE_PRESSURE_PLATE_ID, 0, 0);
    add(ids_t::IRON_DOOR_BLOCK_ID, 0, 0);
    add(ids_t::WOODEN_PRESSURE_PLATE_ID, 0, 0);
    add(ids_t::REDSTONE_ORE_ID, 3, 3);
    add(ids_t::GLOWING_REDSTONE_ORE_ID, 3, 3); // FIX
    add(ids_t::OFF_REDSTONE_TORCH_ID, 3, 7);
    add(ids_t::ON_REDSTONE_TORCH_ID, 3, 6);
    add(ids_t::STONE_BUTTON_ID, 0, 0);
    add(ids_t::SNOW_ID, 0, 0);
    add(ids_t::ICE_ID, 0, 0);
    add(ids_t::SNOW_BLOCK_ID, 0, 0);
    add(ids_t::CACTUS_ID, 0, 0);
    add(ids_t::CLAY_BLOCK_ID, 8, 4);
    add(ids_t::SUGAR_CANES_ID, 0, 0);
    add(ids_t::JUKEBOX_ID, 0, 0);
    add(ids_t::OAK_FENCE_ID, 0, 0);
    add(ids_t::PUMPKIN_ID, 0, 0);
    add(ids_t::NETHERRACK_ID, 7, 6);
    add(ids_t::SOUL_SAND_ID, 8, 6);
    add(ids_t::GLOWSTONE_ID, 9, 6);
    add(ids_t::NETHER_PORTAL_ID, 0, 0);
    add(ids_t::JACK_O_LANTERN_ID, 0, 0);
    add(ids_t::CAKE_BLOCK_ID, 0, 0);
    add(ids_t::OFF_REDSTONE_REPEATER_BLOCK_ID, 0, 0);
    add(ids_t::ON_REDSTONE_REPEATER_BLOCK_ID, 0, 0);
    add(ids_t::WHITE_STAINED_GLASS_ID, 0, 0);
    add(ids_t::WOODEN_TRAPDOOR_ID, 0, 0);
    add(ids_t::STONE_MONSTER_EGG_ID, 0, 0);
    add(ids_t::STONE_BRICKS_ID, 0, 0);
    add(ids_t::BROWN_MUSHROOM_BLOCK_ID, 14, 7);
    add(ids_t::RED_MUSHROOM_BLOCK_ID, 13, 7);
    add(ids_t::IRON_BARS_ID, 5, 5);
    add(ids_t::GLASS_PANE_ID, 0, 0);
    add(ids_t::MELON_BLOCK_ID, 0, 0);
    add(ids_t::PUMPKIN_STEM_ID, 0, 0);
    add(ids_t::MELON_STEM_ID, 0, 0);
    add(ids_t::VINES_ID, 0, 0);
    add(ids_t::OAK_FENCE_GATE_ID, 0, 0);
    add(ids_t::BRICK_STAIRS_ID, 0, 0);
    add(ids_t::STONE_BRICK_STAIRS_ID, 0, 0);
    add(ids_t::MYCELIUM_ID, 0, 0);
    add(ids_t::LILY_PAD_ID, 0, 0);
    add(ids_t::NETHER_BRICK_BLOCK_ID, 0, 14);
    add(ids_t::NETHER_BRICK_FENCE_ID, 0, 14); // FIX
    add(ids_t::NETHER_BRICK_STAIRS_ID, 0, 14); // FIX
    add(ids_t::BLOCK_NETHER_WART_ID, 4, 14); // (2-4,14)
    add(ids_t::ENCHANTMENT_TABLE_ID, 6, 11); // (6,10), (6,11), (7, 11)
    add(ids_t::BLOCK_BREWING_STAND_ID, 0, 0);
    add(ids_t::BLOCK_CAULDRON_ITEM_ID, 0, 0);
    add(ids_t::END_PORTAL_ID, 0, 0);
    add(ids_t::END_PORTAL_FRAME_ID, 0, 0);
    add(ids_t::END_STONE_ID, 15, 10);
    add(ids_t::DRAGON_EGG_ID, 7, 10);
    add(ids_t::INACTIVE_REDSTONE_LAMP_ID, 3, 13);
    add(ids_t::ACTIVE_REDSTONE_LAMP_ID, 4, 13);
    add(ids_t::DOUBLE_OAK_WOOD_SLAB_ID, 0, 0);
    add(ids_t::OAK_WOOD_SLAB_ID, 0, 0);
    add(ids_t::COCOA_ID, 0, 0);
    add(ids_t::SANDSTONE_STAIRS_ID, 0, 0);
    add(ids_t::EMERALD_ORE_ID, 11, 10);
    add(ids_t::ENDER_CHEST_ID, 0, 0);
    add(ids_t::TRIPWIRE_HOOK_ID, 12, 10);
    add(ids_t::TRIPWIRE_ID, 0, 0);
    add(ids_t::EMERALD_BLOCK_ID, 9, 1);
    add(ids_t::SPRUCE_WOOD_STAIRS_ID, 0, 0);
    add(ids_t::BIRCH_WOOD_STAIRS_ID, 0, 0);
    add(ids_t::JUNGLE_WOOD_STAIRS_ID, 0, 0);
    add(ids_t::COMMAND_BLOCK_ID, 0, 0);
    add(ids_t::BEACON_ID, 0, 0);
    add(ids_t::COBBLESTONE_WALL_ID, 0, 0);
    add(ids_t::FLOWER_POT_ID, 0, 0);
    add(ids_t::CARROTS_ID, 11, 12); // (8-11,12)
    add(ids_t::POTATOES_ID, 0, 0);
    add(ids_t::WOODEN_BUTTON_ID, 0, 0);
    add(ids_t::MOB_HEAD_ID, 0, 0);
    add(ids_t::ANVIL_ID, 0, 0);
    add(ids_t::TRAPPED_CHEST_ID, 0, 0);
    add(ids_t::LIGHT_WEIGHTED_PRESSURE_PLATE_ID, 0, 0);
    add(ids_t::HEAVY_WEIGHTED_PRESSURE_PLATE_ID, 0, 0);
    add(ids_t::INACTIVE_REDSTONE_COMPARATOR_ID, 0, 0);
    add(ids_t::ACTIVE_REDSTONE_COMPARATOR_ID, 0, 0);
    add(ids_t::DAYLIGHT_SENSOR_ID, 0, 0);
    add(ids_t::REDSTONE_BLOCK_ID, 10, 1);
    add(ids_t::NETHER_QUARTZ_ORE_ID, 15, 11);
    add(ids_t::HOPPER_ID, 0, 0);
    add(ids_t::QUARTZ_BLOCK_ID, 0, 0);
    add(ids_t::QUARTZ_STAIRS_ID, 0, 0);
    add(ids_t::ACTIVATOR_RAIL_ID, 0, 0);
    add(ids_t::DROPPER_ID, 0, 0);
    add(ids_t::WHITE_HARDENED_CLAY_ID, 0, 0);
    add(ids_t::WHITE_STAINED_GLASS_PANE_ID, 0, 0);
    add(ids_t::ACACIA_LEAVES_ID, 0, 0);
    add(ids_t::ACACIA_WOOD_ID, 0, 0);
    add(ids_t::ACACIA_WOOD_STAIRS_ID, 0, 0);
    add(ids_t::DARK_OAK_WOOD_STAIRS_ID, 0, 0);
    add(ids_t::SLIME_BLOCK_ID, 12, 12);
    add(ids_t::BARRIER_ID, 11, 23);
    add(ids_t::IRON_TRAPDOOR_ID, 0, 0);
    add(ids_t::PRISMARINE_ID, 0, 0);
    add(ids_t::SEA_LANTERN_ID, 0, 0);
    add(ids_t::HAY_BALE_ID, 10, 15); // (13,15)
    add(ids_t::WHITE_CARPET_ID, 0, 0);
    add(ids_t::HARDENED_CLAY_ID, 0, 0);
    add(ids_t::BLOCK_OF_COAL_ID, 0, 16);
    add(ids_t::PACKED_ICE_ID, 0, 0);
    add(ids_t::SUNFLOWER_ID, 0, 0);
    add(ids_t::FREE_STANDING_BANNER_ID, 0, 0);
    add(ids_t::WALL_MOUNTED_BANNER_ID, 0, 0);
    add(ids_t::INVERTED_DAYLIGHT_SENSOR_ID, 0, 0);
    add(ids_t::RED_SANDSTONE_ID, 0, 0);
    add(ids_t::RED_SANDSTONE_STAIRS_ID, 0, 0);
    add(ids_t::DOUBLE_RED_SANDSTONE_SLAB_ID, 0, 0);
    add(ids_t::RED_SANDSTONE_SLAB_ID, 0, 0);
    add(ids_t::SPRUCE_FENCE_GATE_ID, 0, 0);
    add(ids_t::BIRCH_FENCE_GATE_ID, 0, 0);
    add(ids_t::JUNGLE_FENCE_GATE_ID, 0, 0);
    add(ids_t::DARK_OAK_FENCE_GATE_ID, 0, 0);
    add(ids_t::ACACIA_FENCE_GATE_ID, 0, 0);
    add(ids_t::SPRUCE_FENCE_ID, 0, 0);
    add(ids_t::BIRCH_FENCE_ID, 0, 0);
    add(ids_t::JUNGLE_FENCE_ID, 0, 0);
    add(ids_t::DARK_OAK_FENCE_ID, 0, 0);
    add(ids_t::ACACIA_FENCE_ID, 0, 0);
    add(ids_t::SPRUCE_DOOR_BLOCK_ID, 0, 0);
    add(ids_t::BIRCH_DOOR_BLOCK_ID, 0, 0);
    add(ids_t::JUNGLE_DOOR_BLOCK_ID, 0, 0);
    add(ids_t::ACACIA_DOOR_BLOCK_ID, 0, 0);
    add(ids_t::DARK_OAK_DOOR_BLOCK_ID, 0, 0);
    add(ids_t::END_ROD_ID, 0, 0);
    add(ids_t::CHORUS_PLANT_ID, 0, 0);
    add(ids_t::CHORUS_FLOWER_ID, 0, 0);
    add(ids_t::PURPUR_BLOCK_ID, 0, 0);
    add(ids_t::PURPUR_PILLAR_ID, 0, 0);
    add(ids_t::PURPUR_STAIRS_ID, 0, 0);
    add(ids_t::PURPUR_DOUBLE_SLAB_ID, 0, 0);
    add(ids_t::PURPUR_SLAB_ID, 0, 0);
    add(ids_t::END_STONE_BRICKS_ID, 8, 23);
    add(ids_t::BEETROOT_BLOCK_ID, 0, 0);
    add(ids_t::GRASS_PATH_ID, 0, 0);
    add(ids_t::END_GATEWAY_ID, 0, 0);
    add(ids_t::REPEATING_COMMAND_BLOCK_ID, 0, 0);
    add(ids_t::CHAIN_COMMAND_BLOCK_ID, 0, 0);
    add(ids_t::FROSTED_ICE_ID, 12, 24); // (12-15,24)
    add(ids_t::MAGMA_BLOCK_ID, 9, 24);
    add(ids_t::NETHER_WART_BLOCK_ID, 10, 24);
    add(ids_t::RED_NETHER_BRICK_ID, 11, 24);
    add(ids_t::BONE_BLOCK_ID, 0, 0);
    add(ids_t::STRUCTURE_VOID_ID, 0, 0);
    add(ids_t::OBSERVER_ID, 4, 26); // (4-8,26)
    add(ids_t::WHITE_SHULKER_BOX_ID, 0, 0);
    add(ids_t::ORANGE_SHULKER_BOX_ID, 0, 0);
    add(ids_t::MAGENTA_SHULKER_BOX_ID, 0, 0);
    add(ids_t::LIGHT_BLUE_SHULKER_BOX_ID, 0, 0);
    add(ids_t::YELLOW_SHULKER_BOX_ID, 0, 0);
    add(ids_t::LIME_SHULKER_BOX_ID, 0, 0);
    add(ids_t::PINK_SHULKER_BOX_ID, 0, 0);
    add(ids_t::GRAY_SHULKER_BOX_ID, 0, 0);
    add(ids_t::LIGHT_GRAY_SHULKER_BOX_ID, 0, 0);
    add(ids_t::CYAN_SHULKER_BOX_ID, 0, 0);
    add(ids_t::PURPLE_SHULKER_BOX_ID, 0, 0);
    add(ids_t::BLUE_SHULKER_BOX_ID, 0, 0);
    add(ids_t::BROWN_SHULKER_BOX_ID, 0, 0);
    add(ids_t::GREEN_SHULKER_BOX_ID, 0, 0);
    add(ids_t::RED_SHULKER_BOX_ID, 0, 0);
    add(ids_t::BLACK_SHULKER_BOX_ID, 0, 0);
    add(ids_t::WHITE_GLAZED_TERRACOTTA_ID, 0, 0);
    add(ids_t::ORANGE_GLAZED_TERRACOTTA_ID, 0, 0);
    add(ids_t::MAGENTA_GLAZED_TERRACOTTA_ID, 0, 0);
    add(ids_t::LIGHT_BLUE_GLAZED_TERRACOTTA_ID, 0, 0);
    add(ids_t::YELLOW_GLAZED_TERRACOTTA_ID, 0, 0);
    add(ids_t::LIME_GLAZED_TERRACOTTA_ID, 0, 0);
    add(ids_t::PINK_GLAZED_TERRACOTTA_ID, 0, 0);
    add(ids_t::GRAY_GLAZED_TERRACOTTA_ID, 0, 0);
    add(ids_t::LIGHT_GRAY_GLAZED_TERRACOTTA_ID, 0, 0);
    add(ids_t::CYAN_GLAZED_TERRACOTTA_ID, 0, 0);
    add(ids_t::PURPLE_GLAZED_TERRACOTTA_ID, 0, 0);
    add(ids_t::BLUE_GLAZED_TERRACOTTA_ID, 0, 0);
    add(ids_t::BROWN_GLAZED_TERRACOTTA_ID, 0, 0);
    add(ids_t::GREEN_GLAZED_TERRACOTTA_ID, 0, 0);
    add(ids_t::RED_GLAZED_TERRACOTTA_ID, 0, 0);
    add(ids_t::BLACK_GLAZED_TERRACOTTA_ID, 0, 0);
    add(ids_t::WHITE_CONCRETE_ID, 0, 0);
    add(ids_t::WHITE_CONCRETE_POWDER_ID, 0, 0);
    add(ids_t::STRUCTURE_BLOCK_ID, 13, 26); // (11-15,26)
    add(ids_t::CONDUIT_ID, 0, 0);
    add(ids_t::UNKNOWN_PUMPKIN, 0, 0);
    add(ids_t::KELP_ID, 0, 0);
    add(ids_t::CORAL_BLOCK_ID, 0, 0);
    add(ids_t::CORAL_ID, 0, 0);
    add(ids_t::CORAL_FAN_ID, 0, 0);
    add(ids_t::CORAL_FAN_DEAD_ID, 0, 0);
    add(ids_t::CORAL_FAN_WALL1_ID, 0, 0);
    add(ids_t::CORAL_FAN_WALL2_ID, 0, 0);
    add(ids_t::CORAL_FAN_WALL3_ID, 0, 0);
    add(ids_t::DRIED_KELP_BLOCK_ID, 0, 0);
    add(ids_t::SEAGRASS_ID, 0, 0);
    add(ids_t::SEAPICKLE_ID, 0, 0);
    add(ids_t::BUBBLE_COLUMN_ID, 0, 0);
    add(ids_t::BLUE_ICE_ID, 0, 0);
    add(ids_t::SPRUCE_TRAPDOOR, 0, 0);
    add(ids_t::BIRCH_TRAPDOOR, 0, 0);
    add(ids_t::JUNGLE_TRAPDOOR, 0, 0);
    add(ids_t::ACACIA_TRAPDOOR, 0, 0);
    add(ids_t::DARK_OAK_TRAPDOOR, 0, 0);
    add(ids_t::TURTLE_EGG_ID, 0, 0);
    add(ids_t::PRISMARINE_STAIRS, 0, 0);
    add(ids_t::PRISMARINE_BRICK_STAIRS, 0, 0);
    add(ids_t::DARK_PRISMARINE_STAIRS, 0, 0);
    add(ids_t::STRIPPED_SPRUCE_LOG, 0, 0);
    add(ids_t::STRIPPED_BIRCH_LOG, 0, 0);
    add(ids_t::STRIPPED_JUNGLE_LOG, 0, 0);
    add(ids_t::STRIPPED_ACACIA_LOG, 0, 0);
    add(ids_t::STRIPPED_DARK_0AK_LOG, 0, 0);
    add(ids_t::STRIPPED_OAK_LOG, 0, 0);
    add(ids_t::ACACIA_PRESSURE_PLATE, 0, 0);
    add(ids_t::BIRCH_PRESSURE_PLATE, 0, 0);
    add(ids_t::DARK_OAK_PRESSURE_PLATE, 0, 0);
    add(ids_t::JUNGLE_PRESSURE_PLATE, 0, 0);
    add(ids_t::SPRUCE_PRESSURE_PLATE, 0, 0);
    add(ids_t::ACACIA_BUTTON, 0, 0);
    add(ids_t::BIRCH_BUTTON, 0, 0);
    add(ids_t::DARK_OAK_BUTTON, 0, 0);
    add(ids_t::JUNGLE_BUTTON, 0, 0);
    add(ids_t::SPRUCE_BUTTON, 0, 0);
    add(ids_t::DOUBLE_PRISMARINE_SLAB, 0, 0);
    add(ids_t::PRISMARINE_SLAB, 0, 0);
    add(ids_t::SPRUCE_WOOD_2, 0, 0);
    add(ids_t::BIRCH_WOOD_2, 0, 0);
    add(ids_t::JUNGLE_WOOD_2, 0, 0);
    add(ids_t::ACACIA_WOOD_2, 0, 0);
    add(ids_t::DARK_OAK_WOOD_2, 0, 0);
    add(ids_t::OAK_WOOD_2, 0, 0);

}