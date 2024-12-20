#include "lce/blocks/block_ids.hpp"
#include "lce/blocks/blocks.hpp"
#include "textureRegistry.hpp"


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
        namespace ids_t_b = lce::blocks::ids;
        addBlock(ids_t_b::AIR_ID, lce::blocks::BlocksInit::AIR.getName(), 15, 31); // FIX
        addBlock(ids_t_b::STONE_ID, lce::blocks::BlocksInit::STONE.getName(), 1, 0);
        addBlock(ids_t_b::GRASS_ID, lce::blocks::BlocksInit::GRASS.getName(), 3, 0);
        addBlock(ids_t_b::DIRT_ID, lce::blocks::BlocksInit::DIRT.getName(), 2, 0);
        addBlock(ids_t_b::COBBLESTONE_ID, lce::blocks::BlocksInit::COBBLESTONE.getName(), 0, 1);
        addBlock(ids_t_b::OAK_WOOD_PLANK_ID, lce::blocks::BlocksInit::OAK_WOOD_PLANK.getName(), 4, 0);
        addBlock(ids_t_b::OAK_SAPLING_ID, lce::blocks::BlocksInit::OAK_SAPLING.getName(), 15, 0);
        addBlock(ids_t_b::BEDROCK_ID, lce::blocks::BlocksInit::BEDROCK.getName(), 1, 1);
        addBlock(ids_t_b::FLOWING_WATER_ID, lce::blocks::BlocksInit::FLOWING_WATER.getName(), 13, 12);
        addBlock(ids_t_b::STILL_WATER_ID, lce::blocks::BlocksInit::STILL_WATER.getName(), 13, 12);
        addBlock(ids_t_b::FLOWING_LAVA_ID, lce::blocks::BlocksInit::FLOWING_LAVA.getName(), 13, 14);
        addBlock(ids_t_b::STILL_LAVA_ID, lce::blocks::BlocksInit::STILL_LAVA.getName(), 13, 14);
        addBlock(ids_t_b::SAND_ID, lce::blocks::BlocksInit::SAND.getName(), 2, 1);
        addBlock(ids_t_b::GRAVEL_ID, lce::blocks::BlocksInit::GRAVEL.getName(), 3, 1);
        addBlock(ids_t_b::GOLD_ORE_ID, lce::blocks::BlocksInit::GOLD_ORE.getName(), 0, 2);
        addBlock(ids_t_b::IRON_ORE_ID, lce::blocks::BlocksInit::IRON_ORE.getName(), 1, 2);
        addBlock(ids_t_b::COAL_ORE_ID, lce::blocks::BlocksInit::COAL_ORE.getName(), 2, 2);
        addBlock(ids_t_b::OAK_WOOD_ID, lce::blocks::BlocksInit::OAK_WOOD.getName(), 4, 1); // bottom(5,1)
        addBlock(ids_t_b::OAK_LEAVES_ID, lce::blocks::BlocksInit::OAK_LEAVES.getName(), 0, 0);
        addBlock(ids_t_b::SPONGE_ID, lce::blocks::BlocksInit::SPONGE.getName(), 0, 3); // (12,8)
        addBlock(ids_t_b::GLASS_ID, lce::blocks::BlocksInit::GLASS.getName(), 0, 0);
        addBlock(ids_t_b::LAPIS_LAZULI_ORE_ID, lce::blocks::BlocksInit::LAPIS_LAZULI_ORE.getName(), 0, 10);
        addBlock(ids_t_b::LAPIS_LAZULI_BLOCK_ID, lce::blocks::BlocksInit::LAPIS_LAZULI_BLOCK.getName(), 0, 9);
        addBlock(ids_t_b::DISPENSER_ID, lce::blocks::BlocksInit::DISPENSER.getName(), 11, 1);
        addBlock(ids_t_b::SANDSTONE_ID, lce::blocks::BlocksInit::SANDSTONE.getName(), 0, 0);
        addBlock(ids_t_b::NOTE_BLOCK_ID, lce::blocks::BlocksInit::NOTE_BLOCK.getName(), 2, 16);
        addBlock(ids_t_b::BED_BLOCK_ID, lce::blocks::BlocksInit::BED_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::POWERED_RAIL_ID, lce::blocks::BlocksInit::POWERED_RAIL.getName(), 0, 0);
        addBlock(ids_t_b::DETECTOR_RAIL_ID, lce::blocks::BlocksInit::DETECTOR_RAIL.getName(), 0, 0);
        addBlock(ids_t_b::STICKY_PISTON_ID, lce::blocks::BlocksInit::STICKY_PISTON.getName(), 0, 0);
        addBlock(ids_t_b::COBWEB_ID, lce::blocks::BlocksInit::COBWEB.getName(), 11, 0);
        addBlock(ids_t_b::TALL_GRASS_SHRUB_ID, lce::blocks::BlocksInit::TALL_GRASS_SHRUB.getName(), 0, 0);
        addBlock(ids_t_b::DEAD_BUSH_ID, lce::blocks::BlocksInit::DEAD_BUSH.getName(), 0, 0);
        addBlock(ids_t_b::PISTON_ID, lce::blocks::BlocksInit::PISTON.getName(), 0, 0);
        addBlock(ids_t_b::PISTON_HEAD_ID, lce::blocks::BlocksInit::PISTON_HEAD.getName(), 0, 0);
        addBlock(ids_t_b::WOOL_ID, lce::blocks::BlocksInit::WHITE_WOOL.getName(), 0, 0);
        addBlock(ids_t_b::DANDELION_ID, lce::blocks::BlocksInit::DANDELION.getName(), 13, 0);
        addBlock(ids_t_b::POPPY_ID, lce::blocks::BlocksInit::POPPY.getName(), 12, 0);
        addBlock(ids_t_b::BROWN_MUSHROOM_ID, lce::blocks::BlocksInit::BROWN_MUSHROOM.getName(), 13, 1);
        addBlock(ids_t_b::RED_MUSHROOM_ID, lce::blocks::BlocksInit::RED_MUSHROOM.getName(), 12, 1);
        addBlock(ids_t_b::GOLD_BLOCK_ID, lce::blocks::BlocksInit::GOLD_BLOCK.getName(), 7, 1);
        addBlock(ids_t_b::IRON_BLOCK_ID, lce::blocks::BlocksInit::IRON_BLOCK.getName(), 6, 1);
        addBlock(ids_t_b::DOUBLE_STONE_SLAB_ID, lce::blocks::BlocksInit::DOUBLE_STONE_SLAB.getName(), 0, 0);
        addBlock(ids_t_b::STONE_SLAB_ID, lce::blocks::BlocksInit::STONE_SLAB.getName(), 0, 0);
        addBlock(ids_t_b::BRICKS_ID, lce::blocks::BlocksInit::BRICKS.getName(), 7, 0);
        addBlock(ids_t_b::TNT_ID, lce::blocks::BlocksInit::TNT.getName(), 8, 0); // (9,0), (10,0)
        addBlock(ids_t_b::BOOKSHELF_ID, lce::blocks::BlocksInit::BOOKSHELF.getName(), 3, 2);
        addBlock(ids_t_b::MOSS_STONE_ID, lce::blocks::BlocksInit::MOSS_STONE.getName(), 4, 2);
        addBlock(ids_t_b::OBSIDIAN_ID, lce::blocks::BlocksInit::OBSIDIAN.getName(), 5, 2);
        addBlock(ids_t_b::TORCH_ID, lce::blocks::BlocksInit::TORCH.getName(), 0, 5);
        addBlock(ids_t_b::FIRE_ID, lce::blocks::BlocksInit::FIRE.getName(), 0, 0);
        addBlock(ids_t_b::MONSTER_SPAWNER_ID, lce::blocks::BlocksInit::MONSTER_SPAWNER.getName(), 0, 0);
        addBlock(ids_t_b::OAK_WOOD_STAIRS_ID, lce::blocks::BlocksInit::OAK_WOOD_STAIRS.getName(), 0, 0);
        addBlock(ids_t_b::CHEST_ID, lce::blocks::BlocksInit::CHEST.getName(), 0, 0);
        addBlock(ids_t_b::REDSTONE_WIRE_ID, lce::blocks::BlocksInit::REDSTONE_WIRE.getName(), 0, 0);
        addBlock(ids_t_b::DIAMOND_ORE_ID, lce::blocks::BlocksInit::DIAMOND_ORE.getName(), 2, 3);
        addBlock(ids_t_b::DIAMOND_BLOCK_ID, lce::blocks::BlocksInit::DIAMOND_BLOCK.getName(), 8, 1);
        addBlock(ids_t_b::CRAFTING_TABLE_ID, lce::blocks::BlocksInit::CRAFTING_TABLE.getName(), 11, 3); // (12,3), (11,2)
        addBlock(ids_t_b::WHEAT_CROPS_ID, lce::blocks::BlocksInit::WHEAT_CROPS.getName(), 15, 5);       // (8-15,5)
        addBlock(ids_t_b::FARMLAND_ID, lce::blocks::BlocksInit::FARMLAND.getName(), 0, 0);
        addBlock(ids_t_b::FURNACE_ID, lce::blocks::BlocksInit::FURNACE.getName(), 12, 2);                 // (13,2), (14,3)
        addBlock(ids_t_b::BURNING_FURNACE_ID, lce::blocks::BlocksInit::BURNING_FURNACE.getName(), 13, 3); // (13,2), (14,3)
        addBlock(ids_t_b::STANDING_SIGN_BLOCK_ID, lce::blocks::BlocksInit::STANDING_SIGN_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::OAK_DOOR_BLOCK_ID, lce::blocks::BlocksInit::OAK_DOOR_BLOCK.getName(), 1, 5); // (1,6)
        addBlock(ids_t_b::LADDER_ID, lce::blocks::BlocksInit::LADDER.getName(), 3, 5);
        addBlock(ids_t_b::RAIL_ID, lce::blocks::BlocksInit::RAIL.getName(), 0, 0);
        addBlock(ids_t_b::COBBLESTONE_STAIRS_ID, lce::blocks::BlocksInit::COBBLESTONE_STAIRS.getName(), 0, 0);
        addBlock(ids_t_b::WALL_MOUNTED_SIGN_BLOCK_ID, lce::blocks::BlocksInit::WALL_MOUNTED_SIGN_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::LEVER_ID, lce::blocks::BlocksInit::LEVER.getName(), 0, 0);
        addBlock(ids_t_b::STONE_PRESSURE_PLATE_ID, lce::blocks::BlocksInit::STONE_PRESSURE_PLATE.getName(), 0, 0);
        addBlock(ids_t_b::IRON_DOOR_BLOCK_ID, lce::blocks::BlocksInit::IRON_DOOR_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::WOODEN_PRESSURE_PLATE_ID, lce::blocks::BlocksInit::WOODEN_PRESSURE_PLATE.getName(), 0, 0);
        addBlock(ids_t_b::REDSTONE_ORE_ID, lce::blocks::BlocksInit::REDSTONE_ORE.getName(), 3, 3);
        addBlock(ids_t_b::GLOWING_REDSTONE_ORE_ID, lce::blocks::BlocksInit::GLOWING_REDSTONE_ORE.getName(), 3, 3); // FIX
        addBlock(ids_t_b::OFF_REDSTONE_TORCH_ID, lce::blocks::BlocksInit::OFF_REDSTONE_TORCH.getName(), 3, 7);
        addBlock(ids_t_b::ON_REDSTONE_TORCH_ID, lce::blocks::BlocksInit::ON_REDSTONE_TORCH.getName(), 3, 6);
        addBlock(ids_t_b::STONE_BUTTON_ID, lce::blocks::BlocksInit::STONE_BUTTON.getName(), 0, 0);
        addBlock(ids_t_b::SNOW_ID, lce::blocks::BlocksInit::SNOW.getName(), 0, 0);
        addBlock(ids_t_b::ICE_ID, lce::blocks::BlocksInit::ICE.getName(), 0, 0);
        addBlock(ids_t_b::SNOW_BLOCK_ID, lce::blocks::BlocksInit::SNOW_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::CACTUS_ID, lce::blocks::BlocksInit::CACTUS.getName(), 0, 0);
        addBlock(ids_t_b::CLAY_BLOCK_ID, lce::blocks::BlocksInit::CLAY_BLOCK.getName(), 8, 4);
        addBlock(ids_t_b::SUGAR_CANES_ID, lce::blocks::BlocksInit::SUGAR_CANES.getName(), 0, 0);
        addBlock(ids_t_b::JUKEBOX_ID, lce::blocks::BlocksInit::JUKEBOX.getName(), 0, 0);
        addBlock(ids_t_b::OAK_FENCE_ID, lce::blocks::BlocksInit::OAK_FENCE.getName(), 0, 0);
        addBlock(ids_t_b::CARVED_PUMPKIN_ID, lce::blocks::BlocksInit::PUMPKIN.getName(), 0, 0);
        addBlock(ids_t_b::NETHERRACK_ID, lce::blocks::BlocksInit::NETHERRACK.getName(), 7, 6);
        addBlock(ids_t_b::SOUL_SAND_ID, lce::blocks::BlocksInit::SOUL_SAND.getName(), 8, 6);
        addBlock(ids_t_b::GLOWSTONE_ID, lce::blocks::BlocksInit::GLOWSTONE.getName(), 9, 6);
        addBlock(ids_t_b::NETHER_PORTAL_ID, lce::blocks::BlocksInit::NETHER_PORTAL.getName(), 0, 0);
        addBlock(ids_t_b::JACK_O_LANTERN_ID, lce::blocks::BlocksInit::JACK_O_LANTERN.getName(), 0, 0);
        addBlock(ids_t_b::CAKE_BLOCK_ID, lce::blocks::BlocksInit::CAKE_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::OFF_REDSTONE_REPEATER_BLOCK_ID, lce::blocks::BlocksInit::OFF_REDSTONE_REPEATER_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::ON_REDSTONE_REPEATER_BLOCK_ID, lce::blocks::BlocksInit::ON_REDSTONE_REPEATER_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::STAINED_GLASS_ID, lce::blocks::BlocksInit::WHITE_STAINED_GLASS.getName(), 0, 0);
        addBlock(ids_t_b::WOODEN_TRAPDOOR_ID, lce::blocks::BlocksInit::WOODEN_TRAPDOOR.getName(), 0, 0);
        addBlock(ids_t_b::STONE_MONSTER_EGG_ID, lce::blocks::BlocksInit::STONE_MONSTER_EGG.getName(), 0, 0);
        addBlock(ids_t_b::STONE_BRICKS_ID, lce::blocks::BlocksInit::STONE_BRICKS.getName(), 0, 0);
        addBlock(ids_t_b::BROWN_MUSHROOM_BLOCK_ID, lce::blocks::BlocksInit::BROWN_MUSHROOM_BLOCK.getName(), 14, 7);
        addBlock(ids_t_b::RED_MUSHROOM_BLOCK_ID, lce::blocks::BlocksInit::RED_MUSHROOM_BLOCK.getName(), 13, 7);
        addBlock(ids_t_b::IRON_BARS_ID, lce::blocks::BlocksInit::IRON_BARS.getName(), 5, 5);
        addBlock(ids_t_b::GLASS_PANE_ID, lce::blocks::BlocksInit::GLASS_PANE.getName(), 0, 0);
        addBlock(ids_t_b::MELON_BLOCK_ID, lce::blocks::BlocksInit::MELON_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::PUMPKIN_STEM_ID, lce::blocks::BlocksInit::PUMPKIN_STEM.getName(), 0, 0);
        addBlock(ids_t_b::MELON_STEM_ID, lce::blocks::BlocksInit::MELON_STEM.getName(), 0, 0);
        addBlock(ids_t_b::VINES_ID, lce::blocks::BlocksInit::VINES.getName(), 0, 0);
        addBlock(ids_t_b::OAK_FENCE_GATE_ID, lce::blocks::BlocksInit::OAK_FENCE_GATE.getName(), 0, 0);
        addBlock(ids_t_b::BRICK_STAIRS_ID, lce::blocks::BlocksInit::BRICK_STAIRS.getName(), 0, 0);
        addBlock(ids_t_b::STONE_BRICK_STAIRS_ID, lce::blocks::BlocksInit::STONE_BRICK_STAIRS.getName(), 0, 0);
        addBlock(ids_t_b::MYCELIUM_ID, lce::blocks::BlocksInit::MYCELIUM.getName(), 0, 0);
        addBlock(ids_t_b::LILY_PAD_ID, lce::blocks::BlocksInit::LILY_PAD.getName(), 0, 0);
        addBlock(ids_t_b::NETHER_BRICK_BLOCK_ID, lce::blocks::BlocksInit::NETHER_BRICK_BLOCK.getName(), 0, 14);
        addBlock(ids_t_b::NETHER_BRICK_FENCE_ID, lce::blocks::BlocksInit::NETHER_BRICK_FENCE.getName(), 0, 14);   // FIX
        addBlock(ids_t_b::NETHER_BRICK_STAIRS_ID, lce::blocks::BlocksInit::NETHER_BRICK_STAIRS.getName(), 0, 14); // FIX
        addBlock(ids_t_b::NETHER_WART_ID, lce::blocks::BlocksInit::NETHER_WART.getName(), 4, 14);                 // (2-4,14)
        addBlock(ids_t_b::ENCHANTMENT_TABLE_ID, lce::blocks::BlocksInit::ENCHANTMENT_TABLE.getName(), 6, 11);     // (6,10), (6,11), (7, 11)
        addBlock(ids_t_b::BREWING_STAND_ID, lce::blocks::BlocksInit::BREWING_STAND.getName(), 0, 0);
        addBlock(ids_t_b::CAULDRON_ID, lce::blocks::BlocksInit::CAULDRON.getName(), 0, 0);
        addBlock(ids_t_b::END_PORTAL_ID, lce::blocks::BlocksInit::END_PORTAL.getName(), 0, 0);
        addBlock(ids_t_b::END_PORTAL_FRAME_ID, lce::blocks::BlocksInit::END_PORTAL_FRAME.getName(), 0, 0);
        addBlock(ids_t_b::END_STONE_ID, lce::blocks::BlocksInit::END_STONE.getName(), 15, 10);
        addBlock(ids_t_b::DRAGON_EGG_ID, lce::blocks::BlocksInit::DRAGON_EGG.getName(), 7, 10);
        addBlock(ids_t_b::INACTIVE_REDSTONE_LAMP_ID, lce::blocks::BlocksInit::INACTIVE_REDSTONE_LAMP.getName(), 3, 13);
        addBlock(ids_t_b::ACTIVE_REDSTONE_LAMP_ID, lce::blocks::BlocksInit::ACTIVE_REDSTONE_LAMP.getName(), 4, 13);
        addBlock(ids_t_b::DOUBLE_OAK_WOOD_SLAB_ID, lce::blocks::BlocksInit::DOUBLE_OAK_WOOD_SLAB.getName(), 0, 0);
        addBlock(ids_t_b::OAK_WOOD_SLAB_ID, lce::blocks::BlocksInit::OAK_WOOD_SLAB.getName(), 0, 0);
        addBlock(ids_t_b::COCOA_ID, lce::blocks::BlocksInit::COCOA.getName(), 0, 0);
        addBlock(ids_t_b::SANDSTONE_STAIRS_ID, lce::blocks::BlocksInit::SANDSTONE_STAIRS.getName(), 0, 0);
        addBlock(ids_t_b::EMERALD_ORE_ID, lce::blocks::BlocksInit::EMERALD_ORE.getName(), 11, 10);
        addBlock(ids_t_b::ENDER_CHEST_ID, lce::blocks::BlocksInit::ENDER_CHEST.getName(), 0, 0);
        addBlock(ids_t_b::TRIPWIRE_HOOK_ID, lce::blocks::BlocksInit::TRIPWIRE_HOOK.getName(), 12, 10);
        addBlock(ids_t_b::TRIPWIRE_ID, lce::blocks::BlocksInit::TRIPWIRE.getName(), 0, 0);
        addBlock(ids_t_b::EMERALD_BLOCK_ID, lce::blocks::BlocksInit::EMERALD_BLOCK.getName(), 9, 1);
        addBlock(ids_t_b::SPRUCE_WOOD_STAIRS_ID, lce::blocks::BlocksInit::SPRUCE_WOOD_STAIRS.getName(), 0, 0);
        addBlock(ids_t_b::BIRCH_WOOD_STAIRS_ID, lce::blocks::BlocksInit::BIRCH_WOOD_STAIRS.getName(), 0, 0);
        addBlock(ids_t_b::JUNGLE_WOOD_STAIRS_ID, lce::blocks::BlocksInit::JUNGLE_WOOD_STAIRS.getName(), 0, 0);
        addBlock(ids_t_b::COMMAND_BLOCK_ID, lce::blocks::BlocksInit::COMMAND_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::BEACON_ID, lce::blocks::BlocksInit::BEACON.getName(), 0, 0);
        addBlock(ids_t_b::COBBLESTONE_WALL_ID, lce::blocks::BlocksInit::COBBLESTONE_WALL.getName(), 0, 0);
        addBlock(ids_t_b::FLOWER_POT_ID, lce::blocks::BlocksInit::FLOWER_POT.getName(), 0, 0);
        addBlock(ids_t_b::CARROTS_ID, lce::blocks::BlocksInit::CARROTS.getName(), 11, 12); // (8-11,12)
        addBlock(ids_t_b::POTATOES_ID, lce::blocks::BlocksInit::POTATOES.getName(), 0, 0);
        addBlock(ids_t_b::WOODEN_BUTTON_ID, lce::blocks::BlocksInit::WOODEN_BUTTON.getName(), 0, 0);
        addBlock(ids_t_b::MOB_HEAD_ID, lce::blocks::BlocksInit::MOB_HEAD.getName(), 0, 0);
        addBlock(ids_t_b::ANVIL_ID, lce::blocks::BlocksInit::ANVIL.getName(), 0, 0);
        addBlock(ids_t_b::TRAPPED_CHEST_ID, lce::blocks::BlocksInit::TRAPPED_CHEST.getName(), 0, 0);
        addBlock(ids_t_b::LIGHT_WEIGHTED_PRESSURE_PLATE_ID, lce::blocks::BlocksInit::LIGHT_WEIGHTED_PRESSURE_PLATE.getName(), 0, 0);
        addBlock(ids_t_b::HEAVY_WEIGHTED_PRESSURE_PLATE_ID, lce::blocks::BlocksInit::HEAVY_WEIGHTED_PRESSURE_PLATE.getName(), 0, 0);
        addBlock(ids_t_b::INACTIVE_REDSTONE_COMPARATOR_ID, lce::blocks::BlocksInit::INACTIVE_REDSTONE_COMPARATOR.getName(), 0, 0);
        addBlock(ids_t_b::ACTIVE_REDSTONE_COMPARATOR_ID, lce::blocks::BlocksInit::ACTIVE_REDSTONE_COMPARATOR.getName(), 0, 0);
        addBlock(ids_t_b::DAYLIGHT_SENSOR_ID, lce::blocks::BlocksInit::DAYLIGHT_SENSOR.getName(), 0, 0);
        addBlock(ids_t_b::REDSTONE_BLOCK_ID, lce::blocks::BlocksInit::REDSTONE_BLOCK.getName(), 10, 1);
        addBlock(ids_t_b::NETHER_QUARTZ_ORE_ID, lce::blocks::BlocksInit::NETHER_QUARTZ_ORE.getName(), 15, 11);
        addBlock(ids_t_b::HOPPER_ID, lce::blocks::BlocksInit::HOPPER.getName(), 0, 0);
        addBlock(ids_t_b::QUARTZ_BLOCK_ID, lce::blocks::BlocksInit::QUARTZ_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::QUARTZ_STAIRS_ID, lce::blocks::BlocksInit::QUARTZ_STAIRS.getName(), 0, 0);
        addBlock(ids_t_b::ACTIVATOR_RAIL_ID, lce::blocks::BlocksInit::ACTIVATOR_RAIL.getName(), 0, 0);
        addBlock(ids_t_b::DROPPER_ID, lce::blocks::BlocksInit::DROPPER.getName(), 0, 0);
        addBlock(ids_t_b::STAINED_HARDENED_CLAY_ID, lce::blocks::BlocksInit::WHITE_HARDENED_CLAY.getName(), 0, 0);
        addBlock(ids_t_b::STAINED_GLASS_PANE_ID, lce::blocks::BlocksInit::WHITE_STAINED_GLASS_PANE.getName(), 0, 0);
        addBlock(ids_t_b::ACACIA_LEAVES_ID, lce::blocks::BlocksInit::ACACIA_LEAVES.getName(), 0, 0);
        addBlock(ids_t_b::ACACIA_WOOD_ID, lce::blocks::BlocksInit::ACACIA_WOOD.getName(), 0, 0);
        addBlock(ids_t_b::ACACIA_WOOD_STAIRS_ID, lce::blocks::BlocksInit::ACACIA_WOOD_STAIRS.getName(), 0, 0);
        addBlock(ids_t_b::DARK_OAK_WOOD_STAIRS_ID, lce::blocks::BlocksInit::DARK_OAK_WOOD_STAIRS.getName(), 0, 0);
        addBlock(ids_t_b::SLIME_BLOCK_ID, lce::blocks::BlocksInit::SLIME_BLOCK.getName(), 12, 12);
        addBlock(ids_t_b::BARRIER_ID, lce::blocks::BlocksInit::BARRIER.getName(), 11, 23);
        addBlock(ids_t_b::IRON_TRAPDOOR_ID, lce::blocks::BlocksInit::IRON_TRAPDOOR.getName(), 0, 0);
        addBlock(ids_t_b::PRISMARINE_ID, lce::blocks::BlocksInit::PRISMARINE.getName(), 0, 0);
        addBlock(ids_t_b::SEA_LANTERN_ID, lce::blocks::BlocksInit::SEA_LANTERN.getName(), 0, 0);
        addBlock(ids_t_b::HAY_BALE_ID, lce::blocks::BlocksInit::HAY_BALE.getName(), 10, 15); // (13,15)
        addBlock(ids_t_b::CARPET_ID, lce::blocks::BlocksInit::WHITE_CARPET.getName(), 0, 0);
        addBlock(ids_t_b::HARDENED_CLAY_ID, lce::blocks::BlocksInit::HARDENED_CLAY.getName(), 0, 0);
        addBlock(ids_t_b::BLOCK_OF_COAL_ID, lce::blocks::BlocksInit::BLOCK_OF_COAL.getName(), 0, 16);
        addBlock(ids_t_b::PACKED_ICE_ID, lce::blocks::BlocksInit::PACKED_ICE.getName(), 0, 0);
        addBlock(ids_t_b::DOUBLE_PLANT_ID, lce::blocks::BlocksInit::SUNFLOWER.getName(), 0, 0);
        addBlock(ids_t_b::FREE_STANDING_BANNER_ID, lce::blocks::BlocksInit::FREE_STANDING_BANNER.getName(), 0, 0);
        addBlock(ids_t_b::WALL_MOUNTED_BANNER_ID, lce::blocks::BlocksInit::WALL_MOUNTED_BANNER.getName(), 0, 0);
        addBlock(ids_t_b::INVERTED_DAYLIGHT_SENSOR_ID, lce::blocks::BlocksInit::INVERTED_DAYLIGHT_SENSOR.getName(), 0, 0);
        addBlock(ids_t_b::RED_SANDSTONE_ID, lce::blocks::BlocksInit::RED_SANDSTONE.getName(), 0, 0);
        addBlock(ids_t_b::RED_SANDSTONE_STAIRS_ID, lce::blocks::BlocksInit::RED_SANDSTONE_STAIRS.getName(), 0, 0);
        addBlock(ids_t_b::DOUBLE_RED_SANDSTONE_SLAB_ID, lce::blocks::BlocksInit::DOUBLE_RED_SANDSTONE_SLAB.getName(), 0, 0);
        addBlock(ids_t_b::RED_SANDSTONE_SLAB_ID, lce::blocks::BlocksInit::RED_SANDSTONE_SLAB.getName(), 0, 0);
        addBlock(ids_t_b::SPRUCE_FENCE_GATE_ID, lce::blocks::BlocksInit::SPRUCE_FENCE_GATE.getName(), 0, 0);
        addBlock(ids_t_b::BIRCH_FENCE_GATE_ID, lce::blocks::BlocksInit::BIRCH_FENCE_GATE.getName(), 0, 0);
        addBlock(ids_t_b::JUNGLE_FENCE_GATE_ID, lce::blocks::BlocksInit::JUNGLE_FENCE_GATE.getName(), 0, 0);
        addBlock(ids_t_b::DARK_OAK_FENCE_GATE_ID, lce::blocks::BlocksInit::DARK_OAK_FENCE_GATE.getName(), 0, 0);
        addBlock(ids_t_b::ACACIA_FENCE_GATE_ID, lce::blocks::BlocksInit::ACACIA_FENCE_GATE.getName(), 0, 0);
        addBlock(ids_t_b::SPRUCE_FENCE_ID, lce::blocks::BlocksInit::SPRUCE_FENCE.getName(), 0, 0);
        addBlock(ids_t_b::BIRCH_FENCE_ID, lce::blocks::BlocksInit::BIRCH_FENCE.getName(), 0, 0);
        addBlock(ids_t_b::JUNGLE_FENCE_ID, lce::blocks::BlocksInit::JUNGLE_FENCE.getName(), 0, 0);
        addBlock(ids_t_b::DARK_OAK_FENCE_ID, lce::blocks::BlocksInit::DARK_OAK_FENCE.getName(), 0, 0);
        addBlock(ids_t_b::ACACIA_FENCE_ID, lce::blocks::BlocksInit::ACACIA_FENCE.getName(), 0, 0);
        addBlock(ids_t_b::SPRUCE_DOOR_BLOCK_ID, lce::blocks::BlocksInit::SPRUCE_DOOR_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::BIRCH_DOOR_BLOCK_ID, lce::blocks::BlocksInit::BIRCH_DOOR_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::JUNGLE_DOOR_BLOCK_ID, lce::blocks::BlocksInit::JUNGLE_DOOR_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::ACACIA_DOOR_BLOCK_ID, lce::blocks::BlocksInit::ACACIA_DOOR_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::DARK_OAK_DOOR_BLOCK_ID, lce::blocks::BlocksInit::DARK_OAK_DOOR_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::END_ROD_ID, lce::blocks::BlocksInit::END_ROD.getName(), 0, 0);
        addBlock(ids_t_b::CHORUS_PLANT_ID, lce::blocks::BlocksInit::CHORUS_PLANT.getName(), 0, 0);
        addBlock(ids_t_b::CHORUS_FLOWER_ID, lce::blocks::BlocksInit::CHORUS_FLOWER.getName(), 0, 0);
        addBlock(ids_t_b::PURPUR_BLOCK_ID, lce::blocks::BlocksInit::PURPUR_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::PURPUR_PILLAR_ID, lce::blocks::BlocksInit::PURPUR_PILLAR.getName(), 0, 0);
        addBlock(ids_t_b::PURPUR_STAIRS_ID, lce::blocks::BlocksInit::PURPUR_STAIRS.getName(), 0, 0);
        addBlock(ids_t_b::PURPUR_DOUBLE_SLAB_ID, lce::blocks::BlocksInit::PURPUR_DOUBLE_SLAB.getName(), 0, 0);
        addBlock(ids_t_b::PURPUR_SLAB_ID, lce::blocks::BlocksInit::PURPUR_SLAB.getName(), 0, 0);
        addBlock(ids_t_b::END_STONE_BRICKS_ID, lce::blocks::BlocksInit::END_STONE_BRICKS.getName(), 8, 23);
        addBlock(ids_t_b::BEETROOT_BLOCK_ID, lce::blocks::BlocksInit::BEETROOT_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::GRASS_PATH_ID, lce::blocks::BlocksInit::GRASS_PATH.getName(), 0, 0);
        addBlock(ids_t_b::END_GATEWAY_ID, lce::blocks::BlocksInit::END_GATEWAY.getName(), 0, 0);
        addBlock(ids_t_b::REPEATING_COMMAND_BLOCK_ID, lce::blocks::BlocksInit::REPEATING_COMMAND_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::CHAIN_COMMAND_BLOCK_ID, lce::blocks::BlocksInit::CHAIN_COMMAND_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::FROSTED_ICE_ID, lce::blocks::BlocksInit::FROSTED_ICE.getName(), 12, 24); // (12-15,24)
        addBlock(ids_t_b::MAGMA_BLOCK_ID, lce::blocks::BlocksInit::MAGMA_BLOCK.getName(), 9, 24);
        addBlock(ids_t_b::NETHER_WART_BLOCK_ID, lce::blocks::BlocksInit::NETHER_WART_BLOCK.getName(), 10, 24);
        addBlock(ids_t_b::RED_NETHER_BRICK_ID, lce::blocks::BlocksInit::RED_NETHER_BRICK.getName(), 11, 24);
        addBlock(ids_t_b::BONE_BLOCK_ID, lce::blocks::BlocksInit::BONE_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::STRUCTURE_VOID_ID, lce::blocks::BlocksInit::STRUCTURE_VOID.getName(), 0, 0);
        addBlock(ids_t_b::OBSERVER_ID, lce::blocks::BlocksInit::OBSERVER.getName(), 4, 26); // (4-8,26)
        addBlock(ids_t_b::WHITE_SHULKER_BOX_ID, lce::blocks::BlocksInit::WHITE_SHULKER_BOX.getName(), 0, 0);
        addBlock(ids_t_b::ORANGE_SHULKER_BOX_ID, lce::blocks::BlocksInit::ORANGE_SHULKER_BOX.getName(), 0, 0);
        addBlock(ids_t_b::MAGENTA_SHULKER_BOX_ID, lce::blocks::BlocksInit::MAGENTA_SHULKER_BOX.getName(), 0, 0);
        addBlock(ids_t_b::LIGHT_BLUE_SHULKER_BOX_ID, lce::blocks::BlocksInit::LIGHT_BLUE_SHULKER_BOX.getName(), 0, 0);
        addBlock(ids_t_b::YELLOW_SHULKER_BOX_ID, lce::blocks::BlocksInit::YELLOW_SHULKER_BOX.getName(), 0, 0);
        addBlock(ids_t_b::LIME_SHULKER_BOX_ID, lce::blocks::BlocksInit::LIME_SHULKER_BOX.getName(), 0, 0);
        addBlock(ids_t_b::PINK_SHULKER_BOX_ID, lce::blocks::BlocksInit::PINK_SHULKER_BOX.getName(), 0, 0);
        addBlock(ids_t_b::GRAY_SHULKER_BOX_ID, lce::blocks::BlocksInit::GRAY_SHULKER_BOX.getName(), 0, 0);
        addBlock(ids_t_b::LIGHT_GRAY_SHULKER_BOX_ID, lce::blocks::BlocksInit::LIGHT_GRAY_SHULKER_BOX.getName(), 0, 0);
        addBlock(ids_t_b::CYAN_SHULKER_BOX_ID, lce::blocks::BlocksInit::CYAN_SHULKER_BOX.getName(), 0, 0);
        addBlock(ids_t_b::PURPLE_SHULKER_BOX_ID, lce::blocks::BlocksInit::PURPLE_SHULKER_BOX.getName(), 0, 0);
        addBlock(ids_t_b::BLUE_SHULKER_BOX_ID, lce::blocks::BlocksInit::BLUE_SHULKER_BOX.getName(), 0, 0);
        addBlock(ids_t_b::BROWN_SHULKER_BOX_ID, lce::blocks::BlocksInit::BROWN_SHULKER_BOX.getName(), 0, 0);
        addBlock(ids_t_b::GREEN_SHULKER_BOX_ID, lce::blocks::BlocksInit::GREEN_SHULKER_BOX.getName(), 0, 0);
        addBlock(ids_t_b::RED_SHULKER_BOX_ID, lce::blocks::BlocksInit::RED_SHULKER_BOX.getName(), 0, 0);
        addBlock(ids_t_b::BLACK_SHULKER_BOX_ID, lce::blocks::BlocksInit::BLACK_SHULKER_BOX.getName(), 0, 0);
        addBlock(ids_t_b::WHITE_GLAZED_TERRACOTTA_ID, lce::blocks::BlocksInit::WHITE_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(ids_t_b::ORANGE_GLAZED_TERRACOTTA_ID, lce::blocks::BlocksInit::ORANGE_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(ids_t_b::MAGENTA_GLAZED_TERRACOTTA_ID, lce::blocks::BlocksInit::MAGENTA_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(ids_t_b::LIGHT_BLUE_GLAZED_TERRACOTTA_ID, lce::blocks::BlocksInit::LIGHT_BLUE_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(ids_t_b::YELLOW_GLAZED_TERRACOTTA_ID, lce::blocks::BlocksInit::YELLOW_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(ids_t_b::LIME_GLAZED_TERRACOTTA_ID, lce::blocks::BlocksInit::LIME_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(ids_t_b::PINK_GLAZED_TERRACOTTA_ID, lce::blocks::BlocksInit::PINK_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(ids_t_b::GRAY_GLAZED_TERRACOTTA_ID, lce::blocks::BlocksInit::GRAY_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(ids_t_b::LIGHT_GRAY_GLAZED_TERRACOTTA_ID, lce::blocks::BlocksInit::LIGHT_GRAY_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(ids_t_b::CYAN_GLAZED_TERRACOTTA_ID, lce::blocks::BlocksInit::CYAN_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(ids_t_b::PURPLE_GLAZED_TERRACOTTA_ID, lce::blocks::BlocksInit::PURPLE_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(ids_t_b::BLUE_GLAZED_TERRACOTTA_ID, lce::blocks::BlocksInit::BLUE_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(ids_t_b::BROWN_GLAZED_TERRACOTTA_ID, lce::blocks::BlocksInit::BROWN_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(ids_t_b::GREEN_GLAZED_TERRACOTTA_ID, lce::blocks::BlocksInit::GREEN_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(ids_t_b::RED_GLAZED_TERRACOTTA_ID, lce::blocks::BlocksInit::RED_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(ids_t_b::BLACK_GLAZED_TERRACOTTA_ID, lce::blocks::BlocksInit::BLACK_GLAZED_TERRACOTTA.getName(), 0, 0);
        addBlock(ids_t_b::CONCRETE_ID, lce::blocks::BlocksInit::WHITE_CONCRETE.getName(), 0, 0);
        addBlock(ids_t_b::CONCRETE_POWDER_ID, lce::blocks::BlocksInit::WHITE_CONCRETE_POWDER.getName(), 0, 0);
        addBlock(ids_t_b::STRUCTURE_BLOCK_ID, lce::blocks::BlocksInit::STRUCTURE_BLOCK.getName(), 13, 26); // (11-15,26)
        addBlock(ids_t_b::CONDUIT_ID, lce::blocks::BlocksInit::CONDUIT.getName(), 0, 0);
        addBlock(ids_t_b::PUMPKIN_ID, lce::blocks::BlocksInit::UNKNOWN_PUMP.getName(), 0, 0);
        addBlock(ids_t_b::KELP_ID, lce::blocks::BlocksInit::KELP.getName(), 0, 0);
        addBlock(ids_t_b::CORAL_BLOCK_ID, lce::blocks::BlocksInit::CORAL_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::CORAL_ID, lce::blocks::BlocksInit::CORAL.getName(), 0, 0);
        addBlock(ids_t_b::CORAL_FAN_ID, lce::blocks::BlocksInit::CORAL_FAN.getName(), 0, 0);
        addBlock(ids_t_b::CORAL_FAN_DEAD_ID, lce::blocks::BlocksInit::CORAL_FAN_DEAD.getName(), 0, 0);
        addBlock(ids_t_b::CORAL_FAN_WALL1_ID, lce::blocks::BlocksInit::CORAL_FAN_WALL1.getName(), 0, 0);
        addBlock(ids_t_b::CORAL_FAN_WALL2_ID, lce::blocks::BlocksInit::CORAL_FAN_WALL2.getName(), 0, 0);
        addBlock(ids_t_b::CORAL_FAN_WALL3_ID, lce::blocks::BlocksInit::CORAL_FAN_WALL3.getName(), 0, 0);
        addBlock(ids_t_b::DRIED_KELP_BLOCK_ID, lce::blocks::BlocksInit::DRIED_KELP_BLOCK.getName(), 0, 0);
        addBlock(ids_t_b::SEAGRASS_ID, lce::blocks::BlocksInit::SEAGRASS.getName(), 0, 0);
        addBlock(ids_t_b::SEAPICKLE_ID, lce::blocks::BlocksInit::SEAPICKLE.getName(), 0, 0);
        addBlock(ids_t_b::BUBBLE_COLUMN_ID, lce::blocks::BlocksInit::BUBBLE_COLUMN.getName(), 0, 0);
        addBlock(ids_t_b::BLUE_ICE_ID, lce::blocks::BlocksInit::BLUE_ICE.getName(), 0, 0);
        addBlock(ids_t_b::SPRUCE_TRAPDOOR_ID, lce::blocks::BlocksInit::SPRUCE_TRAPDOOR.getName(), 0, 0);
        addBlock(ids_t_b::BIRCH_TRAPDOOR_ID, lce::blocks::BlocksInit::BIRCH_TRAPDOOR.getName(), 0, 0);
        addBlock(ids_t_b::JUNGLE_TRAPDOOR_ID, lce::blocks::BlocksInit::JUNGLE_TRAPDOOR.getName(), 0, 0);
        addBlock(ids_t_b::ACACIA_TRAPDOOR_ID, lce::blocks::BlocksInit::ACACIA_TRAPDOOR.getName(), 0, 0);
        addBlock(ids_t_b::DARK_OAK_TRAPDOOR_ID, lce::blocks::BlocksInit::DARK_OAK_TRAPDOOR.getName(), 0, 0);
        addBlock(ids_t_b::TURTLE_EGG_ID_ID, lce::blocks::BlocksInit::TURTLE_EGG.getName(), 0, 0);
        addBlock(ids_t_b::PRISMARINE_STAIRS_ID, lce::blocks::BlocksInit::PRISMARINE_STAIRS.getName(), 0, 0);
        addBlock(ids_t_b::PRISMARINE_BRICK_STAIRS_ID, lce::blocks::BlocksInit::PRISMARINE_BRICK_STAIRS.getName(), 0, 0);
        addBlock(ids_t_b::DARK_PRISMARINE_STAIRS_ID, lce::blocks::BlocksInit::DARK_PRISMARINE_STAIRS.getName(), 0, 0);
        addBlock(ids_t_b::STRIPPED_SPRUCE_LOG_ID, lce::blocks::BlocksInit::STRIPPED_SPRUCE_LOG.getName(), 0, 0);
        addBlock(ids_t_b::STRIPPED_BIRCH_LOG_ID, lce::blocks::BlocksInit::STRIPPED_BIRCH_LOG.getName(), 0, 0);
        addBlock(ids_t_b::STRIPPED_JUNGLE_LOG_ID, lce::blocks::BlocksInit::STRIPPED_JUNGLE_LOG.getName(), 0, 0);
        addBlock(ids_t_b::STRIPPED_ACACIA_LOG_ID, lce::blocks::BlocksInit::STRIPPED_ACACIA_LOG.getName(), 0, 0);
        addBlock(ids_t_b::STRIPPED_DARK_0AK_LOG_ID, lce::blocks::BlocksInit::STRIPPED_DARK_0AK_LOG.getName(), 0, 0);
        addBlock(ids_t_b::STRIPPED_OAK_LOG_ID, lce::blocks::BlocksInit::STRIPPED_OAK_LOG.getName(), 0, 0);
        addBlock(ids_t_b::ACACIA_PRESSURE_PLATE_ID, lce::blocks::BlocksInit::ACACIA_PRESSURE_PLATE.getName(), 0, 0);
        addBlock(ids_t_b::BIRCH_PRESSURE_PLATE_ID, lce::blocks::BlocksInit::BIRCH_PRESSURE_PLATE.getName(), 0, 0);
        addBlock(ids_t_b::DARK_OAK_PRESSURE_PLATE_ID, lce::blocks::BlocksInit::DARK_OAK_PRESSURE_PLATE.getName(), 0, 0);
        addBlock(ids_t_b::JUNGLE_PRESSURE_PLATE_ID, lce::blocks::BlocksInit::JUNGLE_PRESSURE_PLATE.getName(), 0, 0);
        addBlock(ids_t_b::SPRUCE_PRESSURE_PLATE_ID, lce::blocks::BlocksInit::SPRUCE_PRESSURE_PLATE.getName(), 0, 0);
        addBlock(ids_t_b::ACACIA_BUTTON_ID, lce::blocks::BlocksInit::ACACIA_BUTTON.getName(), 0, 0);
        addBlock(ids_t_b::BIRCH_BUTTON_ID, lce::blocks::BlocksInit::BIRCH_BUTTON.getName(), 0, 0);
        addBlock(ids_t_b::DARK_OAK_BUTTON_ID, lce::blocks::BlocksInit::DARK_OAK_BUTTON.getName(), 0, 0);
        addBlock(ids_t_b::JUNGLE_BUTTON_ID, lce::blocks::BlocksInit::JUNGLE_BUTTON.getName(), 0, 0);
        addBlock(ids_t_b::SPRUCE_BUTTON_ID, lce::blocks::BlocksInit::SPRUCE_BUTTON.getName(), 0, 0);
        addBlock(ids_t_b::DOUBLE_PRISMARINE_SLAB_ID, lce::blocks::BlocksInit::DOUBLE_PRISMARINE_SLAB.getName(), 0, 0);
        addBlock(ids_t_b::PRISMARINE_SLAB_ID, lce::blocks::BlocksInit::PRISMARINE_SLAB.getName(), 0, 0);
        addBlock(ids_t_b::SPRUCE_WOOD_2_ID, lce::blocks::BlocksInit::SPRUCE_WOOD_2.getName(), 0, 0);
        addBlock(ids_t_b::BIRCH_WOOD_2_ID, lce::blocks::BlocksInit::BIRCH_WOOD_2.getName(), 0, 0);
        addBlock(ids_t_b::JUNGLE_WOOD_2_ID, lce::blocks::BlocksInit::JUNGLE_WOOD_2.getName(), 0, 0);
        addBlock(ids_t_b::ACACIA_WOOD_2_ID, lce::blocks::BlocksInit::ACACIA_WOOD_2.getName(), 0, 0);
        addBlock(ids_t_b::DARK_OAK_WOOD_2_ID, lce::blocks::BlocksInit::DARK_OAK_WOOD_2.getName(), 0, 0);
        addBlock(ids_t_b::OAK_WOOD_2_ID, lce::blocks::BlocksInit::OAK_WOOD_2.getName(), 0, 0);
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


