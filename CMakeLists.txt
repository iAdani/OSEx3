cmake_minimum_required(VERSION 3.22)
project(OSEx3)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(OSEx3 main.cpp BoundedQueue.cpp UnboundedQueue.cpp Producer.cpp Dispatcher.cpp CoEditor.cpp)
