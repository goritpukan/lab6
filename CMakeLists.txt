cmake_minimum_required(VERSION 3.30)
project(lab6 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab6 main.c
        include/io.h
        src/io.c
        include/colors.h
        include/calculations.h
        src/calculations.c
        include/matrix.h
        src/matrix.c)

target_link_libraries(lab6 m)
