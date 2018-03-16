cmake_minimum_required(VERSION 3.8)
project(BubbleSort)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES BubbleSort.cpp)
add_executable(BubbleSort ${SOURCE_FILES})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)