
cmake_minimum_required (VERSION 3.8)

add_executable (p_2 "p_2.cpp" "p_2.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET p_2 PROPERTY CXX_STANDARD 20)
endif()


