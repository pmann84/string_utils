cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_NAME "string_utils")

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")
target_sources(${PROJECT_NAME} INTERFACE "string_utils.h")