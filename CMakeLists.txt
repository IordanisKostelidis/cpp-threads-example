cmake_minimum_required(VERSION 3.19)
project(cpp_threads_example)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(cpp_threads_example src/main.cpp src/RunnableObject.cpp src/RunnableObject.h)