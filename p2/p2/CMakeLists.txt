# CMakeList.txt : CMake project for p2, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (p2 "p2.cpp" "p2.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET p2 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
