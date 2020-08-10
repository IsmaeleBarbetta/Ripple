cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 20)

project(Ripple VERSION 0.1 DESCRIPTION "Simple 2D game engine for c++.")
include(GNUInstallDirs)

# Ripple Library
add_library(Ripple SHARED src/Ripple.h src/Ripple/Log/Log.cpp src/Ripple/Log/Log.h src/rpph.h)
# !Ripple Library

# Include dirs
target_include_directories(Ripple PUBLIC src/Ripple)
# !Include dirs

# GLFW
# !GLFW

# GLAD
# !GLAD

# SPDLOG
target_include_directories(Ripple PUBLIC Vendor/spdlog/include)
# !SPDLOG

# PRECOMPILED HEADERS
target_precompile_headers(Ripple PRIVATE src/rpph.h)
# !PRECOMPILED HEADERS
