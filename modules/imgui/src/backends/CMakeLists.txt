project(AlmondeoVideoPlayer)
option(BUILD_SHARED_LIBS "Build using shared libraries" ON)
add_library(imgui_backends 
    imgui_impl_opengl3.cpp
    imgui_impl_glfw.cpp
    )
target_include_directories(imgui_backends
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../../inc/imgui 
    ${CMAKE_CURRENT_SOURCE_DIR}/../../inc/imgui/backends
    )
