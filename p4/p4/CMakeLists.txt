# CMakeList.txt : CMake project for p4, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (p4 "p4.cpp" "p4.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET p4 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/NewFile.txt
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})