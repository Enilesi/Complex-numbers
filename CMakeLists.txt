cmake_minimum_required(VERSION 3.8)

set(This Prog)
project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

set(Sources
    complex.cpp
)

add_library(${This} STATIC ${Sources})

add_subdirectory(test)
