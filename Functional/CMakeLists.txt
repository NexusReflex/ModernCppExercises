# 1. Tell CMake where the headers are for this directory
include_directories(include)

add_executable(EventManager 
    src/main.cpp
    src/EventManager.cpp
)