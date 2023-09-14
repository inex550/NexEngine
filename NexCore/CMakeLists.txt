cmake_minimum_required(VERSION 3.12)

project(NexEngineCore)

set(PUBLIC_INCLUDES
    includes/NexCore/Core/Core.h
    includes/NexCore/Core/Log.h
    includes/NexCore/Core/Singleton.h
    includes/NexCore/Core/Window.h
    includes/NexCore/Core/Application.h
    includes/NexCore/Core/CoreEvent.h
    includes/NexCore/Core/CoreEventTypes.h
    includes/NexCore/Core/FrameListener.h

    includes/NexCore/Input/InputManager.h
    includes/NexCore/input/Input.h
    includes/NexCore/Input/InputEventTypes.h

    includes/NexCore/Ui/ImGui/ImGuiLayer.h
)

set (PRIVATE_SOURCES
    src/NexCore/Core/Application.cpp

    src/NexCore/Input/InputManager.cpp
    
    src/NexCore/Platform/Windows/WindowsWindow.h
    src/NexCore/Platform/Windows/WindowsWindow.cpp

    src/NexCore/Ui/ImGui/ImGuiLayer.cpp
)

add_library(nex_core SHARED
    ${PUBLIC_INCLUDES}
    ${PRIVATE_SOURCES}
)

target_include_directories(nex_core PUBLIC includes)

if ((CMAKE_BUILD_TYPE STREQUAL "Debug") OR (CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo"))
    target_compile_definitions(nex_core PRIVATE NEXCORE_DEBINFO)
endif()

target_link_libraries(nex_core
    PUBLIC nex_math

    PRIVATE glfw
    PRIVATE glad
    PRIVATE imgui
    PRIVATE spdlog
)