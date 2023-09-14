cmake_minimum_required(VERSION 3.12)

project(NexMath)

set(NEX_MATH_LIB nex_math)

set(PUBLIC_INCLUDES
    includes/NexMath/base/definisions.h
    includes/NexMath/base/vec2_type.h
    includes/NexMath/base/vec2_type.inl
    includes/NexMath/base/vec3_type.h
    includes/NexMath/base/vec3_type.inl

    includes/NexMath/Vec2.h
    includes/NexMath/Vec3.h
)

# set(PRIVATE_SOURCES)

add_library(${NEX_MATH_LIB} INTERFACE
    ${PUBLIC_INCLUDES}
    # ${PRIVATE_SOURCES}
)

target_include_directories(${NEX_MATH_LIB} INTERFACE includes)