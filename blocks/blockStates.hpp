#pragma once

#include "lce/processor.hpp"
#include "lce/enums.hpp"


template <class T>
    static constexpr i32 cast(const T value) { return static_cast<i32>(value); }


namespace lce::blocks::states {

    enum class Half : u8 {
        Lower = 0,
        Upper = 1
    };

    enum class Hinge : u8 {
        Left = 0,
        Right = 1,
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
        static constexpr i32 withProperty(const EnumAxis axis = EnumAxis::Y) {
            return cast(axis) << 2;
        }

        static constexpr i32 withProperty(const u8 variantData, const EnumAxis axis = EnumAxis::Y) {
            return cast(axis) << 2 | variantData;
        }
    };


    class Stairs {
    public:
        /// reverse facing index but for horizontal only
        /// east, west, south, north, up, down
        MU static constexpr i32 getMetaFromFacing(const EnumFacing facing) {
            switch (facing) {
                case EnumFacing::UP:
                case EnumFacing::DOWN:
                case EnumFacing::NORTH:
                    return 3;
                case EnumFacing::SOUTH:
                    return 2;
                case EnumFacing::WEST:
                    return 1;
                case EnumFacing::EAST:
                // default:
                    return 0;
            }
            std::unreachable();
        }

        static constexpr i32 withProperty(
                const EnumFacing facing = EnumFacing::SOUTH,
                const Half half = Half::Lower) {
            return cast(half) << 3 | getMetaFromFacing(facing);
        }
    };


    class Vine {
        static constexpr i32 getMetaFromFacing(
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
                case EnumFacing::UP:
                case EnumFacing::DOWN:
                default:
                    return 0;
            }
        }

    public:
        static constexpr i32 withProperty(
                const EnumFacing facing) {
            return getMetaFromFacing(facing);
        }
    };


    class Button {
        /// custom 6-way facing
        static constexpr i32 getMetaFromFacing(
                const EnumFacing facing) {
            switch (facing) {
                case EnumFacing::UP:
                default:
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
            }
        }
    public:

        static constexpr i32 withProperty(
                const EnumFacing facing = EnumFacing::DOWN,
                const Powered powered = Powered::False) {
            return cast(powered) << 3 | getMetaFromFacing(facing);
        }
    };

    class Ladder {
        /// facing index but for horizontal only
        /// down, up, north, south, west, east
        static constexpr i32 getMetaFromFacing(
                const EnumFacing facing) {
            switch (facing) {
                default:
                case EnumFacing::DOWN:
                case EnumFacing::UP:
                case EnumFacing::NORTH:
                    return 2;
                case EnumFacing::SOUTH:
                    return 3;
                case EnumFacing::WEST:
                    return 4;
                case EnumFacing::EAST:
                    return 5;
            }
        }

    public:
        static constexpr i32 withProperty(
                const EnumFacing facing = EnumFacing::NORTH) {
            return getMetaFromFacing(facing);
        }
    };



    class DoorUpper {
    public:
        static constexpr i32 withProperty(
                const Hinge hinge = Hinge::Left,
                const Powered powered = Powered::False) {
            return 1 << 3 | cast(powered) << 1 | cast(hinge);
        }
    };


    class DoorLower {
        /// horizontal facing index rotated cw
        static constexpr i32 getMetaFromFacing(
                const EnumFacing facing) {
            switch (facing) {
                default:
                case EnumFacing::UP:
                case EnumFacing::DOWN:
                case EnumFacing::NORTH:
                    return 3;
                case EnumFacing::SOUTH:
                    return 1;
                case EnumFacing::WEST:
                    return 2;
                case EnumFacing::EAST:
                    return 0;
            }
        }

    public:
        static constexpr i32 withProperty(
                const EnumFacing facing = EnumFacing::EAST,
                const Open open = Open::False) {
            return (0 << 3) | (cast(open) << 2) | getMetaFromFacing(facing);
        }
    };


    class Torch {
        /// custom 5-way facing
        static constexpr i32 getMetaFromFacing(
                const EnumFacing facing) {
            switch (facing) {
                default:
                case EnumFacing::UP:
                case EnumFacing::DOWN:
                    return 5;
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
        static constexpr i32 withProperty(
                const EnumFacing facing = EnumFacing::DOWN) {
            return getMetaFromFacing(facing);
        }
    };


    class TrapDoor {
    public:
        static constexpr i32 withProperty(
                const EnumFacing facing = EnumFacing::NORTH,
                const Half half = Half::Lower, const Open open = Open::False) {
            return cast(half) << 3 | cast(open) << 2 | cast(facing) >> 1;
        }
    };


    class FenceGate {
        static constexpr i32 getMetaFromFacing(
                const EnumFacing facing) {
            switch (facing) {
                default:
                case EnumFacing::UP:
                case EnumFacing::DOWN:
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

        static constexpr i32 withProperty(
                const EnumFacing facing = EnumFacing::SOUTH,
                const Open open = Open::False, const Powered powered = Powered::False) {
            return cast(powered) << 3 | cast(open) << 2 | getMetaFromFacing(facing);
        }
    };


    class Piston {
    public:
        static constexpr i32 withProperty(
                const EnumFacing facing = EnumFacing::UP,
                const PistonExtended extended = PistonExtended::False) {
            return cast(extended) << 3 | cast(facing);
        }
    };


    class PistonHead {
    public:
        static constexpr i32 withProperty(
                const EnumFacing facing = EnumFacing::UP,
                const PistonHeadType type = PistonHeadType::False) {
            return cast(type) << 3 | cast(facing);
        }
    };


    class Rail {
    public:
        static constexpr i32 withProperty(
                const RailShape shape) {
            return cast(shape);
        }
    };


    class PoweredRail {
    public:
        static constexpr i32 withProperty(
                const PoweredRailShape shape,
                const Powered powered = Powered::False) {
            return cast(powered) << 3 | cast(shape);
        }
    };


    class EndPortalFrame {
        /// horizontal facing index
        static constexpr i32 getMetaFromFacing(
                const EnumFacing facing) {
            switch (facing) {
                default:
                case EnumFacing::UP:
                case EnumFacing::DOWN:
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
        static constexpr i32 withProperty(const EnumFacing facing, const bool eye) {
            return cast(eye) << 2 | getMetaFromFacing(facing);
        }

        static constexpr i32 withProperty(const EnumFacing facing = EnumFacing::NORTH) {
            return getMetaFromFacing(facing);
        }

        static constexpr i32 withProperty(const int facingData, const bool eye) {
            return cast(eye) << 2 | facingData;
        }
    };

}
