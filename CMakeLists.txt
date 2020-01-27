cmake_minimum_required(VERSION 3.0)
project(cpplibs CXX)

set(CMAKE_CXX_STANDARD 11)

#SET(CMAKE_C_COMPILER avr-gcc)
#SET(CMAKE_CXX_COMPILER avr-g++)
SET(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdump-tree-original -O0")
#SET(CMAKE_VERBOSE_MAKEFILE "ON")

add_executable(piotest meta.cpp)
