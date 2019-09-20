cmake_minimum_required(VERSION 3.14)
project(get_next_line C)

set(CMAKE_C_STANDARD 11)

file(GLOB test_libft_SRC
        "*.c"
        )

file(GLOB libft_SRC
        "./libft/sources/*.c"
        )
include_directories(libft/includes)

add_executable(test_libft ${test_libft_SRC} ${libft_SRC} main.c)