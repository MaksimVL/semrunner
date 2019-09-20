cmake_minimum_required(VERSION 3.14)
project(odrinkwa C)

set(CMAKE_C_STANDARD 11)

file(GLOB libft_SRC
        "*.c"
        )

#add_executable(odrinkwa main.c ft_memset.c libft.h)

add_executable(odrinkwa ${libft_SRC} libft.h)