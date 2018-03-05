cmake_minimum_required(VERSION 3.8)
project(heapSort)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES MaxHeap.h main.cpp MaxHeap.h main.cpp)
add_executable(heap_sort ${SOURCE_FILES})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)