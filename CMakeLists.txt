cmake_minimum_required(VERSION 3.23)
project(graph_vertex_black_hole C)

set(CMAKE_C_STANDARD 99)

add_compile_options(
        -Wall
        -Wextra
        -Wpedantic
        -Werror
        -fno-pie
        -fno-stack-protector
        -fcf-protection=none
        -march=native
        -mtune=native
)
add_link_options(-no-pie)

add_executable(validate
        fastest.c
        main.c
        naive.c
        project.h
        )
