cmake_minimum_required(VERSION 3.17)
project(Ripple VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_library(Ripple STATIC Ripple.hpp src/rppch.hpp)

set_target_properties(
        Ripple
        PROPERTIES
            CXX_STANDARD 20
            CXX_EXTENSION NO
)

add_subdirectory(vendor/glfw)
target_link_libraries(Ripple PRIVATE glfw)

add_subdirectory(vendor/glad)
target_link_libraries(Ripple PRIVATE glad)
target_include_directories(Ripple PUBLIC vendor/glad/include)

add_subdirectory(vendor/glm)
target_link_libraries(Ripple PRIVATE glm)

target_include_directories(Ripple PUBLIC src)
target_include_directories(Ripple PUBLIC vendor)

target_precompile_headers(Ripple PRIVATE src/rppch.hpp)