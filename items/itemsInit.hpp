#pragma once

#include "lce/processor.hpp"
#include "lce/items/Item.hpp"



namespace lce::items {
    MU static constexpr auto AIR = Item(0, 0, "Air", "minecraft:air");

    MU static constexpr auto STONE = Item(1, 0, "Stone", "minecraft:stone");
    MU static constexpr auto GRANITE = Item(1, 1, "Granite", "minecraft:stone");
    MU static constexpr auto POLISHED_GRANITE = Item(1, 2, "Polished Granite", "minecraft:stone");
    MU static constexpr auto DIORITE = Item(1, 3, "Diorite", "minecraft:stone");
    MU static constexpr auto POLISHED_DIORITE = Item(1, 4, "Polished Diorite", "minecraft:stone");
    MU static constexpr auto ANDESITE = Item(1, 5, "Andesite", "minecraft:stone");
    MU static constexpr auto POLISHED_ANDESITE = Item(1, 6, "Polished Andesite", "minecraft:stone");

    MU static constexpr auto GRASS = Item(2, 0, "Grass", "minecraft:grass");

    MU static constexpr auto DIRT = Item(3, 0, "Dirt", "minecraft:dirt");
    MU static constexpr auto COARSE_DIRT = Item(3, 1, "Coarse Dirt", "minecraft:dirt");
    MU static constexpr auto PODZOL = Item(3, 2, "Podzol", "minecraft:dirt");

    MU static constexpr auto COBBLESTONE = Item(4, 0, "Cobblestone", "minecraft:cobblestone");

    MU static constexpr auto OAK_WOOD_PLANK = Item(5, 0, "Oak Wood Plank", "minecraft:planks");
    MU static constexpr auto SPRUCE_WOOD_PLANK = Item(5, 1, "Spruce Wood Plank", "minecraft:planks");
    MU static constexpr auto BIRCH_WOOD_PLANK = Item(5, 2, "Birch Wood Plank", "minecraft:planks");
    MU static constexpr auto JUNGLE_WOOD_PLANK = Item(5, 3, "Jungle Wood Plank", "minecraft:planks");
    MU static constexpr auto ACACIA_WOOD_PLANK = Item(5, 4, "Acacia Wood Plank", "minecraft:planks");
    MU static constexpr auto DARK_OAK_WOOD_PLANK = Item(5, 5, "Dark Oak Wood Plank", "minecraft:planks");

    MU static constexpr auto OAK_SAPLING = Item(6, 0, "Oak Sapling", "minecraft:sapling");
    MU static constexpr auto SPRUCE_SAPLING = Item(6, 1, "Spruce Sapling", "minecraft:sapling");
    MU static constexpr auto BIRCH_SAPLING = Item(6, 2, "Birch Sapling", "minecraft:sapling");
    MU static constexpr auto JUNGLE_SAPLING = Item(6, 3, "Jungle Sapling", "minecraft:sapling");
    MU static constexpr auto ACACIA_SAPLING = Item(6, 4, "Acacia Sapling", "minecraft:sapling");
    MU static constexpr auto DARK_OAK_SAPLING = Item(6, 5, "Dark Oak Sapling", "minecraft:sapling");

    MU static constexpr auto BEDROCK = Item(7, 0, "Bedrock", "minecraft:bedrock");
    MU static constexpr auto FLOWING_WATER = Item(8, 0, "Flowing Water", "minecraft:flowing_water");
    MU static constexpr auto STILL_WATER = Item(9, 0, "Still Water", "minecraft:water");
    MU static constexpr auto FLOWING_LAVA = Item(10, 0, "Flowing Lava", "minecraft:flowing_lava");
    MU static constexpr auto STILL_LAVA = Item(11, 0, "Still Lava", "minecraft:lava");

    MU static constexpr auto SAND = Item(12, 0, "Sand", "minecraft:sand");
    MU static constexpr auto RED_SAND = Item(12, 1, "Red Sand", "minecraft:sand");

    MU static constexpr auto GRAVEL = Item(13, 0, "Gravel", "minecraft:gravel");
    MU static constexpr auto GOLD_ORE = Item(14, 0, "Gold Ore", "minecraft:gold_ore");
    MU static constexpr auto IRON_ORE = Item(15, 0, "Iron Ore", "minecraft:iron_ore");
    MU static constexpr auto COAL_ORE = Item(16, 0, "Coal Ore", "minecraft:coal_ore");

    MU static constexpr auto OAK_WOOD = Item(17, 0, "Oak Wood", "minecraft:log");
    MU static constexpr auto SPRUCE_WOOD = Item(17, 1, "Spruce Wood", "minecraft:log");
    MU static constexpr auto BIRCH_WOOD = Item(17, 2, "Birch Wood", "minecraft:log");
    MU static constexpr auto JUNGLE_WOOD = Item(17, 3, "Jungle Wood", "minecraft:log");

    MU static constexpr auto OAK_LEAVES = Item(18, 0, "Oak Leaves", "minecraft:leaves");
    MU static constexpr auto SPRUCE_LEAVES = Item(18, 1, "Spruce Leaves", "minecraft:leaves");
    MU static constexpr auto BIRCH_LEAVES = Item(18, 2, "Birch Leaves", "minecraft:leaves");
    MU static constexpr auto JUNGLE_LEAVES = Item(18, 3, "Jungle Leaves", "minecraft:leaves");

    MU static constexpr auto SPONGE = Item(19, 0, "Sponge", "minecraft:sponge");
    MU static constexpr auto WET_SPONGE = Item(19, 1, "Wet Sponge", "minecraft:sponge");

    MU static constexpr auto GLASS = Item(20, 0, "Glass", "minecraft:glass");
    MU static constexpr auto LAPIS_LAZULI_ORE = Item(21, 0, "Lapis Lazuli Ore", "minecraft:lapis_ore");
    MU static constexpr auto LAPIS_LAZULI_BLOCK = Item(22, 0, "Lapis Lazuli Block", "minecraft:lapis_block");
    MU static constexpr auto DISPENSER = Item(23, 0, "Dispenser", "minecraft:dispenser");

    MU static constexpr auto SANDSTONE = Item(24, 0, "Sandstone", "minecraft:sandstone");
    MU static constexpr auto CHISELED_SANDSTONE = Item(24, 1, "Chiseled Sandstone", "minecraft:sandstone");
    MU static constexpr auto SMOOTH_SANDSTONE = Item(24, 2, "Smooth Sandstone", "minecraft:sandstone");

    MU static constexpr auto NOTE_BLOCK = Item(25, 0, "Note Block", "minecraft:noteblock");
    MU static constexpr auto BED_BLOCK = Item(26, 0, "Bed Block", "minecraft:bed");
    MU static constexpr auto POWERED_RAIL = Item(27, 0, "Powered Rail", "minecraft:golden_rail");
    MU static constexpr auto DETECTOR_RAIL = Item(28, 0, "Detector Rail", "minecraft:detector_rail");
    MU static constexpr auto STICKY_PISTON = Item(29, 0, "Sticky Piston", "minecraft:sticky_piston");
    MU static constexpr auto COBWEB = Item(30, 0, "Cobweb", "minecraft:web");

    MU static constexpr auto TALL_GRASS_SHRUB = Item(31, 0, "Shrub", "minecraft:tallgrass");
    MU static constexpr auto TALL_GRASS_GRASS = Item(31, 1, "Grass", "minecraft:tallgrass");
    MU static constexpr auto TALL_GRASS_FERN = Item(31, 2, "Fern", "minecraft:tallgrass");

    MU static constexpr auto DEAD_BUSH = Item(32, 0, "Dead Bush", "minecraft:deadbush");

    MU static constexpr auto PISTON = Item(33, 0, "Piston", "minecraft:piston");
    MU static constexpr auto PISTON_HEAD = Item(34, 0, "Piston Head", "minecraft:piston_head");

    MU static constexpr auto WHITE_WOOL = Item(35, 0, "White Wool", "minecraft:wool");
    MU static constexpr auto ORANGE_WOOL = Item(35, 1, "Orange Wool", "minecraft:wool");
    MU static constexpr auto MAGENTA_WOOL = Item(35, 2, "Magenta Wool", "minecraft:wool");
    MU static constexpr auto LIGHT_BLUE_WOOL = Item(35, 3, "Light Blue Wool", "minecraft:wool");
    MU static constexpr auto YELLOW_WOOL = Item(35, 4, "Yellow Wool", "minecraft:wool");
    MU static constexpr auto LIME_WOOL = Item(35, 5, "Lime Wool", "minecraft:wool");
    MU static constexpr auto PINK_WOOL = Item(35, 6, "Pink Wool", "minecraft:wool");
    MU static constexpr auto GRAY_WOOL = Item(35, 7, "Gray Wool", "minecraft:wool");
    MU static constexpr auto LIGHT_GRAY_WOOL = Item(35, 8, "Light Gray Wool", "minecraft:wool");
    MU static constexpr auto CYAN_WOOL = Item(35, 9, "Cyan Wool", "minecraft:wool");
    MU static constexpr auto PURPLE_WOOL = Item(35, 10, "Purple Wool", "minecraft:wool");
    MU static constexpr auto BLUE_WOOL = Item(35, 11, "Blue Wool", "minecraft:wool");
    MU static constexpr auto BROWN_WOOL = Item(35, 12, "Brown Wool", "minecraft:wool");
    MU static constexpr auto GREEN_WOOL = Item(35, 13, "Green Wool", "minecraft:wool");
    MU static constexpr auto RED_WOOL = Item(35, 14, "Red Wool", "minecraft:wool");
    MU static constexpr auto BLACK_WOOL = Item(35, 15, "Black Wool", "minecraft:wool");

    MU static constexpr auto DANDELION = Item(37, 0, "Dandelion", "minecraft:yellow_flower");

    MU static constexpr auto POPPY = Item(38, 0, "Poppy", "minecraft:red_flower");
    MU static constexpr auto BLUE_ORCHID = Item(38, 1, "Blue Orchid", "minecraft:red_flower");
    MU static constexpr auto ALLIUM = Item(38, 2, "Allium", "minecraft:red_flower");
    MU static constexpr auto AZURE_BLUET = Item(38, 3, "Azure Bluet", "minecraft:red_flower");
    MU static constexpr auto RED_TULIP = Item(38, 4, "Red Tulip", "minecraft:red_flower");
    MU static constexpr auto ORANGE_TULIP = Item(38, 5, "Orange Tulip", "minecraft:red_flower");
    MU static constexpr auto WHITE_TULIP = Item(38, 6, "White Tulip", "minecraft:red_flower");
    MU static constexpr auto PINK_TULIP = Item(38, 7, "Pink Tulip", "minecraft:red_flower");
    MU static constexpr auto OXEYE_DAISY = Item(38, 8, "Oxeye Daisy", "minecraft:red_flower");

    MU static constexpr auto BROWN_MUSHROOM = Item(39, 0, "Brown Mushroom", "minecraft:brown_mushroom");
    MU static constexpr auto RED_MUSHROOM = Item(40, 0, "Red Mushroom", "minecraft:red_mushroom");
    MU static constexpr auto GOLD_BLOCK = Item(41, 0, "Gold Block", "minecraft:gold_block");
    MU static constexpr auto IRON_BLOCK = Item(42, 0, "Iron Block", "minecraft:iron_block");

    MU static constexpr auto DOUBLE_STONE_SLAB = Item(43, 0, "Double Stone Slab", "minecraft:double_stone_slab");
    MU static constexpr auto DOUBLE_SANDSTONE_SLAB = Item(43, 1, "Double Sandstone Slab", "minecraft:double_stone_slab");
    MU static constexpr auto DOUBLE_WOODEN_SLAB = Item(43, 2, "Double Wooden Slab", "minecraft:double_stone_slab");
    MU static constexpr auto DOUBLE_COBBLESTONE_SLAB = Item(43, 3, "Double Cobblestone Slab", "minecraft:double_stone_slab");
    MU static constexpr auto DOUBLE_BRICK_SLAB = Item(43, 4, "Double Brick Slab", "minecraft:double_stone_slab");
    MU static constexpr auto DOUBLE_STONE_BRICK_SLAB = Item(43, 5, "Double Stone Brick Slab", "minecraft:double_stone_slab");
    MU static constexpr auto DOUBLE_NETHER_BRICK_SLAB = Item(43, 6, "Double Nether Brick Slab", "minecraft:double_stone_slab");
    MU static constexpr auto DOUBLE_QUARTZ_SLAB = Item(43, 7, "Double Quartz Slab", "minecraft:double_stone_slab");
    MU static constexpr auto SMOOTH_DOUBLE_STONE_SLAB = Item(43, 8, "Smooth Double Stone Slab", "minecraft:double_stone_slab");
    MU static constexpr auto SMOOTH_DOUBLE_SANDSTONE_SLAB = Item(43, 9, "Smooth Double Sandstone Slab", "minecraft:double_stone_slab");
    MU static constexpr auto TILE_DOUBLE_QUARTZ_SLAB = Item(43, 15, "Tile Double Quartz Slab", "minecraft:double_stone_slab");

    MU static constexpr auto STONE_SLAB = Item(44, 0, "Stone Slab", "minecraft:stone_slab");
    MU static constexpr auto SANDSTONE_SLAB = Item(44, 1, "Sandstone Slab", "minecraft:stone_slab");
    MU static constexpr auto WOODEN_SLAB = Item(44, 2, "Wooden Slab", "minecraft:stone_slab");
    MU static constexpr auto COBBLESTONE_SLAB = Item(44, 3, "Cobblestone Slab", "minecraft:stone_slab");
    MU static constexpr auto BRICK_SLAB = Item(44, 4, "Brick Slab", "minecraft:stone_slab");
    MU static constexpr auto STONE_BRICK_SLAB = Item(44, 5, "Stone Brick Slab", "minecraft:stone_slab");
    MU static constexpr auto NETHER_STONE_SLAB = Item(44, 6, "Nether Brick Slab", "minecraft:stone_slab");
    MU static constexpr auto QUARTZ_SLAB = Item(44, 7, "Quartz Slab", "minecraft:stone_slab");
    MU static constexpr auto UPPER_STONE_SLAB = Item(44, 8, "Upper Stone Slab", "minecraft:stone_slab");
    MU static constexpr auto UPPER_SANDSTONE_SLAB = Item(44, 9, "Upper Sandstone Slab", "minecraft:stone_slab");
    MU static constexpr auto UPPER_WOODEN_SLAB = Item(44, 10, "Upper Wooden Slab", "minecraft:stone_slab");
    MU static constexpr auto UPPER_COBBLESTONE_SLAB = Item(44, 11, "Upper Cobblestone Slab", "minecraft:stone_slab");
    MU static constexpr auto UPPER_BRICKS_SLAB = Item(44, 12, "Upper Bricks Slab", "minecraft:stone_slab");
    MU static constexpr auto UPPER_STONE_BRICK_SLAB = Item(44, 13, "Upper Stone Brick Slab", "minecraft:stone_slab");
    MU static constexpr auto UPPER_NETHER_BRICK_SLAB = Item(44, 14, "Upper Nether Brick Slab", "minecraft:stone_slab");
    MU static constexpr auto UPPER_QUARTZ_SLAB = Item(44, 15, "Upper Quartz Slab", "minecraft:stone_slab");

    MU static constexpr auto BRICKS = Item(45, 0, "Bricks", "minecraft:brick_block");
    MU static constexpr auto TNT = Item(46, 0, "TNT", "minecraft:tnt");
    MU static constexpr auto BOOKSHELF = Item(47, 0, "Bookshelf", "minecraft:bookshelf");
    MU static constexpr auto MOSS_STONE = Item(48, 0, "Moss Stone", "minecraft:mossy_cobblestone");
    MU static constexpr auto OBSIDIAN = Item(49, 0, "Obsidian", "minecraft:obsidian");
    MU static constexpr auto TORCH = Item(50, 0, "Torch", "minecraft:torch");
    MU static constexpr auto FIRE = Item(51, 0, "Fire", "minecraft:fire");
    MU static constexpr auto MONSTER_SPAWNER = Item(52, 0, "Monster Spawner", "minecraft:mob_spawner");
    MU static constexpr auto OAK_WOOD_STAIRS = Item(53, 0, "Oak Wood Stairs", "minecraft:oak_stairs");
    MU static constexpr auto CHEST = Item(54, 0, "Chest", "minecraft:chest");
    MU static constexpr auto REDSTONE_WIRE = Item(55, 0, "Redstone Wire", "minecraft:redstone_wire");
    MU static constexpr auto DIAMOND_ORE = Item(56, 0, "Diamond Ore", "minecraft:diamond_ore");
    MU static constexpr auto DIAMOND_BLOCK = Item(57, 0, "Diamond Block", "minecraft:diamond_block");
    MU static constexpr auto CRAFTING_TABLE = Item(58, 0, "Crafting Table", "minecraft:crafting_table");
    MU static constexpr auto WHEAT_CROPS = Item(59, 0, "Wheat Crops", "minecraft:wheat");
    MU static constexpr auto FARMLAND = Item(60, 0, "Farmland", "minecraft:farmland");
    MU static constexpr auto FURNACE = Item(61, 0, "Furnace", "minecraft:furnace");
    MU static constexpr auto BURNING_FURNACE = Item(62, 0, "Burning Furnace", "minecraft:lit_furnace");
    MU static constexpr auto STANDING_SIGN_BLOCK = Item(63, 0, "Standing Sign Block", "minecraft:standing_sign");
    MU static constexpr auto OAK_DOOR_BLOCK = Item(64, 0, "Oak Door Block", "minecraft:wooden_door");
    MU static constexpr auto LADDER = Item(65, 0, "Ladder", "minecraft:ladder");
    MU static constexpr auto RAIL = Item(66, 0, "Rail", "minecraft:rail");
    MU static constexpr auto COBBLESTONE_STAIRS = Item(67, 0, "Cobblestone Stairs", "minecraft:stone_stairs");
    MU static constexpr auto WALL_MOUNTED_SIGN_BLOCK = Item(68, 0, "Wall-mounted Sign Block", "minecraft:wall_sign");
    MU static constexpr auto LEVER = Item(69, 0, "Lever", "minecraft:lever");
    MU static constexpr auto STONE_PRESSURE_PLATE = Item(70, 0, "Stone Pressure Plate", "minecraft:stone_pressure_plate");
    MU static constexpr auto IRON_DOOR_BLOCK = Item(71, 0, "Iron Door Block", "minecraft:iron_door");
    MU static constexpr auto WOODEN_PRESSURE_PLATE = Item(72, 0, "Wooden Pressure Plate", "minecraft:wooden_pressure_plate");
    MU static constexpr auto REDSTONE_ORE = Item(73, 0, "Redstone Ore", "minecraft:redstone_ore");
    MU static constexpr auto GLOWING_REDSTONE_ORE = Item(74, 0, "Glowing Redstone Ore", "minecraft:lit_redstone_ore");
    MU static constexpr auto OFF_REDSTONE_TORCH = Item(75, 0, "Redstone Torch (off)", "minecraft:unlit_redstone_torch");
    MU static constexpr auto ON_REDSTONE_TORCH = Item(76, 0, "Redstone Torch (on)", "minecraft:redstone_torch");
    MU static constexpr auto STONE_BUTTON = Item(77, 0, "Stone Button", "minecraft:stone_button");
    MU static constexpr auto SNOW = Item(78, 0, "Snow", "minecraft:snow_layer");
    MU static constexpr auto ICE = Item(79, 0, "Ice", "minecraft:ice");
    MU static constexpr auto SNOW_BLOCK = Item(80, 0, "Snow Block", "minecraft:snow");
    MU static constexpr auto CACTUS = Item(81, 0, "Cactus", "minecraft:cactus");
    MU static constexpr auto CLAY_BLOCK = Item(82, 0, "Clay", "minecraft:clay");
    MU static constexpr auto SUGAR_CANES = Item(83, 0, "Sugar Canes", "minecraft:reeds");
    MU static constexpr auto JUKEBOX = Item(84, 0, "Jukebox", "minecraft:jukebox");
    MU static constexpr auto OAK_FENCE = Item(85, 0, "Oak Fence", "minecraft:fence");
    MU static constexpr auto PUMPKIN = Item(86, 0, "Pumpkin", "minecraft:pumpkin");
    MU static constexpr auto NETHERRACK = Item(87, 0, "Netherrack", "minecraft:netherrack");
    MU static constexpr auto SOUL_SAND = Item(88, 0, "Soul Sand", "minecraft:soul_sand");
    MU static constexpr auto GLOWSTONE = Item(89, 0, "Glowstone", "minecraft:glowstone");
    MU static constexpr auto NETHER_PORTAL = Item(90, 0, "Nether Portal", "minecraft:portal");
    MU static constexpr auto JACK_O_LANTERN = Item(91, 0, "Jack o’Lantern", "minecraft:lit_pumpkin");
    MU static constexpr auto CAKE_BLOCK = Item(92, 0, "Cake Block", "minecraft:cake");
    MU static constexpr auto OFF_REDSTONE_REPEATER_BLOCK = Item(93, 0, "Redstone Repeater Block (off)", "minecraft:unpowered_repeater");
    MU static constexpr auto ON_REDSTONE_REPEATER_BLOCK = Item(94, 0, "Redstone Repeater Block (on)", "minecraft:powered_repeater");

    MU static constexpr auto WHITE_STAINED_GLASS = Item(95, 0, "White Stained Glass", "minecraft:stained_glass");
    MU static constexpr auto ORANGE_STAINED_GLASS = Item(95, 1, "Orange Stained Glass", "minecraft:stained_glass");
    MU static constexpr auto MAGENTA_STAINED_GLASS = Item(95, 2, "Magenta Stained Glass", "minecraft:stained_glass");
    MU static constexpr auto LIGHT_BLUE_STAINED_GLASS = Item(95, 3, "Light Blue Stained Glass", "minecraft:stained_glass");
    MU static constexpr auto YELLOW_STAINED_GLASS = Item(95, 4, "Yellow Stained Glass", "minecraft:stained_glass");
    MU static constexpr auto LIME_STAINED_GLASS = Item(95, 5, "Lime Stained Glass", "minecraft:stained_glass");
    MU static constexpr auto PINK_STAINED_GLASS = Item(95, 6, "Pink Stained Glass", "minecraft:stained_glass");
    MU static constexpr auto GRAY_STAINED_GLASS = Item(95, 7, "Gray Stained Glass", "minecraft:stained_glass");
    MU static constexpr auto LIGHT_GRAY_STAINED_GLASS = Item(95, 8, "Light Gray Stained Glass", "minecraft:stained_glass");
    MU static constexpr auto CYAN_STAINED_GLASS = Item(95, 9, "Cyan Stained Glass", "minecraft:stained_glass");
    MU static constexpr auto PURPLE_STAINED_GLASS = Item(95, 10, "Purple Stained Glass", "minecraft:stained_glass");
    MU static constexpr auto BLUE_STAINED_GLASS = Item(95, 11, "Blue Stained Glass", "minecraft:stained_glass");
    MU static constexpr auto BROWN_STAINED_GLASS = Item(95, 12, "Brown Stained Glass", "minecraft:stained_glass");
    MU static constexpr auto GREEN_STAINED_GLASS = Item(95, 13, "Green Stained Glass", "minecraft:stained_glass");
    MU static constexpr auto RED_STAINED_GLASS = Item(95, 14, "Red Stained Glass", "minecraft:stained_glass");
    MU static constexpr auto BLACK_STAINED_GLASS = Item(95, 15, "Black Stained Glass", "minecraft:stained_glass");

    MU static constexpr auto WOODEN_TRAPDOOR = Item(96, 0, "Wooden Trapdoor", "minecraft:trapdoor");

    MU static constexpr auto STONE_MONSTER_EGG = Item(97, 0, "Stone Monster Egg", "minecraft:monster_egg");
    MU static constexpr auto COBBLESTONE_MONSTER_EGG = Item(97, 1, "Cobblestone Monster Egg", "minecraft:monster_egg");
    MU static constexpr auto STONE_BRICK_MONSTER_EGG = Item(97, 2, "Stone Brick Monster Egg", "minecraft:monster_egg");
    MU static constexpr auto MOSSY_STONE_MONSTER_EGG = Item(97, 3, "Mossy Stone Brick Monster Egg", "minecraft:monster_egg");
    MU static constexpr auto CRACKED_STONE_BRICK_MONSTER_EGG = Item(97, 4, "Cracked Stone Brick Monster Egg", "minecraft:monster_egg");
    MU static constexpr auto CHISELED_STONE_BRICK_MONSTER_EGG = Item(97, 5, "Chiseled Stone Brick Monster Egg", "minecraft:monster_egg");

    MU static constexpr auto STONE_BRICKS = Item(98, 0, "Stone Bricks", "minecraft:stonebrick");
    MU static constexpr auto MOSSY_STONE_BRICKS = Item(98, 1, "Mossy Stone Bricks", "minecraft:stonebrick");
    MU static constexpr auto CRACKED_STONE_BRICKS = Item(98, 2, "Cracked Stone Bricks", "minecraft:stonebrick");
    MU static constexpr auto CHISELED_STONE_BRICKS = Item(98, 3, "Chiseled Stone Bricks", "minecraft:stonebrick");

    MU static constexpr auto BROWN_MUSHROOM_BLOCK = Item(99, 0, "Brown Mushroom Block", "minecraft:brown_mushroom_block");
    MU static constexpr auto RED_MUSHROOM_BLOCK = Item(100, 0, "Red Mushroom Block", "minecraft:red_mushroom_block");
    MU static constexpr auto IRON_BARS = Item(101, 0, "Iron Bars", "minecraft:iron_bars");
    MU static constexpr auto GLASS_PANE = Item(102, 0, "Glass Pane", "minecraft:glass_pane");
    MU static constexpr auto MELON_BLOCK = Item(103, 0, "Melon Block", "minecraft:melon_block");
    MU static constexpr auto PUMPKIN_STEM = Item(104, 0, "Pumpkin Stem", "minecraft:pumpkin_stem");
    MU static constexpr auto MELON_STEM = Item(105, 0, "Melon Stem", "minecraft:melon_stem");
    MU static constexpr auto VINES = Item(106, 0, "Vines", "minecraft:vine");
    MU static constexpr auto OAK_FENCE_GATE = Item(107, 0, "Oak Fence Gate", "minecraft:fence_gate");
    MU static constexpr auto BRICK_STAIRS = Item(108, 0, "Brick Stairs", "minecraft:brick_stairs");
    MU static constexpr auto STONE_BRICK_STAIRS = Item(109, 0, "Stone Brick Stairs", "minecraft:stone_brick_stairs");
    MU static constexpr auto MYCELIUM = Item(110, 0, "Mycelium", "minecraft:mycelium");
    MU static constexpr auto LILY_PAD = Item(111, 0, "Lily Pad", "minecraft:waterlily");
    MU static constexpr auto NETHER_BRICK_BLOCK = Item(112, 0, "Nether Brick", "minecraft:nether_brick");
    MU static constexpr auto NETHER_BRICK_FENCE = Item(113, 0, "Nether Brick Fence", "minecraft:nether_brick_fence");
    MU static constexpr auto NETHER_BRICK_STAIRS = Item(114, 0, "Nether Brick Stairs", "minecraft:nether_brick_stairs");
    MU static constexpr auto NETHER_WART_ITEM_BLOCK = Item(115, 0, "Nether Wart", "minecraft:nether_wart");
    MU static constexpr auto ENCHANTMENT_TABLE = Item(116, 0, "Enchant Table", "minecraft:enchanting_table");
    MU static constexpr auto BREWING_STAND_ITEM_BLOCK = Item(117, 0, "Brewing Stand", "minecraft:brewing_stand");
    MU static constexpr auto CAULDRON_ITEM_BLOCK = Item(118, 0, "Cauldron", "minecraft:cauldron");
    MU static constexpr auto END_PORTAL = Item(119, 0, "End Portal", "minecraft:end_portal");
    MU static constexpr auto END_PORTAL_FRAME = Item(120, 0, "End Portal Frame", "minecraft:end_portal_frame");
    MU static constexpr auto END_STONE = Item(121, 0, "End Stone", "minecraft:end_stone");
    MU static constexpr auto DRAGON_EGG = Item(122, 0, "Dragon Egg", "minecraft:dragon_egg");
    MU static constexpr auto INACTIVE_REDSTONE_LAMP = Item(123, 0, "Redstone Lamp (inactive)", "minecraft:redstone_lamp");
    MU static constexpr auto ACTIVE_REDSTONE_LAMP = Item(124, 0, "Redstone Lamp (active)", "minecraft:lit_redstone_lamp");

    MU static constexpr auto DOUBLE_OAK_WOOD_SLAB = Item(125, 0, "Double Oak Wood Slab", "minecraft:double_wooden_slab");
    MU static constexpr auto DOUBLE_SPRUCE_WOOD_SLAB = Item(125, 1, "Double Spruce Wood Slab", "minecraft:double_wooden_slab");
    MU static constexpr auto DOUBLE_BIRCH_WOOD_SLAB = Item(125, 2, "Double Birch Wood Slab", "minecraft:double_wooden_slab");
    MU static constexpr auto DOUBLE_JUNGLE_WOOD_SLAB = Item(125, 3, "Double Jungle Wood Slab", "minecraft:double_wooden_slab");
    MU static constexpr auto DOUBLE_ACACIA_WOOD_SLAB = Item(125, 4, "Double Acacia Wood Slab", "minecraft:double_wooden_slab");
    MU static constexpr auto DOUBLE_DARK_OAK_WOOD_SLAB = Item(125, 5, "Double Dark Oak Wood Slab", "minecraft:double_wooden_slab");

    MU static constexpr auto OAK_WOOD_SLAB = Item(126, 0, "Oak Wood Slab", "minecraft:wooden_slab");
    MU static constexpr auto SPRUCE_WOOD_SLAB = Item(126, 1, "Spruce Wood Slab", "minecraft:wooden_slab");
    MU static constexpr auto BIRCH_WOOD_SLAB = Item(126, 2, "Birch Wood Slab", "minecraft:wooden_slab");
    MU static constexpr auto JUNGLE_WOOD_SLAB = Item(126, 3, "Jungle Wood Slab", "minecraft:wooden_slab");
    MU static constexpr auto ACACIA_WOOD_SLAB = Item(126, 4, "Acacia Wood Slab", "minecraft:wooden_slab");
    MU static constexpr auto DARK_OAK_WOOD_SLAB = Item(126, 5, "Dark Wood Slab", "minecraft:wooden_slab");
    MU static constexpr auto UPPER_OAK_WOOD_SLAB = Item(126, 8, "Upper Oak Wood Slab", "minecraft:wooden_slab");
    MU static constexpr auto UPPER_SPRUCE_WOOD_SLAB = Item(126, 9, "Upper Spruce Wood Slab", "minecraft:wooden_slab");
    MU static constexpr auto UPPER_BIRCH_WOOD_SLAB = Item(126, 10, "Upper Birch Wood Slab", "minecraft:wooden_slab");
    MU static constexpr auto UPPER_JUNGLE_WOOD_SLAB = Item(126, 11, "Upper Jungle Wood Slab", "minecraft:wooden_slab");
    MU static constexpr auto UPPER_ACACIA_WOOD_SLAB = Item(126, 12, "Upper Acacia Wood Slab", "minecraft:wooden_slab");
    MU static constexpr auto UPPER_DARK_OAK_WOOD_SLAB = Item(126, 13, "Upper Dark Wood Slab", "minecraft:wooden_slab");

    MU static constexpr auto COCOA = Item(127, 0, "Cocoa", "minecraft:cocoa");
    MU static constexpr auto SANDSTONE_STAIRS = Item(128, 0, "Sandstone Stairs", "minecraft:sandstone_stairs");
    MU static constexpr auto EMERALD_ORE = Item(129, 0, "Emerald Ore", "minecraft:emerald_ore");
    MU static constexpr auto ENDER_CHEST = Item(130, 0, "Ender Chest", "minecraft:ender_chest");
    MU static constexpr auto TRIPWIRE_HOOK = Item(131, 0, "Tripwire Hook", "minecraft:tripwire_hook");
    MU static constexpr auto TRIPWIRE = Item(132, 0, "Tripwire", "minecraft:tripwire_hook");
    MU static constexpr auto EMERALD_BLOCK = Item(133, 0, "Emerald Block", "minecraft:emerald_block");
    MU static constexpr auto SPRUCE_WOOD_STAIRS = Item(134, 0, "Spruce Wood Stairs", "minecraft:spruce_stairs");
    MU static constexpr auto BIRCH_WOOD_STAIRS = Item(135, 0, "Birch Wood Stairs", "minecraft:birch_stairs");
    MU static constexpr auto JUNGLE_WOOD_STAIRS = Item(136, 0, "Jungle Wood Stairs", "minecraft:jungle_stairs");
    MU static constexpr auto COMMAND_BLOCK = Item(137, 0, "Command Block", "minecraft:command_block");
    MU static constexpr auto BEACON = Item(138, 0, "Beacon", "minecraft:beacon");

    MU static constexpr auto COBBLESTONE_WALL = Item(139, 0, "Cobblestone Wall", "minecraft:cobblestone_wall");
    MU static constexpr auto MOSSY_COBBLESTONE_WALL = Item(139, 1, "Mossy Cobblestone Wall", "minecraft:cobblestone_wall");

    MU static constexpr auto FLOWER_POT_ITEM_BLOCK = Item(140, 0, "Flower Pot", "minecraft:flower_pot");
    MU static constexpr auto CARROTS = Item(141, 0, "Carrots", "minecraft:carrots");
    MU static constexpr auto POTATOES = Item(142, 0, "Potatoes", "minecraft:potatoes");
    MU static constexpr auto WOODEN_BUTTON = Item(143, 0, "Wooden Button", "minecraft:wooden_button");

    MU static constexpr auto MOB_HEAD = Item(144, 0, "Mob Head", "minecraft:skull");

    MU static constexpr auto ANVIL = Item(145, 0, "Anvil", "minecraft:anvil");
    MU static constexpr auto SLIGHTLY_DAMAGED_ANVIL = Item(145, 1, "Slightly Damaged Anvil", "minecraft:anvil");
    MU static constexpr auto VERY_DAMAGED_ANVIL = Item(145, 2, "Very Damaged Anvil", "minecraft:anvil");

    MU static constexpr auto TRAPPED_CHEST = Item(146, 0, "Trapped Chest", "minecraft:trapped_chest");
    MU static constexpr auto LIGHT_WEIGHTED_PRESSURE_PLATE = Item(147, 0, "Weighted Pressure Plate (light)", "minecraft:light_weighted_pressure_plate");
    MU static constexpr auto HEAVY_WEIGHTED_PRESSURE_PLATE = Item(148, 0, "Weighted Pressure Plate (heavy)", "minecraft:heavy_weighted_pressure_plate");
    MU static constexpr auto INACTIVE_REDSTONE_COMPARATOR = Item(149, 0, "Redstone Comparator (inactive)", "minecraft:unpowered_comparator");
    MU static constexpr auto ACTIVE_REDSTONE_COMPARATOR = Item(150, 0, "Redstone Comparator (active)", "minecraft:powered_comparator");
    MU static constexpr auto DAYLIGHT_SENSOR = Item(151, 0, "Daylight Sensor", "minecraft:daylight_detector");
    MU static constexpr auto REDSTONE_BLOCK = Item(152, 0, "Redstone Block", "minecraft:redstone_block");
    MU static constexpr auto NETHER_QUARTZ_ORE = Item(153, 0, "Nether Quartz Ore", "minecraft:quartz_ore");
    MU static constexpr auto HOPPER = Item(154, 0, "Hopper", "minecraft:hopper");

    MU static constexpr auto QUARTZ_BLOCK = Item(155, 0, "Quartz Block", "minecraft:quartz_block");
    MU static constexpr auto CHISELED_QUARTZ_BLOCK = Item(155, 1, "Chiseled Quartz Block", "minecraft:quartz_block");
    MU static constexpr auto PILLAR_QUARTZ_BLOCK = Item(155, 2, "Pillar Quartz Block", "minecraft:quartz_block");

    MU static constexpr auto QUARTZ_STAIRS = Item(156, 0, "Quartz Stairs", "minecraft:quartz_stairs");
    MU static constexpr auto ACTIVATOR_RAIL = Item(157, 0, "Activator Rail", "minecraft:activator_rail");
    MU static constexpr auto DROPPER = Item(158, 0, "Dropper", "minecraft:dropper");

    MU static constexpr auto WHITE_HARDENED_CLAY = Item(159, 0, "White Hardened Clay", "minecraft:stained_hardened_clay");
    MU static constexpr auto ORANGE_HARDENED_CLAY = Item(159, 1, "Orange Hardened Clay", "minecraft:stained_hardened_clay");
    MU static constexpr auto MAGENTA_HARDENED_CLAY = Item(159, 2, "Magenta Hardened Clay", "minecraft:stained_hardened_clay");
    MU static constexpr auto LIGHT_BLUE_HARDENED_CLAY = Item(159, 3, "Light Blue Hardened Clay", "minecraft:stained_hardened_clay");
    MU static constexpr auto YELLOW_HARDENED_CLAY = Item(159, 4, "Yellow Hardened Clay", "minecraft:stained_hardened_clay");
    MU static constexpr auto LIME_HARDENED_CLAY = Item(159, 5, "Lime Hardened Clay", "minecraft:stained_hardened_clay");
    MU static constexpr auto PINK_HARDENED_CLAY = Item(159, 6, "Pink Hardened Clay", "minecraft:stained_hardened_clay");
    MU static constexpr auto GRAY_HARDENED_CLAY = Item(159, 7, "Gray Hardened Clay", "minecraft:stained_hardened_clay");
    MU static constexpr auto LIGHT_GRAY_HARDENED_CLAY = Item(159, 8, "Light Gray Hardened Clay", "minecraft:stained_hardened_clay");
    MU static constexpr auto CYAN_HARDENED_CLAY = Item(159, 9, "Cyan Hardened Clay", "minecraft:stained_hardened_clay");
    MU static constexpr auto PURPLE_HARDENED_CLAY = Item(159, 10, "Purple Hardened Clay", "minecraft:stained_hardened_clay");
    MU static constexpr auto BLUE_HARDENED_CLAY = Item(159, 11, "Blue Hardened Clay", "minecraft:stained_hardened_clay");
    MU static constexpr auto BROWN_HARDENED_CLAY = Item(159, 12, "Brown Hardened Clay", "minecraft:stained_hardened_clay");
    MU static constexpr auto GREEN_HARDENED_CLAY = Item(159, 13, "Green Hardened Clay", "minecraft:stained_hardened_clay");
    MU static constexpr auto RED_HARDENED_CLAY = Item(159, 14, "Red Hardened Clay", "minecraft:stained_hardened_clay");
    MU static constexpr auto BLACK_HARDENED_CLAY = Item(159, 15, "Black Hardened Clay", "minecraft:stained_hardened_clay");

    MU static constexpr auto WHITE_STAINED_GLASS_PANE = Item(160, 0, "White Stained Glass Pane", "minecraft:stained_glass_pane");
    MU static constexpr auto ORANGE_STAINED_GLASS_PANE = Item(160, 1, "Orange Stained Glass Pane", "minecraft:stained_glass_pane");
    MU static constexpr auto MAGENTA_STAINED_GLASS_PANE = Item(160, 2, "Magenta Stained Glass Pane", "minecraft:stained_glass_pane");
    MU static constexpr auto LIGHT_BLUE_STAINED_GLASS_PANE = Item(160, 3, "Light Blue Stained Glass Pane", "minecraft:stained_glass_pane");
    MU static constexpr auto YELLOW_STAINED_GLASS_PANE = Item(160, 4, "Yellow Stained Glass Pane", "minecraft:stained_glass_pane");
    MU static constexpr auto LIME_STAINED_GLASS_PANE = Item(160, 5, "Lime Stained Glass Pane", "minecraft:stained_glass_pane");
    MU static constexpr auto PINK_STAINED_GLASS_PANE = Item(160, 6, "Pink Stained Glass Pane", "minecraft:stained_glass_pane");
    MU static constexpr auto GRAY_STAINED_GLASS_PANE = Item(160, 7, "Gray Stained Glass Pane", "minecraft:stained_glass_pane");
    MU static constexpr auto LIGHT_GRAY_STAINED_GLASS_PANE = Item(160, 8, "Light Gray Stained Glass Pane", "minecraft:stained_glass_pane");
    MU static constexpr auto CYAN_STAINED_GLASS_PANE = Item(160, 9, "Cyan Stained Glass Pane", "minecraft:stained_glass_pane");
    MU static constexpr auto PURPLE_STAINED_GLASS_PANE = Item(160, 10, "Purple Stained Glass Pane", "minecraft:stained_glass_pane");
    MU static constexpr auto BLUE_STAINED_GLASS_PANE = Item(160, 11, "Blue Stained Glass Pane", "minecraft:stained_glass_pane");
    MU static constexpr auto BROWN_STAINED_GLASS_PANE = Item(160, 12, "Brown Stained Glass Pane", "minecraft:stained_glass_pane");
    MU static constexpr auto GREEN_STAINED_GLASS_PANE = Item(160, 13, "Green Stained Glass Pane", "minecraft:stained_glass_pane");
    MU static constexpr auto RED_STAINED_GLASS_PANE = Item(160, 14, "Red Stained Glass Pane", "minecraft:stained_glass_pane");
    MU static constexpr auto BLACK_STAINED_GLASS_PANE = Item(160, 15, "Black Stained Glass Pane", "minecraft:stained_glass_pane");

    MU static constexpr auto ACACIA_LEAVES = Item(161, 0, "Acacia Leaves", "minecraft:leaves2");
    MU static constexpr auto DARK_OAK_LEAVES = Item(161, 1, "Dark Oak Leaves", "minecraft:leaves2");

    MU static constexpr auto ACACIA_WOOD = Item(162, 0, "Acacia Wood", "minecraft:log2");
    MU static constexpr auto DARK_OAK_WOOD = Item(162, 1, "Dark Oak Wood", "minecraft:log2");

    MU static constexpr auto ACACIA_WOOD_STAIRS = Item(163, 0, "Acacia Wood Stairs", "minecraft:acacia_stairs");
    MU static constexpr auto DARK_OAK_WOOD_STAIRS = Item(164, 0, "Dark Oak Wood Stairs", "minecraft:dark_oak_stairs");
    MU static constexpr auto SLIME_BLOCK = Item(165, 0, "Slime Block", "minecraft:slime");
    MU static constexpr auto BARRIER = Item(166, 0, "Barrier", "minecraft:barrier");
    MU static constexpr auto IRON_TRAPDOOR = Item(167, 0, "Iron Trapdoor", "minecraft:iron_trapdoor");

    MU static constexpr auto PRISMARINE = Item(168, 0, "Prismarine", "minecraft:prismarine");
    MU static constexpr auto PRISMARINE_BRICKS = Item(168, 1, "Prismarine Bricks", "minecraft:prismarine");
    MU static constexpr auto DARK_PRISMARINE = Item(168, 2, "Dark Prismarine", "minecraft:prismarine");

    MU static constexpr auto SEA_LANTERN = Item(169, 0, "Sea Lantern", "minecraft:sea_lantern");
    MU static constexpr auto HAY_BALE = Item(170, 0, "Hay Bale", "minecraft:hay_block");

    MU static constexpr auto WHITE_CARPET = Item(171, 0, "White White Carpet", "minecraft:carpet");
    MU static constexpr auto ORANGE_CARPET = Item(171, 1, "Orange White Carpet", "minecraft:carpet");
    MU static constexpr auto MAGENTA_CARPET = Item(171, 2, "Magenta White Carpet", "minecraft:carpet");
    MU static constexpr auto LIGHT_BLUE_CARPET = Item(171, 3, "Light Blue White Carpet", "minecraft:carpet");
    MU static constexpr auto YELLOW_CARPET = Item(171, 4, "Yellow White Carpet", "minecraft:carpet");
    MU static constexpr auto LIME_CARPET = Item(171, 5, "Lime White Carpet", "minecraft:carpet");
    MU static constexpr auto PINK_CARPET = Item(171, 6, "Pink White Carpet", "minecraft:carpet");
    MU static constexpr auto GRAY_CARPET = Item(171, 7, "Gray White Carpet", "minecraft:carpet");
    MU static constexpr auto LIGHT_GRAY_CARPET = Item(171, 8, "Light Gray White Carpet", "minecraft:carpet");
    MU static constexpr auto CYAN_CARPET = Item(171, 9, "Cyan White Carpet", "minecraft:carpet");
    MU static constexpr auto PURPLE_CARPET = Item(171, 10, "Purple White Carpet", "minecraft:carpet");
    MU static constexpr auto BLUE_CARPET = Item(171, 11, "Blue White Carpet", "minecraft:carpet");
    MU static constexpr auto BROWN_CARPET = Item(171, 12, "Brown White Carpet", "minecraft:carpet");
    MU static constexpr auto GREEN_CARPET = Item(171, 13, "Green White Carpet", "minecraft:carpet");
    MU static constexpr auto RED_CARPET = Item(171, 14, "Red White Carpet", "minecraft:carpet");
    MU static constexpr auto BLACK_CARPET = Item(171, 15, "Black White Carpet", "minecraft:carpet");

    MU static constexpr auto HARDENED_CLAY = Item(172, 0, "Hardened Clay", "minecraft:hardened_clay");
    MU static constexpr auto BLOCK_OF_COAL = Item(173, 0, "Block of Coal", "minecraft:coal_block");
    MU static constexpr auto PACKED_ICE = Item(174, 0, "Packed Ice", "minecraft:packed_ice");

    MU static constexpr auto SUNFLOWER = Item(175, 0, "Sunflower", "minecraft:double_plant");
    MU static constexpr auto LILAC = Item(175, 1, "Lilac", "minecraft:double_plant");
    MU static constexpr auto DOUBLE_TALLGRASS = Item(175, 2, "Double Tall Grass", "minecraft:double_plant");
    MU static constexpr auto LARGE_FERN = Item(175, 3, "Large Fern", "minecraft:double_plant");
    MU static constexpr auto ROSE_BUSH = Item(175, 4, "Rose Bush", "minecraft:double_plant");
    MU static constexpr auto PEONY = Item(175, 5, "Peony", "minecraft:double_plant");

    MU static constexpr auto FREE_STANDING_BANNER = Item(176, 0, "Free-standing Banner", "minecraft:standing_banner");

    MU static constexpr auto WALL_MOUNTED_BANNER = Item(177, 0, "Wall-mounted Banner", "minecraft:wall_banner");

    MU static constexpr auto INVERTED_DAYLIGHT_SENSOR = Item(178, 0, "Inverted Daylight Sensor", "minecraft:daylight_detector_inverted");

    MU static constexpr auto RED_SANDSTONE = Item(179, 0, "Red Sandstone", "minecraft:red_sandstone");
    MU static constexpr auto CHISELED_RED_SANDSTONE = Item(179, 1, "Chiseled Red Sandstone", "minecraft:red_sandstone");
    MU static constexpr auto SMOOTH_RED_SANDSTONE = Item(179, 2, "Smooth Red Sandstone", "minecraft:red_sandstone");

    MU static constexpr auto RED_SANDSTONE_STAIRS = Item(180, 0, "Red Sandstone Stairs", "minecraft:red_sandstone_stairs");

    MU static constexpr auto DOUBLE_RED_SANDSTONE_SLAB = Item(181, 0, "Double Red Sandstone Slab", "minecraft:double_stone_slab2");
    MU static constexpr auto SMOOTH_DOUBLE_RED_SANDSTONE_SLAB = Item(181, 8, "Smooth Double Red Sandstone Slab", "minecraft:double_stone_slab2");

    MU static constexpr auto RED_SANDSTONE_SLAB = Item(182, 0, "Red Sandstone Slab", "minecraft:stone_slab2");
    MU static constexpr auto UPPER_RED_SANDSTONE_SLAB = Item(182, 1, "Upper Red Sandstone Slab", "minecraft:stone_slab2");

    MU static constexpr auto SPRUCE_FENCE_GATE = Item(183, 0, "Spruce Fence Gate", "minecraft:spruce_fence_gate");
    MU static constexpr auto BIRCH_FENCE_GATE = Item(184, 0, "Birch Fence Gate", "minecraft:birch_fence_gate");
    MU static constexpr auto JUNGLE_FENCE_GATE = Item(185, 0, "Jungle Fence Gate", "minecraft:jungle_fence_gate");
    MU static constexpr auto DARK_OAK_FENCE_GATE = Item(186, 0, "Dark Oak Fence Gate", "minecraft:dark_oak_fence_gate");
    MU static constexpr auto ACACIA_FENCE_GATE = Item(187, 0, "Acacia Fence Gate", "minecraft:acacia_fence_gate");
    MU static constexpr auto SPRUCE_FENCE = Item(188, 0, "Spruce Fence", "minecraft:spruce_fence");
    MU static constexpr auto BIRCH_FENCE = Item(189, 0, "Birch Fence", "minecraft:birch_fence");
    MU static constexpr auto JUNGLE_FENCE = Item(190, 0, "Jungle Fence", "minecraft:jungle_fence");
    MU static constexpr auto DARK_OAK_FENCE = Item(191, 0, "Dark Oak Fence", "minecraft:dark_oak_fence");
    MU static constexpr auto ACACIA_FENCE = Item(192, 0, "Acacia Fence", "minecraft:acacia_fence");
    MU static constexpr auto SPRUCE_DOOR_BLOCK = Item(193, 0, "Spruce Door Block", "minecraft:spruce_door");
    MU static constexpr auto BIRCH_DOOR_BLOCK = Item(194, 0, "Birch Door Block", "minecraft:birch_door");
    MU static constexpr auto JUNGLE_DOOR_BLOCK = Item(195, 0, "Jungle Door Block", "minecraft:jungle_door");
    MU static constexpr auto ACACIA_DOOR_BLOCK = Item(196, 0, "Acacia Door Block", "minecraft:acacia_door");
    MU static constexpr auto DARK_OAK_DOOR_BLOCK = Item(197, 0, "Dark Oak Door Block", "minecraft:dark_oak_door");
    MU static constexpr auto END_ROD = Item(198, 0, "End Rod", "minecraft:end_rod");
    MU static constexpr auto CHORUS_PLANT = Item(199, 0, "Chorus Plant", "minecraft:chorus_plant");
    MU static constexpr auto CHORUS_FLOWER = Item(200, 0, "Chorus Flower", "minecraft:chorus_flower");
    MU static constexpr auto PURPUR_BLOCK = Item(201, 0, "Purpur Block", "minecraft:purpur_block");
    MU static constexpr auto PURPUR_PILLAR = Item(202, 0, "Purpur Pillar", "minecraft:purpur_pillar");
    MU static constexpr auto PURPUR_STAIRS = Item(203, 0, "Purpur Stairs", "minecraft:purpur_stairs");
    MU static constexpr auto PURPUR_DOUBLE_SLAB = Item(204, 0, "Purpur Double Slab", "minecraft:purpur_double_slab");
    MU static constexpr auto PURPUR_SLAB = Item(205, 0, "Purpur Slab", "minecraft:purpur_slab");
    MU static constexpr auto END_STONE_BRICKS = Item(206, 0, "End Stone Bricks", "minecraft:end_bricks");
    MU static constexpr auto BEETROOT_BLOCK = Item(207, 0, "Beetroot Block", "minecraft:beetroots");
    MU static constexpr auto GRASS_PATH = Item(208, 0, "Grass Path", "minecraft:grass_path");
    MU static constexpr auto END_GATEWAY = Item(209, 0, "End Gateway", "minecraft:end_gateway");
    MU static constexpr auto REPEATING_COMMAND_BLOCK = Item(210, 0, "Repeating Command Block", "minecraft:repeating_command_block");
    MU static constexpr auto CHAIN_COMMAND_BLOCK = Item(211, 0, "Chain Command Block", "minecraft:chain_command_block");
    MU static constexpr auto FROSTED_ICE = Item(212, 0, "Frosted Ice", "minecraft:frosted_ice");
    MU static constexpr auto MAGMA_BLOCK = Item(213, 0, "Magma Block", "minecraft:magma");
    MU static constexpr auto NETHER_WART_BLOCK = Item(214, 0, "Nether Wart Block", "minecraft:nether_wart_block");
    MU static constexpr auto RED_NETHER_BRICK = Item(215, 0, "Red Nether Brick", "minecraft:red_nether_brick");
    MU static constexpr auto BONE_BLOCK = Item(216, 0, "Bone Block", "minecraft:bone_block");
    MU static constexpr auto STRUCTURE_VOID = Item(217, 0, "Structure Void", "minecraft:structure_void");
    MU static constexpr auto OBSERVER = Item(218, 0, "Observer", "minecraft:observer");
    MU static constexpr auto WHITE_SHULKER_BOX = Item(219, 0, "White Shulker Box", "minecraft:white_shulker_box");
    MU static constexpr auto ORANGE_SHULKER_BOX = Item(220, 0, "Orange Shulker Box", "minecraft:orange_shulker_box");
    MU static constexpr auto MAGENTA_SHULKER_BOX = Item(221, 0, "Magenta Shulker Box", "minecraft:magenta_shulker_box");
    MU static constexpr auto LIGHT_BLUE_SHULKER_BOX = Item(222, 0, "Light Blue Shulker Box", "minecraft:light_blue_shulker_box");
    MU static constexpr auto YELLOW_SHULKER_BOX = Item(223, 0, "Yellow Shulker Box", "minecraft:yellow_shulker_box");
    MU static constexpr auto LIME_SHULKER_BOX = Item(224, 0, "Lime Shulker Box", "minecraft:lime_shulker_box");
    MU static constexpr auto PINK_SHULKER_BOX = Item(225, 0, "Pink Shulker Box", "minecraft:pink_shulker_box");
    MU static constexpr auto GRAY_SHULKER_BOX = Item(226, 0, "Gray Shulker Box", "minecraft:gray_shulker_box");
    MU static constexpr auto LIGHT_GRAY_SHULKER_BOX = Item(227, 0, "Light Gray Shulker Box", "minecraft:silver_shulker_box");
    MU static constexpr auto CYAN_SHULKER_BOX = Item(228, 0, "Cyan Shulker Box", "minecraft:cyan_shulker_box");
    MU static constexpr auto PURPLE_SHULKER_BOX = Item(229, 0, "Purple Shulker Box", "minecraft:purple_shulker_box");
    MU static constexpr auto BLUE_SHULKER_BOX = Item(230, 0, "Blue Shulker Box", "minecraft:blue_shulker_box");
    MU static constexpr auto BROWN_SHULKER_BOX = Item(231, 0, "Brown Shulker Box", "minecraft:brown_shulker_box");
    MU static constexpr auto GREEN_SHULKER_BOX = Item(232, 0, "Green Shulker Box", "minecraft:green_shulker_box");
    MU static constexpr auto RED_SHULKER_BOX = Item(233, 0, "Red Shulker Box", "minecraft:red_shulker_box");
    MU static constexpr auto BLACK_SHULKER_BOX = Item(234, 0, "Black Shulker Box", "minecraft:black_shulker_box");

    MU static constexpr auto WHITE_GLAZED_TERRACOTTA = Item(235, 0, "White Glazed Terracotta", "minecraft:white_glazed_terracotta");
    MU static constexpr auto ORANGE_GLAZED_TERRACOTTA = Item(236, 0, "Orange Glazed Terracotta", "minecraft:orange_glazed_terracotta");
    MU static constexpr auto MAGENTA_GLAZED_TERRACOTTA = Item(237, 0, "Magenta Glazed Terracotta", "minecraft:magenta_glazed_terracotta");
    MU static constexpr auto LIGHT_BLUE_GLAZED_TERRACOTTA = Item(238, 0, "Light Blue Glazed Terracotta", "minecraft:light_blue_glazed_terracotta");
    MU static constexpr auto YELLOW_GLAZED_TERRACOTTA = Item(239, 0, "Yellow Glazed Terracotta", "minecraft:yellow_glazed_terracotta");
    MU static constexpr auto LIME_GLAZED_TERRACOTTA = Item(240, 0, "Lime Glazed Terracotta", "minecraft:lime_glazed_terracotta");
    MU static constexpr auto PINK_GLAZED_TERRACOTTA = Item(241, 0, "Pink Glazed Terracotta", "minecraft:pink_glazed_terracotta");
    MU static constexpr auto GRAY_GLAZED_TERRACOTTA = Item(242, 0, "Gray Glazed Terracotta", "minecraft:gray_glazed_terracotta");
    MU static constexpr auto LIGHT_GRAY_GLAZED_TERRACOTTA = Item(243, 0, "Light Gray Glazed Terracotta", "minecraft:light_gray_glazed_terracotta");
    MU static constexpr auto SILVER_GLAZED_TERRACOTTA = Item(243, 0, "Silver Glazed Terracotta", "minecraft:silver_glazed_terracotta");
    MU static constexpr auto CYAN_GLAZED_TERRACOTTA = Item(244, 0, "Cyan Glazed Terracotta", "minecraft:cyan_glazed_terracotta");
    MU static constexpr auto PURPLE_GLAZED_TERRACOTTA = Item(245, 0, "Purple Glazed Terracotta", "minecraft:purple_glazed_terracotta");
    MU static constexpr auto BLUE_GLAZED_TERRACOTTA = Item(246, 0, "Blue Glazed Terracotta", "minecraft:blue_glazed_terracotta");
    MU static constexpr auto BROWN_GLAZED_TERRACOTTA = Item(247, 0, "Brown Glazed Terracotta", "minecraft:brown_glazed_terracotta");
    MU static constexpr auto GREEN_GLAZED_TERRACOTTA = Item(248, 0, "Green Glazed Terracotta", "minecraft:green_glazed_terracotta");
    MU static constexpr auto RED_GLAZED_TERRACOTTA = Item(249, 0, "Red Glazed Terracotta", "minecraft:red_glazed_terracotta");
    MU static constexpr auto BLACK_GLAZED_TERRACOTTA = Item(250, 0, "Black Glazed Terracotta", "minecraft:black_glazed_terracotta");

    MU static constexpr auto WHITE_CONCRETE = Item(251, 0, "White Concrete", "minecraft:concrete");
    MU static constexpr auto ORANGE_CONCRETE = Item(251, 1, "Orange Concrete", "minecraft:concrete");
    MU static constexpr auto MAGENTA_CONCRETE = Item(251, 2, "Magenta Concrete", "minecraft:concrete");
    MU static constexpr auto LIGHT_BLUE_CONCRETE = Item(251, 3, "Light Blue Concrete", "minecraft:concrete");
    MU static constexpr auto YELLOW_CONCRETE = Item(251, 4, "Yellow Concrete", "minecraft:concrete");
    MU static constexpr auto LIME_CONCRETE = Item(251, 5, "Lime Concrete", "minecraft:concrete");
    MU static constexpr auto PINK_CONCRETE = Item(251, 6, "Pink Concrete", "minecraft:concrete");
    MU static constexpr auto GRAY_CONCRETE = Item(251, 7, "Gray Concrete", "minecraft:concrete");
    MU static constexpr auto LIGHT_GRAY_CONCRETE = Item(251, 8, "Light Gray Concrete", "minecraft:concrete");
    MU static constexpr auto CYAN_CONCRETE = Item(251, 9, "Cyan Concrete", "minecraft:concrete");
    MU static constexpr auto PURPLE_CONCRETE = Item(251, 10, "Purple Concrete", "minecraft:concrete");
    MU static constexpr auto BLUE_CONCRETE = Item(251, 11, "Blue Concrete", "minecraft:concrete");
    MU static constexpr auto BROWN_CONCRETE = Item(251, 12, "Brown Concrete", "minecraft:concrete");
    MU static constexpr auto GREEN_CONCRETE = Item(251, 13, "Green Concrete", "minecraft:concrete");
    MU static constexpr auto RED_CONCRETE = Item(251, 14, "Red Concrete", "minecraft:concrete");
    MU static constexpr auto BLACK_CONCRETE = Item(251, 15, "Black Concrete", "minecraft:concrete");

    MU static constexpr auto WHITE_CONCRETE_POWDER = Item(252, 0, "White Concrete Powder", "minecraft:concrete_powder");
    MU static constexpr auto ORANGE_CONCRETE_POWDER = Item(252, 1, "Orange Concrete Powder", "minecraft:concrete_powder");
    MU static constexpr auto MAGENTA_CONCRETE_POWDER = Item(252, 2, "Magenta Concrete Powder", "minecraft:concrete_powder");
    MU static constexpr auto LIGHT_BLUE_CONCRETE_POWDER = Item(252, 3, "Light Blue Concrete Powder", "minecraft:concrete_powder");
    MU static constexpr auto YELLOW_CONCRETE_POWDER = Item(252, 4, "Yellow Concrete Powder", "minecraft:concrete_powder");
    MU static constexpr auto LIME_CONCRETE_POWDER = Item(252, 5, "Lime Concrete Powder", "minecraft:concrete_powder");
    MU static constexpr auto PINK_CONCRETE_POWDER = Item(252, 6, "Pink Concrete Powder", "minecraft:concrete_powder");
    MU static constexpr auto GRAY_CONCRETE_POWDER = Item(252, 7, "Gray Concrete Powder", "minecraft:concrete_powder");
    MU static constexpr auto LIGHT_GRAY_CONCRETE_POWDER = Item(252, 8, "Light Gray Concrete Powder", "minecraft:concrete_powder");
    MU static constexpr auto CYAN_CONCRETE_POWDER = Item(252, 9, "Cyan Concrete Powder", "minecraft:concrete_powder");
    MU static constexpr auto PURPLE_CONCRETE_POWDER = Item(252, 10, "Purple Concrete Powder", "minecraft:concrete_powder");
    MU static constexpr auto BLUE_CONCRETE_POWDER = Item(252, 11, "Blue Concrete Powder", "minecraft:concrete_powder");
    MU static constexpr auto BROWN_CONCRETE_POWDER = Item(252, 12, "Brown Concrete Powder", "minecraft:concrete_powder");
    MU static constexpr auto GREEN_CONCRETE_POWDER = Item(252, 13, "Green Concrete Powder", "minecraft:concrete_powder");
    MU static constexpr auto RED_CONCRETE_POWDER = Item(252, 14, "Red Concrete Powder", "minecraft:concrete_powder");
    MU static constexpr auto BLACK_CONCRETE_POWDER = Item(252, 15, "Black Concrete Powder", "minecraft:concrete_powder");

    MU static constexpr auto STRUCTURE_BLOCK = Item(255, 0, "Structure Block", "minecraft:structure_block");

    MU static constexpr auto IRON_SHOVEL = Item(256, 0, ItemType::ItemTool, "Iron Shovel", "minecraft:iron_shovel", true);
    MU static constexpr auto IRON_PICKAXE = Item(257, 0, ItemType::ItemTool, "Iron Pickaxe", "minecraft:iron_pickaxe", true);
    MU static constexpr auto IRON_AXE = Item(258, 0, ItemType::ItemTool, "Iron Axe", "minecraft:iron_axe", true);
    MU static constexpr auto FLINT_AND_STEEL = Item(259, 0, ItemType::ItemTool, "Flint and Steel", "minecraft:flint_and_steel", true);
    MU static constexpr auto APPLE = Item(260, 0, "Apple", "minecraft:apple");
    MU static constexpr auto BOW = Item(261, 0, ItemType::ItemBow, "Bow", "minecraft:bow");
    MU static constexpr auto ARROW = Item(262, 0, "Arrow", "minecraft:arrow");

    MU static constexpr auto COAL = Item(263, 0, "Coal", "minecraft:coal");
    MU static constexpr auto CHARCOAL = Item(263, 1, "Charcoal", "minecraft:coal");

    MU static constexpr auto DIAMOND = Item(264, 0, "Diamond", "minecraft:diamond");
    MU static constexpr auto IRON_INGOT = Item(265, 0, "Iron Ingot", "minecraft:iron_ingot");
    MU static constexpr auto GOLD_INGOT = Item(266, 0, "Gold Ingot", "minecraft:gold_ingot");

    MU static constexpr auto IRON_SWORD = Item(267, 0, ItemType::ItemSword, "Iron Sword", "minecraft:iron_sword", true);

    MU static constexpr auto WOODEN_SWORD = Item(268, 0, ItemType::ItemSword, "Wooden Sword", "minecraft:wooden_sword", true, TOOL_WOOD);
    MU static constexpr auto WOODEN_SHOVEL = Item(269, 0, ItemType::ItemTool, "Wooden Shovel", "minecraft:wooden_shovel", true, TOOL_WOOD);
    MU static constexpr auto WOODEN_PICKAXE = Item(270, 0, ItemType::ItemTool, "Wooden Pickaxe", "minecraft:wooden_pickaxe", true, TOOL_WOOD);
    MU static constexpr auto WOODEN_AXE = Item(271, 0, ItemType::ItemTool, "Wooden Axe", "minecraft:wooden_axe", true, TOOL_WOOD);

    MU static constexpr auto STONE_SWORD = Item(272, 0, ItemType::ItemSword, "Stone Sword", "minecraft:stone_sword", true, TOOL_STONE);
    MU static constexpr auto STONE_SHOVEL = Item(273, 0, ItemType::ItemTool, "Stone Shovel", "minecraft:stone_shovel", true, TOOL_STONE);
    MU static constexpr auto STONE_PICKAXE = Item(274, 0, ItemType::ItemTool, "Stone Pickaxe", "minecraft:stone_pickaxe", true, TOOL_STONE);
    MU static constexpr auto STONE_AXE = Item(275, 0, ItemType::ItemTool, "Stone Axe", "minecraft:stone_axe", true, TOOL_STONE);

    MU static constexpr auto DIAMOND_SWORD = Item(276, 0, ItemType::ItemSword, "Diamond Sword", "minecraft:diamond_sword", true, TOOL_DIAMOND);
    MU static constexpr auto DIAMOND_SHOVEL = Item(277, 0, ItemType::ItemTool, "Diamond Shovel", "minecraft:diamond_shovel", true, TOOL_DIAMOND);
    MU static constexpr auto DIAMOND_PICKAXE = Item(278, 0, ItemType::ItemTool, "Diamond Pickaxe", "minecraft:diamond_pickaxe", true, TOOL_DIAMOND);
    MU static constexpr auto DIAMOND_AXE = Item(279, 0, ItemType::ItemTool, "Diamond Axe", "minecraft:diamond_axe", true, TOOL_DIAMOND);

    MU static constexpr auto STICK = Item(280, 0, "Stick", "minecraft:stick");
    MU static constexpr auto BOWL = Item(281, 0, "Bowl", "minecraft:bowl");
    MU static constexpr auto MUSHROOM_STEW = Item(282, 0, "Mushroom Stew", "minecraft:mushroom_stew");

    MU static constexpr auto GOLDEN_SWORD = Item(283, 0, ItemType::ItemSword, "Golden Sword", "minecraft:golden_sword", true, TOOL_GOLD);
    MU static constexpr auto GOLDEN_SHOVEL = Item(284, 0, ItemType::ItemTool, "Golden Shovel", "minecraft:golden_shovel", true, TOOL_GOLD);
    MU static constexpr auto GOLDEN_PICKAXE = Item(285, 0, ItemType::ItemTool, "Golden Pickaxe", "minecraft:golden_pickaxe", true, TOOL_GOLD);
    MU static constexpr auto GOLDEN_AXE = Item(286, 0, ItemType::ItemTool, "Golden Axe", "minecraft:golden_axe", true, TOOL_GOLD);

    MU static constexpr auto STRING = Item(287, 0, "String", "minecraft:string");
    MU static constexpr auto FEATHER = Item(288, 0, "Feather", "minecraft:feather");
    MU static constexpr auto GUNPOWDER = Item(289, 0, "Gunpowder", "minecraft:gunpowder");

    MU static constexpr auto WOODEN_HOE = Item(290, 0, ItemType::ItemTool, "Wooden Hoe", "minecraft:wooden_hoe", true, TOOL_WOOD);
    MU static constexpr auto STONE_HOE = Item(291, 0, ItemType::ItemTool, "Stone Hoe", "minecraft:stone_hoe", true, TOOL_STONE);
    MU static constexpr auto IRON_HOE = Item(292, 0, ItemType::ItemTool, "Iron Hoe", "minecraft:iron_hoe", true, TOOL_IRON);
    MU static constexpr auto DIAMOND_HOE = Item(293, 0, ItemType::ItemTool, "Diamond Hoe", "minecraft:diamond_hoe", true, TOOL_DIAMOND);
    MU static constexpr auto GOLDEN_HOE = Item(294, 0, ItemType::ItemTool, "Golden Hoe", "minecraft:golden_hoe", true, TOOL_GOLD);

    MU static constexpr auto WHEAT_SEEDS = Item(295, 0, "Wheat Seeds", "minecraft:wheat_seeds");
    MU static constexpr auto WHEAT = Item(296, 0, "Wheat", "minecraft:wheat");
    MU static constexpr auto BREAD = Item(297, 0, "Bread", "minecraft:bread");

    MU static constexpr auto LEATHER_HELMET = Item(298, 0, ItemType::ItemArmor, "Leather Helmet", "minecraft:leather_helmet", true, ItemEquipSlot::HEAD, ARMOR_LEATHER);
    MU static constexpr auto LEATHER_TUNIC = Item(299, 0, ItemType::ItemArmor, "Leather Tunic", "minecraft:leather_chestplate", true, ItemEquipSlot::CHEST, ARMOR_LEATHER);
    MU static constexpr auto LEATHER_PANTS = Item(300, 0, ItemType::ItemArmor, "Leather Pants", "minecraft:leather_leggings", true, ItemEquipSlot::LEGS, ARMOR_LEATHER);
    MU static constexpr auto LEATHER_BOOTS = Item(301, 0, ItemType::ItemArmor, "Leather Boots", "minecraft:leather_boots", true, ItemEquipSlot::FEET, ARMOR_LEATHER);

    MU static constexpr auto CHAINMAIL_HELMET = Item(302, 0, ItemType::ItemArmor, "Chainmail Helmet", "minecraft:chainmail_helmet", true, ItemEquipSlot::HEAD, ARMOR_CHAIN);
    MU static constexpr auto CHAINMAIL_CHESTPLATE = Item(303, 0, ItemType::ItemArmor, "Chainmail Chestplate", "minecraft:chainmail_chestplate", true,                                     ItemEquipSlot::CHEST, ARMOR_CHAIN);
    MU static constexpr auto CHAINMAIL_LEGGINGS = Item(304, 0, ItemType::ItemArmor, "Chainmail Leggings", "minecraft:chainmail_leggings", true, ItemEquipSlot::LEGS, ARMOR_CHAIN);
    MU static constexpr auto CHAINMAIL_BOOTS = Item(305, 0, ItemType::ItemArmor, "Chainmail Boots", "minecraft:chainmail_boots", true, ItemEquipSlot::FEET, ARMOR_CHAIN);

    MU static constexpr auto IRON_HELMET = Item(306, 0, ItemType::ItemArmor, "Iron Helmet", "minecraft:iron_helmet", true, ItemEquipSlot::HEAD, ARMOR_IRON);
    MU static constexpr auto IRON_CHESTPLATE = Item(307, 0, ItemType::ItemArmor, "Iron Chestplate", "minecraft:iron_chestplate", true, ItemEquipSlot::CHEST, ARMOR_IRON);
    MU static constexpr auto IRON_LEGGINGS = Item(308, 0, ItemType::ItemArmor, "Iron Leggings", "minecraft:iron_leggings", true, ItemEquipSlot::LEGS, ARMOR_IRON);
    MU static constexpr auto IRON_BOOTS = Item(309, 0, ItemType::ItemArmor, "Iron Boots", "minecraft:iron_boots", true, ItemEquipSlot::FEET, ARMOR_IRON);

    MU static constexpr auto DIAMOND_HELMET = Item(310, 0, ItemType::ItemArmor, "Diamond Helmet", "minecraft:diamond_helmet", true, ItemEquipSlot::HEAD, ARMOR_DIAMOND);
    MU static constexpr auto DIAMOND_CHESTPLATE = Item(311, 0, ItemType::ItemArmor, "Diamond Chestplate", "minecraft:diamond_chestplate", true, ItemEquipSlot::CHEST,                                   ARMOR_DIAMOND);
    MU static constexpr auto DIAMOND_LEGGINGS = Item(312, 0, ItemType::ItemArmor, "Diamond Leggings", "minecraft:diamond_leggings", true, ItemEquipSlot::LEGS, ARMOR_DIAMOND);
    MU static constexpr auto DIAMOND_BOOTS = Item(313, 0, ItemType::ItemArmor, "Diamond Boots", "minecraft:diamond_boots", true, ItemEquipSlot::FEET, ARMOR_DIAMOND);

    MU static constexpr auto GOLDEN_HELMET = Item(314, 0, ItemType::ItemArmor, "Golden Helmet", "minecraft:golden_helmet", true, ItemEquipSlot::HEAD, ARMOR_GOLD);
    MU static constexpr auto GOLDEN_CHESTPLATE = Item(315, 0, ItemType::ItemArmor, "Golden Chestplate", "minecraft:golden_chestplate", true, ItemEquipSlot::CHEST, ARMOR_GOLD);
    MU static constexpr auto GOLDEN_LEGGINGS = Item(316, 0, ItemType::ItemArmor, "Golden Leggings", "minecraft:golden_leggings", true, ItemEquipSlot::LEGS, ARMOR_GOLD);
    MU static constexpr auto GOLDEN_BOOTS = Item(317, 0, ItemType::ItemArmor, "Golden Boots", "minecraft:golden_boots", true, ItemEquipSlot::FEET, ARMOR_GOLD);

    MU static constexpr auto FLINT = Item(318, 0, "Flint", "minecraft:flint");
    MU static constexpr auto RAW_PORKCHOP = Item(319, 0, "Raw Porkchop", "minecraft:porkchop");
    MU static constexpr auto COOKED_PORKCHOP = Item(320, 0, "Cooked Porkchop", "minecraft:cooked_porkchop");
    MU static constexpr auto PAINTING = Item(321, 0, "Painting", "minecraft:painting");

    MU static constexpr auto GOLDEN_APPLE = Item(322, 0, "Golden Apple", "minecraft:golden_apple");
    MU static constexpr auto ENCHANTED_GOLDEN_APPLE = Item(322, 1, "Enchanted Golden Apple", "minecraft:golden_apple");

    MU static constexpr auto SIGN = Item(323, 0, "Sign", "minecraft:sign");
    MU static constexpr auto OAK_DOOR = Item(324, 0, "Oak Door", "minecraft:wooden_door");
    MU static constexpr auto BUCKET = Item(325, 0, "Bucket", "minecraft:bucket");
    MU static constexpr auto WATER_BUCKET = Item(326, 0, "Water Bucket", "minecraft:water_bucket");
    MU static constexpr auto LAVA_BUCKET = Item(327, 0, "Lava Bucket", "minecraft:lava_bucket");
    MU static constexpr auto MINECART = Item(328, 0, "Minecart", "minecraft:minecart");
    MU static constexpr auto SADDLE = Item(329, 0, "Saddle", "minecraft:saddle");
    MU static constexpr auto IRON_DOOR = Item(330, 0, "Iron Door", "minecraft:iron_door");
    MU static constexpr auto REDSTONE = Item(331, 0, "Redstone", "minecraft:redstone");
    MU static constexpr auto SNOWBALL = Item(332, 0, "Snowball", "minecraft:snowball");
    MU static constexpr auto OAK_BOAT = Item(333, 0, "Oak Boat", "minecraft:boat");
    MU static constexpr auto LEATHER = Item(334, 0, "Leather", "minecraft:leather");
    MU static constexpr auto MILK_BUCKET = Item(335, 0, "Milk Bucket", "minecraft:milk_bucket");
    MU static constexpr auto BRICK = Item(336, 0, "Brick", "minecraft:brick");
    MU static constexpr auto CLAY = Item(337, 0, "Clay", "minecraft:clay_ball");
    MU static constexpr auto SUGAR_CANES_2 = Item(338, 0, "Sugar Canes", "minecraft:reeds");
    MU static constexpr auto PAPER = Item(339, 0, "Paper", "minecraft:paper");
    MU static constexpr auto BOOK = Item(340, 0, "Book", "minecraft:book");
    MU static constexpr auto SLIMEBALL = Item(341, 0, "Slimeball", "minecraft:slime_ball");
    MU static constexpr auto MINECART_WITH_CHEST = Item(342, 0, "Minecart with Chest", "minecraft:chest_minecart");
    MU static constexpr auto MINECART_WITH_FURNACE = Item(343, 0, "Minecart with Furnace", "minecraft:furnace_minecart");
    MU static constexpr auto EGG = Item(344, 0, "Egg", "minecraft:egg");
    MU static constexpr auto COMPASS = Item(345, 0, "Compass", "minecraft:compass");
    MU static constexpr auto FISHING_ROD = Item(346, 0, ItemType::ItemFishingRod, "Fishing Rod", "minecraft:fishing_rod", true);
    MU static constexpr auto CLOCK = Item(347, 0, "Clock", "minecraft:clock");
    MU static constexpr auto GLOWSTONE_DUST = Item(348, 0, "Glowstone Dust", "minecraft:glowstone_dust");

    MU static constexpr auto RAW_FISH = Item(349, 0, "Raw Fish", "minecraft:fish");
    MU static constexpr auto RAW_SALMON = Item(349, 1, "Raw Fish", "minecraft:fish");
    MU static constexpr auto RAW_CLOWN_FISH = Item(349, 2, "Raw Fish", "minecraft:fish");
    MU static constexpr auto PUFFERFISH = Item(349, 3, "Pufferfish", "minecraft:fish");

    MU static constexpr auto COOKED_FISH = Item(350, 0, "Cooked Fish", "minecraft:cooked_fish");
    MU static constexpr auto COOKED_SALMON = Item(350, 1, "Cooked Salmon", "minecraft:cooked_fish");

    MU static constexpr auto INK_SACK = Item(351, 0, "Ink Sack", "minecraft:dye");
    MU static constexpr auto ROSE_RED = Item(351, 1, "Rose Red", "minecraft:dye");
    MU static constexpr auto CACTUS_GREEN = Item(351, 2, "Cactus Green", "minecraft:dye");
    MU static constexpr auto COCOA_BEANS = Item(351, 3, "Cocoa Beans", "minecraft:dye");
    MU static constexpr auto LAPIS_LAZULI = Item(351, 4, "Lapis Lazuli", "minecraft:dye");
    MU static constexpr auto PURPLE_DYE = Item(351, 5, "Purple Dye", "minecraft:dye");
    MU static constexpr auto CYAN_DYE = Item(351, 6, "Cyan Dye", "minecraft:dye");
    MU static constexpr auto LIGHT_GRAY_DYE = Item(351, 7, "Light Gray Dye", "minecraft:dye");
    MU static constexpr auto GRAY_DYE = Item(351, 8, "Gray Dye", "minecraft:dye");
    MU static constexpr auto PINK_DYE = Item(351, 9, "Pink Dye", "minecraft:dye");
    MU static constexpr auto LIME_DYE = Item(351, 10, "Lime Dye", "minecraft:dye");
    MU static constexpr auto DANDELION_YELLOW = Item(351, 11, "Dandelion Yellow", "minecraft:dye");
    MU static constexpr auto LIGHT_BLUE_DYE = Item(351, 12, "Light Blue Dye", "minecraft:dye");
    MU static constexpr auto MAGENTA_DYE = Item(351, 13, "Magenta Dye", "minecraft:dye");
    MU static constexpr auto ORANGE_DYE = Item(351, 14, "Orange Dye", "minecraft:dye");
    MU static constexpr auto BONE_MEAL = Item(351, 15, "Bone Meal", "minecraft:dye");

    MU static constexpr auto BONE = Item(352, 0, "Bone", "minecraft:bone");
    MU static constexpr auto SUGAR = Item(353, 0, "Sugar", "minecraft:sugar");
    MU static constexpr auto CAKE = Item(354, 0, "Cake", "minecraft:cake");

    MU static constexpr auto WHITE_BED = Item(355, 0, "White Bed", "minecraft:bed");
    MU static constexpr auto ORANGE_BED = Item(355, 1, "Orange Bed", "minecraft:bed");
    MU static constexpr auto MAGENTA_BED = Item(355, 2, "Magenta Bed", "minecraft:bed");
    MU static constexpr auto LIGHT_BLUE_BED = Item(355, 3, "Light Blue Bed", "minecraft:bed");
    MU static constexpr auto YELLOW_BED = Item(355, 4, "Yellow Bed", "minecraft:bed");
    MU static constexpr auto LIME_BED = Item(355, 5, "Lime Bed", "minecraft:bed");
    MU static constexpr auto PINK_BED = Item(355, 6, "Pink Bed", "minecraft:bed");
    MU static constexpr auto GRAY_BED = Item(355, 7, "Gray Bed", "minecraft:bed");
    MU static constexpr auto LIGHT_GRAY_BED = Item(355, 8, "Light Gray Bed", "minecraft:bed");
    MU static constexpr auto CYAN_BED = Item(355, 9, "Cyan Bed", "minecraft:bed");
    MU static constexpr auto PURPLE_BED = Item(355, 10, "Purple Bed", "minecraft:bed");
    MU static constexpr auto BLUE_BED = Item(355, 11, "Blue Bed", "minecraft:bed");
    MU static constexpr auto BROWN_BED = Item(355, 12, "Brown Bed", "minecraft:bed");
    MU static constexpr auto GREEN_BED = Item(355, 13, "Green Bed", "minecraft:bed");
    MU static constexpr auto RED_BED = Item(355, 14, "Red Bed", "minecraft:bed");
    MU static constexpr auto BLACK_BED = Item(355, 15, "Black Bed", "minecraft:bed");

    MU static constexpr auto REDSTONE_REPEATER = Item(356, 0, "Redstone Repeater", "minecraft:repeater");
    MU static constexpr auto COOKIE = Item(357, 0, "Cookie", "minecraft:cookie");

    MU static constexpr auto MAP = Item(358, 0, "Map", "minecraft:filled_map");
    MU static constexpr auto LOCATOR_MAP = Item(358, 2, "Locator Map", "minecraft:filled_map");
    MU static constexpr auto OCEAN_EXPLORER_MAP = Item(358, 3, "Ocean Explorer Map", "minecraft:filled_map");
    MU static constexpr auto WOODLAND_EXPLORER_MAP = Item(358, 4, "Woodland Explorer Map", "minecraft:filled_map");
    MU static constexpr auto TREASURE_MAP = Item(358, 5, "Treasure Map", "minecraft:filled_map");
    MU static constexpr auto LOCKED_MAP = Item(358, 6, "Locked Map", "minecraft:filled_map");


    MU static constexpr auto SHEARS = Item(359, 0, ItemType::ItemTool, "Shears", "minecraft:shears", true);
    MU static constexpr auto MELON = Item(360, 0, "Melon", "minecraft:melon");
    MU static constexpr auto PUMPKIN_SEEDS = Item(361, 0, "Pumpkin Seeds", "minecraft:pumpkin_seeds");
    MU static constexpr auto MELON_SEEDS = Item(362, 0, "Melon Seeds", "minecraft:melon_seeds");
    MU static constexpr auto RAW_BEEF = Item(363, 0, "Raw Beef", "minecraft:beef");
    MU static constexpr auto STEAK = Item(364, 0, "Steak", "minecraft:cooked_beef");
    MU static constexpr auto RAW_CHICKEN = Item(365, 0, "Raw Chicken", "minecraft:chicken");
    MU static constexpr auto COOKED_CHICKEN = Item(366, 0, "Cooked Chicken", "minecraft:cooked_chicken");
    MU static constexpr auto ROTTEN_FLESH = Item(367, 0, "Rotten Flesh", "minecraft:rotten_flesh");
    MU static constexpr auto ENDER_PEARL = Item(368, 0, "Ender Pearl", "minecraft:ender_pearl");
    MU static constexpr auto BLAZE_ROD = Item(369, 0, "Blaze Rod", "minecraft:blaze_rod");
    MU static constexpr auto GHAST_TEAR = Item(370, 0, "Ghast Tear", "minecraft:ghast_tear");
    MU static constexpr auto GOLD_NUGGET = Item(371, 0, "Gold Nugget", "minecraft:gold_nugget");

    MU static constexpr auto NETHER_WART = Item(372, 0, "Nether Wart", "minecraft:nether_wart");

    MU static constexpr auto POTION = Item(373, 0, "Potion", "minecraft:potion");
    MU static constexpr auto POTION_AWKWARD = Item(373, 0, "Awkward", "minecraft:potion");
    MU static constexpr auto MUNDANE_POTION = Item(373, 0, "Mundane Potion", "minecraft:potion");
    MU static constexpr auto POTION_OF_EXTENDED_INVISIBILITY = Item(373, 0, "Potion of Extended Invisibility", "minecraft:potion");
    MU static constexpr auto POTION_OF_EXTENDED_LEAPING = Item(373, 0, "Potion of Extended Leaping", "minecraft:potion");
    MU static constexpr auto POTION_OF_EXTENDED_NIGHT_VISION = Item(373, 0, "Potion of Extended Night Vision", "minecraft:potion");
    MU static constexpr auto POTION_OF_EXTENDED_POISON = Item(373, 0, "Potion of Extended Poison", "minecraft:potion");
    MU static constexpr auto POTION_OF_EXTENDED_REGENERATION = Item(373, 0, "Potion of Extended Regeneration", "minecraft:potion");
    MU static constexpr auto POTION_OF_EXTENDED_SLOWNESS = Item(373, 0, "Potion of Extended Slowness", "minecraft:potion");
    MU static constexpr auto POTION_OF_EXTENDED_STRENGTH = Item(373, 0, "Potion of Extended Strength", "minecraft:potion");
    MU static constexpr auto POTION_OF_EXTENDED_SWIFTNESS = Item(373, 0, "Potion of Extended Swiftness", "minecraft:potion");
    MU static constexpr auto POTION_OF_EXTENDED_WATER_BREATHING = Item(373, 0, "Potion of Extended Water Breathing", "minecraft:potion");
    MU static constexpr auto POTION_OF_EXTENDED_WEAKNESS = Item(373, 0, "Potion of Extended Weakness", "minecraft:potion");
    MU static constexpr auto POTION_OF_FIRE_RESISTANCE = Item(373, 0, "Potion of Fire Resistance", "minecraft:potion");
    MU static constexpr auto POTION_OF_HARMING = Item(373, 0, "Potion of Harming", "minecraft:potion");
    MU static constexpr auto POTION_OF_HARMING_II = Item(373, 0, "Potion of Harming II", "minecraft:potion");
    MU static constexpr auto POTION_OF_HEALING = Item(373, 0, "Potion of Healing", "minecraft:potion");
    MU static constexpr auto POTION_OF_HEALING_II = Item(373, 0, "Potion of Healing II", "minecraft:potion");
    MU static constexpr auto POTION_OF_INVISIBILITY = Item(373, 0, "Potion of Invisibility", "minecraft:potion");
    MU static constexpr auto POTION_OF_LEAPING = Item(373, 0, "Potion of Leaping", "minecraft:potion");
    MU static constexpr auto POTION_OF_LEAPING_II = Item(373, 0, "Potion of Leaping II", "minecraft:potion");
    MU static constexpr auto POTION_OF_LUCK = Item(373, 0, "Potion of Luck", "minecraft:potion");
    MU static constexpr auto POTION_OF_NIGHT_VISION = Item(373, 0, "Potion of Night Vision", "minecraft:potion");
    MU static constexpr auto POTION_OF_POISON = Item(373, 0, "Potion of Poison", "minecraft:potion");
    MU static constexpr auto POTION_OF_POISON_II = Item(373, 0, "Potion of Poison II", "minecraft:potion");
    MU static constexpr auto POTION_OF_REGENERATION = Item(373, 1, "Potion of Regeneration", "minecraft:potion");
    MU static constexpr auto POTION_OF_REGENERATION_II = Item(373, 0, "Potion of Regeneration II", "minecraft:potion");
    MU static constexpr auto POTION_OF_SLOWNESS = Item(373, 0, "Potion of Slowness", "minecraft:potion");
    MU static constexpr auto POTION_OF_STRENGTH = Item(373, 0, "Potion of Strength", "minecraft:potion");
    MU static constexpr auto POTION_OF_STRENGTH_II = Item(373, 0, "Potion of Strength II", "minecraft:potion");
    MU static constexpr auto POTION_OF_SWIFTNESS = Item(373, 0, "Potion of Swiftness", "minecraft:potion");
    MU static constexpr auto POTION_OF_SWIFTNESS_II = Item(373, 0, "Potion of Swiftness II", "minecraft:potion");
    MU static constexpr auto POTION_OF_WATER_BREATHING = Item(373, 2, "Potion of Water Breathing", "minecraft:potion");
    MU static constexpr auto POTION_OF_WEAKNESS = Item(373, 0, "Potion of Weakness", "minecraft:potion");
    MU static constexpr auto THICK_POTION = Item(373, 0, "Thick Potion", "minecraft:potion");
    MU static constexpr auto UNCRAFTABLE_POTION = Item(373, 0, "Uncraftable Potion", "minecraft:potion");
    MU static constexpr auto WATER_BOTTLE = Item(373, 0, "Water Bottle", "minecraft:potion");

    MU static constexpr auto GLASS_BOTTLE = Item(374, 0, "Glass Bottle", "minecraft:glass_bottle");
    MU static constexpr auto SPIDER_EYE = Item(375, 0, "Spider Eye", "minecraft:spider_eye");
    MU static constexpr auto FERMENTED_SPIDER_EYE = Item(376, 0, "Fermented Spider Eye", "minecraft:fermented_spider_eye");
    MU static constexpr auto BLAZE_POWDER = Item(377, 0, "Blaze Powder", "minecraft:blaze_powder");
    MU static constexpr auto MAGMA_CREAM = Item(378, 0, "Magma Cream", "minecraft:magma_cream");
    MU static constexpr auto BREWING_STAND = Item(379, 0, "Brewing Stand", "minecraft:brewing_stand");
    MU static constexpr auto CAULDRON = Item(380, 0, "Cauldron", "minecraft:cauldron");
    MU static constexpr auto EYE_OF_ENDER = Item(381, 0, "Eye of Ender", "minecraft:ender_eye");
    MU static constexpr auto GLISTERING_MELON = Item(382, 0, "Glistering Melon", "minecraft:speckled_melon");

    MU static constexpr auto SPAWN_EGG = Item(383, 0, "Spawn Egg", "minecraft:spawn_egg");
    // times 1000 million

    MU static constexpr auto BOTTLE_O_ENCHANTING = Item(384, 0, "Bottle o' Enchanting", "minecraft:experience_bottle");
    MU static constexpr auto FIRE_CHARGE = Item(385, 0, "Fire Charge", "minecraft:fire_charge");
    MU static constexpr auto BOOK_AND_QUILL = Item(386, 0, "Book and Quill", "minecraft:writable_book");
    MU static constexpr auto WRITTEN_BOOK = Item(387, 0, "Written Book", "minecraft:written_book");
    MU static constexpr auto EMERALD = Item(388, 0, "Emerald", "minecraft:emerald");
    MU static constexpr auto ITEM_FRAME = Item(389, 0, "Item Frame", "minecraft:item_frame");
    MU static constexpr auto FLOWER_POT = Item(390, 0, "Flower Pot", "minecraft:flower_pot");
    MU static constexpr auto CARROT = Item(391, 0, "Carrot", "minecraft:carrot");
    MU static constexpr auto POTATO = Item(392, 0, "Potato", "minecraft:potato");
    MU static constexpr auto BAKED_POTATO = Item(393, 0, "Baked Potato", "minecraft:baked_potato");
    MU static constexpr auto POISONOUS_POTATO = Item(394, 0, "Poisonous Potato", "minecraft:poisonous_potato");
    MU static constexpr auto EMPTY_MAP = Item(395, 0, "Empty Map", "minecraft:map");
    MU static constexpr auto GOLDEN_CARROT = Item(396, 0, "Golden Carrot", "minecraft:golden_carrot");

    MU static constexpr auto SKELETON_SKULL = Item(397, 0,  ItemType::ItemSkull, "Skeleton Skull", "minecraft:skull");
    MU static constexpr auto WITHER_SKELETON_SKULL = Item(397, 1,  ItemType::ItemSkull, "Wither Skeleton Skull", "minecraft:skull");
    MU static constexpr auto ZOMBIE_HEAD = Item(397, 2,  ItemType::ItemSkull, "Zombie Head", "minecraft:skull");
    MU static constexpr auto PLAYER_HEAD = Item(397, 3,  ItemType::ItemSkull, "Player Head", "minecraft:skull");
    MU static constexpr auto CREEPER_HEAD = Item(397, 4,  ItemType::ItemSkull, "Creeper Head", "minecraft:skull");
    MU static constexpr auto DRAGON_HEAD = Item(397, 5,  ItemType::ItemSkull, "Dragon Head", "minecraft:skull");

    MU static constexpr auto CARROT_ON_A_STICK = Item(398, 0, "Carrot on a Stick", "minecraft:carrot_on_a_stick");
    MU static constexpr auto NETHER_STAR = Item(399, 0, "Nether Star", "minecraft:nether_star");
    MU static constexpr auto PUMPKIN_PIE = Item(400, 0, "Pumpkin Pie", "minecraft:pumpkin_pie");
    MU static constexpr auto FIREWORK_ROCKET = Item(401, 0, "Firework Rocket", "minecraft:fireworks");
    MU static constexpr auto FIREWORK_STAR = Item(402, 0, "Firework Star", "minecraft:firework_charge");
    MU static constexpr auto ENCHANTED_BOOK = Item(403, 0, "Enchanted Book", "minecraft:enchanted_book");
    MU static constexpr auto REDSTONE_COMPARATOR = Item(404, 0, "Redstone Comparator", "minecraft:comparator");
    MU static constexpr auto NETHER_BRICK = Item(405, 0, "Nether Brick", "minecraft:netherbrick");
    MU static constexpr auto NETHER_QUARTZ = Item(406, 0, "Nether Quartz", "minecraft:quartz");
    MU static constexpr auto MINECART_WITH_TNT = Item(407, 0, "Minecart with TNT", "minecraft:tnt_minecart");
    MU static constexpr auto MINECART_WITH_HOPPER = Item(408, 0, "Minecart with Hopper", "minecraft:hopper_minecart");
    MU static constexpr auto PRISMARINE_SHARD = Item(409, 0, "Prismarine Shard", "minecraft:prismarine_shard");
    MU static constexpr auto PRISMARINE_CRYSTALS = Item(410, 0, "Prismarine Crystals", "minecraft:prismarine_crystals");
    MU static constexpr auto RAW_RABBIT = Item(411, 0, "Raw Rabbit", "minecraft:rabbit");
    MU static constexpr auto COOKED_RABBIT = Item(412, 0, "Cooked Rabbit", "minecraft:cooked_rabbit");
    MU static constexpr auto RABBIT_STEW = Item(413, 0, "Rabbit Stew", "minecraft:rabbit_stew");
    MU static constexpr auto RABBITS_FOOT = Item(414, 0, "Rabbit’s Foot", "minecraft:rabbit_foot");
    MU static constexpr auto RABBIT_HIDE = Item(415, 0, "Rabbit Hide", "minecraft:rabbit_hide");
    MU static constexpr auto ARMOR_STAND = Item(416, 0, "Armor Stand", "minecraft:armor_stand");
    MU static constexpr auto IRON_HORSE_ARMOR = Item(417, 0, "Iron Horse Armor", "minecraft:iron_horse_armor");
    MU static constexpr auto GOLDEN_HORSE_ARMOR = Item(418, 0, "Golden Horse Armor", "minecraft:golden_horse_armor");
    MU static constexpr auto DIAMOND_HORSE_ARMOR = Item(419, 0, "Diamond Horse Armor", "minecraft:diamond_horse_armor");
    MU static constexpr auto LEAD = Item(420, 0, "Lead", "minecraft:lead");
    MU static constexpr auto NAME_TAG = Item(421, 0, "Name Tag", "minecraft:name_tag");
    MU static constexpr auto MINECART_WITH_COMMAND_BLOCK = Item(422, 0, "Minecart with Command Block", "minecraft:command_block_minecart");
    MU static constexpr auto RAW_MUTTON = Item(423, 0, "Raw Mutton", "minecraft:mutton");
    MU static constexpr auto COOKED_MUTTON = Item(424, 0, "Cooked Mutton", "minecraft:cooked_mutton");

    MU static constexpr auto BLACK_BANNER = Item(425, 0, "Black Banner", "minecraft:banner");
    MU static constexpr auto RED_BANNER = Item(425, 1, "Red Banner", "minecraft:banner");
    MU static constexpr auto GREEN_BANNER = Item(425, 2, "Green Banner", "minecraft:banner");
    MU static constexpr auto BROWN_BANNER = Item(425, 3, "Brown Banner", "minecraft:banner");
    MU static constexpr auto BLUE_BANNER = Item(425, 4, "Blue Banner", "minecraft:banner");
    MU static constexpr auto PURPLE_BANNER = Item(425, 5, "Purple Banner", "minecraft:banner");
    MU static constexpr auto CYAN_BANNER = Item(425, 6, "Cyan Banner", "minecraft:banner");
    MU static constexpr auto LIGHT_BANNER = Item(425, 7, "Light Gray Banner", "minecraft:banner");
    MU static constexpr auto GRAY_BANNER = Item(425, 8, "Gray Banner", "minecraft:banner");
    MU static constexpr auto PINK_BANNER = Item(425, 9, "Pink Banner", "minecraft:banner");
    MU static constexpr auto LIME_BANNER = Item(425, 10, "Lime Banner", "minecraft:banner");
    MU static constexpr auto YELLOW_BANNER = Item(425, 11, "Yellow Banner", "minecraft:banner");
    MU static constexpr auto LIGHT_BLUE_BANNER = Item(425, 12, "Light Blue Banner", "minecraft:banner");
    MU static constexpr auto MAGENTA_BANNER = Item(425, 13, "Magenta Banner", "minecraft:banner");
    MU static constexpr auto ORANGE_BANNER = Item(425, 14, "Orange Banner", "minecraft:banner");
    MU static constexpr auto WHITE_BANNER = Item(425, 15, "White Banner", "minecraft:banner");

    MU static constexpr auto END_CRYSTAL = Item(426, 0, "End Crystal", "minecraft:end_crystal");
    MU static constexpr auto SPRUCE_DOOR = Item(427, 0, "Spruce Door", "minecraft:spruce_door");
    MU static constexpr auto BIRCH_DOOR = Item(428, 0, "Birch Door", "minecraft:birch_door");
    MU static constexpr auto JUNGLE_DOOR = Item(429, 0, "Jungle Door", "minecraft:jungle_door");
    MU static constexpr auto ACACIA_DOOR = Item(430, 0, "Acacia Door", "minecraft:acacia_door");
    MU static constexpr auto DARK_OAK_DOOR = Item(431, 0, "Dark Oak Door", "minecraft:dark_oak_door");
    MU static constexpr auto CHORUS_FRUIT = Item(432, 0, "Chorus Fruit", "minecraft:chorus_fruit");
    MU static constexpr auto POPPED_CHORUS_FRUIT = Item(433, 0, "Popped Chorus Fruit", "minecraft:chorus_fruit_popped");
    MU static constexpr auto BEETROOT = Item(434, 0, "Beetroot", "minecraft:beetroot");
    MU static constexpr auto BEETROOT_SEEDS = Item(435, 0, "Beetroot Seeds", "minecraft:beetroot_seeds");
    MU static constexpr auto BEETROOT_SOUP = Item(436, 0, "Beetroot Soup", "minecraft:beetroot_soup");
    MU static constexpr auto DRAGONS_BREATH = Item(437, 0, "Dragon’s Breath", "minecraft:dragon_breath");
    MU static constexpr auto SPLASH_POTION = Item(438, 0, "Splash Potion", "minecraft:splash_potion");
    MU static constexpr auto SPECTRAL_ARROW = Item(439, 0, "Spectral Arrow", "minecraft:spectral_arrow");
    MU static constexpr auto TIPPED_ARROW = Item(440, 0, "Tipped Arrow", "minecraft:tipped_arrow");
    MU static constexpr auto LINGERING_POTION = Item(441, 0, "Lingering Potion", "minecraft:lingering_potion");
    MU static constexpr auto SHIELD = Item(442, 0, "Shield", "minecraft:shield");
    MU static constexpr auto ELYTRA = Item(443, 0, ItemType::ItemElytra, "Elytra", "minecraft:elytra");
    MU static constexpr auto SPRUCE_BOAT = Item(444, 0, "Spruce Boat", "minecraft:spruce_boat");
    MU static constexpr auto BIRCH_BOAT = Item(445, 0, "Birch Boat", "minecraft:birch_boat");
    MU static constexpr auto JUNGLE_BOAT = Item(446, 0, "Jungle Boat", "minecraft:jungle_boat");
    MU static constexpr auto ACACIA_BOAT = Item(447, 0, "Acacia Boat", "minecraft:acacia_boat");
    MU static constexpr auto DARK_OAK_BOAT = Item(448, 0, "Dark Oak Boat", "minecraft:dark_oak_boat");
    MU static constexpr auto TOTEM_OF_UNDYING = Item(449, 0, "Totem of Undying", "minecraft:totem_of_undying");
    MU static constexpr auto SHULKER_SHELL = Item(450, 0, "Shulker Shell", "minecraft:shulker_shell");
    MU static constexpr auto IRON_NUGGET = Item(452, 0, "Iron Nugget", "minecraft:iron_nugget");

    MU static constexpr auto LEATHER_HORSE_ARMOR = Item(453, 1, "Leather Horse Armor", "minecraft:leather_horse_armor");

    MU static constexpr auto TRIDENT = Item(546, 0, ItemType::ItemTrident, "Trident", "minecraft:trident", true);

    MU static constexpr auto HEART_OF_THE_SEA = Item(571, 0, "Heart of the Sea", "minecraft:heart_of_the_sea");
    MU static constexpr auto NAUTILUS_CORE = HEART_OF_THE_SEA;

    MU static constexpr auto ERROR_ITEM = Item(666, 0, "Error", "minecraft:error");














    MU static constexpr auto DISC_13 = Item(2256, 0, "13 Disc", "minecraft:record_13");
    MU static constexpr auto DISC_CAT = Item(2257, 0, "Cat Disc", "minecraft:record_cat");
    MU static constexpr auto DISC_BLOCKS = Item(2258, 0, "Blocks Disc", "minecraft:record_blocks");
    MU static constexpr auto DISC_CHIRP = Item(2259, 0, "Chirp Disc", "minecraft:record_chirp");
    MU static constexpr auto DISC_FAR = Item(2260, 0, "Far Disc", "minecraft:record_far");
    MU static constexpr auto DISC_MALL = Item(2261, 0, "Mall Disc", "minecraft:record_mall");
    MU static constexpr auto DISC_MELLOHI = Item(2262, 0, "Mellohi Disc", "minecraft:record_mellohi");
    MU static constexpr auto DISC_STAL = Item(2263, 0, "Stal Disc", "minecraft:record_stal");
    MU static constexpr auto DISC_STRAD = Item(2264, 0, "Strad Disc", "minecraft:record_strad");
    MU static constexpr auto WARD_DISC = Item(2265, 0, "Ward Disc", "minecraft:record_ward");
    MU static constexpr auto DISC_11 = Item(2266, 0, "11 Disc", "minecraft:record_11");
    MU static constexpr auto DISC_WAIT = Item(2267, 0, "Wait Disc", "minecraft:record_wait");
}
