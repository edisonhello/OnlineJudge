cmake_minimum_required(VERSION 3.3)
project(TIOJ)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES 1031.cpp)
add_executable(TIOJ ${SOURCE_FILES})