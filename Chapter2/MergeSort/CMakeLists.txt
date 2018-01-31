cmake_minimum_required(VERSION 3.8)
project(merge_sort)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES merge_sort.cpp)
add_executable(merge_sort ${SOURCE_FILES})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)