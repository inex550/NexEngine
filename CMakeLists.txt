cmake_minimum_required(VERSION 3.12)

project(NexEngine)

add_subdirectory(external/glad)
add_subdirectory(external/glfw)
add_subdirectory(external/imgui)
add_subdirectory(external/spdlog)
add_subdirectory(external/stb)

add_subdirectory(NexMath)
add_subdirectory(NexCore)