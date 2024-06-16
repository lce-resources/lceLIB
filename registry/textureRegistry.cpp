#include "lce/blocks/block_ids.hpp"
#include "lce/blocks/blocks.hpp"
#include "lce/items/item_ids.hpp"
#include "textureRegistry.hpp"


namespace lce::registry {


    const std::string TextureRegistry::BLOCK_TEXTURE_FILE = "lce/assets/terrain.png";
    bool TextureRegistry::isSetup = false;


    Picture const* TextureRegistry::getBlockFromID(int id) {
        return textureRegistry.getObjFromId(id);
    }


    Picture const* TextureRegistry::getBlockFromName(const std::string& name) {
        return textureRegistry.getObjFromName(name);
    }


    void TextureRegistry::setup() {
        if (isSetup) { return; }

        textureRegistry.setName("BLOCK_TEXTURES");

        blockPicture.loadFromFile(BLOCK_TEXTURE_FILE.c_str());
        if (blockPicture.myWidth != BLOCK_TEXTURE_WIDTH
            || blockPicture.myHeight != BLOCK_TEXTURE_HEIGHT) {
            throw std::runtime_error("failed to load " + BLOCK_TEXTURE_FILE);
        }
        setUpTextures();
        isSetup = true;
    }


    void TextureRegistry::deallocate() {
        if (!isSetup) { return; }
        textureRegistry.clear(true);
        isSetup = false;
    }


    void TextureRegistry::addBlock(int theID, const std::string& theIdentifier,
                                   uint32_t theX, uint32_t theY) {
        static constexpr uint32_t CELL = 16;
        auto tempPic = new Picture(CELL, CELL);
        blockPicture.getSubImage(*tempPic, CELL * theX, CELL * theY);
        textureRegistry.registerValue(theID, theIdentifier, tempPic);
    }


    void TextureRegistry::setUpTextures() {
        namespace ids_t_b = lce::blocks::ids;
        addBlock(ids_t_b::AIR_ID, lce::blocks::AIR.getName(), 15, 31); // FIX
        addBlock(ids_t_b::STONE_ID, lce::blocks::STONE.getName(), 1, 0);
        addBlock(ids_t_b::GRASS_ID, lce::blocks::GRASS.getName(), 3, 0);
        addBlock(ids_t_b::DIRT_ID, lce::blocks::DIRT.getName(), 2, 0);
        addBlock(ids_t_b::COBBLESTONE_ID, lce::blocks::COBBLESTONE.getName(), 0, 1);
        addBlock(ids_t_b::OAK_WOOD_PLANK_ID, lce::blocks::OAK_WOOD_PLANK.getName(), 4, 0);
        addBlock(ids_t_b::OAK_SAPLING_ID, lce::blocks::OAK_SAPLING.getName(), 15, 0);
        addBlock(ids_t_b::BEDROCK_ID, lce::blocks::BEDROCK.getName(), 1, 1);
        addBlock(ids_t_b::FLOWING_WATER_ID, lce::blocks::FLOWING_WATER.getName(), 13, 12);
        addBlock(ids_t_b::STILL_WATER_ID, lce::blocks::STILL_WATER.getName(), 13, 12);
        addBlock(ids_t_b::FLOWING_LAVA_ID, lce::blocks::FLOWING_LAVA.getName(), 13, 14);
        addBlock(ids_t_b::STILL_LAVA_ID, lce::blocks::STILL_LAVA.getName(), 13, 14);
        addBlock(ids_t_b::SAND_ID, lce::blocks::SAND.getName(), 2, 1);
        addBlock(ids_t_b::GRAVEL_ID, lce::blocks::GRAVEL.getName(), 3, 1);
        addBlock(ids_t_b::GOLD_ORE_ID, lce::blocks::GOLD_ORE.getName(), 0, 2);
        addBlock(ids_t_b::IRON_ORE_ID, lce::blocks::IRON_ORE.getName(), 1, 2);
        addBlock(ids_t_b::COAL_ORE_ID, lce::blocks::COAL_ORE.getName(), 2, 2);
        addBlock(ids_t_b::OAK_WOOD_ID, lce::blocks::OAK_WOOD.getName(), 4, 1); // bottom(5,1)
        addBlock(ids_t_b::OAK_LEAVES_ID, lce::blocks::OAK_LEAVES.getName(), 0, 0);
        addBlock(ids_t_b::SPONGE_ID, lce::blocks::SPONGE.getName(), 0, 3); // (12,8)
        addBlock(ids_t_b::GLASS_ID, lce::blocks::GLASS.getName(), 0, 0);
        addBlock(ids_t_b::LAPIS_LAZULI_ORE_ID, lce::blocks::LAPIS_LAZULI_ORE.getName(), 0, 10);
        addBlock(ids_t_b::LAPIS_LAZULI_BLOCK_ID, lce::blocks::LAPIS_LAZULI_BLOCK.getName(), 0, 9);
        addBlock(ids_t_b::DISPENSER_ID, lce::blocks::DISPENSER.getName(), 11, 1);
        addBlock(ids_t_b::SANDSTONE_ID, lce::blocks::SANDSTONE.getName(), 0, 0);
        addBlock(ids_t_b::NOTE_BLOCK_ID, lce::blocks::NOTE_BLOCK.getName(), 2, 16);
        addBlock(ids_t_b::BED_BLOCK_ID, lce::blocks::BED_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::POWERED_RAIL_ID, lce::blocks::POWERED_RAIL.getName(), 0, 0);
        addBlock(ids_t_b::DETECTOR_RAIL_ID, lce::blocks::DETECTOR_RAIL.getName(), 0, 0);
        addBlock(ids_t_b::STICKY_PISTON_ID, lce::blocks::STICKY_PISTON.getName(), 0, 0);
        addBlock(ids_t_b::COBWEB_ID, lce::blocks::COBWEB.getName(), 11, 0);
        addBlock(ids_t_b::TALL_GRASS_SHRUB_ID, lce::blocks::TALL_GRASS_SHRUB.getName(), 0, 0);
        addBlock(ids_t_b::DEAD_BUSH_ID, lce::blocks::DEAD_BUSH.getName(), 0, 0);
        addBlock(ids_t_b::PISTON_ID, lce::blocks::PISTON.getName(), 0, 0);
        addBlock(ids_t_b::PISTON_HEAD_ID, lce::blocks::PISTON_HEAD.getName(), 0, 0);
        addBlock(ids_t_b::WHITE_WOOL_ID, lce::blocks::WHITE_WOOL.getName(), 0, 0);
        addBlock(ids_t_b::DANDELION_ID, lce::blocks::DANDELION.getName(), 13, 0);
        addBlock(ids_t_b::POPPY_ID, lce::blocks::POPPY.getName(), 12, 0);
        addBlock(ids_t_b::BROWN_MUSHROOM_ID, lce::blocks::BROWN_MUSHROOM.getName(), 13, 1);
        addBlock(ids_t_b::RED_MUSHROOM_ID, lce::blocks::RED_MUSHROOM.getName(), 12, 1);
        addBlock(ids_t_b::GOLD_BLOCK_ID, lce::blocks::GOLD_BLOCK.getName(), 7, 1);
        addBlock(ids_t_b::IRON_BLOCK_ID, lce::blocks::IRON_BLOCK.getName(), 6, 1);
        addBlock(ids_t_b::DOUBLE_STONE_SLAB_ID, lce::blocks::DOUBLE_STONE_SLAB.getName(), 0, 0);
        addBlock(ids_t_b::STONE_SLAB_ID, lce::blocks::STONE_SLAB.getName(), 0, 0);
        addBlock(ids_t_b::BRICKS_ID, lce::blocks::BRICKS.getName(), 7, 0);
        addBlock(ids_t_b::TNT_ID, lce::blocks::TNT.getName(), 8, 0); // (9,0), (10,0)
        addBlock(ids_t_b::BOOKSHELF_ID, lce::blocks::BOOKSHELF.getName(), 3, 2);
        addBlock(ids_t_b::MOSS_STONE_ID, lce::blocks::MOSS_STONE.getName(), 4, 2);
        addBlock(ids_t_b::OBSIDIAN_ID, lce::blocks::OBSIDIAN.getName(), 5, 2);
        addBlock(ids_t_b::TORCH_ID, lce::blocks::TORCH.getName(), 0, 5);
        addBlock(ids_t_b::FIRE_ID, lce::blocks::FIRE.getName(), 0, 0);
        addBlock(ids_t_b::MONSTER_SPAWNER_ID, lce::blocks::MONSTER_SPAWNER.getName(), 0, 0);
        addBlock(ids_t_b::OAK_WOOD_STAIRS_ID, lce::blocks::OAK_WOOD_STAIRS.getName(), 0, 0);
        addBlock(ids_t_b::CHEST_ID, lce::blocks::CHEST.getName(), 0, 0);
        addBlock(ids_t_b::REDSTONE_WIRE_ID, lce::blocks::REDSTONE_WIRE.getName(), 0, 0);
        addBlock(ids_t_b::DIAMOND_ORE_ID, lce::blocks::DIAMOND_ORE.getName(), 2, 3);
        addBlock(ids_t_b::DIAMOND_BLOCK_ID, lce::blocks::DIAMOND_BLOCK.getName(), 8, 1);
        addBlock(ids_t_b::CRAFTING_TABLE_ID, lce::blocks::CRAFTING_TABLE.getName(), 11, 3); // (12,3), (11,2)
        addBlock(ids_t_b::WHEAT_CROPS_ID, lce::blocks::WHEAT_CROPS.getName(), 15, 5);       // (8-15,5)
        addBlock(ids_t_b::FARMLAND_ID, lce::blocks::FARMLAND.getName(), 0, 0);
        addBlock(ids_t_b::FURNACE_ID, lce::blocks::FURNACE.getName(), 12, 2);                 // (13,2), (14,3)
        addBlock(ids_t_b::BURNING_FURNACE_ID, lce::blocks::BURNING_FURNACE.getName(), 13, 3); // (13,2), (14,3)
        addBlock(ids_t_b::STANDING_SIGN_BLOCK_ID, lce::blocks::STANDING_SIGN_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::OAK_DOOR_BLOCK_ID, lce::blocks::OAK_DOOR_BLOCK.getName(), 1, 5); // (1,6)
        addBlock(ids_t_b::LADDER_ID, lce::blocks::LADDER.getName(), 3, 5);
        addBlock(ids_t_b::RAIL_ID, lce::blocks::RAIL.getName(), 0, 0);
        addBlock(ids_t_b::COBBLESTONE_STAIRS_ID, lce::blocks::COBBLESTONE_STAIRS.getName(), 0, 0);
        addBlock(ids_t_b::WALL_MOUNTED_SIGN_BLOCK_ID, lce::blocks::WALL_MOUNTED_SIGN_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::LEVER_ID, lce::blocks::LEVER.getName(), 0, 0);
        addBlock(ids_t_b::STONE_PRESSURE_PLATE_ID, lce::blocks::STONE_PRESSURE_PLATE.getName(), 0, 0);
        addBlock(ids_t_b::IRON_DOOR_BLOCK_ID, lce::blocks::IRON_DOOR_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::WOODEN_PRESSURE_PLATE_ID, lce::blocks::WOODEN_PRESSURE_PLATE.getName(), 0, 0);
        addBlock(ids_t_b::REDSTONE_ORE_ID, lce::blocks::REDSTONE_ORE.getName(), 3, 3);
        addBlock(ids_t_b::GLOWING_REDSTONE_ORE_ID, lce::blocks::GLOWING_REDSTONE_ORE.getName(), 3, 3); // FIX
        addBlock(ids_t_b::OFF_REDSTONE_TORCH_ID, lce::blocks::OFF_REDSTONE_TORCH.getName(), 3, 7);
        addBlock(ids_t_b::ON_REDSTONE_TORCH_ID, lce::blocks::ON_REDSTONE_TORCH.getName(), 3, 6);
        addBlock(ids_t_b::STONE_BUTTON_ID, lce::blocks::STONE_BUTTON.getName(), 0, 0);
        addBlock(ids_t_b::SNOW_ID, lce::blocks::SNOW.getName(), 0, 0);
        addBlock(ids_t_b::ICE_ID, lce::blocks::ICE.getName(), 0, 0);
        addBlock(ids_t_b::SNOW_BLOCK_ID, lce::blocks::SNOW_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::CACTUS_ID, lce::blocks::CACTUS.getName(), 0, 0);
        addBlock(ids_t_b::CLAY_BLOCK_ID, lce::blocks::CLAY_BLOCK.getName(), 8, 4);
        addBlock(ids_t_b::SUGAR_CANES_ID, lce::blocks::SUGAR_CANES.getName(), 0, 0);
        addBlock(ids_t_b::JUKEBOX_ID, lce::blocks::JUKEBOX.getName(), 0, 0);
        addBlock(ids_t_b::OAK_FENCE_ID, lce::blocks::OAK_FENCE.getName(), 0, 0);
        addBlock(ids_t_b::PUMPKIN_ID, lce::blocks::PUMPKIN.getName(), 0, 0);
        addBlock(ids_t_b::NETHERRACK_ID, lce::blocks::NETHERRACK.getName(), 7, 6);
        addBlock(ids_t_b::SOUL_SAND_ID, lce::blocks::SOUL_SAND.getName(), 8, 6);
        addBlock(ids_t_b::GLOWSTONE_ID, lce::blocks::GLOWSTONE.getName(), 9, 6);
        addBlock(ids_t_b::NETHER_PORTAL_ID, lce::blocks::NETHER_PORTAL.getName(), 0, 0);
        addBlock(ids_t_b::JACK_O_LANTERN_ID, lce::blocks::JACK_O_LANTERN.getName(), 0, 0);
        addBlock(ids_t_b::CAKE_BLOCK_ID, lce::blocks::CAKE_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::OFF_REDSTONE_REPEATER_BLOCK_ID, lce::blocks::OFF_REDSTONE_REPEATER_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::ON_REDSTONE_REPEATER_BLOCK_ID, lce::blocks::ON_REDSTONE_REPEATER_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::WHITE_STAINED_GLASS_ID, lce::blocks::WHITE_STAINED_GLASS.getName(), 0, 0);
        addBlock(ids_t_b::WOODEN_TRAPDOOR_ID, lce::blocks::WOODEN_TRAPDOOR.getName(), 0, 0);
        addBlock(ids_t_b::STONE_MONSTER_EGG_ID, lce::blocks::STONE_MONSTER_EGG.getName(), 0, 0);
        addBlock(ids_t_b::STONE_BRICKS_ID, lce::blocks::STONE_BRICKS.getName(), 0, 0);
        addBlock(ids_t_b::BROWN_MUSHROOM_BLOCK_ID, lce::blocks::BROWN_MUSHROOM_BLOCK.getName(), 14, 7);
        addBlock(ids_t_b::RED_MUSHROOM_BLOCK_ID, lce::blocks::RED_MUSHROOM_BLOCK.getName(), 13, 7);
        addBlock(ids_t_b::IRON_BARS_ID, lce::blocks::IRON_BARS.getName(), 5, 5);
        addBlock(ids_t_b::GLASS_PANE_ID, lce::blocks::GLASS_PANE.getName(), 0, 0);
        addBlock(ids_t_b::MELON_BLOCK_ID, lce::blocks::MELON_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::PUMPKIN_STEM_ID, lce::blocks::PUMPKIN_STEM.getName(), 0, 0);
        addBlock(ids_t_b::MELON_STEM_ID, lce::blocks::MELON_STEM.getName(), 0, 0);
        addBlock(ids_t_b::VINES_ID, lce::blocks::VINES.getName(), 0, 0);
        addBlock(ids_t_b::OAK_FENCE_GATE_ID, lce::blocks::OAK_FENCE_GATE.getName(), 0, 0);
        addBlock(ids_t_b::BRICK_STAIRS_ID, lce::blocks::BRICK_STAIRS.getName(), 0, 0);
        addBlock(ids_t_b::STONE_BRICK_STAIRS_ID, lce::blocks::STONE_BRICK_STAIRS.getName(), 0, 0);
        addBlock(ids_t_b::MYCELIUM_ID, lce::blocks::MYCELIUM.getName(), 0, 0);
        addBlock(ids_t_b::LILY_PAD_ID, lce::blocks::LILY_PAD.getName(), 0, 0);
        addBlock(ids_t_b::NETHER_BRICK_BLOCK_ID, lce::blocks::NETHER_BRICK_BLOCK.getName(), 0, 14);
        addBlock(ids_t_b::NETHER_BRICK_FENCE_ID, lce::blocks::NETHER_BRICK_FENCE.getName(), 0, 14);   // FIX
        addBlock(ids_t_b::NETHER_BRICK_STAIRS_ID, lce::blocks::NETHER_BRICK_STAIRS.getName(), 0, 14); // FIX
        addBlock(ids_t_b::NETHER_WART_ID, lce::blocks::NETHER_WART.getName(), 4, 14);                 // (2-4,14)
        addBlock(ids_t_b::ENCHANTMENT_TABLE_ID, lce::blocks::ENCHANTMENT_TABLE.getName(), 6, 11);     // (6,10), (6,11), (7, 11)
        addBlock(ids_t_b::BREWING_STAND_ID, lce::blocks::BREWING_STAND.getName(), 0, 0);
        addBlock(ids_t_b::CAULDRON_ID, lce::blocks::CAULDRON.getName(), 0, 0);
        addBlock(ids_t_b::END_PORTAL_ID, lce::blocks::END_PORTAL.getName(), 0, 0);
        addBlock(ids_t_b::END_PORTAL_FRAME_ID, lce::blocks::END_PORTAL_FRAME.getName(), 0, 0);
        addBlock(ids_t_b::END_STONE_ID, lce::blocks::END_STONE.getName(), 15, 10);
        addBlock(ids_t_b::DRAGON_EGG_ID, lce::blocks::DRAGON_EGG.getName(), 7, 10);
        addBlock(ids_t_b::INACTIVE_REDSTONE_LAMP_ID, lce::blocks::INACTIVE_REDSTONE_LAMP.getName(), 3, 13);
        addBlock(ids_t_b::ACTIVE_REDSTONE_LAMP_ID, lce::blocks::ACTIVE_REDSTONE_LAMP.getName(), 4, 13);
        addBlock(ids_t_b::DOUBLE_OAK_WOOD_SLAB_ID, lce::blocks::DOUBLE_OAK_WOOD_SLAB.getName(), 0, 0);
        addBlock(ids_t_b::OAK_WOOD_SLAB_ID, lce::blocks::OAK_WOOD_SLAB.getName(), 0, 0);
        addBlock(ids_t_b::COCOA_ID, lce::blocks::COCOA.getName(), 0, 0);
        addBlock(ids_t_b::SANDSTONE_STAIRS_ID, lce::blocks::SANDSTONE_STAIRS.getName(), 0, 0);
        addBlock(ids_t_b::EMERALD_ORE_ID, lce::blocks::EMERALD_ORE.getName(), 11, 10);
        addBlock(ids_t_b::ENDER_CHEST_ID, lce::blocks::ENDER_CHEST.getName(), 0, 0);
        addBlock(ids_t_b::TRIPWIRE_HOOK_ID, lce::blocks::TRIPWIRE_HOOK.getName(), 12, 10);
        addBlock(ids_t_b::TRIPWIRE_ID, lce::blocks::TRIPWIRE.getName(), 0, 0);
        addBlock(ids_t_b::EMERALD_BLOCK_ID, lce::blocks::EMERALD_BLOCK.getName(), 9, 1);
        addBlock(ids_t_b::SPRUCE_WOOD_STAIRS_ID, lce::blocks::SPRUCE_WOOD_STAIRS.getName(), 0, 0);
        addBlock(ids_t_b::BIRCH_WOOD_STAIRS_ID, lce::blocks::BIRCH_WOOD_STAIRS.getName(), 0, 0);
        addBlock(ids_t_b::JUNGLE_WOOD_STAIRS_ID, lce::blocks::JUNGLE_WOOD_STAIRS.getName(), 0, 0);
        addBlock(ids_t_b::COMMAND_BLOCK_ID, lce::blocks::COMMAND_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::BEACON_ID, lce::blocks::BEACON.getName(), 0, 0);
        addBlock(ids_t_b::COBBLESTONE_WALL_ID, lce::blocks::COBBLESTONE_WALL.getName(), 0, 0);
        addBlock(ids_t_b::FLOWER_POT_ID, lce::blocks::FLOWER_POT.getName(), 0, 0);
        addBlock(ids_t_b::CARROTS_ID, lce::blocks::CARROTS.getName(), 11, 12); // (8-11,12)
        addBlock(ids_t_b::POTATOES_ID, lce::blocks::POTATOES.getName(), 0, 0);
        addBlock(ids_t_b::WOODEN_BUTTON_ID, lce::blocks::WOODEN_BUTTON.getName(), 0, 0);
        addBlock(ids_t_b::MOB_HEAD_ID, lce::blocks::MOB_HEAD.getName(), 0, 0);
        addBlock(ids_t_b::ANVIL_ID, lce::blocks::ANVIL.getName(), 0, 0);
        addBlock(ids_t_b::TRAPPED_CHEST_ID, lce::blocks::TRAPPED_CHEST.getName(), 0, 0);
        addBlock(ids_t_b::LIGHT_WEIGHTED_PRESSURE_PLATE_ID, lce::blocks::LIGHT_WEIGHTED_PRESSURE_PLATE.getName(), 0, 0);
        addBlock(ids_t_b::HEAVY_WEIGHTED_PRESSURE_PLATE_ID, lce::blocks::HEAVY_WEIGHTED_PRESSURE_PLATE.getName(), 0, 0);
        addBlock(ids_t_b::INACTIVE_REDSTONE_COMPARATOR_ID, lce::blocks::INACTIVE_REDSTONE_COMPARATOR.getName(), 0, 0);
        addBlock(ids_t_b::ACTIVE_REDSTONE_COMPARATOR_ID, lce::blocks::ACTIVE_REDSTONE_COMPARATOR.getName(), 0, 0);
        addBlock(ids_t_b::DAYLIGHT_SENSOR_ID, lce::blocks::DAYLIGHT_SENSOR.getName(), 0, 0);
        addBlock(ids_t_b::REDSTONE_BLOCK_ID, lce::blocks::REDSTONE_BLOCK.getName(), 10, 1);
        addBlock(ids_t_b::NETHER_QUARTZ_ORE_ID, lce::blocks::NETHER_QUARTZ_ORE.getName(), 15, 11);
        addBlock(ids_t_b::HOPPER_ID, lce::blocks::HOPPER.getName(), 0, 0);
        addBlock(ids_t_b::QUARTZ_BLOCK_ID, lce::blocks::QUARTZ_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::QUARTZ_STAIRS_ID, lce::blocks::QUARTZ_STAIRS.getName(), 0, 0);
        addBlock(ids_t_b::ACTIVATOR_RAIL_ID, lce::blocks::ACTIVATOR_RAIL.getName(), 0, 0);
        addBlock(ids_t_b::DROPPER_ID, lce::blocks::DROPPER.getName(), 0, 0);
        addBlock(ids_t_b::WHITE_HARDENED_CLAY_ID, lce::blocks::WHITE_HARDENED_CLAY.getName(), 0, 0);
        addBlock(ids_t_b::WHITE_STAINED_GLASS_PANE_ID, lce::blocks::WHITE_STAINED_GLASS_PANE.getName(), 0, 0);
        addBlock(ids_t_b::ACACIA_LEAVES_ID, lce::blocks::ACACIA_LEAVES.getName(), 0, 0);
        addBlock(ids_t_b::ACACIA_WOOD_ID, lce::blocks::ACACIA_WOOD.getName(), 0, 0);
        addBlock(ids_t_b::ACACIA_WOOD_STAIRS_ID, lce::blocks::ACACIA_WOOD_STAIRS.getName(), 0, 0);
        addBlock(ids_t_b::DARK_OAK_WOOD_STAIRS_ID, lce::blocks::DARK_OAK_WOOD_STAIRS.getName(), 0, 0);
        addBlock(ids_t_b::SLIME_BLOCK_ID, lce::blocks::SLIME_BLOCK.getName(), 12, 12);
        addBlock(ids_t_b::BARRIER_ID, lce::blocks::BARRIER.getName(), 11, 23);
        addBlock(ids_t_b::IRON_TRAPDOOR_ID, lce::blocks::IRON_TRAPDOOR.getName(), 0, 0);
        addBlock(ids_t_b::PRISMARINE_ID, lce::blocks::PRISMARINE.getName(), 0, 0);
        addBlock(ids_t_b::SEA_LANTERN_ID, lce::blocks::SEA_LANTERN.getName(), 0, 0);
        addBlock(ids_t_b::HAY_BALE_ID, lce::blocks::HAY_BALE.getName(), 10, 15); // (13,15)
        addBlock(ids_t_b::WHITE_CARPET_ID, lce::blocks::WHITE_CARPET.getName(), 0, 0);
        addBlock(ids_t_b::HARDENED_CLAY_ID, lce::blocks::HARDENED_CLAY.getName(), 0, 0);
        addBlock(ids_t_b::BLOCK_OF_COAL_ID, lce::blocks::BLOCK_OF_COAL.getName(), 0, 16);
        addBlock(ids_t_b::PACKED_ICE_ID, lce::blocks::PACKED_ICE.getName(), 0, 0);
        addBlock(ids_t_b::SUNFLOWER_ID, lce::blocks::SUNFLOWER.getName(), 0, 0);
        addBlock(ids_t_b::FREE_STANDING_BANNER_ID, lce::blocks::FREE_STANDING_BANNER.getName(), 0, 0);
        addBlock(ids_t_b::WALL_MOUNTED_BANNER_ID, lce::blocks::WALL_MOUNTED_BANNER.getName(), 0, 0);
        addBlock(ids_t_b::INVERTED_DAYLIGHT_SENSOR_ID, lce::blocks::INVERTED_DAYLIGHT_SENSOR.getName(), 0, 0);
        addBlock(ids_t_b::RED_SANDSTONE_ID, lce::blocks::RED_SANDSTONE.getName(), 0, 0);
        addBlock(ids_t_b::RED_SANDSTONE_STAIRS_ID, lce::blocks::RED_SANDSTONE_STAIRS.getName(), 0, 0);
        addBlock(ids_t_b::DOUBLE_RED_SANDSTONE_SLAB_ID, lce::blocks::DOUBLE_RED_SANDSTONE_SLAB.getName(), 0, 0);
        addBlock(ids_t_b::RED_SANDSTONE_SLAB_ID, lce::blocks::RED_SANDSTONE_SLAB.getName(), 0, 0);
        addBlock(ids_t_b::SPRUCE_FENCE_GATE_ID, lce::blocks::SPRUCE_FENCE_GATE.getName(), 0, 0);
        addBlock(ids_t_b::BIRCH_FENCE_GATE_ID, lce::blocks::BIRCH_FENCE_GATE.getName(), 0, 0);
        addBlock(ids_t_b::JUNGLE_FENCE_GATE_ID, lce::blocks::JUNGLE_FENCE_GATE.getName(), 0, 0);
        addBlock(ids_t_b::DARK_OAK_FENCE_GATE_ID, lce::blocks::DARK_OAK_FENCE_GATE.getName(), 0, 0);
        addBlock(ids_t_b::ACACIA_FENCE_GATE_ID, lce::blocks::ACACIA_FENCE_GATE.getName(), 0, 0);
        addBlock(ids_t_b::SPRUCE_FENCE_ID, lce::blocks::SPRUCE_FENCE.getName(), 0, 0);
        addBlock(ids_t_b::BIRCH_FENCE_ID, lce::blocks::BIRCH_FENCE.getName(), 0, 0);
        addBlock(ids_t_b::JUNGLE_FENCE_ID, lce::blocks::JUNGLE_FENCE.getName(), 0, 0);
        addBlock(ids_t_b::DARK_OAK_FENCE_ID, lce::blocks::DARK_OAK_FENCE.getName(), 0, 0);
        addBlock(ids_t_b::ACACIA_FENCE_ID, lce::blocks::ACACIA_FENCE.getName(), 0, 0);
        addBlock(ids_t_b::SPRUCE_DOOR_BLOCK_ID, lce::blocks::SPRUCE_DOOR_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::BIRCH_DOOR_BLOCK_ID, lce::blocks::BIRCH_DOOR_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::JUNGLE_DOOR_BLOCK_ID, lce::blocks::JUNGLE_DOOR_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::ACACIA_DOOR_BLOCK_ID, lce::blocks::ACACIA_DOOR_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::DARK_OAK_DOOR_BLOCK_ID, lce::blocks::DARK_OAK_DOOR_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::END_ROD_ID, lce::blocks::END_ROD.getName(), 0, 0);
        addBlock(ids_t_b::CHORUS_PLANT_ID, lce::blocks::CHORUS_PLANT.getName(), 0, 0);
        addBlock(ids_t_b::CHORUS_FLOWER_ID, lce::blocks::CHORUS_FLOWER.getName(), 0, 0);
        addBlock(ids_t_b::PURPUR_BLOCK_ID, lce::blocks::PURPUR_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::PURPUR_PILLAR_ID, lce::blocks::PURPUR_PILLAR.getName(), 0, 0);
        addBlock(ids_t_b::PURPUR_STAIRS_ID, lce::blocks::PURPUR_STAIRS.getName(), 0, 0);
        addBlock(ids_t_b::PURPUR_DOUBLE_SLAB_ID, lce::blocks::PURPUR_DOUBLE_SLAB.getName(), 0, 0);
        addBlock(ids_t_b::PURPUR_SLAB_ID, lce::blocks::PURPUR_SLAB.getName(), 0, 0);
        addBlock(ids_t_b::END_STONE_BRICKS_ID, lce::blocks::END_STONE_BRICKS.getName(), 8, 23);
        addBlock(ids_t_b::BEETROOT_BLOCK_ID, lce::blocks::BEETROOT_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::GRASS_PATH_ID, lce::blocks::GRASS_PATH.getName(), 0, 0);
        addBlock(ids_t_b::END_GATEWAY_ID, lce::blocks::END_GATEWAY.getName(), 0, 0);
        addBlock(ids_t_b::REPEATING_COMMAND_BLOCK_ID, lce::blocks::REPEATING_COMMAND_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::CHAIN_COMMAND_BLOCK_ID, lce::blocks::CHAIN_COMMAND_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::FROSTED_ICE_ID, lce::blocks::FROSTED_ICE.getName(), 12, 24); // (12-15,24)
        addBlock(ids_t_b::MAGMA_BLOCK_ID, lce::blocks::MAGMA_BLOCK.getName(), 9, 24);
        addBlock(ids_t_b::NETHER_WART_BLOCK_ID, lce::blocks::NETHER_WART_BLOCK.getName(), 10, 24);
        addBlock(ids_t_b::RED_NETHER_BRICK_ID, lce::blocks::RED_NETHER_BRICK.getName(), 11, 24);
        addBlock(ids_t_b::BONE_BLOCK_ID, lce::blocks::BONE_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::STRUCTURE_VOID_ID, lce::blocks::STRUCTURE_VOID.getName(), 0, 0);
        addBlock(ids_t_b::OBSERVER_ID, lce::blocks::OBSERVER.getName(), 4, 26); // (4-8,26)
        addBlock(ids_t_b::WHITE_SHULKER_BOX_ID, lce::blocks::WHITE_SHULKER_BOX.getName(), 0, 0);
        addBlock(ids_t_b::ORANGE_SHULKER_BOX_ID, lce::blocks::ORANGE_SHULKER_BOX.getName(), 0, 0);
        addBlock(ids_t_b::MAGENTA_SHULKER_BOX_ID, lce::blocks::MAGENTA_SHULKER_BOX.getName(), 0, 0);
        addBlock(ids_t_b::LIGHT_BLUE_SHULKER_BOX_ID, lce::blocks::LIGHT_BLUE_SHULKER_BOX.getName(), 0, 0);
        addBlock(ids_t_b::YELLOW_SHULKER_BOX_ID, lce::blocks::YELLOW_SHULKER_BOX.getName(), 0, 0);
        addBlock(ids_t_b::LIME_SHULKER_BOX_ID, lce::blocks::LIME_SHULKER_BOX.getName(), 0, 0);
        addBlock(ids_t_b::PINK_SHULKER_BOX_ID, lce::blocks::PINK_SHULKER_BOX.getName(), 0, 0);
        addBlock(ids_t_b::GRAY_SHULKER_BOX_ID, lce::blocks::GRAY_SHULKER_BOX.getName(), 0, 0);
        addBlock(ids_t_b::LIGHT_GRAY_SHULKER_BOX_ID, lce::blocks::LIGHT_GRAY_SHULKER_BOX.getName(), 0, 0);
        addBlock(ids_t_b::CYAN_SHULKER_BOX_ID, lce::blocks::CYAN_SHULKER_BOX.getName(), 0, 0);
        addBlock(ids_t_b::PURPLE_SHULKER_BOX_ID, lce::blocks::PURPLE_SHULKER_BOX.getName(), 0, 0);
        addBlock(ids_t_b::BLUE_SHULKER_BOX_ID, lce::blocks::BLUE_SHULKER_BOX.getName(), 0, 0);
        addBlock(ids_t_b::BROWN_SHULKER_BOX_ID, lce::blocks::BROWN_SHULKER_BOX.getName(), 0, 0);
        addBlock(ids_t_b::GREEN_SHULKER_BOX_ID, lce::blocks::GREEN_SHULKER_BOX.getName(), 0, 0);
        addBlock(ids_t_b::RED_SHULKER_BOX_ID, lce::blocks::RED_SHULKER_BOX.getName(), 0, 0);
        addBlock(ids_t_b::BLACK_SHULKER_BOX_ID, lce::blocks::BLACK_SHULKER_BOX.getName(), 0, 0);
        addBlock(ids_t_b::WHITE_GLAZED_TERRACOTTA_ID, lce::blocks::WHITE_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(ids_t_b::ORANGE_GLAZED_TERRACOTTA_ID, lce::blocks::ORANGE_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(ids_t_b::MAGENTA_GLAZED_TERRACOTTA_ID, lce::blocks::MAGENTA_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(ids_t_b::LIGHT_BLUE_GLAZED_TERRACOTTA_ID, lce::blocks::LIGHT_BLUE_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(ids_t_b::YELLOW_GLAZED_TERRACOTTA_ID, lce::blocks::YELLOW_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(ids_t_b::LIME_GLAZED_TERRACOTTA_ID, lce::blocks::LIME_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(ids_t_b::PINK_GLAZED_TERRACOTTA_ID, lce::blocks::PINK_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(ids_t_b::GRAY_GLAZED_TERRACOTTA_ID, lce::blocks::GRAY_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(ids_t_b::LIGHT_GRAY_GLAZED_TERRACOTTA_ID, lce::blocks::LIGHT_GRAY_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(ids_t_b::CYAN_GLAZED_TERRACOTTA_ID, lce::blocks::CYAN_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(ids_t_b::PURPLE_GLAZED_TERRACOTTA_ID, lce::blocks::PURPLE_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(ids_t_b::BLUE_GLAZED_TERRACOTTA_ID, lce::blocks::BLUE_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(ids_t_b::BROWN_GLAZED_TERRACOTTA_ID, lce::blocks::BROWN_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(ids_t_b::GREEN_GLAZED_TERRACOTTA_ID, lce::blocks::GREEN_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(ids_t_b::RED_GLAZED_TERRACOTTA_ID, lce::blocks::RED_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(ids_t_b::BLACK_GLAZED_TERRACOTTA_ID, lce::blocks::BLACK_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(ids_t_b::WHITE_CONCRETE_ID, lce::blocks::WHITE_CONCRETE.getName(), 0, 0);
        addBlock(ids_t_b::WHITE_CONCRETE_POWDER_ID, lce::blocks::WHITE_CONCRETE_POWDER.getName(), 0, 0);
        addBlock(ids_t_b::STRUCTURE_BLOCK_ID, lce::blocks::STRUCTURE_BLOCK.getName(), 13, 26); // (11-15,26)
        addBlock(ids_t_b::CONDUIT_ID, lce::blocks::CONDUIT.getName(), 0, 0);
        addBlock(ids_t_b::UNKNOWN_PUMPKIN, lce::blocks::UNKNOWN_PUMP.getName(), 0, 0);
        addBlock(ids_t_b::KELP_ID, lce::blocks::KELP.getName(), 0, 0);
        addBlock(ids_t_b::CORAL_BLOCK_ID, lce::blocks::CORAL_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::CORAL_ID, lce::blocks::CORAL.getName(), 0, 0);
        addBlock(ids_t_b::CORAL_FAN_ID, lce::blocks::CORAL_FAN.getName(), 0, 0);
        addBlock(ids_t_b::CORAL_FAN_DEAD_ID, lce::blocks::CORAL_FAN_DEAD.getName(), 0, 0);
        addBlock(ids_t_b::CORAL_FAN_WALL1_ID, lce::blocks::CORAL_FAN_WALL1.getName(), 0, 0);
        addBlock(ids_t_b::CORAL_FAN_WALL2_ID, lce::blocks::CORAL_FAN_WALL2.getName(), 0, 0);
        addBlock(ids_t_b::CORAL_FAN_WALL3_ID, lce::blocks::CORAL_FAN_WALL3.getName(), 0, 0);
        addBlock(ids_t_b::DRIED_KELP_BLOCK_ID, lce::blocks::DRIED_KELP_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::SEAGRASS_ID, lce::blocks::SEAGRASS.getName(), 0, 0);
        addBlock(ids_t_b::SEAPICKLE_ID, lce::blocks::SEAPICKLE.getName(), 0, 0);
        addBlock(ids_t_b::BUBBLE_COLUMN_ID, lce::blocks::BUBBLE_COLUMN.getName(), 0, 0);
        addBlock(ids_t_b::BLUE_ICE_ID, lce::blocks::BLUE_ICE.getName(), 0, 0);
        addBlock(ids_t_b::SPRUCE_TRAPDOOR_ID, lce::blocks::SPRUCE_TRAPDOOR.getName(), 0, 0);
        addBlock(ids_t_b::BIRCH_TRAPDOOR_ID, lce::blocks::BIRCH_TRAPDOOR.getName(), 0, 0);
        addBlock(ids_t_b::JUNGLE_TRAPDOOR_ID, lce::blocks::JUNGLE_TRAPDOOR.getName(), 0, 0);
        addBlock(ids_t_b::ACACIA_TRAPDOOR_ID, lce::blocks::ACACIA_TRAPDOOR.getName(), 0, 0);
        addBlock(ids_t_b::DARK_OAK_TRAPDOOR_ID, lce::blocks::DARK_OAK_TRAPDOOR.getName(), 0, 0);
        addBlock(ids_t_b::TURTLE_EGG_ID_ID, lce::blocks::TURTLE_EGG.getName(), 0, 0);
        addBlock(ids_t_b::PRISMARINE_STAIRS_ID, lce::blocks::PRISMARINE_STAIRS.getName(), 0, 0);
        addBlock(ids_t_b::PRISMARINE_BRICK_STAIRS_ID, lce::blocks::PRISMARINE_BRICK_STAIRS.getName(), 0, 0);
        addBlock(ids_t_b::DARK_PRISMARINE_STAIRS_ID, lce::blocks::DARK_PRISMARINE_STAIRS.getName(), 0, 0);
        addBlock(ids_t_b::STRIPPED_SPRUCE_LOG_ID, lce::blocks::STRIPPED_SPRUCE_LOG.getName(), 0, 0);
        addBlock(ids_t_b::STRIPPED_BIRCH_LOG_ID, lce::blocks::STRIPPED_BIRCH_LOG.getName(), 0, 0);
        addBlock(ids_t_b::STRIPPED_JUNGLE_LOG_ID, lce::blocks::STRIPPED_JUNGLE_LOG.getName(), 0, 0);
        addBlock(ids_t_b::STRIPPED_ACACIA_LOG_ID, lce::blocks::STRIPPED_ACACIA_LOG.getName(), 0, 0);
        addBlock(ids_t_b::STRIPPED_DARK_0AK_LOG_ID, lce::blocks::STRIPPED_DARK_0AK_LOG.getName(), 0, 0);
        addBlock(ids_t_b::STRIPPED_OAK_LOG_ID, lce::blocks::STRIPPED_OAK_LOG.getName(), 0, 0);
        addBlock(ids_t_b::ACACIA_PRESSURE_PLATE_ID, lce::blocks::ACACIA_PRESSURE_PLATE.getName(), 0, 0);
        addBlock(ids_t_b::BIRCH_PRESSURE_PLATE_ID, lce::blocks::BIRCH_PRESSURE_PLATE.getName(), 0, 0);
        addBlock(ids_t_b::DARK_OAK_PRESSURE_PLATE_ID, lce::blocks::DARK_OAK_PRESSURE_PLATE.getName(), 0, 0);
        addBlock(ids_t_b::JUNGLE_PRESSURE_PLATE_ID, lce::blocks::JUNGLE_PRESSURE_PLATE.getName(), 0, 0);
        addBlock(ids_t_b::SPRUCE_PRESSURE_PLATE_ID, lce::blocks::SPRUCE_PRESSURE_PLATE.getName(), 0, 0);
        addBlock(ids_t_b::ACACIA_BUTTON_ID, lce::blocks::ACACIA_BUTTON.getName(), 0, 0);
        addBlock(ids_t_b::BIRCH_BUTTON_ID, lce::blocks::BIRCH_BUTTON.getName(), 0, 0);
        addBlock(ids_t_b::DARK_OAK_BUTTON_ID, lce::blocks::DARK_OAK_BUTTON.getName(), 0, 0);
        addBlock(ids_t_b::JUNGLE_BUTTON_ID, lce::blocks::JUNGLE_BUTTON.getName(), 0, 0);
        addBlock(ids_t_b::SPRUCE_BUTTON_ID, lce::blocks::SPRUCE_BUTTON.getName(), 0, 0);
        addBlock(ids_t_b::DOUBLE_PRISMARINE_SLAB_ID, lce::blocks::DOUBLE_PRISMARINE_SLAB.getName(), 0, 0);
        addBlock(ids_t_b::PRISMARINE_SLAB_ID, lce::blocks::PRISMARINE_SLAB.getName(), 0, 0);
        addBlock(ids_t_b::SPRUCE_WOOD_2_ID, lce::blocks::SPRUCE_WOOD_2.getName(), 0, 0);
        addBlock(ids_t_b::BIRCH_WOOD_2_ID, lce::blocks::BIRCH_WOOD_2.getName(), 0, 0);
        addBlock(ids_t_b::JUNGLE_WOOD_2_ID, lce::blocks::JUNGLE_WOOD_2.getName(), 0, 0);
        addBlock(ids_t_b::ACACIA_WOOD_2_ID, lce::blocks::ACACIA_WOOD_2.getName(), 0, 0);
        addBlock(ids_t_b::DARK_OAK_WOOD_2_ID, lce::blocks::DARK_OAK_WOOD_2.getName(), 0, 0);
        addBlock(ids_t_b::OAK_WOOD_2_ID, lce::blocks::OAK_WOOD_2.getName(), 0, 0);
    }


    // const std::string TextureRegistry::ITEM_TEXTURE_FILE = "lce/assets/items.png";
    /*
    Picture const* TextureMap::getItemByID(int id) {
        return itemRegistry.getObjectById(id);
    }
     */
    /*
    void TextureMap::addItem(int theID, uint32_t theX, uint32_t theY) {
        static constexpr uint32_t CELL = 16;
        auto* tempPic = new Picture(CELL, CELL);
        itemTexture.getSubImage(*tempPic, CELL * theX, CELL * theY);
        itemRegistry.registerValue(theID, tempPic);
    }
     */
}


