cmake_minimum_required(VERSION 3.17)
project(RippleFull)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Ripple)
add_subdirectory(Sandbox)

target_include_directories(Sandbox PUBLIC Ripple)