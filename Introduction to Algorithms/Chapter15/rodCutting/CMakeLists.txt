cmake_minimum_required(VERSION 3.8)
project(rodCutting)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES rodCutting.cpp)
add_executable(rodCutting ${SOURCE_FILES})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)