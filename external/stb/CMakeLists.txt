cmake_minimum_required(VERSION 3.12)

project(stb)

add_library(stb STATIC
    includes/stb/image.h
    src/stb/image.cpp

    includes/stb/image_write.h
    src/stb/image_write.cpp
    
    includes/stb/image_resize.h
    src/stb/image_resize.cpp
)

target_include_directories(stb PUBLIC includes)