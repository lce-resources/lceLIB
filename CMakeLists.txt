# Gathers all lce sources
file(GLOB_RECURSE LCE_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
)

# Propagate sources to parent scope
set(LCE_SOURCES ${LCE_SOURCES} PARENT_SCOPE)

# Propagate include dir to parent
set(LCE_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/.." PARENT_SCOPE)

# Propagate compile options and definitions
set(LCE_COMPILE_OPTIONS -mavx2 -mpopcnt PARENT_SCOPE)
set(LCE_COMPILE_DEFINITIONS DEV_MODE PARENT_SCOPE)

# Precompiled header — propagate only if desired
set(LCE_PCH "${CMAKE_CURRENT_SOURCE_DIR}/processor.hpp" PARENT_SCOPE)

# Asset handling
set(LCE_ASSETS_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/assets" PARENT_SCOPE)

if (DEFINED CMAKE_RUNTIME_OUTPUT_DIRECTORY)
    set(LCE_ASSETS_DEST_DIR "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets/lce" PARENT_SCOPE)
else()
    set(LCE_ASSETS_DEST_DIR "$<JOIN:$<TARGET_FILE_DIR:BatchConverter>,/assets/lce>" PARENT_SCOPE)
endif()