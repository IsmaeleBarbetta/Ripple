cmake_minimum_required(VERSION 3.0)
project(Glad)

add_library(glad STATIC include/glad/glad.h include/KHR/khrplatform.h src/glad.c)
target_include_directories(glad PUBLIC include/)

set_property(TARGET glad PROPERTY POSITION_INDEPENDENT_CODE ON)