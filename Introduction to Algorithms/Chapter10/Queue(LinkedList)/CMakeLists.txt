cmake_minimum_required(VERSION 3.8)
project(queue)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        LinkedList.h
        main.cpp
        queue.h)

add_executable(queue ${SOURCE_FILES})