cmake_minimum_required(VERSION 3.16)
project(libackermann)
set(CMAKE_CXX_STANDARD 17)

add_library(libackermann INTERFACE include/libackermann/libackermann.hpp include/libackermann/types.hpp include/libackermann/conversions.hpp)
target_include_directories(libackermann INTERFACE include)

add_subdirectory(./test)