cmake_minimum_required(VERSION 3.14)
project(get_next_line C)

set(CMAKE_C_STANDARD 11)

file(GLOB fillit_SRC
        "./sources/*.c"
        )

file(GLOB libft_SRC
        "./libft/*.c"
        )


include_directories(includes)
include_directories(libft)


add_executable(fillit ${fillit_SRC} ${libft_SRC} sources/main.c)