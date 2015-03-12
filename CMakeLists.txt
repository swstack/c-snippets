cmake_minimum_required(VERSION 2.8)
project(c-snippets)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES cp-holes/main.c)
add_executable(cpholes ${SOURCE_FILES})
