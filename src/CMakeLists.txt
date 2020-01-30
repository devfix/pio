cmake_minimum_required(VERSION 3.0)
project(pio CXX)

# uncomment to test compilation for avr
#set(TARGET_AVR TRUE)

# uncomment to enable verbose compilation output
#SET(CMAKE_VERBOSE_MAKEFILE "ON")

# avr-gcc 5.4 doesn't support any higher standard
set(CMAKE_CXX_STANDARD 11)

# set optimization level, save assembler code
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -save-temps")

# fake target to run merge script
add_custom_target(merge COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/merge)

# add test target
add_executable(testrunner testrunner.cpp)

# run merge script before build
#add_dependencies(testrunner merge)

if(DEFINED TARGET_AVR)
    SET(CMAKE_C_COMPILER avr-gcc)
    SET(CMAKE_CXX_COMPILER avr-g++)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mmcu=atmega32")
    SET(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "")
else()
    # only add the gtest source if not compiling for avr
    target_sources(testrunner PRIVATE tests.cpp io.cpp test_single_bit.cpp)

    # link google test framework
    target_link_libraries(testrunner gtest pthread)
endif()
