cmake_minimum_required(VERSION 3.8)
project(Graph)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Graph.h ListNode.h DoubleLinkedList.h)
add_executable(Graph ${SOURCE_FILES})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)