cmake_minimum_required(VERSION 3.13)  # CMake version check
project(lab6)                         # Create project "lab6"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add lab6.cpp file of project root directory as source file
set(SOURCE_FILES lab6.cpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(lab6 ${SOURCE_FILES})