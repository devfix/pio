cmake_minimum_required(VERSION 3.0)
project(pio CXX)

set(CMAKE_CXX_STANDARD 11)

# uncomment to compile for avr
SET(CMAKE_C_COMPILER avr-gcc)
SET(CMAKE_CXX_COMPILER avr-g++)

SET(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdump-tree-original -O3 -save-temps -mmcu=atmega32")
#SET(CMAKE_VERBOSE_MAKEFILE "ON")

add_executable(meta main.cpp list.hpp pin.hpp pin_lists.hpp)
