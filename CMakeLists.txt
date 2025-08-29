cmake_minimum_required(VERSION 3.10)
project(Lab2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add src directory for includes
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/external)

# Create benchmark executable
add_executable(benchmark
    src/benchmark.cpp
    src/power.cpp
)

# Create test executable
add_executable(test_power
    tests/test_power.cpp
    src/power.cpp
)

# Add include dirs for test_power target (so it finds catch.hpp and power.hpp)
target_include_directories(test_power PRIVATE
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/external
)

# Optionally add compiler warnings (recommended)
target_compile_options(test_power PRIVATE -Wall -Wextra -pedantic)
target_compile_options(benchmark PRIVATE -Wall -Wextra -pedantic)