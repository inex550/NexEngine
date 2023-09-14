cmake_minimum_required(VERSION 3.12)

project(ImGui)

add_library(imgui STATIC
    imconfig.h
    imgui_demo.cpp
    imgui_draw.cpp
    imgui_internal.h
    imgui_tables.cpp
    imgui_widgets.cpp
    imgui.cpp
    imgui.h
    imstb_rectpack.h
    imstb_textedit.h
    imstb_truetype.h

    backends/imgui_impl_glfw.cpp
    backends/imgui_impl_glfw.h
    backends/imgui_impl_opengl3.cpp
    backends/imgui_impl_opengl3.h
)

target_include_directories(imgui PUBLIC .)

target_link_libraries(imgui PRIVATE glfw)