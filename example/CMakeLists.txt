project(AlmondeoVideoPlayer)
find_package(PkgConfig REQUIRED)
add_executable(main main.cpp)
message("PATH is " $(CMAKE_CURRENT_SOURCE_DIR))
#target_include_directories(main
#    PUBLIC 
#    $(CMAKE_CURRENT_SOURCE_DIR)/../lib/glfw)
pkg_check_modules(GLFW REQUIRED glfw3)
pkg_check_modules(OPENGL2 REQUIRED opengl)

set(IMGUI_LIBRARIES imgui;imgui_backends;glfw;OpenGL)
target_link_libraries(main
    PRIVATE
    ${IMGUI_LIBRARIES}
    )

