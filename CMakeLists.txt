cmake_minimum_required(VERSION 3.23)
project(TP C)

set(CMAKE_C_STANDARD 11)

add_executable(TP
        matrix.c main.c)
target_link_libraries(TP PRIVATE m)
