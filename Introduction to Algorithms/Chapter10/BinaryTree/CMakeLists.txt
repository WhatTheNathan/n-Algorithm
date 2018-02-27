cmake_minimum_required(VERSION 3.8)
project(BinaryTree)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        BinaryTreeNode.h BinaryTree.h)

add_executable(BinaryTree ${SOURCE_FILES})