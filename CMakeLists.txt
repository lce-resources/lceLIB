cmake_minimum_required(VERSION 3.24)
project(LIB_lce)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Gather all source files in lce
file(GLOB_RECURSE LCE_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
)

add_library(LIB_lce STATIC ${LCE_SOURCES})

# target_precompile_headers(LIB_lce PRIVATE
#         ${CMAKE_CURRENT_SOURCE_DIR}/processor.hpp
# )

target_include_directories(LIB_lce
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
)

# -include ${CMAKE_CURRENT_SOURCE_DIR}/processor.hpp
target_compile_options(LIB_lce PUBLIC -mavx2 -mpopcnt)
add_definitions(-DDEV_MODE)
