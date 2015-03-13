cmake_minimum_required(VERSION 2.8)
project(c-snippets)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(cpholes cp-holes/main.c)
