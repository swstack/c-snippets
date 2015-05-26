cmake_minimum_required(VERSION 2.8)
project(c-snippets)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(cpholes cp-holes/main.c)
add_executable(cbs callbacks/cbs.c)
add_executable(array_of_strings arrays/array_of_strings.c)
add_executable(pointers1 pointers/pointers1.c)
add_executable(pointers2 pointers/pointers2.c)
add_executable(indexing arrays/indexing.c)
add_executable(struct_heap structs/struct_heap.c)
add_executable(struct_stack structs/struct_stack.c)
add_executable(memory memory/memory.c)