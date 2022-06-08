cmake_minimum_required(VERSION 3.22)
project(OSEx3)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lpthread -lm -lrt")

add_executable(OSEx3 main.cpp BoundedQueue.cpp UnboundedQueue.cpp Producer.cpp)
