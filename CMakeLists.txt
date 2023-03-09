cmake_minimum_required(VERSION 3.16)
project(libackermann)
set(CMAKE_CXX_STANDARD 17)

add_library(libackermann STATIC src/tta.cpp src/att.cpp src/steering_ratio.cpp src/steering_ratio.cpp)
target_include_directories(libackermann PUBLIC include)

add_subdirectory(./test)