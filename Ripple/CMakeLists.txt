cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 20)

project(Ripple VERSION 0.1 DESCRIPTION "Simple 2D game engine for c++.")
include(GNUInstallDirs)

# Include dirs
# !Include dirs

# GLFW
# !GLFW

# GLAD
# !GLAD

# Ripple Library
add_library(Ripple SHARED Ripple.h Ripple.cpp)
# !Ripple Library