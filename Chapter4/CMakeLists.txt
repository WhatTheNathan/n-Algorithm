cmake_minimum_required(VERSION 3.8)
project(max_subarray)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES max_subarray.cpp)
add_executable(max_subarray ${SOURCE_FILES})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)