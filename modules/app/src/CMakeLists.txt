project(AlmondeoVideoPlayer)
find_package(PkgConfig REQUIRED)
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")
add_executable(app_framework main.cpp app_design.cpp)
message("PATH is " $(CMAKE_CURRENT_SOURCE_DIR))
pkg_check_modules(GLFW REQUIRED glfw3)
pkg_check_modules(OPENGL2 REQUIRED opengl)

set(IMGUI_LIBRARIES imgui;imgui_backends;glfw;OpenGL)
target_link_libraries(app_framework
    PRIVATE
    ${IMGUI_LIBRARIES}
    )
target_include_directories(app_framework
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../inc
    ${CMAKE_CURRENT_SOURCE_DIR}/../../stb_image/inc/
    /usr/include/
    )
