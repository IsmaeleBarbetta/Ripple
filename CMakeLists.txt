cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_BUILD_TYPE}")

project(Ripple VERSION 0.1 DESCRIPTION "Simple 2D game engine for c++")

# Ripple Library
add_subdirectory("Ripple" "${CMAKE_BINARY_DIR}/Ripple")
# !Ripple Library

# Sandbox Example
add_subdirectory("Sandbox" "${CMAKE_BINARY_DIR}/Sandbox")
# !Sandbox Example