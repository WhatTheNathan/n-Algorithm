cmake_minimum_required(VERSION 3.8)
project(insert_sort)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES insert_sort.cpp)
add_executable(insert_sort ${SOURCE_FILES})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)