cmake_minimum_required(VERSION 3.24)
project(FLITA_HW2and3 C)

set(CMAKE_C_STANDARD 11)

add_executable(FLITA_HW2and3 main.c source/parser.c include/parser.h source/graph.c include/graph.h source/dfs.c include/dfs.h)
