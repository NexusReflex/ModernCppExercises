# 1. Tell CMake where the headers are for this directory
include_directories(include)

add_executable(MultiThreading
    src/main.cpp
    src/MultiThreading.cpp
)