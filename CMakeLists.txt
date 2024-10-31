cmake_minimum_required(VERSION 3.13)
project(AlmondeoVideoPlayer)

add_subdirectory(modules)
#add_subdirectory(lib)

option(BUILD_EXAMPLES "Whether or not to build examples"
    ON)

if(BUILD_EXAMPLES)
    message(STATUS "Building examples...")
    add_subdirectory(example)
endif()
