cmake_minimum_required(VERSION 3.17)
project(LinkedList)

set(CMAKE_CXX_STANDARD 14)

add_executable(LinkedList main.cpp main.cpp Node.h LinkedList.h SinglyLinkedList.cpp)