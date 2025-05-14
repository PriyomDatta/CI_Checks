cmake_minimum_required(VERSION 3.10)

# Project name
project(Module_01)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(
    Interface/inc
    Mod/inc
)

# Source files
set(SOURCES
    Interface/src/intf.cpp
    Mod/src/Mod_000.cpp
)

# Add the library
add_library(Module_01_lib ${SOURCES})

# Make the library available for other modules
target_include_directories(Module_01_lib PUBLIC
    Interface/inc
    Mod/inc
)