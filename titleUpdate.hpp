#pragma once

#include "processor.hpp"


MU static auto parseLabel(std::string_view s) -> std::pair<int, int> {
    int cat = 2;    // default = “other”
    size_t pos = 0; // position where the digits start

    if (s.starts_with("preTU")) {
        cat = 0;
        pos = 5; // skip "preTU"
    } else if (s.starts_with("TU")) {
        cat = 1;
        pos = 2; // skip "TU"
    }

    int num = 0;
    while (pos < s.size() && std::isdigit(s[pos]))
        num = num * 10 + (s[pos++] - '0');

    return {cat, num};
}


class TU {
    std::string_view m_tu_str;
    int m_tu;

public:
    constexpr explicit TU(std::string_view tu_str, int tu)
        : m_tu_str(tu_str), m_tu(tu) {}

    ND const std::string_view& str() const { return m_tu_str; }

    ND constexpr int value() const { return m_tu; }

    auto operator<=>(const TU& other) const {
        return m_tu <=> other.m_tu;
    }

    bool operator==(const TU& other) const = default;
};


MU static constexpr TU TU_BASE = TU("everything", -3);
MU static constexpr TU preTU0033 = TU("preTU0033", -2);
MU static constexpr TU preTU0035 = TU("preTU0035", -1);
MU static constexpr TU TU00 = TU("TU00", 0);
MU static constexpr TU TU01 = TU("TU01", 1);
MU static constexpr TU TU02 = TU("TU02", 2);
MU static constexpr TU TU03 = TU("TU03", 3);
MU static constexpr TU TU04 = TU("TU04", 4);
MU static constexpr TU TU05 = TU("TU05", 5);
MU static constexpr TU TU06 = TU("TU06", 6);
MU static constexpr TU TU07 = TU("TU07", 7);
MU static constexpr TU TU08 = TU("TU08", 8);
MU static constexpr TU TU09 = TU("TU09", 9);
MU static constexpr TU TU10 = TU("TU10", 10);
MU static constexpr TU TU11 = TU("TU11", 11);
MU static constexpr TU TU12 = TU("TU12", 12);
MU static constexpr TU TU13 = TU("TU13", 13);
MU static constexpr TU TU14 = TU("TU14", 14);
MU static constexpr TU TU15 = TU("TU15", 15);
MU static constexpr TU TU16 = TU("TU16", 16);
MU static constexpr TU TU17 = TU("TU17", 17);
MU static constexpr TU TU18 = TU("TU18", 18);
MU static constexpr TU TU19 = TU("TU19", 19);
MU static constexpr TU TU20 = TU("TU20", 20);
MU static constexpr TU TU21 = TU("TU21", 21);
MU static constexpr TU TU22 = TU("TU22", 22);
MU static constexpr TU TU23 = TU("TU23", 23);
MU static constexpr TU TU24 = TU("TU24", 24);
MU static constexpr TU TU25 = TU("TU25", 25);
MU static constexpr TU TU26 = TU("TU26", 26);
MU static constexpr TU TU27 = TU("TU27", 27);
MU static constexpr TU TU28 = TU("TU28", 28);
MU static constexpr TU TU29 = TU("TU29", 29);
MU static constexpr TU TU30 = TU("TU30", 30);
MU static constexpr TU TU31 = TU("TU31", 31);
MU static constexpr TU TU32 = TU("TU32", 32);
MU static constexpr TU TU33 = TU("TU33", 33);
MU static constexpr TU TU34 = TU("TU34", 34);
MU static constexpr TU TU35 = TU("TU35", 35);
MU static constexpr TU TU36 = TU("TU36", 36);
MU static constexpr TU TU37 = TU("TU37", 37);
MU static constexpr TU TU38 = TU("TU38", 38);
MU static constexpr TU TU39 = TU("TU39", 39);
MU static constexpr TU TU40 = TU("TU40", 40);
MU static constexpr TU TU41 = TU("TU41", 41);
MU static constexpr TU TU42 = TU("TU42", 42);
MU static constexpr TU TU43 = TU("TU43", 43);
MU static constexpr TU TU44 = TU("TU44", 44);
MU static constexpr TU TU45 = TU("TU45", 45);
MU static constexpr TU TU46 = TU("TU46", 46);
MU static constexpr TU TU47 = TU("TU47", 47);
MU static constexpr TU TU48 = TU("TU48", 48);
MU static constexpr TU TU49 = TU("TU49", 49);
MU static constexpr TU TU50 = TU("TU50", 50);
MU static constexpr TU TU51 = TU("TU51", 51);
MU static constexpr TU TU52 = TU("TU52", 52);
MU static constexpr TU TU53 = TU("TU53", 53);
MU static constexpr TU TU54 = TU("TU54", 54);
MU static constexpr TU TU55 = TU("TU55", 55);
MU static constexpr TU TU56 = TU("TU56", 56);
MU static constexpr TU TU57 = TU("TU57", 57);
MU static constexpr TU TU58 = TU("TU58", 58);
MU static constexpr TU TU59 = TU("TU59", 59);
MU static constexpr TU TU60 = TU("TU60", 60);
MU static constexpr TU TU61 = TU("TU61", 61);
MU static constexpr TU TU62 = TU("TU62", 62);
MU static constexpr TU TU63 = TU("TU63", 63);
MU static constexpr TU TU64 = TU("TU64", 64);
MU static constexpr TU TU65 = TU("TU65", 65);
MU static constexpr TU TU66 = TU("TU66", 66);
MU static constexpr TU TU67 = TU("TU67", 67);
MU static constexpr TU TU68 = TU("TU68", 68);
MU static constexpr TU TU69 = TU("TU69", 69);

MU static constexpr TU TU83 = TU("TU83", 83);
MU static constexpr TU TU88 = TU("TU88", 88);
MU static constexpr TU TU90 = TU("TU90", 90);
MU static constexpr TU TU91 = TU("TU91", 91);

MU static constexpr TU TU_UNKNOWN = TU("TU_UNKNOWN", 255);
