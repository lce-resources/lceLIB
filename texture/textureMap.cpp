#include "textureMap.hpp"
#include "lce/blocks/block_ids.hpp"
#include "lce/blocks/blocks.hpp"
#include "lce/items/item_ids.hpp"


Picture const* TextureMap::getBlockFromID(int id) {
    return blockRegistry.getObjectById(id);
}

/*
Picture const* TextureMap::getItemByID(int id) {
    return itemRegistry.getObjectById(id);
}
 */


void TextureMap::addBlock(int theID, const std::string& theIdentifier, uint32_t theX, uint32_t theY) {
    static constexpr uint32_t CELL = 16;
    auto tempPic = new Picture(CELL, CELL);
    blockTexture.getSubImage(*tempPic, CELL * theX, CELL * theY);
    blockRegistry.registerValue(theID, theIdentifier, tempPic);
}

/*
void TextureMap::addItem(int theID, uint32_t theX, uint32_t theY) {
    static constexpr uint32_t CELL = 16;
    auto* tempPic = new Picture(CELL, CELL);
    itemTexture.getSubImage(*tempPic, CELL * theX, CELL * theY);
    itemRegistry.registerValue(theID, tempPic);
}
 */


void TextureMap::setup() {

    blockTexture.loadFromFile(BLOCK_TEXTURE_FILE.c_str());
    if (blockTexture.myWidth != BLOCK_TEXTURE_WIDTH || blockTexture.myHeight != BLOCK_TEXTURE_HEIGHT) {
        throw std::runtime_error("failed to load " + BLOCK_TEXTURE_FILE);
    }
    setupBlocks();
    /*
    itemTexture.loadFromFile(ITEM_TEXTURE_FILE.c_str());
    if (itemTexture.myWidth != ITEM_TEXTURE_WIDTH || itemTexture.myHeight != ITEM_TEXTURE_HEIGHT) {
        throw std::runtime_error("failed to load " + ITEM_TEXTURE_FILE);
    }
    setupItems();
    */
}

void TextureMap::setupBlocks() {

    namespace ids_t_b = lce::blocks::ids;
    addBlock(ids_t_b::AIR_ID, lce::blocks::AIR.getIdentifier(), 0, 0); // FIX
    addBlock(ids_t_b::STONE_ID, lce::blocks::STONE.getIdentifier(), 1, 0);
    addBlock(ids_t_b::GRASS_ID, lce::blocks::GRASS.getIdentifier(), 3, 0);
    addBlock(ids_t_b::DIRT_ID, lce::blocks::DIRT.getIdentifier(), 2, 0);
    addBlock(ids_t_b::COBBLESTONE_ID, lce::blocks::COBBLESTONE.getIdentifier(), 0, 1);
    addBlock(ids_t_b::OAK_WOOD_PLANK_ID, lce::blocks::OAK_WOOD_PLANK.getIdentifier(), 4, 0);
    addBlock(ids_t_b::OAK_SAPLING_ID, lce::blocks::OAK_SAPLING.getIdentifier(), 15, 0);
    addBlock(ids_t_b::BEDROCK_ID, lce::blocks::BEDROCK.getIdentifier(), 1, 1);
    addBlock(ids_t_b::FLOWING_WATER_ID, lce::blocks::FLOWING_WATER.getIdentifier(), 0, 0); // FIX
    addBlock(ids_t_b::STILL_WATER_ID, lce::blocks::STILL_WATER.getIdentifier(), 0, 0); // FIX
    addBlock(ids_t_b::FLOWING_LAVA_ID, lce::blocks::FLOWING_LAVA.getIdentifier(), 0, 0); // FIX
    addBlock(ids_t_b::STILL_LAVA_ID, lce::blocks::STILL_LAVA.getIdentifier(), 0, 0); // FIX
    addBlock(ids_t_b::SAND_ID, lce::blocks::SAND.getIdentifier(), 2, 1);
    addBlock(ids_t_b::GRAVEL_ID, lce::blocks::GRAVEL.getIdentifier(), 3, 1);
    addBlock(ids_t_b::GOLD_ORE_ID, lce::blocks::GOLD_ORE.getIdentifier(), 0, 2);
    addBlock(ids_t_b::IRON_ORE_ID, lce::blocks::IRON_ORE.getIdentifier(), 1, 2);
    addBlock(ids_t_b::COAL_ORE_ID, lce::blocks::COAL_ORE.getIdentifier(), 2, 2);
    addBlock(ids_t_b::OAK_WOOD_ID, lce::blocks::OAK_WOOD.getIdentifier(), 4, 1); // bottom(5,1)
    addBlock(ids_t_b::OAK_LEAVES_ID, lce::blocks::OAK_LEAVES.getIdentifier(), 0, 0);
    addBlock(ids_t_b::SPONGE_ID, lce::blocks::SPONGE.getIdentifier(), 0, 3); // (12,8)
    addBlock(ids_t_b::GLASS_ID, lce::blocks::GLASS.getIdentifier(), 0, 0);
    addBlock(ids_t_b::LAPIS_LAZULI_ORE_ID, lce::blocks::LAPIS_LAZULI_ORE.getIdentifier(), 0, 10);
    addBlock(ids_t_b::LAPIS_LAZULI_BLOCK_ID, lce::blocks::LAPIS_LAZULI_BLOCK.getIdentifier(), 0, 9);
    addBlock(ids_t_b::DISPENSER_ID, lce::blocks::DISPENSER.getIdentifier(), 11, 1);
    addBlock(ids_t_b::SANDSTONE_ID, lce::blocks::SANDSTONE.getIdentifier(), 0, 0);
    addBlock(ids_t_b::NOTE_BLOCK_ID, lce::blocks::NOTE_BLOCK.getIdentifier(), 2, 16);
    addBlock(ids_t_b::BED_BLOCK_ID, lce::blocks::BED_BLOCK.getIdentifier(), 0, 0);
    addBlock(ids_t_b::POWERED_RAIL_ID, lce::blocks::POWERED_RAIL.getIdentifier(), 0, 0);
    addBlock(ids_t_b::DETECTOR_RAIL_ID, lce::blocks::DETECTOR_RAIL.getIdentifier(), 0, 0);
    addBlock(ids_t_b::STICKY_PISTON_ID, lce::blocks::STICKY_PISTON.getIdentifier(), 0, 0);
    addBlock(ids_t_b::COBWEB_ID, lce::blocks::COBWEB.getIdentifier(), 11, 0);
    addBlock(ids_t_b::TALL_GRASS_SHRUB_ID, lce::blocks::TALL_GRASS_SHRUB.getIdentifier(), 0, 0);
    addBlock(ids_t_b::DEAD_BUSH_ID, lce::blocks::DEAD_BUSH.getIdentifier(), 0, 0);
    addBlock(ids_t_b::PISTON_ID, lce::blocks::PISTON.getIdentifier(), 0, 0);
    addBlock(ids_t_b::PISTON_HEAD_ID, lce::blocks::PISTON_HEAD.getIdentifier(), 0, 0);
    addBlock(ids_t_b::WHITE_WOOL_ID, lce::blocks::WHITE_WOOL.getIdentifier(), 0, 0);
    addBlock(ids_t_b::DANDELION_ID, lce::blocks::DANDELION.getIdentifier(), 13, 0);
    addBlock(ids_t_b::POPPY_ID, lce::blocks::POPPY.getIdentifier(), 12, 0);
    addBlock(ids_t_b::BROWN_MUSHROOM_ID, lce::blocks::BROWN_MUSHROOM.getIdentifier(), 13, 1);
    addBlock(ids_t_b::RED_MUSHROOM_ID, lce::blocks::RED_MUSHROOM.getIdentifier(), 12, 1);
    addBlock(ids_t_b::GOLD_BLOCK_ID, lce::blocks::GOLD_BLOCK.getIdentifier(), 7, 1);
    addBlock(ids_t_b::IRON_BLOCK_ID, lce::blocks::IRON_BLOCK.getIdentifier(), 6, 1);
    addBlock(ids_t_b::DOUBLE_STONE_SLAB_ID, lce::blocks::DOUBLE_STONE_SLAB.getIdentifier(), 0, 0);
    addBlock(ids_t_b::STONE_SLAB_ID, lce::blocks::STONE_SLAB.getIdentifier(), 0, 0);
    addBlock(ids_t_b::BRICKS_ID, lce::blocks::BRICKS.getIdentifier(), 7, 0);
    addBlock(ids_t_b::TNT_ID, lce::blocks::TNT.getIdentifier(), 8, 0); // (9,0), (10,0)
    addBlock(ids_t_b::BOOKSHELF_ID, lce::blocks::BOOKSHELF.getIdentifier(), 3, 2);
    addBlock(ids_t_b::MOSS_STONE_ID, lce::blocks::MOSS_STONE.getIdentifier(), 4, 2);
    addBlock(ids_t_b::OBSIDIAN_ID, lce::blocks::OBSIDIAN.getIdentifier(), 5, 2);
    addBlock(ids_t_b::TORCH_ID, lce::blocks::TORCH.getIdentifier(), 0, 5);
    addBlock(ids_t_b::FIRE_ID, lce::blocks::FIRE.getIdentifier(), 0, 0);
    addBlock(ids_t_b::MONSTER_SPAWNER_ID, lce::blocks::MONSTER_SPAWNER.getIdentifier(), 0, 0);
    addBlock(ids_t_b::OAK_WOOD_STAIRS_ID, lce::blocks::OAK_WOOD_STAIRS.getIdentifier(), 0, 0);
    addBlock(ids_t_b::CHEST_ID, lce::blocks::CHEST.getIdentifier(), 0, 0);
    addBlock(ids_t_b::REDSTONE_WIRE_ID, lce::blocks::REDSTONE_WIRE.getIdentifier(), 0, 0);
    addBlock(ids_t_b::DIAMOND_ORE_ID, lce::blocks::DIAMOND_ORE.getIdentifier(), 2, 3);
    addBlock(ids_t_b::DIAMOND_BLOCK_ID, lce::blocks::DIAMOND_BLOCK.getIdentifier(), 8, 1);
    addBlock(ids_t_b::CRAFTING_TABLE_ID, lce::blocks::CRAFTING_TABLE.getIdentifier(), 11, 3); // (12,3), (11,2)
    addBlock(ids_t_b::WHEAT_CROPS_ID, lce::blocks::WHEAT_CROPS.getIdentifier(), 15, 5); // (8-15,5)
    addBlock(ids_t_b::FARMLAND_ID, lce::blocks::FARMLAND.getIdentifier(), 0, 0);
    addBlock(ids_t_b::FURNACE_ID, lce::blocks::FURNACE.getIdentifier(), 12, 2); // (13,2), (14,3)
    addBlock(ids_t_b::BURNING_FURNACE_ID, lce::blocks::BURNING_FURNACE.getIdentifier(), 13, 3); // (13,2), (14,3)
    addBlock(ids_t_b::STANDING_SIGN_BLOCK_ID, lce::blocks::STANDING_SIGN_BLOCK.getIdentifier(), 0, 0);
    addBlock(ids_t_b::OAK_DOOR_BLOCK_ID, lce::blocks::OAK_DOOR_BLOCK.getIdentifier(), 1, 5); // (1,6)
    addBlock(ids_t_b::LADDER_ID, lce::blocks::LADDER.getIdentifier(), 3, 5);
    addBlock(ids_t_b::RAIL_ID, lce::blocks::RAIL.getIdentifier(), 0, 0);
    addBlock(ids_t_b::COBBLESTONE_STAIRS_ID, lce::blocks::COBBLESTONE_STAIRS.getIdentifier(), 0, 0);
    addBlock(ids_t_b::WALL_MOUNTED_SIGN_BLOCK_ID, lce::blocks::WALL_MOUNTED_SIGN_BLOCK.getIdentifier(), 0, 0);
    addBlock(ids_t_b::LEVER_ID, lce::blocks::LEVER.getIdentifier(), 0, 0);
    addBlock(ids_t_b::STONE_PRESSURE_PLATE_ID, lce::blocks::STONE_PRESSURE_PLATE.getIdentifier(), 0, 0);
    addBlock(ids_t_b::IRON_DOOR_BLOCK_ID, lce::blocks::IRON_DOOR_BLOCK.getIdentifier(), 0, 0);
    addBlock(ids_t_b::WOODEN_PRESSURE_PLATE_ID, lce::blocks::WOODEN_PRESSURE_PLATE.getIdentifier(), 0, 0);
    addBlock(ids_t_b::REDSTONE_ORE_ID, lce::blocks::REDSTONE_ORE.getIdentifier(), 3, 3);
    addBlock(ids_t_b::GLOWING_REDSTONE_ORE_ID, lce::blocks::GLOWING_REDSTONE_ORE.getIdentifier(), 3, 3); // FIX
    addBlock(ids_t_b::OFF_REDSTONE_TORCH_ID, lce::blocks::OFF_REDSTONE_TORCH.getIdentifier(), 3, 7);
    addBlock(ids_t_b::ON_REDSTONE_TORCH_ID, lce::blocks::ON_REDSTONE_TORCH.getIdentifier(), 3, 6);
    addBlock(ids_t_b::STONE_BUTTON_ID, lce::blocks::STONE_BUTTON.getIdentifier(), 0, 0);
    addBlock(ids_t_b::SNOW_ID, lce::blocks::SNOW.getIdentifier(), 0, 0);
    addBlock(ids_t_b::ICE_ID, lce::blocks::ICE.getIdentifier(), 0, 0);
    addBlock(ids_t_b::SNOW_BLOCK_ID, lce::blocks::SNOW_BLOCK.getIdentifier(), 0, 0);
    addBlock(ids_t_b::CACTUS_ID, lce::blocks::CACTUS.getIdentifier(), 0, 0);
    addBlock(ids_t_b::CLAY_BLOCK_ID, lce::blocks::CLAY_BLOCK.getIdentifier(), 8, 4);
    addBlock(ids_t_b::SUGAR_CANES_ID, lce::blocks::SUGAR_CANES.getIdentifier(), 0, 0);
    addBlock(ids_t_b::JUKEBOX_ID, lce::blocks::JUKEBOX.getIdentifier(), 0, 0);
    addBlock(ids_t_b::OAK_FENCE_ID, lce::blocks::OAK_FENCE.getIdentifier(), 0, 0);
    addBlock(ids_t_b::PUMPKIN_ID, lce::blocks::PUMPKIN.getIdentifier(), 0, 0);
    addBlock(ids_t_b::NETHERRACK_ID, lce::blocks::NETHERRACK.getIdentifier(), 7, 6);
    addBlock(ids_t_b::SOUL_SAND_ID, lce::blocks::SOUL_SAND.getIdentifier(), 8, 6);
    addBlock(ids_t_b::GLOWSTONE_ID, lce::blocks::GLOWSTONE.getIdentifier(), 9, 6);
    addBlock(ids_t_b::NETHER_PORTAL_ID, lce::blocks::NETHER_PORTAL.getIdentifier(), 0, 0);
    addBlock(ids_t_b::JACK_O_LANTERN_ID, lce::blocks::JACK_O_LANTERN.getIdentifier(), 0, 0);
    addBlock(ids_t_b::CAKE_BLOCK_ID, lce::blocks::CAKE_BLOCK.getIdentifier(), 0, 0);
    addBlock(ids_t_b::OFF_REDSTONE_REPEATER_BLOCK_ID, lce::blocks::OFF_REDSTONE_REPEATER_BLOCK.getIdentifier(), 0, 0);
    addBlock(ids_t_b::ON_REDSTONE_REPEATER_BLOCK_ID, lce::blocks::ON_REDSTONE_REPEATER_BLOCK.getIdentifier(), 0, 0);
    addBlock(ids_t_b::WHITE_STAINED_GLASS_ID, lce::blocks::WHITE_STAINED_GLASS.getIdentifier(), 0, 0);
    addBlock(ids_t_b::WOODEN_TRAPDOOR_ID, lce::blocks::WOODEN_TRAPDOOR.getIdentifier(), 0, 0);
    addBlock(ids_t_b::STONE_MONSTER_EGG_ID, lce::blocks::STONE_MONSTER_EGG.getIdentifier(), 0, 0);
    addBlock(ids_t_b::STONE_BRICKS_ID, lce::blocks::STONE_BRICKS.getIdentifier(), 0, 0);
    addBlock(ids_t_b::BROWN_MUSHROOM_BLOCK_ID, lce::blocks::BROWN_MUSHROOM_BLOCK.getIdentifier(), 14, 7);
    addBlock(ids_t_b::RED_MUSHROOM_BLOCK_ID, lce::blocks::RED_MUSHROOM_BLOCK.getIdentifier(), 13, 7);
    addBlock(ids_t_b::IRON_BARS_ID, lce::blocks::IRON_BARS.getIdentifier(), 5, 5);
    addBlock(ids_t_b::GLASS_PANE_ID, lce::blocks::GLASS_PANE.getIdentifier(), 0, 0);
    addBlock(ids_t_b::MELON_BLOCK_ID, lce::blocks::MELON_BLOCK.getIdentifier(), 0, 0);
    addBlock(ids_t_b::PUMPKIN_STEM_ID, lce::blocks::PUMPKIN_STEM.getIdentifier(), 0, 0);
    addBlock(ids_t_b::MELON_STEM_ID, lce::blocks::MELON_STEM.getIdentifier(), 0, 0);
    addBlock(ids_t_b::VINES_ID, lce::blocks::VINES.getIdentifier(), 0, 0);
    addBlock(ids_t_b::OAK_FENCE_GATE_ID, lce::blocks::OAK_FENCE_GATE.getIdentifier(), 0, 0);
    addBlock(ids_t_b::BRICK_STAIRS_ID, lce::blocks::BRICK_STAIRS.getIdentifier(), 0, 0);
    addBlock(ids_t_b::STONE_BRICK_STAIRS_ID, lce::blocks::STONE_BRICK_STAIRS.getIdentifier(), 0, 0);
    addBlock(ids_t_b::MYCELIUM_ID, lce::blocks::MYCELIUM.getIdentifier(), 0, 0);
    addBlock(ids_t_b::LILY_PAD_ID, lce::blocks::LILY_PAD.getIdentifier(), 0, 0);
    addBlock(ids_t_b::NETHER_BRICK_BLOCK_ID, lce::blocks::NETHER_BRICK_BLOCK.getIdentifier(), 0, 14);
    addBlock(ids_t_b::NETHER_BRICK_FENCE_ID, lce::blocks::NETHER_BRICK_FENCE.getIdentifier(), 0, 14); // FIX
    addBlock(ids_t_b::NETHER_BRICK_STAIRS_ID, lce::blocks::NETHER_BRICK_STAIRS.getIdentifier(), 0, 14); // FIX
    addBlock(ids_t_b::NETHER_WART_ID, lce::blocks::NETHER_WART.getIdentifier(), 4, 14); // (2-4,14)
    addBlock(ids_t_b::ENCHANTMENT_TABLE_ID, lce::blocks::ENCHANTMENT_TABLE.getIdentifier(), 6, 11); // (6,10), (6,11), (7, 11)
    addBlock(ids_t_b::BREWING_STAND_ID, lce::blocks::BREWING_STAND.getIdentifier(), 0, 0);
    addBlock(ids_t_b::CAULDRON_ID, lce::blocks::CAULDRON.getIdentifier(), 0, 0);
    addBlock(ids_t_b::END_PORTAL_ID, lce::blocks::END_PORTAL.getIdentifier(), 0, 0);
    addBlock(ids_t_b::END_PORTAL_FRAME_ID, lce::blocks::END_PORTAL_FRAME.getIdentifier(), 0, 0);
    addBlock(ids_t_b::END_STONE_ID, lce::blocks::END_STONE.getIdentifier(), 15, 10);
    addBlock(ids_t_b::DRAGON_EGG_ID, lce::blocks::DRAGON_EGG.getIdentifier(), 7, 10);
    addBlock(ids_t_b::INACTIVE_REDSTONE_LAMP_ID, lce::blocks::INACTIVE_REDSTONE_LAMP.getIdentifier(), 3, 13);
    addBlock(ids_t_b::ACTIVE_REDSTONE_LAMP_ID, lce::blocks::ACTIVE_REDSTONE_LAMP.getIdentifier(), 4, 13);
    addBlock(ids_t_b::DOUBLE_OAK_WOOD_SLAB_ID, lce::blocks::DOUBLE_OAK_WOOD_SLAB.getIdentifier(), 0, 0);
    addBlock(ids_t_b::OAK_WOOD_SLAB_ID, lce::blocks::OAK_WOOD_SLAB.getIdentifier(), 0, 0);
    addBlock(ids_t_b::COCOA_ID, lce::blocks::COCOA.getIdentifier(), 0, 0);
    addBlock(ids_t_b::SANDSTONE_STAIRS_ID, lce::blocks::SANDSTONE_STAIRS.getIdentifier(), 0, 0);
    addBlock(ids_t_b::EMERALD_ORE_ID, lce::blocks::EMERALD_ORE.getIdentifier(), 11, 10);
    addBlock(ids_t_b::ENDER_CHEST_ID, lce::blocks::ENDER_CHEST.getIdentifier(), 0, 0);
    addBlock(ids_t_b::TRIPWIRE_HOOK_ID, lce::blocks::TRIPWIRE_HOOK.getIdentifier(), 12, 10);
    addBlock(ids_t_b::TRIPWIRE_ID, lce::blocks::TRIPWIRE.getIdentifier(), 0, 0);
    addBlock(ids_t_b::EMERALD_BLOCK_ID, lce::blocks::EMERALD_BLOCK.getIdentifier(), 9, 1);
    addBlock(ids_t_b::SPRUCE_WOOD_STAIRS_ID, lce::blocks::SPRUCE_WOOD_STAIRS.getIdentifier(), 0, 0);
    addBlock(ids_t_b::BIRCH_WOOD_STAIRS_ID, lce::blocks::BIRCH_WOOD_STAIRS.getIdentifier(), 0, 0);
    addBlock(ids_t_b::JUNGLE_WOOD_STAIRS_ID, lce::blocks::JUNGLE_WOOD_STAIRS.getIdentifier(), 0, 0);
    addBlock(ids_t_b::COMMAND_BLOCK_ID, lce::blocks::COMMAND_BLOCK.getIdentifier(), 0, 0);
    addBlock(ids_t_b::BEACON_ID, lce::blocks::BEACON.getIdentifier(), 0, 0);
    addBlock(ids_t_b::COBBLESTONE_WALL_ID, lce::blocks::COBBLESTONE_WALL.getIdentifier(), 0, 0);
    addBlock(ids_t_b::FLOWER_POT_ID, lce::blocks::FLOWER_POT.getIdentifier(), 0, 0);
    addBlock(ids_t_b::CARROTS_ID, lce::blocks::CARROTS.getIdentifier(), 11, 12); // (8-11,12)
    addBlock(ids_t_b::POTATOES_ID, lce::blocks::POTATOES.getIdentifier(), 0, 0);
    addBlock(ids_t_b::WOODEN_BUTTON_ID, lce::blocks::WOODEN_BUTTON.getIdentifier(), 0, 0);
    addBlock(ids_t_b::MOB_HEAD_ID, lce::blocks::MOB_HEAD.getIdentifier(), 0, 0);
    addBlock(ids_t_b::ANVIL_ID, lce::blocks::ANVIL.getIdentifier(), 0, 0);
    addBlock(ids_t_b::TRAPPED_CHEST_ID, lce::blocks::TRAPPED_CHEST.getIdentifier(), 0, 0);
    addBlock(ids_t_b::LIGHT_WEIGHTED_PRESSURE_PLATE_ID, lce::blocks::LIGHT_WEIGHTED_PRESSURE_PLATE.getIdentifier(), 0, 0);
    addBlock(ids_t_b::HEAVY_WEIGHTED_PRESSURE_PLATE_ID, lce::blocks::HEAVY_WEIGHTED_PRESSURE_PLATE.getIdentifier(), 0, 0);
    addBlock(ids_t_b::INACTIVE_REDSTONE_COMPARATOR_ID, lce::blocks::INACTIVE_REDSTONE_COMPARATOR.getIdentifier(), 0, 0);
    addBlock(ids_t_b::ACTIVE_REDSTONE_COMPARATOR_ID, lce::blocks::ACTIVE_REDSTONE_COMPARATOR.getIdentifier(), 0, 0);
    addBlock(ids_t_b::DAYLIGHT_SENSOR_ID, lce::blocks::DAYLIGHT_SENSOR.getIdentifier(), 0, 0);
    addBlock(ids_t_b::REDSTONE_BLOCK_ID, lce::blocks::REDSTONE_BLOCK.getIdentifier(), 10, 1);
    addBlock(ids_t_b::NETHER_QUARTZ_ORE_ID, lce::blocks::NETHER_QUARTZ_ORE.getIdentifier(), 15, 11);
    addBlock(ids_t_b::HOPPER_ID, lce::blocks::HOPPER.getIdentifier(), 0, 0);
    addBlock(ids_t_b::QUARTZ_BLOCK_ID, lce::blocks::QUARTZ_BLOCK.getIdentifier(), 0, 0);
    addBlock(ids_t_b::QUARTZ_STAIRS_ID, lce::blocks::QUARTZ_STAIRS.getIdentifier(), 0, 0);
    addBlock(ids_t_b::ACTIVATOR_RAIL_ID, lce::blocks::ACTIVATOR_RAIL.getIdentifier(), 0, 0);
    addBlock(ids_t_b::DROPPER_ID, lce::blocks::DROPPER.getIdentifier(), 0, 0);
    addBlock(ids_t_b::WHITE_HARDENED_CLAY_ID, lce::blocks::WHITE_HARDENED_CLAY.getIdentifier(), 0, 0);
    addBlock(ids_t_b::WHITE_STAINED_GLASS_PANE_ID, lce::blocks::WHITE_STAINED_GLASS_PANE.getIdentifier(), 0, 0);
    addBlock(ids_t_b::ACACIA_LEAVES_ID, lce::blocks::ACACIA_LEAVES.getIdentifier(), 0, 0);
    addBlock(ids_t_b::ACACIA_WOOD_ID, lce::blocks::ACACIA_WOOD.getIdentifier(), 0, 0);
    addBlock(ids_t_b::ACACIA_WOOD_STAIRS_ID, lce::blocks::ACACIA_WOOD_STAIRS.getIdentifier(), 0, 0);
    addBlock(ids_t_b::DARK_OAK_WOOD_STAIRS_ID, lce::blocks::DARK_OAK_WOOD_STAIRS.getIdentifier(), 0, 0);
    addBlock(ids_t_b::SLIME_BLOCK_ID, lce::blocks::SLIME_BLOCK.getIdentifier(), 12, 12);
    addBlock(ids_t_b::BARRIER_ID, lce::blocks::BARRIER.getIdentifier(), 11, 23);
    addBlock(ids_t_b::IRON_TRAPDOOR_ID, lce::blocks::IRON_TRAPDOOR.getIdentifier(), 0, 0);
    addBlock(ids_t_b::PRISMARINE_ID, lce::blocks::PRISMARINE.getIdentifier(), 0, 0);
    addBlock(ids_t_b::SEA_LANTERN_ID, lce::blocks::SEA_LANTERN.getIdentifier(), 0, 0);
    addBlock(ids_t_b::HAY_BALE_ID, lce::blocks::HAY_BALE.getIdentifier(), 10, 15); // (13,15)
    addBlock(ids_t_b::WHITE_CARPET_ID, lce::blocks::WHITE_CARPET.getIdentifier(), 0, 0);
    addBlock(ids_t_b::HARDENED_CLAY_ID, lce::blocks::HARDENED_CLAY.getIdentifier(), 0, 0);
    addBlock(ids_t_b::BLOCK_OF_COAL_ID, lce::blocks::BLOCK_OF_COAL.getIdentifier(), 0, 16);
    addBlock(ids_t_b::PACKED_ICE_ID, lce::blocks::PACKED_ICE.getIdentifier(), 0, 0);
    addBlock(ids_t_b::SUNFLOWER_ID, lce::blocks::SUNFLOWER.getIdentifier(), 0, 0);
    addBlock(ids_t_b::FREE_STANDING_BANNER_ID, lce::blocks::FREE_STANDING_BANNER.getIdentifier(), 0, 0);
    addBlock(ids_t_b::WALL_MOUNTED_BANNER_ID, lce::blocks::WALL_MOUNTED_BANNER.getIdentifier(), 0, 0);
    addBlock(ids_t_b::INVERTED_DAYLIGHT_SENSOR_ID, lce::blocks::INVERTED_DAYLIGHT_SENSOR.getIdentifier(), 0, 0);
    addBlock(ids_t_b::RED_SANDSTONE_ID, lce::blocks::RED_SANDSTONE.getIdentifier(), 0, 0);
    addBlock(ids_t_b::RED_SANDSTONE_STAIRS_ID, lce::blocks::RED_SANDSTONE_STAIRS.getIdentifier(), 0, 0);
    addBlock(ids_t_b::DOUBLE_RED_SANDSTONE_SLAB_ID, lce::blocks::DOUBLE_RED_SANDSTONE_SLAB.getIdentifier(), 0, 0);
    addBlock(ids_t_b::RED_SANDSTONE_SLAB_ID, lce::blocks::RED_SANDSTONE_SLAB.getIdentifier(), 0, 0);
    addBlock(ids_t_b::SPRUCE_FENCE_GATE_ID, lce::blocks::SPRUCE_FENCE_GATE.getIdentifier(), 0, 0);
    addBlock(ids_t_b::BIRCH_FENCE_GATE_ID, lce::blocks::BIRCH_FENCE_GATE.getIdentifier(), 0, 0);
    addBlock(ids_t_b::JUNGLE_FENCE_GATE_ID, lce::blocks::JUNGLE_FENCE_GATE.getIdentifier(), 0, 0);
    addBlock(ids_t_b::DARK_OAK_FENCE_GATE_ID, lce::blocks::DARK_OAK_FENCE_GATE.getIdentifier(), 0, 0);
    addBlock(ids_t_b::ACACIA_FENCE_GATE_ID, lce::blocks::ACACIA_FENCE_GATE.getIdentifier(), 0, 0);
    addBlock(ids_t_b::SPRUCE_FENCE_ID, lce::blocks::SPRUCE_FENCE.getIdentifier(), 0, 0);
    addBlock(ids_t_b::BIRCH_FENCE_ID, lce::blocks::BIRCH_FENCE.getIdentifier(), 0, 0);
    addBlock(ids_t_b::JUNGLE_FENCE_ID, lce::blocks::JUNGLE_FENCE.getIdentifier(), 0, 0);
    addBlock(ids_t_b::DARK_OAK_FENCE_ID, lce::blocks::DARK_OAK_FENCE.getIdentifier(), 0, 0);
    addBlock(ids_t_b::ACACIA_FENCE_ID, lce::blocks::ACACIA_FENCE.getIdentifier(), 0, 0);
    addBlock(ids_t_b::SPRUCE_DOOR_BLOCK_ID, lce::blocks::SPRUCE_DOOR_BLOCK.getIdentifier(), 0, 0);
    addBlock(ids_t_b::BIRCH_DOOR_BLOCK_ID, lce::blocks::BIRCH_DOOR_BLOCK.getIdentifier(), 0, 0);
    addBlock(ids_t_b::JUNGLE_DOOR_BLOCK_ID, lce::blocks::JUNGLE_DOOR_BLOCK.getIdentifier(), 0, 0);
    addBlock(ids_t_b::ACACIA_DOOR_BLOCK_ID, lce::blocks::ACACIA_DOOR_BLOCK.getIdentifier(), 0, 0);
    addBlock(ids_t_b::DARK_OAK_DOOR_BLOCK_ID, lce::blocks::DARK_OAK_DOOR_BLOCK.getIdentifier(), 0, 0);
    addBlock(ids_t_b::END_ROD_ID, lce::blocks::END_ROD.getIdentifier(), 0, 0);
    addBlock(ids_t_b::CHORUS_PLANT_ID, lce::blocks::CHORUS_PLANT.getIdentifier(), 0, 0);
    addBlock(ids_t_b::CHORUS_FLOWER_ID, lce::blocks::CHORUS_FLOWER.getIdentifier(), 0, 0);
    addBlock(ids_t_b::PURPUR_BLOCK_ID, lce::blocks::PURPUR_BLOCK.getIdentifier(), 0, 0);
    addBlock(ids_t_b::PURPUR_PILLAR_ID, lce::blocks::PURPUR_PILLAR.getIdentifier(), 0, 0);
    addBlock(ids_t_b::PURPUR_STAIRS_ID, lce::blocks::PURPUR_STAIRS.getIdentifier(), 0, 0);
    addBlock(ids_t_b::PURPUR_DOUBLE_SLAB_ID, lce::blocks::PURPUR_DOUBLE_SLAB.getIdentifier(), 0, 0);
    addBlock(ids_t_b::PURPUR_SLAB_ID, lce::blocks::PURPUR_SLAB.getIdentifier(), 0, 0);
    addBlock(ids_t_b::END_STONE_BRICKS_ID, lce::blocks::END_STONE_BRICKS.getIdentifier(), 8, 23);
    addBlock(ids_t_b::BEETROOT_BLOCK_ID, lce::blocks::BEETROOT_BLOCK.getIdentifier(), 0, 0);
    addBlock(ids_t_b::GRASS_PATH_ID, lce::blocks::GRASS_PATH.getIdentifier(), 0, 0);
    addBlock(ids_t_b::END_GATEWAY_ID, lce::blocks::END_GATEWAY.getIdentifier(), 0, 0);
    addBlock(ids_t_b::REPEATING_COMMAND_BLOCK_ID, lce::blocks::REPEATING_COMMAND_BLOCK.getIdentifier(), 0, 0);
    addBlock(ids_t_b::CHAIN_COMMAND_BLOCK_ID, lce::blocks::CHAIN_COMMAND_BLOCK.getIdentifier(), 0, 0);
    addBlock(ids_t_b::FROSTED_ICE_ID, lce::blocks::FROSTED_ICE.getIdentifier(), 12, 24); // (12-15,24)
    addBlock(ids_t_b::MAGMA_BLOCK_ID, lce::blocks::MAGMA_BLOCK.getIdentifier(), 9, 24);
    addBlock(ids_t_b::NETHER_WART_BLOCK_ID, lce::blocks::NETHER_WART_BLOCK.getIdentifier(), 10, 24);
    addBlock(ids_t_b::RED_NETHER_BRICK_ID, lce::blocks::RED_NETHER_BRICK.getIdentifier(), 11, 24);
    addBlock(ids_t_b::BONE_BLOCK_ID, lce::blocks::BONE_BLOCK.getIdentifier(), 0, 0);
    addBlock(ids_t_b::STRUCTURE_VOID_ID, lce::blocks::STRUCTURE_VOID.getIdentifier(), 0, 0);
    addBlock(ids_t_b::OBSERVER_ID, lce::blocks::OBSERVER.getIdentifier(), 4, 26); // (4-8,26)
    addBlock(ids_t_b::WHITE_SHULKER_BOX_ID, lce::blocks::WHITE_SHULKER_BOX.getIdentifier(), 0, 0);
    addBlock(ids_t_b::ORANGE_SHULKER_BOX_ID, lce::blocks::ORANGE_SHULKER_BOX.getIdentifier(), 0, 0);
    addBlock(ids_t_b::MAGENTA_SHULKER_BOX_ID, lce::blocks::MAGENTA_SHULKER_BOX.getIdentifier(), 0, 0);
    addBlock(ids_t_b::LIGHT_BLUE_SHULKER_BOX_ID, lce::blocks::LIGHT_BLUE_SHULKER_BOX.getIdentifier(), 0, 0);
    addBlock(ids_t_b::YELLOW_SHULKER_BOX_ID, lce::blocks::YELLOW_SHULKER_BOX.getIdentifier(), 0, 0);
    addBlock(ids_t_b::LIME_SHULKER_BOX_ID, lce::blocks::LIME_SHULKER_BOX.getIdentifier(), 0, 0);
    addBlock(ids_t_b::PINK_SHULKER_BOX_ID, lce::blocks::PINK_SHULKER_BOX.getIdentifier(), 0, 0);
    addBlock(ids_t_b::GRAY_SHULKER_BOX_ID, lce::blocks::GRAY_SHULKER_BOX.getIdentifier(), 0, 0);
    addBlock(ids_t_b::LIGHT_GRAY_SHULKER_BOX_ID, lce::blocks::LIGHT_GRAY_SHULKER_BOX.getIdentifier(), 0, 0);
    addBlock(ids_t_b::CYAN_SHULKER_BOX_ID, lce::blocks::CYAN_SHULKER_BOX.getIdentifier(), 0, 0);
    addBlock(ids_t_b::PURPLE_SHULKER_BOX_ID, lce::blocks::PURPLE_SHULKER_BOX.getIdentifier(), 0, 0);
    addBlock(ids_t_b::BLUE_SHULKER_BOX_ID, lce::blocks::BLUE_SHULKER_BOX.getIdentifier(), 0, 0);
    addBlock(ids_t_b::BROWN_SHULKER_BOX_ID, lce::blocks::BROWN_SHULKER_BOX.getIdentifier(), 0, 0);
    addBlock(ids_t_b::GREEN_SHULKER_BOX_ID, lce::blocks::GREEN_SHULKER_BOX.getIdentifier(), 0, 0);
    addBlock(ids_t_b::RED_SHULKER_BOX_ID, lce::blocks::RED_SHULKER_BOX.getIdentifier(), 0, 0);
    addBlock(ids_t_b::BLACK_SHULKER_BOX_ID, lce::blocks::BLACK_SHULKER_BOX.getIdentifier(), 0, 0);
    addBlock(ids_t_b::WHITE_GLAZED_TERRACOTTA_ID, lce::blocks::WHITE_GLAZED_TERRACOTTA.getIdentifier(), 0, 0);
    addBlock(ids_t_b::ORANGE_GLAZED_TERRACOTTA_ID, lce::blocks::ORANGE_GLAZED_TERRACOTTA.getIdentifier(), 0, 0);
    addBlock(ids_t_b::MAGENTA_GLAZED_TERRACOTTA_ID, lce::blocks::MAGENTA_GLAZED_TERRACOTTA.getIdentifier(), 0, 0);
    addBlock(ids_t_b::LIGHT_BLUE_GLAZED_TERRACOTTA_ID, lce::blocks::LIGHT_BLUE_GLAZED_TERRACOTTA.getIdentifier(), 0, 0);
    addBlock(ids_t_b::YELLOW_GLAZED_TERRACOTTA_ID, lce::blocks::YELLOW_GLAZED_TERRACOTTA.getIdentifier(), 0, 0);
    addBlock(ids_t_b::LIME_GLAZED_TERRACOTTA_ID, lce::blocks::LIME_GLAZED_TERRACOTTA.getIdentifier(), 0, 0);
    addBlock(ids_t_b::PINK_GLAZED_TERRACOTTA_ID, lce::blocks::PINK_GLAZED_TERRACOTTA.getIdentifier(), 0, 0);
    addBlock(ids_t_b::GRAY_GLAZED_TERRACOTTA_ID, lce::blocks::GRAY_GLAZED_TERRACOTTA.getIdentifier(), 0, 0);
    addBlock(ids_t_b::LIGHT_GRAY_GLAZED_TERRACOTTA_ID, lce::blocks::LIGHT_GRAY_GLAZED_TERRACOTTA.getIdentifier(), 0, 0);
    addBlock(ids_t_b::CYAN_GLAZED_TERRACOTTA_ID, lce::blocks::CYAN_GLAZED_TERRACOTTA.getIdentifier(), 0, 0);
    addBlock(ids_t_b::PURPLE_GLAZED_TERRACOTTA_ID, lce::blocks::PURPLE_GLAZED_TERRACOTTA.getIdentifier(), 0, 0);
    addBlock(ids_t_b::BLUE_GLAZED_TERRACOTTA_ID, lce::blocks::BLUE_GLAZED_TERRACOTTA.getIdentifier(), 0, 0);
    addBlock(ids_t_b::BROWN_GLAZED_TERRACOTTA_ID, lce::blocks::BROWN_GLAZED_TERRACOTTA.getIdentifier(), 0, 0);
    addBlock(ids_t_b::GREEN_GLAZED_TERRACOTTA_ID, lce::blocks::GREEN_GLAZED_TERRACOTTA.getIdentifier(), 0, 0);
    addBlock(ids_t_b::RED_GLAZED_TERRACOTTA_ID, lce::blocks::RED_GLAZED_TERRACOTTA.getIdentifier(), 0, 0);
    addBlock(ids_t_b::BLACK_GLAZED_TERRACOTTA_ID, lce::blocks::BLACK_GLAZED_TERRACOTTA.getIdentifier(), 0, 0);
    addBlock(ids_t_b::WHITE_CONCRETE_ID, lce::blocks::WHITE_CONCRETE.getIdentifier(), 0, 0);
    addBlock(ids_t_b::WHITE_CONCRETE_POWDER_ID, lce::blocks::WHITE_CONCRETE_POWDER.getIdentifier(), 0, 0);
    addBlock(ids_t_b::STRUCTURE_BLOCK_ID, lce::blocks::STRUCTURE_BLOCK.getIdentifier(), 13, 26); // (11-15,26)
    addBlock(ids_t_b::CONDUIT_ID, lce::blocks::CONDUIT.getIdentifier(), 0, 0);
    addBlock(ids_t_b::UNKNOWN_PUMPKIN, lce::blocks::UNKNOWN_PUMP.getIdentifier(), 0, 0);
    addBlock(ids_t_b::KELP_ID, lce::blocks::KELP.getIdentifier(), 0, 0);
    addBlock(ids_t_b::CORAL_BLOCK_ID, lce::blocks::CORAL_BLOCK.getIdentifier(), 0, 0);
    addBlock(ids_t_b::CORAL_ID, lce::blocks::CORAL.getIdentifier(), 0, 0);
    addBlock(ids_t_b::CORAL_FAN_ID, lce::blocks::CORAL_FAN.getIdentifier(), 0, 0);
    addBlock(ids_t_b::CORAL_FAN_DEAD_ID, lce::blocks::CORAL_FAN_DEAD.getIdentifier(), 0, 0);
    addBlock(ids_t_b::CORAL_FAN_WALL1_ID, lce::blocks::CORAL_FAN_WALL1.getIdentifier(), 0, 0);
    addBlock(ids_t_b::CORAL_FAN_WALL2_ID, lce::blocks::CORAL_FAN_WALL2.getIdentifier(), 0, 0);
    addBlock(ids_t_b::CORAL_FAN_WALL3_ID, lce::blocks::CORAL_FAN_WALL3.getIdentifier(), 0, 0);
    addBlock(ids_t_b::DRIED_KELP_BLOCK_ID, lce::blocks::DRIED_KELP_BLOCK.getIdentifier(), 0, 0);
    addBlock(ids_t_b::SEAGRASS_ID, lce::blocks::SEAGRASS.getIdentifier(), 0, 0);
    addBlock(ids_t_b::SEAPICKLE_ID, lce::blocks::SEAPICKLE.getIdentifier(), 0, 0);
    addBlock(ids_t_b::BUBBLE_COLUMN_ID, lce::blocks::BUBBLE_COLUMN.getIdentifier(), 0, 0);
    addBlock(ids_t_b::BLUE_ICE_ID, lce::blocks::BLUE_ICE.getIdentifier(), 0, 0);
    addBlock(ids_t_b::SPRUCE_TRAPDOOR_ID, lce::blocks::SPRUCE_TRAPDOOR.getIdentifier(), 0, 0);
    addBlock(ids_t_b::BIRCH_TRAPDOOR_ID, lce::blocks::BIRCH_TRAPDOOR.getIdentifier(), 0, 0);
    addBlock(ids_t_b::JUNGLE_TRAPDOOR_ID, lce::blocks::JUNGLE_TRAPDOOR.getIdentifier(), 0, 0);
    addBlock(ids_t_b::ACACIA_TRAPDOOR_ID, lce::blocks::ACACIA_TRAPDOOR.getIdentifier(), 0, 0);
    addBlock(ids_t_b::DARK_OAK_TRAPDOOR_ID, lce::blocks::DARK_OAK_TRAPDOOR.getIdentifier(), 0, 0);
    addBlock(ids_t_b::TURTLE_EGG_ID_ID, lce::blocks::TURTLE_EGG.getIdentifier(), 0, 0);
    addBlock(ids_t_b::PRISMARINE_STAIRS_ID, lce::blocks::PRISMARINE_STAIRS.getIdentifier(), 0, 0);
    addBlock(ids_t_b::PRISMARINE_BRICK_STAIRS_ID, lce::blocks::PRISMARINE_BRICK_STAIRS.getIdentifier(), 0, 0);
    addBlock(ids_t_b::DARK_PRISMARINE_STAIRS_ID, lce::blocks::DARK_PRISMARINE_STAIRS.getIdentifier(), 0, 0);
    addBlock(ids_t_b::STRIPPED_SPRUCE_LOG_ID, lce::blocks::STRIPPED_SPRUCE_LOG.getIdentifier(), 0, 0);
    addBlock(ids_t_b::STRIPPED_BIRCH_LOG_ID, lce::blocks::STRIPPED_BIRCH_LOG.getIdentifier(), 0, 0);
    addBlock(ids_t_b::STRIPPED_JUNGLE_LOG_ID, lce::blocks::STRIPPED_JUNGLE_LOG.getIdentifier(), 0, 0);
    addBlock(ids_t_b::STRIPPED_ACACIA_LOG_ID, lce::blocks::STRIPPED_ACACIA_LOG.getIdentifier(), 0, 0);
    addBlock(ids_t_b::STRIPPED_DARK_0AK_LOG_ID, lce::blocks::STRIPPED_DARK_0AK_LOG.getIdentifier(), 0, 0);
    addBlock(ids_t_b::STRIPPED_OAK_LOG_ID, lce::blocks::STRIPPED_OAK_LOG.getIdentifier(), 0, 0);
    addBlock(ids_t_b::ACACIA_PRESSURE_PLATE_ID, lce::blocks::ACACIA_PRESSURE_PLATE.getIdentifier(), 0, 0);
    addBlock(ids_t_b::BIRCH_PRESSURE_PLATE_ID, lce::blocks::BIRCH_PRESSURE_PLATE.getIdentifier(), 0, 0);
    addBlock(ids_t_b::DARK_OAK_PRESSURE_PLATE_ID, lce::blocks::DARK_OAK_PRESSURE_PLATE.getIdentifier(), 0, 0);
    addBlock(ids_t_b::JUNGLE_PRESSURE_PLATE_ID, lce::blocks::JUNGLE_PRESSURE_PLATE.getIdentifier(), 0, 0);
    addBlock(ids_t_b::SPRUCE_PRESSURE_PLATE_ID, lce::blocks::SPRUCE_PRESSURE_PLATE.getIdentifier(), 0, 0);
    addBlock(ids_t_b::ACACIA_BUTTON_ID, lce::blocks::ACACIA_BUTTON.getIdentifier(), 0, 0);
    addBlock(ids_t_b::BIRCH_BUTTON_ID, lce::blocks::BIRCH_BUTTON.getIdentifier(), 0, 0);
    addBlock(ids_t_b::DARK_OAK_BUTTON_ID, lce::blocks::DARK_OAK_BUTTON.getIdentifier(), 0, 0);
    addBlock(ids_t_b::JUNGLE_BUTTON_ID, lce::blocks::JUNGLE_BUTTON.getIdentifier(), 0, 0);
    addBlock(ids_t_b::SPRUCE_BUTTON_ID, lce::blocks::SPRUCE_BUTTON.getIdentifier(), 0, 0);
    addBlock(ids_t_b::DOUBLE_PRISMARINE_SLAB_ID, lce::blocks::DOUBLE_PRISMARINE_SLAB.getIdentifier(), 0, 0);
    addBlock(ids_t_b::PRISMARINE_SLAB_ID, lce::blocks::PRISMARINE_SLAB.getIdentifier(), 0, 0);
    addBlock(ids_t_b::SPRUCE_WOOD_2_ID, lce::blocks::SPRUCE_WOOD_2.getIdentifier(), 0, 0);
    addBlock(ids_t_b::BIRCH_WOOD_2_ID, lce::blocks::BIRCH_WOOD_2.getIdentifier(), 0, 0);
    addBlock(ids_t_b::JUNGLE_WOOD_2_ID, lce::blocks::JUNGLE_WOOD_2.getIdentifier(), 0, 0);
    addBlock(ids_t_b::ACACIA_WOOD_2_ID, lce::blocks::ACACIA_WOOD_2.getIdentifier(), 0, 0);
    addBlock(ids_t_b::DARK_OAK_WOOD_2_ID, lce::blocks::DARK_OAK_WOOD_2.getIdentifier(), 0, 0);
    addBlock(ids_t_b::OAK_WOOD_2_ID, lce::blocks::OAK_WOOD_2.getIdentifier(), 0, 0);

}

/*
void TextureMap::setupItems() {

}
 */