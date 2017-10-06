cmake_minimum_required(VERSION 3.5)
project(Alg_lab1_v3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ListClass.cpp ListClass.h QueueClass.cpp QueueClass.h)
add_executable(Alg_lab1_v3 ${SOURCE_FILES})