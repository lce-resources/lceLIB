cmake_minimum_required(VERSION 3.24)
project(lceLib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Gather all source files in lce
file(GLOB_RECURSE LCE_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
)

add_library(lceLib STATIC ${LCE_SOURCES})


target_include_directories(lceLib
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
)


target_compile_options(lceLib PUBLIC -mavx2 -mpopcnt)
add_definitions(-DDEV_MODE)
