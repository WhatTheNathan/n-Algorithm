cmake_minimum_required(VERSION 3.8)
project(matrixChain)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES matrixChain.cpp)
add_executable(matrixChain ${SOURCE_FILES})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)