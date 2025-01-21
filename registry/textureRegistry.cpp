#include "textureRegistry.hpp"
#include "lce/blocks/blockID.hpp"
#include "lce/blocks/blocksInit.hpp"


namespace lce::registry {


    const std::string TextureRegistry::BLOCK_TEXTURE_FILE = "assets/lce/terrain.png";
    bool TextureRegistry::isSetup = false;


    MU Picture const* TextureRegistry::getBlockFromID(int id) {
        return textureRegistry.getObjFromId(id);
    }


    MU Picture const* TextureRegistry::getBlockFromName(const std::string& name) {
        return textureRegistry.getObjFromName(name);
    }


    MU void TextureRegistry::setup() {
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
        using namespace lce::blocks;
        addBlock(AIR_ID, lce::BlocksInit::AIR.getName(), 15, 31); // FIX
        addBlock(STONE_ID, lce::BlocksInit::STONE.getName(), 1, 0);
        addBlock(GRASS_ID, lce::BlocksInit::GRASS.getName(), 3, 0);
        addBlock(DIRT_ID, lce::BlocksInit::DIRT.getName(), 2, 0);
        addBlock(COBBLESTONE_ID, lce::BlocksInit::COBBLESTONE.getName(), 0, 1);
        addBlock(OAK_WOOD_PLANK_ID, lce::BlocksInit::OAK_WOOD_PLANK.getName(), 4, 0);
        addBlock(OAK_SAPLING_ID, lce::BlocksInit::OAK_SAPLING.getName(), 15, 0);
        addBlock(BEDROCK_ID, lce::BlocksInit::BEDROCK.getName(), 1, 1);
        addBlock(FLOWING_WATER_ID, lce::BlocksInit::FLOWING_WATER.getName(), 13, 12);
        addBlock(STILL_WATER_ID, lce::BlocksInit::STILL_WATER.getName(), 13, 12);
        addBlock(FLOWING_LAVA_ID, lce::BlocksInit::FLOWING_LAVA.getName(), 13, 14);
        addBlock(STILL_LAVA_ID, lce::BlocksInit::STILL_LAVA.getName(), 13, 14);
        addBlock(SAND_ID, lce::BlocksInit::SAND.getName(), 2, 1);
        addBlock(GRAVEL_ID, lce::BlocksInit::GRAVEL.getName(), 3, 1);
        addBlock(GOLD_ORE_ID, lce::BlocksInit::GOLD_ORE.getName(), 0, 2);
        addBlock(IRON_ORE_ID, lce::BlocksInit::IRON_ORE.getName(), 1, 2);
        addBlock(COAL_ORE_ID, lce::BlocksInit::COAL_ORE.getName(), 2, 2);
        addBlock(OAK_WOOD_ID, lce::BlocksInit::OAK_WOOD.getName(), 4, 1); // bottom(5,1)
        addBlock(OAK_LEAVES_ID, lce::BlocksInit::OAK_LEAVES.getName(), 0, 0);
        addBlock(SPONGE_ID, lce::BlocksInit::SPONGE.getName(), 0, 3); // (12,8)
        addBlock(GLASS_ID, lce::BlocksInit::GLASS.getName(), 0, 0);
        addBlock(LAPIS_LAZULI_ORE_ID, lce::BlocksInit::LAPIS_LAZULI_ORE.getName(), 0, 10);
        addBlock(LAPIS_LAZULI_BLOCK_ID, lce::BlocksInit::LAPIS_LAZULI_BLOCK.getName(), 0, 9);
        addBlock(DISPENSER_ID, lce::BlocksInit::DISPENSER.getName(), 11, 1);
        addBlock(SANDSTONE_ID, lce::BlocksInit::SANDSTONE.getName(), 0, 0);
        addBlock(NOTE_BLOCK_ID, lce::BlocksInit::NOTE_BLOCK.getName(), 2, 16);
        addBlock(BED_BLOCK_ID, lce::BlocksInit::BED_BLOCK.getName(), 0, 0);
        addBlock(POWERED_RAIL_ID, lce::BlocksInit::POWERED_RAIL.getName(), 0, 0);
        addBlock(DETECTOR_RAIL_ID, lce::BlocksInit::DETECTOR_RAIL.getName(), 0, 0);
        addBlock(STICKY_PISTON_ID, lce::BlocksInit::STICKY_PISTON.getName(), 0, 0);
        addBlock(COBWEB_ID, lce::BlocksInit::COBWEB.getName(), 11, 0);
        addBlock(TALL_GRASS_SHRUB_ID, lce::BlocksInit::TALL_GRASS_SHRUB.getName(), 0, 0);
        addBlock(DEAD_BUSH_ID, lce::BlocksInit::DEAD_BUSH.getName(), 0, 0);
        addBlock(PISTON_ID, lce::BlocksInit::PISTON.getName(), 0, 0);
        addBlock(PISTON_HEAD_ID, lce::BlocksInit::PISTON_HEAD.getName(), 0, 0);
        addBlock(WOOL_ID, lce::BlocksInit::WHITE_WOOL.getName(), 0, 0);
        addBlock(DANDELION_ID, lce::BlocksInit::DANDELION.getName(), 13, 0);
        addBlock(POPPY_ID, lce::BlocksInit::POPPY.getName(), 12, 0);
        addBlock(BROWN_MUSHROOM_ID, lce::BlocksInit::BROWN_MUSHROOM.getName(), 13, 1);
        addBlock(RED_MUSHROOM_ID, lce::BlocksInit::RED_MUSHROOM.getName(), 12, 1);
        addBlock(GOLD_BLOCK_ID, lce::BlocksInit::GOLD_BLOCK.getName(), 7, 1);
        addBlock(IRON_BLOCK_ID, lce::BlocksInit::IRON_BLOCK.getName(), 6, 1);
        addBlock(DOUBLE_STONE_SLAB_ID, lce::BlocksInit::DOUBLE_STONE_SLAB.getName(), 0, 0);
        addBlock(STONE_SLAB_ID, lce::BlocksInit::STONE_SLAB.getName(), 0, 0);
        addBlock(BRICKS_ID, lce::BlocksInit::BRICKS.getName(), 7, 0);
        addBlock(TNT_ID, lce::BlocksInit::TNT.getName(), 8, 0); // (9,0), (10,0)
        addBlock(BOOKSHELF_ID, lce::BlocksInit::BOOKSHELF.getName(), 3, 2);
        addBlock(MOSS_STONE_ID, lce::BlocksInit::MOSS_STONE.getName(), 4, 2);
        addBlock(OBSIDIAN_ID, lce::BlocksInit::OBSIDIAN.getName(), 5, 2);
        addBlock(TORCH_ID, lce::BlocksInit::TORCH.getName(), 0, 5);
        addBlock(FIRE_ID, lce::BlocksInit::FIRE.getName(), 0, 0);
        addBlock(MONSTER_SPAWNER_ID, lce::BlocksInit::MONSTER_SPAWNER.getName(), 0, 0);
        addBlock(OAK_WOOD_STAIRS_ID, lce::BlocksInit::OAK_WOOD_STAIRS.getName(), 0, 0);
        addBlock(CHEST_ID, lce::BlocksInit::CHEST.getName(), 0, 0);
        addBlock(REDSTONE_WIRE_ID, lce::BlocksInit::REDSTONE_WIRE.getName(), 0, 0);
        addBlock(DIAMOND_ORE_ID, lce::BlocksInit::DIAMOND_ORE.getName(), 2, 3);
        addBlock(DIAMOND_BLOCK_ID, lce::BlocksInit::DIAMOND_BLOCK.getName(), 8, 1);
        addBlock(CRAFTING_TABLE_ID, lce::BlocksInit::CRAFTING_TABLE.getName(), 11, 3); // (12,3), (11,2)
        addBlock(WHEAT_CROPS_ID, lce::BlocksInit::WHEAT_CROPS.getName(), 15, 5);       // (8-15,5)
        addBlock(FARMLAND_ID, lce::BlocksInit::FARMLAND.getName(), 0, 0);
        addBlock(FURNACE_ID, lce::BlocksInit::FURNACE.getName(), 12, 2);                 // (13,2), (14,3)
        addBlock(BURNING_FURNACE_ID, lce::BlocksInit::BURNING_FURNACE.getName(), 13, 3); // (13,2), (14,3)
        addBlock(STANDING_SIGN_BLOCK_ID, lce::BlocksInit::STANDING_SIGN_BLOCK.getName(), 0, 0);
        addBlock(OAK_DOOR_BLOCK_ID, lce::BlocksInit::OAK_DOOR_BLOCK.getName(), 1, 5); // (1,6)
        addBlock(LADDER_ID, lce::BlocksInit::LADDER.getName(), 3, 5);
        addBlock(RAIL_ID, lce::BlocksInit::RAIL.getName(), 0, 0);
        addBlock(COBBLESTONE_STAIRS_ID, lce::BlocksInit::COBBLESTONE_STAIRS.getName(), 0, 0);
        addBlock(WALL_MOUNTED_SIGN_BLOCK_ID, lce::BlocksInit::WALL_MOUNTED_SIGN_BLOCK.getName(), 0, 0);
        addBlock(LEVER_ID, lce::BlocksInit::LEVER.getName(), 0, 0);
        addBlock(STONE_PRESSURE_PLATE_ID, lce::BlocksInit::STONE_PRESSURE_PLATE.getName(), 0, 0);
        addBlock(IRON_DOOR_BLOCK_ID, lce::BlocksInit::IRON_DOOR_BLOCK.getName(), 0, 0);
        addBlock(WOODEN_PRESSURE_PLATE_ID, lce::BlocksInit::WOODEN_PRESSURE_PLATE.getName(), 0, 0);
        addBlock(REDSTONE_ORE_ID, lce::BlocksInit::REDSTONE_ORE.getName(), 3, 3);
        addBlock(GLOWING_REDSTONE_ORE_ID, lce::BlocksInit::GLOWING_REDSTONE_ORE.getName(), 3, 3); // FIX
        addBlock(OFF_REDSTONE_TORCH_ID, lce::BlocksInit::OFF_REDSTONE_TORCH.getName(), 3, 7);
        addBlock(ON_REDSTONE_TORCH_ID, lce::BlocksInit::ON_REDSTONE_TORCH.getName(), 3, 6);
        addBlock(STONE_BUTTON_ID, lce::BlocksInit::STONE_BUTTON.getName(), 0, 0);
        addBlock(SNOW_ID, lce::BlocksInit::SNOW.getName(), 0, 0);
        addBlock(ICE_ID, lce::BlocksInit::ICE.getName(), 0, 0);
        addBlock(SNOW_BLOCK_ID, lce::BlocksInit::SNOW_BLOCK.getName(), 0, 0);
        addBlock(CACTUS_ID, lce::BlocksInit::CACTUS.getName(), 0, 0);
        addBlock(CLAY_BLOCK_ID, lce::BlocksInit::CLAY_BLOCK.getName(), 8, 4);
        addBlock(SUGAR_CANES_ID, lce::BlocksInit::SUGAR_CANES.getName(), 0, 0);
        addBlock(JUKEBOX_ID, lce::BlocksInit::JUKEBOX.getName(), 0, 0);
        addBlock(OAK_FENCE_ID, lce::BlocksInit::OAK_FENCE.getName(), 0, 0);
        addBlock(CARVED_PUMPKIN_ID, lce::BlocksInit::PUMPKIN.getName(), 0, 0);
        addBlock(NETHERRACK_ID, lce::BlocksInit::NETHERRACK.getName(), 7, 6);
        addBlock(SOUL_SAND_ID, lce::BlocksInit::SOUL_SAND.getName(), 8, 6);
        addBlock(GLOWSTONE_ID, lce::BlocksInit::GLOWSTONE.getName(), 9, 6);
        addBlock(NETHER_PORTAL_ID, lce::BlocksInit::NETHER_PORTAL.getName(), 0, 0);
        addBlock(JACK_O_LANTERN_ID, lce::BlocksInit::JACK_O_LANTERN.getName(), 0, 0);
        addBlock(CAKE_BLOCK_ID, lce::BlocksInit::CAKE_BLOCK.getName(), 0, 0);
        addBlock(OFF_REDSTONE_REPEATER_BLOCK_ID, lce::BlocksInit::OFF_REDSTONE_REPEATER_BLOCK.getName(), 0, 0);
        addBlock(ON_REDSTONE_REPEATER_BLOCK_ID, lce::BlocksInit::ON_REDSTONE_REPEATER_BLOCK.getName(), 0, 0);
        addBlock(STAINED_GLASS_ID, lce::BlocksInit::WHITE_STAINED_GLASS.getName(), 0, 0);
        addBlock(WOODEN_TRAPDOOR_ID, lce::BlocksInit::WOODEN_TRAPDOOR.getName(), 0, 0);
        addBlock(STONE_MONSTER_EGG_ID, lce::BlocksInit::STONE_MONSTER_EGG.getName(), 0, 0);
        addBlock(STONE_BRICKS_ID, lce::BlocksInit::STONE_BRICKS.getName(), 0, 0);
        addBlock(BROWN_MUSHROOM_BLOCK_ID, lce::BlocksInit::BROWN_MUSHROOM_BLOCK.getName(), 14, 7);
        addBlock(RED_MUSHROOM_BLOCK_ID, lce::BlocksInit::RED_MUSHROOM_BLOCK.getName(), 13, 7);
        addBlock(IRON_BARS_ID, lce::BlocksInit::IRON_BARS.getName(), 5, 5);
        addBlock(GLASS_PANE_ID, lce::BlocksInit::GLASS_PANE.getName(), 0, 0);
        addBlock(MELON_BLOCK_ID, lce::BlocksInit::MELON_BLOCK.getName(), 0, 0);
        addBlock(PUMPKIN_STEM_ID, lce::BlocksInit::PUMPKIN_STEM.getName(), 0, 0);
        addBlock(MELON_STEM_ID, lce::BlocksInit::MELON_STEM.getName(), 0, 0);
        addBlock(VINES_ID, lce::BlocksInit::VINES.getName(), 0, 0);
        addBlock(OAK_FENCE_GATE_ID, lce::BlocksInit::OAK_FENCE_GATE.getName(), 0, 0);
        addBlock(BRICK_STAIRS_ID, lce::BlocksInit::BRICK_STAIRS.getName(), 0, 0);
        addBlock(STONE_BRICK_STAIRS_ID, lce::BlocksInit::STONE_BRICK_STAIRS.getName(), 0, 0);
        addBlock(MYCELIUM_ID, lce::BlocksInit::MYCELIUM.getName(), 0, 0);
        addBlock(LILY_PAD_ID, lce::BlocksInit::LILY_PAD.getName(), 0, 0);
        addBlock(NETHER_BRICK_BLOCK_ID, lce::BlocksInit::NETHER_BRICK_BLOCK.getName(), 0, 14);
        addBlock(NETHER_BRICK_FENCE_ID, lce::BlocksInit::NETHER_BRICK_FENCE.getName(), 0, 14);   // FIX
        addBlock(NETHER_BRICK_STAIRS_ID, lce::BlocksInit::NETHER_BRICK_STAIRS.getName(), 0, 14); // FIX
        addBlock(NETHER_WART_ID, lce::BlocksInit::NETHER_WART.getName(), 4, 14);                 // (2-4,14)
        addBlock(ENCHANTMENT_TABLE_ID, lce::BlocksInit::ENCHANTMENT_TABLE.getName(), 6, 11);     // (6,10), (6,11), (7, 11)
        addBlock(BREWING_STAND_ID, lce::BlocksInit::BREWING_STAND.getName(), 0, 0);
        addBlock(CAULDRON_ID, lce::BlocksInit::CAULDRON.getName(), 0, 0);
        addBlock(END_PORTAL_ID, lce::BlocksInit::END_PORTAL.getName(), 0, 0);
        addBlock(END_PORTAL_FRAME_ID, lce::BlocksInit::END_PORTAL_FRAME.getName(), 0, 0);
        addBlock(END_STONE_ID, lce::BlocksInit::END_STONE.getName(), 15, 10);
        addBlock(DRAGON_EGG_ID, lce::BlocksInit::DRAGON_EGG.getName(), 7, 10);
        addBlock(INACTIVE_REDSTONE_LAMP_ID, lce::BlocksInit::INACTIVE_REDSTONE_LAMP.getName(), 3, 13);
        addBlock(ACTIVE_REDSTONE_LAMP_ID, lce::BlocksInit::ACTIVE_REDSTONE_LAMP.getName(), 4, 13);
        addBlock(DOUBLE_OAK_WOOD_SLAB_ID, lce::BlocksInit::DOUBLE_OAK_WOOD_SLAB.getName(), 0, 0);
        addBlock(OAK_WOOD_SLAB_ID, lce::BlocksInit::OAK_WOOD_SLAB.getName(), 0, 0);
        addBlock(COCOA_ID, lce::BlocksInit::COCOA.getName(), 0, 0);
        addBlock(SANDSTONE_STAIRS_ID, lce::BlocksInit::SANDSTONE_STAIRS.getName(), 0, 0);
        addBlock(EMERALD_ORE_ID, lce::BlocksInit::EMERALD_ORE.getName(), 11, 10);
        addBlock(ENDER_CHEST_ID, lce::BlocksInit::ENDER_CHEST.getName(), 0, 0);
        addBlock(TRIPWIRE_HOOK_ID, lce::BlocksInit::TRIPWIRE_HOOK.getName(), 12, 10);
        addBlock(TRIPWIRE_ID, lce::BlocksInit::TRIPWIRE.getName(), 0, 0);
        addBlock(EMERALD_BLOCK_ID, lce::BlocksInit::EMERALD_BLOCK.getName(), 9, 1);
        addBlock(SPRUCE_WOOD_STAIRS_ID, lce::BlocksInit::SPRUCE_WOOD_STAIRS.getName(), 0, 0);
        addBlock(BIRCH_WOOD_STAIRS_ID, lce::BlocksInit::BIRCH_WOOD_STAIRS.getName(), 0, 0);
        addBlock(JUNGLE_WOOD_STAIRS_ID, lce::BlocksInit::JUNGLE_WOOD_STAIRS.getName(), 0, 0);
        addBlock(COMMAND_BLOCK_ID, lce::BlocksInit::COMMAND_BLOCK.getName(), 0, 0);
        addBlock(BEACON_ID, lce::BlocksInit::BEACON.getName(), 0, 0);
        addBlock(COBBLESTONE_WALL_ID, lce::BlocksInit::COBBLESTONE_WALL.getName(), 0, 0);
        addBlock(FLOWER_POT_ID, lce::BlocksInit::FLOWER_POT.getName(), 0, 0);
        addBlock(CARROTS_ID, lce::BlocksInit::CARROTS.getName(), 11, 12); // (8-11,12)
        addBlock(POTATOES_ID, lce::BlocksInit::POTATOES.getName(), 0, 0);
        addBlock(WOODEN_BUTTON_ID, lce::BlocksInit::WOODEN_BUTTON.getName(), 0, 0);
        addBlock(MOB_HEAD_ID, lce::BlocksInit::MOB_HEAD.getName(), 0, 0);
        addBlock(ANVIL_ID, lce::BlocksInit::ANVIL.getName(), 0, 0);
        addBlock(TRAPPED_CHEST_ID, lce::BlocksInit::TRAPPED_CHEST.getName(), 0, 0);
        addBlock(LIGHT_WEIGHTED_PRESSURE_PLATE_ID, lce::BlocksInit::LIGHT_WEIGHTED_PRESSURE_PLATE.getName(), 0, 0);
        addBlock(HEAVY_WEIGHTED_PRESSURE_PLATE_ID, lce::BlocksInit::HEAVY_WEIGHTED_PRESSURE_PLATE.getName(), 0, 0);
        addBlock(INACTIVE_REDSTONE_COMPARATOR_ID, lce::BlocksInit::INACTIVE_REDSTONE_COMPARATOR.getName(), 0, 0);
        addBlock(ACTIVE_REDSTONE_COMPARATOR_ID, lce::BlocksInit::ACTIVE_REDSTONE_COMPARATOR.getName(), 0, 0);
        addBlock(DAYLIGHT_SENSOR_ID, lce::BlocksInit::DAYLIGHT_SENSOR.getName(), 0, 0);
        addBlock(REDSTONE_BLOCK_ID, lce::BlocksInit::REDSTONE_BLOCK.getName(), 10, 1);
        addBlock(NETHER_QUARTZ_ORE_ID, lce::BlocksInit::NETHER_QUARTZ_ORE.getName(), 15, 11);
        addBlock(HOPPER_ID, lce::BlocksInit::HOPPER.getName(), 0, 0);
        addBlock(QUARTZ_BLOCK_ID, lce::BlocksInit::QUARTZ_BLOCK.getName(), 0, 0);
        addBlock(QUARTZ_STAIRS_ID, lce::BlocksInit::QUARTZ_STAIRS.getName(), 0, 0);
        addBlock(ACTIVATOR_RAIL_ID, lce::BlocksInit::ACTIVATOR_RAIL.getName(), 0, 0);
        addBlock(DROPPER_ID, lce::BlocksInit::DROPPER.getName(), 0, 0);
        addBlock(STAINED_HARDENED_CLAY_ID, lce::BlocksInit::WHITE_HARDENED_CLAY.getName(), 0, 0);
        addBlock(STAINED_GLASS_PANE_ID, lce::BlocksInit::WHITE_STAINED_GLASS_PANE.getName(), 0, 0);
        addBlock(ACACIA_LEAVES_ID, lce::BlocksInit::ACACIA_LEAVES.getName(), 0, 0);
        addBlock(ACACIA_WOOD_ID, lce::BlocksInit::ACACIA_WOOD.getName(), 0, 0);
        addBlock(ACACIA_WOOD_STAIRS_ID, lce::BlocksInit::ACACIA_WOOD_STAIRS.getName(), 0, 0);
        addBlock(DARK_OAK_WOOD_STAIRS_ID, lce::BlocksInit::DARK_OAK_WOOD_STAIRS.getName(), 0, 0);
        addBlock(SLIME_BLOCK_ID, lce::BlocksInit::SLIME_BLOCK.getName(), 12, 12);
        addBlock(BARRIER_ID, lce::BlocksInit::BARRIER.getName(), 11, 23);
        addBlock(IRON_TRAPDOOR_ID, lce::BlocksInit::IRON_TRAPDOOR.getName(), 0, 0);
        addBlock(PRISMARINE_ID, lce::BlocksInit::PRISMARINE.getName(), 0, 0);
        addBlock(SEA_LANTERN_ID, lce::BlocksInit::SEA_LANTERN.getName(), 0, 0);
        addBlock(HAY_BALE_ID, lce::BlocksInit::HAY_BALE.getName(), 10, 15); // (13,15)
        addBlock(CARPET_ID, lce::BlocksInit::WHITE_CARPET.getName(), 0, 0);
        addBlock(HARDENED_CLAY_ID, lce::BlocksInit::HARDENED_CLAY.getName(), 0, 0);
        addBlock(BLOCK_OF_COAL_ID, lce::BlocksInit::BLOCK_OF_COAL.getName(), 0, 16);
        addBlock(PACKED_ICE_ID, lce::BlocksInit::PACKED_ICE.getName(), 0, 0);
        addBlock(DOUBLE_PLANT_ID, lce::BlocksInit::SUNFLOWER.getName(), 0, 0);
        addBlock(FREE_STANDING_BANNER_ID, lce::BlocksInit::FREE_STANDING_BANNER.getName(), 0, 0);
        addBlock(WALL_MOUNTED_BANNER_ID, lce::BlocksInit::WALL_MOUNTED_BANNER.getName(), 0, 0);
        addBlock(INVERTED_DAYLIGHT_SENSOR_ID, lce::BlocksInit::INVERTED_DAYLIGHT_SENSOR.getName(), 0, 0);
        addBlock(RED_SANDSTONE_ID, lce::BlocksInit::RED_SANDSTONE.getName(), 0, 0);
        addBlock(RED_SANDSTONE_STAIRS_ID, lce::BlocksInit::RED_SANDSTONE_STAIRS.getName(), 0, 0);
        addBlock(DOUBLE_RED_SANDSTONE_SLAB_ID, lce::BlocksInit::DOUBLE_RED_SANDSTONE_SLAB.getName(), 0, 0);
        addBlock(RED_SANDSTONE_SLAB_ID, lce::BlocksInit::RED_SANDSTONE_SLAB.getName(), 0, 0);
        addBlock(SPRUCE_FENCE_GATE_ID, lce::BlocksInit::SPRUCE_FENCE_GATE.getName(), 0, 0);
        addBlock(BIRCH_FENCE_GATE_ID, lce::BlocksInit::BIRCH_FENCE_GATE.getName(), 0, 0);
        addBlock(JUNGLE_FENCE_GATE_ID, lce::BlocksInit::JUNGLE_FENCE_GATE.getName(), 0, 0);
        addBlock(DARK_OAK_FENCE_GATE_ID, lce::BlocksInit::DARK_OAK_FENCE_GATE.getName(), 0, 0);
        addBlock(ACACIA_FENCE_GATE_ID, lce::BlocksInit::ACACIA_FENCE_GATE.getName(), 0, 0);
        addBlock(SPRUCE_FENCE_ID, lce::BlocksInit::SPRUCE_FENCE.getName(), 0, 0);
        addBlock(BIRCH_FENCE_ID, lce::BlocksInit::BIRCH_FENCE.getName(), 0, 0);
        addBlock(JUNGLE_FENCE_ID, lce::BlocksInit::JUNGLE_FENCE.getName(), 0, 0);
        addBlock(DARK_OAK_FENCE_ID, lce::BlocksInit::DARK_OAK_FENCE.getName(), 0, 0);
        addBlock(ACACIA_FENCE_ID, lce::BlocksInit::ACACIA_FENCE.getName(), 0, 0);
        addBlock(SPRUCE_DOOR_BLOCK_ID, lce::BlocksInit::SPRUCE_DOOR_BLOCK.getName(), 0, 0);
        addBlock(BIRCH_DOOR_BLOCK_ID, lce::BlocksInit::BIRCH_DOOR_BLOCK.getName(), 0, 0);
        addBlock(JUNGLE_DOOR_BLOCK_ID, lce::BlocksInit::JUNGLE_DOOR_BLOCK.getName(), 0, 0);
        addBlock(ACACIA_DOOR_BLOCK_ID, lce::BlocksInit::ACACIA_DOOR_BLOCK.getName(), 0, 0);
        addBlock(DARK_OAK_DOOR_BLOCK_ID, lce::BlocksInit::DARK_OAK_DOOR_BLOCK.getName(), 0, 0);
        addBlock(END_ROD_ID, lce::BlocksInit::END_ROD.getName(), 0, 0);
        addBlock(CHORUS_PLANT_ID, lce::BlocksInit::CHORUS_PLANT.getName(), 0, 0);
        addBlock(CHORUS_FLOWER_ID, lce::BlocksInit::CHORUS_FLOWER.getName(), 0, 0);
        addBlock(PURPUR_BLOCK_ID, lce::BlocksInit::PURPUR_BLOCK.getName(), 0, 0);
        addBlock(PURPUR_PILLAR_ID, lce::BlocksInit::PURPUR_PILLAR.getName(), 0, 0);
        addBlock(PURPUR_STAIRS_ID, lce::BlocksInit::PURPUR_STAIRS.getName(), 0, 0);
        addBlock(PURPUR_DOUBLE_SLAB_ID, lce::BlocksInit::PURPUR_DOUBLE_SLAB.getName(), 0, 0);
        addBlock(PURPUR_SLAB_ID, lce::BlocksInit::PURPUR_SLAB.getName(), 0, 0);
        addBlock(END_STONE_BRICKS_ID, lce::BlocksInit::END_STONE_BRICKS.getName(), 8, 23);
        addBlock(BEETROOT_BLOCK_ID, lce::BlocksInit::BEETROOT_BLOCK.getName(), 0, 0);
        addBlock(GRASS_PATH_ID, lce::BlocksInit::GRASS_PATH.getName(), 0, 0);
        addBlock(END_GATEWAY_ID, lce::BlocksInit::END_GATEWAY.getName(), 0, 0);
        addBlock(REPEATING_COMMAND_BLOCK_ID, lce::BlocksInit::REPEATING_COMMAND_BLOCK.getName(), 0, 0);
        addBlock(CHAIN_COMMAND_BLOCK_ID, lce::BlocksInit::CHAIN_COMMAND_BLOCK.getName(), 0, 0);
        addBlock(FROSTED_ICE_ID, lce::BlocksInit::FROSTED_ICE.getName(), 12, 24); // (12-15,24)
        addBlock(MAGMA_BLOCK_ID, lce::BlocksInit::MAGMA_BLOCK.getName(), 9, 24);
        addBlock(NETHER_WART_BLOCK_ID, lce::BlocksInit::NETHER_WART_BLOCK.getName(), 10, 24);
        addBlock(RED_NETHER_BRICK_ID, lce::BlocksInit::RED_NETHER_BRICK.getName(), 11, 24);
        addBlock(BONE_BLOCK_ID, lce::BlocksInit::BONE_BLOCK.getName(), 0, 0);
        addBlock(STRUCTURE_VOID_ID, lce::BlocksInit::STRUCTURE_VOID.getName(), 0, 0);
        addBlock(OBSERVER_ID, lce::BlocksInit::OBSERVER.getName(), 4, 26); // (4-8,26)
        addBlock(WHITE_SHULKER_BOX_ID, lce::BlocksInit::WHITE_SHULKER_BOX.getName(), 0, 0);
        addBlock(ORANGE_SHULKER_BOX_ID, lce::BlocksInit::ORANGE_SHULKER_BOX.getName(), 0, 0);
        addBlock(MAGENTA_SHULKER_BOX_ID, lce::BlocksInit::MAGENTA_SHULKER_BOX.getName(), 0, 0);
        addBlock(LIGHT_BLUE_SHULKER_BOX_ID, lce::BlocksInit::LIGHT_BLUE_SHULKER_BOX.getName(), 0, 0);
        addBlock(YELLOW_SHULKER_BOX_ID, lce::BlocksInit::YELLOW_SHULKER_BOX.getName(), 0, 0);
        addBlock(LIME_SHULKER_BOX_ID, lce::BlocksInit::LIME_SHULKER_BOX.getName(), 0, 0);
        addBlock(PINK_SHULKER_BOX_ID, lce::BlocksInit::PINK_SHULKER_BOX.getName(), 0, 0);
        addBlock(GRAY_SHULKER_BOX_ID, lce::BlocksInit::GRAY_SHULKER_BOX.getName(), 0, 0);
        addBlock(LIGHT_GRAY_SHULKER_BOX_ID, lce::BlocksInit::LIGHT_GRAY_SHULKER_BOX.getName(), 0, 0);
        addBlock(CYAN_SHULKER_BOX_ID, lce::BlocksInit::CYAN_SHULKER_BOX.getName(), 0, 0);
        addBlock(PURPLE_SHULKER_BOX_ID, lce::BlocksInit::PURPLE_SHULKER_BOX.getName(), 0, 0);
        addBlock(BLUE_SHULKER_BOX_ID, lce::BlocksInit::BLUE_SHULKER_BOX.getName(), 0, 0);
        addBlock(BROWN_SHULKER_BOX_ID, lce::BlocksInit::BROWN_SHULKER_BOX.getName(), 0, 0);
        addBlock(GREEN_SHULKER_BOX_ID, lce::BlocksInit::GREEN_SHULKER_BOX.getName(), 0, 0);
        addBlock(RED_SHULKER_BOX_ID, lce::BlocksInit::RED_SHULKER_BOX.getName(), 0, 0);
        addBlock(BLACK_SHULKER_BOX_ID, lce::BlocksInit::BLACK_SHULKER_BOX.getName(), 0, 0);
        addBlock(WHITE_GLAZED_TERRACOTTA_ID, lce::BlocksInit::WHITE_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(ORANGE_GLAZED_TERRACOTTA_ID, lce::BlocksInit::ORANGE_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(MAGENTA_GLAZED_TERRACOTTA_ID, lce::BlocksInit::MAGENTA_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(LIGHT_BLUE_GLAZED_TERRACOTTA_ID, lce::BlocksInit::LIGHT_BLUE_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(YELLOW_GLAZED_TERRACOTTA_ID, lce::BlocksInit::YELLOW_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(LIME_GLAZED_TERRACOTTA_ID, lce::BlocksInit::LIME_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(PINK_GLAZED_TERRACOTTA_ID, lce::BlocksInit::PINK_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(GRAY_GLAZED_TERRACOTTA_ID, lce::BlocksInit::GRAY_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(LIGHT_GRAY_GLAZED_TERRACOTTA_ID, lce::BlocksInit::LIGHT_GRAY_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(CYAN_GLAZED_TERRACOTTA_ID, lce::BlocksInit::CYAN_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(PURPLE_GLAZED_TERRACOTTA_ID, lce::BlocksInit::PURPLE_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(BLUE_GLAZED_TERRACOTTA_ID, lce::BlocksInit::BLUE_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(BROWN_GLAZED_TERRACOTTA_ID, lce::BlocksInit::BROWN_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(GREEN_GLAZED_TERRACOTTA_ID, lce::BlocksInit::GREEN_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(RED_GLAZED_TERRACOTTA_ID, lce::BlocksInit::RED_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(BLACK_GLAZED_TERRACOTTA_ID, lce::BlocksInit::BLACK_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(CONCRETE_ID, lce::BlocksInit::WHITE_CONCRETE.getName(), 0, 0);
        addBlock(CONCRETE_POWDER_ID, lce::BlocksInit::WHITE_CONCRETE_POWDER.getName(), 0, 0);
        addBlock(STRUCTURE_BLOCK_ID, lce::BlocksInit::STRUCTURE_BLOCK.getName(), 13, 26); // (11-15,26)
        addBlock(CONDUIT_ID, lce::BlocksInit::CONDUIT.getName(), 0, 0);
        addBlock(PUMPKIN_ID, lce::BlocksInit::UNKNOWN_PUMP.getName(), 0, 0);
        addBlock(KELP_ID, lce::BlocksInit::KELP.getName(), 0, 0);
        addBlock(CORAL_BLOCK_ID, lce::BlocksInit::CORAL_BLOCK.getName(), 0, 0);
        addBlock(CORAL_ID, lce::BlocksInit::CORAL.getName(), 0, 0);
        addBlock(CORAL_FAN_ID, lce::BlocksInit::CORAL_FAN.getName(), 0, 0);
        addBlock(CORAL_FAN_DEAD_ID, lce::BlocksInit::CORAL_FAN_DEAD.getName(), 0, 0);
        addBlock(CORAL_FAN_WALL1_ID, lce::BlocksInit::CORAL_FAN_WALL1.getName(), 0, 0);
        addBlock(CORAL_FAN_WALL2_ID, lce::BlocksInit::CORAL_FAN_WALL2.getName(), 0, 0);
        addBlock(CORAL_FAN_WALL3_ID, lce::BlocksInit::CORAL_FAN_WALL3.getName(), 0, 0);
        addBlock(DRIED_KELP_BLOCK_ID, lce::BlocksInit::DRIED_KELP_BLOCK.getName(), 0, 0);
        addBlock(SEAGRASS_ID, lce::BlocksInit::SEAGRASS.getName(), 0, 0);
        addBlock(SEAPICKLE_ID, lce::BlocksInit::SEAPICKLE.getName(), 0, 0);
        addBlock(BUBBLE_COLUMN_ID, lce::BlocksInit::BUBBLE_COLUMN.getName(), 0, 0);
        addBlock(BLUE_ICE_ID, lce::BlocksInit::BLUE_ICE.getName(), 0, 0);
        addBlock(SPRUCE_TRAPDOOR_ID, lce::BlocksInit::SPRUCE_TRAPDOOR.getName(), 0, 0);
        addBlock(BIRCH_TRAPDOOR_ID, lce::BlocksInit::BIRCH_TRAPDOOR.getName(), 0, 0);
        addBlock(JUNGLE_TRAPDOOR_ID, lce::BlocksInit::JUNGLE_TRAPDOOR.getName(), 0, 0);
        addBlock(ACACIA_TRAPDOOR_ID, lce::BlocksInit::ACACIA_TRAPDOOR.getName(), 0, 0);
        addBlock(DARK_OAK_TRAPDOOR_ID, lce::BlocksInit::DARK_OAK_TRAPDOOR.getName(), 0, 0);
        addBlock(TURTLE_EGG_ID_ID, lce::BlocksInit::TURTLE_EGG.getName(), 0, 0);
        addBlock(PRISMARINE_STAIRS_ID, lce::BlocksInit::PRISMARINE_STAIRS.getName(), 0, 0);
        addBlock(PRISMARINE_BRICK_STAIRS_ID, lce::BlocksInit::PRISMARINE_BRICK_STAIRS.getName(), 0, 0);
        addBlock(DARK_PRISMARINE_STAIRS_ID, lce::BlocksInit::DARK_PRISMARINE_STAIRS.getName(), 0, 0);
        addBlock(STRIPPED_SPRUCE_LOG_ID, lce::BlocksInit::STRIPPED_SPRUCE_LOG.getName(), 0, 0);
        addBlock(STRIPPED_BIRCH_LOG_ID, lce::BlocksInit::STRIPPED_BIRCH_LOG.getName(), 0, 0);
        addBlock(STRIPPED_JUNGLE_LOG_ID, lce::BlocksInit::STRIPPED_JUNGLE_LOG.getName(), 0, 0);
        addBlock(STRIPPED_ACACIA_LOG_ID, lce::BlocksInit::STRIPPED_ACACIA_LOG.getName(), 0, 0);
        addBlock(STRIPPED_DARK_0AK_LOG_ID, lce::BlocksInit::STRIPPED_DARK_0AK_LOG.getName(), 0, 0);
        addBlock(STRIPPED_OAK_LOG_ID, lce::BlocksInit::STRIPPED_OAK_LOG.getName(), 0, 0);
        addBlock(ACACIA_PRESSURE_PLATE_ID, lce::BlocksInit::ACACIA_PRESSURE_PLATE.getName(), 0, 0);
        addBlock(BIRCH_PRESSURE_PLATE_ID, lce::BlocksInit::BIRCH_PRESSURE_PLATE.getName(), 0, 0);
        addBlock(DARK_OAK_PRESSURE_PLATE_ID, lce::BlocksInit::DARK_OAK_PRESSURE_PLATE.getName(), 0, 0);
        addBlock(JUNGLE_PRESSURE_PLATE_ID, lce::BlocksInit::JUNGLE_PRESSURE_PLATE.getName(), 0, 0);
        addBlock(SPRUCE_PRESSURE_PLATE_ID, lce::BlocksInit::SPRUCE_PRESSURE_PLATE.getName(), 0, 0);
        addBlock(ACACIA_BUTTON_ID, lce::BlocksInit::ACACIA_BUTTON.getName(), 0, 0);
        addBlock(BIRCH_BUTTON_ID, lce::BlocksInit::BIRCH_BUTTON.getName(), 0, 0);
        addBlock(DARK_OAK_BUTTON_ID, lce::BlocksInit::DARK_OAK_BUTTON.getName(), 0, 0);
        addBlock(JUNGLE_BUTTON_ID, lce::BlocksInit::JUNGLE_BUTTON.getName(), 0, 0);
        addBlock(SPRUCE_BUTTON_ID, lce::BlocksInit::SPRUCE_BUTTON.getName(), 0, 0);
        addBlock(DOUBLE_PRISMARINE_SLAB_ID, lce::BlocksInit::DOUBLE_PRISMARINE_SLAB.getName(), 0, 0);
        addBlock(PRISMARINE_SLAB_ID, lce::BlocksInit::PRISMARINE_SLAB.getName(), 0, 0);
        addBlock(SPRUCE_WOOD_2_ID, lce::BlocksInit::SPRUCE_WOOD_2.getName(), 0, 0);
        addBlock(BIRCH_WOOD_2_ID, lce::BlocksInit::BIRCH_WOOD_2.getName(), 0, 0);
        addBlock(JUNGLE_WOOD_2_ID, lce::BlocksInit::JUNGLE_WOOD_2.getName(), 0, 0);
        addBlock(ACACIA_WOOD_2_ID, lce::BlocksInit::ACACIA_WOOD_2.getName(), 0, 0);
        addBlock(DARK_OAK_WOOD_2_ID, lce::BlocksInit::DARK_OAK_WOOD_2.getName(), 0, 0);
        addBlock(OAK_WOOD_2_ID, lce::BlocksInit::OAK_WOOD_2.getName(), 0, 0);
    }


    // const std::string TextureRegistry::ITEM_TEXTURE_FILE = "assets/lce/items.png";
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


