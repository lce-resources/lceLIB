#pragma once

#include <cinttypes>
#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <vector>
#include <string>

///=============================================================================
///                      Compiler and Platform Features
///=============================================================================

#if __GNUC__
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

#define ND [[nodiscard]]
#define MU [[maybe_unused]]

#define c_int const int
#define c_bool const bool
#define c_auto const auto
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
static int printf_err(const char* format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    return -1;
}


/// printf, but returns -1.
static int printf_err(const std::string& format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format.c_str(), args);
    va_end(args);
    return -1;
}
