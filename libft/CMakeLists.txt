cmake_minimum_required(VERSION 3.14)
project(get_next_line C)

set(CMAKE_C_STANDARD 11)

file(GLOB get_next_line_SRC
        "*.c"
        )

file(GLOB libft_SRC
        "./libft/sources/*.c"
        )
include_directories(libft/includes)
add_executable(get_next_line ${get_next_line_SRC} ${libft_SRC} main.c)