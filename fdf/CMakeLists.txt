cmake_minimum_required(VERSION 3.14)
project(fdf C)

set(CMAKE_C_STANDARD 11)

add_custom_target(fdf
        COMMAND make
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
