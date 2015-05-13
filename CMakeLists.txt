cmake_minimum_required(VERSION 2.8)
project(c-snippets)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(cpholes cp-holes/main.c)
add_executable(cbs pointers/callbacks.c)
add_executable(array_of_strings arrays/array_of_strings.c)
add_executable(pointers pointers/pointers.c)
add_executable(nested_pointers pointers/nested_pointers.c)
add_executable(indexing arrays/indexing.c)
