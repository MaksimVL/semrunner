cmake_minimum_required(VERSION 3.14)
project(printf_double C)

set(CMAKE_C_STANDARD 11)

file(GLOB ft_printf_SRC
        "*.c"
        )

file(GLOB libft_SRC
        "./libft/sources/*.c"
        )

include_directories(libft/includes)

add_executable(ft_printf ${ft_printf_SRC} ${libft_SRC} main.c double.h)