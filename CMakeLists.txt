# stop if cmake version below 3.5
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and supported languages
project(CppNeuralNetwork)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    # set compiler flags
    set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -Wall -Wno-unknown-pragmas -Wno-sign-compare -Woverloaded-virtual")
    set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -Wwrite-strings -Wno-unused")
    set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -O0 -std=c++11 -fno-omit-frame-pointer")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    # set compiler flags
    set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -Wall")
    set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -O0 -std=c++11")
endif()

# add sub directory
add_subdirectory(src)
