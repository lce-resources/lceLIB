#pragma once

#include "lce/processor.hpp"
#include "lce/enums.hpp"


template <class T>
    static i32 cast(const T value) { return static_cast<i32>(value); }


namespace lce::blocks::states {

    enum class Half : u8 {
        Lower = 0,
        Upper = 1
    };

    enum class Hinge : u8 {
        Val0 = 0,
        Val1 = 1,
    };

    enum class Powered : u8 {
        False = 0,
        True = 1
    };

    enum class Open : u8 {
        False = 0,
        True = 1
    };

    enum class PistonExtended : u8 {
        False = 0,
        True = 1
    };

    enum class PistonHeadType : u8 {
        False = 0,
        True = 1
    };

    enum class RailShape : u8 {
        NS = 0,
        EW = 1,
        AE = 2,
        AW = 3,
        AN = 4,
        AS = 5,
        SE = 6,
        SW = 7,
        NW = 8,
        NE = 9,
    };

    enum class PoweredRailShape : u8 {
        NS = 0,
        EW = 1,
        AE = 2,
        AW = 3,
        AN = 4,
        AS = 5,
    };







    class Log {
    public:
        static i32 withProperty(const EnumAxis axis = EnumAxis::Y) {
            return cast(axis) << 2;
        }

        static i32 withProperty(const u8 variantData, const EnumAxis axis = EnumAxis::Y) {
            return cast(axis) << 2 | variantData;
        }
    };


    class Stairs {
    public:
        static int getMetaFromFacing(const EnumFacing facing) {
            switch (facing) {
                case EnumFacing::NORTH:
                    return 3;
                case EnumFacing::SOUTH:
                    return 2;
                case EnumFacing::WEST:
                    return 1;
                case EnumFacing::EAST:
                default:
                    return 0;
            }
        }

        static i32 withProperty(
                const EnumFacing facing = EnumFacing::SOUTH,
                const Half half = Half::Lower) {
            return cast(half) << 3 | getMetaFromFacing(facing);
        }
    };


    class Vine {
        static int getMetaFromFacing(
                const EnumFacing facing) {
            switch (facing) {
                case EnumFacing::SOUTH:
                    return 1;
                case EnumFacing::WEST:
                    return 2;
                case EnumFacing::NORTH:
                    return 4;
                case EnumFacing::EAST:
                    return 8;
                default:
                    return 0;
            }
        }

    public:
        static i32 withProperty(
                const EnumFacing facing) {
            return getMetaFromFacing(facing);
        }
    };


    class Button {
        static int getMetaFromFacing(
                const EnumFacing facing) {
            switch (facing) {
                case EnumFacing::UP:
                    return 5;
                case EnumFacing::DOWN:
                    return 0;
                case EnumFacing::NORTH:
                    return 4;
                case EnumFacing::SOUTH:
                    return 3;
                case EnumFacing::WEST:
                    return 2;
                case EnumFacing::EAST:
                    return 1;
                default:
                    return 0;
            }
        }
    public:

        static i32 withProperty(
                const EnumFacing facing = EnumFacing::DOWN,
                const Powered powered = Powered::False) {
            return cast(powered) << 3 | getMetaFromFacing(facing);
        }
    };

    class Ladder {
        /// HorizontalFacing5
        /// north, south, west, east
        static int getMetaFromFacing(
                const EnumFacing facing) {
            switch (facing) {
                default:
                case EnumFacing::NORTH:
                    return 0;
                case EnumFacing::SOUTH:
                    return 1;
                case EnumFacing::WEST:
                    return 2;
                case EnumFacing::EAST:
                    return 3;
            }
        }

    public:
        static i32 withProperty(
                const EnumFacing facing = EnumFacing::NORTH) {
            return getMetaFromFacing(facing);
        }
    };



    class DoorUpper {
    public:
        static i32 withProperty(
                const Hinge hinge = Hinge::Val0,
                const Powered powered = Powered::False) {
            return 1 << 3 | cast(powered) << 1 | cast(hinge);
        }
    };


    class DoorLower {
        static int getMetaFromFacing(
                const EnumFacing facing) {
            switch (facing) {
                default:
                case EnumFacing::NORTH:
                    return 0;
                case EnumFacing::SOUTH:
                    return 1;
                case EnumFacing::WEST:
                    return 2;
                case EnumFacing::EAST:
                    return 3;
            }
        }

    public:
        static i32 withProperty(
                const EnumFacing facing = EnumFacing::EAST,
                const Open open = Open::False) {
            return 0 << 3 | cast(open) << 2 | getMetaFromFacing(facing);
        }
    };


    class Torch {
        static int getMetaFromFacing(
                const EnumFacing facing) {
            switch (facing) {
                case EnumFacing::UP:
                default:
                    return 0;
                case EnumFacing::EAST:
                    return 1;
                case EnumFacing::WEST:
                    return 2;
                case EnumFacing::SOUTH:
                    return 3;
                case EnumFacing::NORTH:
                    return 4;
            }
        }

    public:
        static i32 withProperty(
                const EnumFacing facing = EnumFacing::DOWN) {
            return getMetaFromFacing(facing);
        }
    };


    class TrapDoor {
    public:
        static i32 withProperty(
                const EnumFacing facing = EnumFacing::NORTH,
                const Half half = Half::Lower, const Open open = Open::False) {
            return cast(half) << 3 | cast(open) << 2 | cast(facing) >> 1;
        }
    };


    class FenceGate {
        static int getMetaFromFacing(
                const EnumFacing facing) {
            switch (facing) {
                default:
                case EnumFacing::SOUTH:
                    return 0;
                case EnumFacing::WEST:
                    return 1;
                case EnumFacing::NORTH:
                    return 2;
                case EnumFacing::EAST:
                    return 3;
            }
        }
    public:

        static i32 withProperty(
                const EnumFacing facing = EnumFacing::SOUTH,
                const Open open = Open::False, const Powered powered = Powered::False) {
            return cast(powered) << 3 | cast(open) << 2 | getMetaFromFacing(facing);
        }
    };


    class Piston {
    public:
        static i32 withProperty(
                const EnumFacing facing = EnumFacing::UP,
                const PistonExtended extended = PistonExtended::False) {
            return cast(extended) << 3 | cast(facing);
        }
    };


    class PistonHead {
    public:
        static i32 withProperty(
                const EnumFacing facing = EnumFacing::UP,
                const PistonHeadType type = PistonHeadType::False) {
            return cast(type) << 3 | cast(facing);
        }
    };


    class Rail {
    public:
        static i32 withProperty(
                const RailShape shape) {
            return cast(shape);
        }
    };


    class PoweredRail {
    public:
        static i32 withProperty(
                const PoweredRailShape shape,
                const Powered powered = Powered::False) {
            return cast(powered) << 3 | cast(shape);
        }
    };


    class EndPortalFrame {
        static int getMetaFromFacing(
                const EnumFacing facing) {
            switch (facing) {
                default:
                case EnumFacing::SOUTH:
                    return 0;
                case EnumFacing::WEST:
                    return 1;
                case EnumFacing::NORTH:
                    return 2;
                case EnumFacing::EAST:
                    return 3;
            }
        }

    public:
        static i32 withProperty(const EnumFacing facing, const bool eye) {
            return cast(eye) << 2 | getMetaFromFacing(facing);
        }

        static i32 withProperty(const EnumFacing facing = EnumFacing::NORTH) {
            return getMetaFromFacing(facing);
        }

        static i32 withProperty(const int facingData, const bool eye) {
            return cast(eye) << 2 | facingData;
        }
    };

}