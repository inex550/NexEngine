cmake_minimum_required(VERSION 3.12)

project(glad)

add_library(glad STATIC
    src/glad.c
    includes/glad/glad.h
    includes/KHR/khrplatform.h
)

target_include_directories(glad PUBLIC includes)