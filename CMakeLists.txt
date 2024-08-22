# Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(NES_Emulator)

# Set C standard to C99
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Include directories
include_directories("include" "include/cpu")

# Find all .c files in the src directory
file(GLOB SOURCES "src/*.c" "src/cpu/*c")

# Add the executable
add_executable(nes_emulator ${SOURCES})

# Optional: Add compiler flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")