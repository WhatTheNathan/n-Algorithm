cmake_minimum_required(VERSION 3.8)
project(binary_search)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES binary_search.cpp)
add_executable(binary_search ${SOURCE_FILES})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)