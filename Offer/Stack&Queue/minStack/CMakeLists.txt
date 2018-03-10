cmake_minimum_required(VERSION 3.8)
project(minStack)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp Stack.h)

add_executable(minStack ${SOURCE_FILES})