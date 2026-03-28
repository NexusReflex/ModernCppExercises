# 1. Tell CMake where the headers are for this directory
include_directories(include)

add_executable(SmartResourceManager 
    src/main.cpp
    src/ResourceManager.cpp
)