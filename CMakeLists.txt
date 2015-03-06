cmake_minimum_required(VERSION 2.8.4)
project(assignment_2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/volimage.cpp)
add_executable(assignment_2 ${SOURCE_FILES})
