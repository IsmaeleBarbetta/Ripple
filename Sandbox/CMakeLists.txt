cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 20)

project(Sandbox VERSION 0.1 DESCRIPTION "Sandbox Application for the Ripple Engine.")

# Sandbox Example
add_executable(Sandbox src/main.cpp)
# !Sandbox Example

# Include dirs
target_include_directories(Sandbox PRIVATE "../Ripple/src")
# !Include dirs

# Libraries
target_link_libraries(Sandbox Ripple)
# !Libraries
