cmake_minimum_required(VERSION 3.17)
project(Sandbox)

set(CMAKE_CXX_STANDARD 20)

add_executable(Sandbox main.cpp)

target_link_libraries(Sandbox PUBLIC Ripple)