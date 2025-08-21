#pragma once

#include "processor.hpp"


static auto parseLabel(std::string_view s) -> std::pair<int, int> {
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
    int m_tu;
    std::string_view m_tu_str;

public:
    constexpr explicit TU(int tu, std::string_view tu_str)
        : m_tu(tu), m_tu_str(tu_str) {}

    ND const std::string_view& str() const { return m_tu_str; }

    ND constexpr int value() const { return m_tu; }

    auto operator<=>(const TU& other) const {
        return m_tu <=> other.m_tu;
    }

    bool operator==(const TU& other) const = default;
};


MU static constexpr TU TU_BASE = TU(-3, "everything");
MU static constexpr TU preTU0033 = TU(-2, "preTU0033");
MU static constexpr TU preTU0035 = TU(-1, "preTU0035");
MU static constexpr TU TU00 = TU(0, "TU00");
MU static constexpr TU TU01 = TU(1, "TU01");
MU static constexpr TU TU02 = TU(2, "TU02");
MU static constexpr TU TU03 = TU(3, "TU03");
MU static constexpr TU TU04 = TU(4, "TU04");
MU static constexpr TU TU05 = TU(5, "TU05");
MU static constexpr TU TU06 = TU(6, "TU06");
MU static constexpr TU TU07 = TU(7, "TU07");
MU static constexpr TU TU08 = TU(8, "TU08");
MU static constexpr TU TU09 = TU(9, "TU09");
MU static constexpr TU TU10 = TU(10, "TU10");
MU static constexpr TU TU11 = TU(11, "TU11");
MU static constexpr TU TU12 = TU(12, "TU12");
MU static constexpr TU TU13 = TU(13, "TU13");
MU static constexpr TU TU14 = TU(14, "TU14");
MU static constexpr TU TU15 = TU(15, "TU15");
MU static constexpr TU TU16 = TU(16, "TU16");
MU static constexpr TU TU17 = TU(17, "TU17");
MU static constexpr TU TU18 = TU(18, "TU18");
MU static constexpr TU TU19 = TU(19, "TU19");
MU static constexpr TU TU20 = TU(20, "TU20");
MU static constexpr TU TU21 = TU(21, "TU21");
MU static constexpr TU TU22 = TU(22, "TU22");
MU static constexpr TU TU23 = TU(23, "TU23");
MU static constexpr TU TU24 = TU(24, "TU24");
MU static constexpr TU TU25 = TU(25, "TU25");
MU static constexpr TU TU26 = TU(26, "TU26");
MU static constexpr TU TU27 = TU(27, "TU27");
MU static constexpr TU TU28 = TU(28, "TU28");
MU static constexpr TU TU29 = TU(29, "TU29");
MU static constexpr TU TU30 = TU(30, "TU30");
MU static constexpr TU TU31 = TU(31, "TU31");
MU static constexpr TU TU32 = TU(32, "TU32");
MU static constexpr TU TU33 = TU(33, "TU33");
MU static constexpr TU TU34 = TU(34, "TU34");
MU static constexpr TU TU35 = TU(35, "TU35");
MU static constexpr TU TU36 = TU(36, "TU36");
MU static constexpr TU TU37 = TU(37, "TU37");
MU static constexpr TU TU38 = TU(38, "TU38");
MU static constexpr TU TU39 = TU(39, "TU39");
MU static constexpr TU TU40 = TU(40, "TU40");
MU static constexpr TU TU41 = TU(41, "TU41");
MU static constexpr TU TU42 = TU(42, "TU42");
MU static constexpr TU TU43 = TU(43, "TU43");
MU static constexpr TU TU44 = TU(44, "TU44");
MU static constexpr TU TU45 = TU(45, "TU45");
MU static constexpr TU TU46 = TU(46, "TU46");
MU static constexpr TU TU47 = TU(47, "TU47");
MU static constexpr TU TU48 = TU(48, "TU48");
MU static constexpr TU TU49 = TU(49, "TU49");
MU static constexpr TU TU50 = TU(50, "TU50");
MU static constexpr TU TU51 = TU(51, "TU51");
MU static constexpr TU TU52 = TU(52, "TU52");
MU static constexpr TU TU53 = TU(53, "TU53");
MU static constexpr TU TU54 = TU(54, "TU54");
MU static constexpr TU TU55 = TU(55, "TU55");
MU static constexpr TU TU56 = TU(56, "TU56");
MU static constexpr TU TU57 = TU(57, "TU57");
MU static constexpr TU TU58 = TU(58, "TU58");
MU static constexpr TU TU59 = TU(59, "TU59");
MU static constexpr TU TU60 = TU(60, "TU60");
MU static constexpr TU TU61 = TU(61, "TU61");
MU static constexpr TU TU62 = TU(62, "TU62");
MU static constexpr TU TU63 = TU(63, "TU63");
MU static constexpr TU TU64 = TU(64, "TU64");
MU static constexpr TU TU65 = TU(65, "TU65");
MU static constexpr TU TU66 = TU(66, "TU66");
MU static constexpr TU TU67 = TU(67, "TU67");
MU static constexpr TU TU68 = TU(68, "TU68");
MU static constexpr TU TU69 = TU(69, "TU69");

MU static constexpr TU TU83 = TU(83, "TU83");
MU static constexpr TU TU88 = TU(88, "TU88");
MU static constexpr TU TU90 = TU(90, "TU90");
MU static constexpr TU TU91 = TU(91, "TU91");

MU static constexpr TU TU_UNKNOWN = TU(255, "TU_UNKNOWN");