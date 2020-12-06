cmake_minimum_required(VERSION 3.17)
project(ass4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DSIZE=3")


include_directories(.)

add_executable(ass4
        ass4.h
        main.c
        ass4.c)
