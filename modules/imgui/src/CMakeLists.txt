project(AlmondeoVideoPlayer)
option(BUILD_SHARED_LIBS "Shared lib" ON)
SET(CMAKE_CXX_FLAGS "-fpermissive")
add_subdirectory(backends)
add_library(imgui 
    imgui_draw.cpp
    imgui_demo.cpp
    imgui_tables.cpp
    imgui_widgets.cpp
    imgui.cpp)
target_include_directories(imgui
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../inc/imgui
    ${CMAKE_CURRENT_SOURCE_DIR}/../inc/imgui/backends
    )
