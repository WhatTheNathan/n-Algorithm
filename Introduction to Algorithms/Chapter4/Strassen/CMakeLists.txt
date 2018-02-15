cmake_minimum_required(VERSION 3.8)
project(Strassen)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Strassen.cpp)
add_executable(Strassen ${SOURCE_FILES})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)