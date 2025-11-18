#pragma once

#include <cstdint>
#include <cstdlib>
#include <cstdarg>
#include <cstdio>

#include <fstream>
#include <iostream>

#include <unordered_map>
#include <unordered_set>
#include <list>
#include <vector>
#include <map>
#include <array>
#include <set>
#include <span>

#include <string>
#include <string_view>
#include <cstring>

#include <stdexcept>
#include <algorithm>
#include <utility>
#include <memory>

#include <cassert>
#include <functional>
#include <optional>
#include <variant>

#include "enums.hpp"





///=============================================================================
///                      Compiler and Platform Features
///=============================================================================

#if __GNUC__
#define RESTRICT __restrict__
#define PREFETCH(PTR, RW, LOC) __builtin_prefetch(PTR, RW, LOC)
#define EXPECT_FALSE(COND) (__builtin_expect((COND), 0)) // [unlikely]
#define EXPECT_TRUE(COND) (__builtin_expect((COND), 1))  // [likely]
#define ATTR(...) __attribute__((__VA_ARGS__))
#else
#define PREFETCH(PTR, RW, LOC)
#define EXPECT_FALSE(COND) (COND) [[unlikely]]
#define EXPECT_TRUE(COND) (COND) [[likely]]
#define ATTR(...)
#endif


constexpr int ctz_constexpr(uint32_t x) noexcept {
    int i = 0;
    while ((x & 1u) == 0u && i < 32) {
        x >>= 1u;
        ++i;
    }
    return i;
}


constexpr int ctzll_constexpr(uint64_t x) noexcept {
    int i = 0;
    while ((x & 1u) == 0u && i < 64) {
        x >>= 1u;
        ++i;
    }
    return i;
}


#if defined(_MSC_VER)
    #define NOINLINE __declspec(noinline)
    #define FORCEINLINE __forceinline
    inline constexpr int CTZ(uint32_t x) noexcept {
        if (std::is_constant_evaluated()) {
            return ctz_constexpr(x);
        } else {
            unsigned long index;
            _BitScanForward(&index, x);
            return static_cast<int>(index);
        }
    }

    // 64-bit overload
    inline constexpr int CTZLL(uint64_t x) noexcept {
        if (std::is_constant_evaluated()) {
            return ctzll_constexpr(x);
        } else {
            unsigned long index;
        #if defined(_M_X64) || defined(_M_AMD64) || defined(_M_ARM64)
            // If x == 0, _BitScanForward64 is undefined; guard if needed.
            _BitScanForward64(&index, x);
            return static_cast<int>(index);
        #else
            // 32-bit target: emulate with two 32-bit scans
            uint32_t lo = static_cast<uint32_t>(x);
            if (lo) {
                _BitScanForward(&index, lo);
                return static_cast<int>(index);
            }
            uint32_t hi = static_cast<uint32_t>(x >> 32);
            // If hi == 0 too, x was 0; decide on your policy (e.g., return 64).
            _BitScanForward(&index, hi);
            return static_cast<int>(index + 32);
        #endif
        }
    }
#elif defined(__GNUC__) || defined(__clang__)
    #define NOINLINE __attribute__((noinline))
    #if !defined(FORCEINLINE)
        #define FORCEINLINE inline __attribute__((always_inline))
    #endif
    constexpr int CTZ(uint32_t x) noexcept {
        return std::is_constant_evaluated() ? ctz_constexpr(x) : __builtin_ctz(x);
    }

    constexpr int CTZLL(uint64_t x) noexcept {
        return std::is_constant_evaluated() ? ctzll_constexpr(x) : __builtin_ctzll(x);
    }
#else
    #define FORCEINLINE inline
    constexpr int CTZ(uint32_t x) noexcept { return ctz_constexpr(x); }
    constexpr int CTZLL(uint64_t x) noexcept { return ctzll_constexpr(x); }
#endif

#define DELETE_NEW_OPS \
    void* operator new(std::size_t) = delete; \
    void* operator new[](std::size_t) = delete

#define ND [[nodiscard]]
#define MU [[maybe_unused]]

#define c_int const int
#define c_bool const bool
#define c_auto const auto
#define c_float const float
#define c_double const double
#define c_string_ref const std::string&

#define i8 int8_t
#define i16 int16_t
#define i32 int32_t
#define i64 int64_t

#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t
#define u64 uint64_t

#define c_i8 const int8_t
#define c_i16 const int16_t
#define c_i32 const int32_t
#define c_i64 const int64_t

#define c_u8 const uint8_t
#define c_u16 const uint16_t
#define c_u32 const uint32_t
#define c_u64 const uint64_t

#define i8_vec std::vector<int8_t>
#define i16_vec std::vector<int16_t>
#define i32_vec std::vector<int32_t>
#define i64_vec std::vector<int64_t>
#define i8_vec_vec std::vector<i8_vec>
#define i16_vec_vec std::vector<i16_vec>
#define i32_vec_vec std::vector<i32_vec>
#define i64_vec_vec std::vector<i64_vec>

#define u8_vec std::vector<uint8_t>
#define u16_vec std::vector<uint16_t>
#define u32_vec std::vector<uint32_t>
#define u64_vec std::vector<uint64_t>
#define u8_vec_vec std::vector<u8_vec>
#define u16_vec_vec std::vector<u16_vec>
#define u32_vec_vec std::vector<u32_vec>
#define u64_vec_vec std::vector<u64_vec>

/// printf, but returns -1.
#include <cstdarg>
#include <cstdio>
#include <vector>
#include <iostream>

// return_code kept, prints formatted message to stderr

template<typename... Args>
MU static int printf_err(int return_code, std::format_string<Args...> fmt, Args&&... args) {
    // produce the formatted string using std::format (type-safe)
    const std::string s = std::vformat(fmt.get(), std::make_format_args(std::forward<Args>(args)...));

    // write exactly the formatted bytes to stderr
    const char* data = s.data();
    size_t to_write = s.size();
    while (to_write > 0) {
        const size_t n = std::fwrite(data, 1, to_write, stderr);
        if (n == 0) break; // actual write error; you can inspect errno
        data += n;
        to_write -= n;
    }

    return return_code;
}
