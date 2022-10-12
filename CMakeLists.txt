cmake_minimum_required(VERSION 3.20)
project(TD4 C)

set(CMAKE_C_STANDARD 99)

add_executable(TD4bis main.c tree.c tree.h bufferNode.c bufferNode.h node.c node.h BST.c BST.h)
