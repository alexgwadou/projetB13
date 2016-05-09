cmake_minimum_required(VERSION 3.5)
project(App2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Memory.cpp Memory.h)
add_executable(App2 ${SOURCE_FILES})