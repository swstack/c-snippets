# Project Name: c-snippets
project(c-snippets)

# Define minimum cmake version required for this project
cmake_minimum_required(VERSION 2.8)

# Setup CFLAGS, here I am saying "-Wall" for all warnings
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

# Executable: cpholes
add_executable(cpholes cp-holes/main.c)

# Executable: array_of_strings
add_executable(array_of_strings arrays/array_of_strings.c)

# Executable: pointers1
add_executable(pointers1 pointers/pointers1.c)

# Executable: pointers2
add_executable(pointers2 pointers/pointers2.c)

# Executable: indexing
add_executable(indexing arrays/indexing.c)

# Executable: struct_heap
add_executable(struct_heap structs/struct_heap.c)

# Executable: struct_stack
add_executable(struct_stack structs/struct_stack.c)

# Executable: memory
add_executable(memory memory/memory.c)

# Executable: cbs1
add_executable(cbs1 pointers/callbacks1.c)

# Executable: cbs2
add_executable(cbs2 pointers/callbacks2.c)
