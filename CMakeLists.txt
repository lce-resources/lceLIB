




file(GLOB_RECURSE LCE_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

set(LCE_SOURCES            "${LCE_SOURCES}"                       PARENT_SCOPE)
set(LCE_INCLUDE_DIR        "${CMAKE_CURRENT_SOURCE_DIR}/.."       PARENT_SCOPE)

if (MSVC)
    set(LCE_COMPILE_OPTIONS "/arch:AVX2")
else()
    set(LCE_COMPILE_OPTIONS "-mavx2;-mpopcnt")
endif()

set(LCE_COMPILE_DEFINITIONS "DEV_MODE"                            PARENT_SCOPE)
set(LCE_PCH               "${CMAKE_CURRENT_SOURCE_DIR}/processor.hpp" PARENT_SCOPE)

# only the *source* of the assets is inherent to the module
set(LCE_ASSETS_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/assets" PARENT_SCOPE)
set(LCE_ASSETS_DEST_DIR "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets/lce" PARENT_SCOPE)