cmake_minimum_required(VERSION 3.14)

set(PROJECT_NAME "StringUtils")
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)

# Disable the ZERO_CHECK project generation
set(CMAKE_SUPPRESS_REGENERATION true)

# Since googletest uses these flags we should too.
SET(CMAKE_CXX_FLAGS_DEBUG "/MTd")
SET(CMAKE_CXX_FLAGS_RELEASE "/MT")

add_subdirectory(vendor)
add_subdirectory(string_utils)
add_subdirectory(test_string_utils)