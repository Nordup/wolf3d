cmake_minimum_required(VERSION 3.16)
project(libft C)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")

file(GLOB SOURCES *.c)

include_directories(.)

add_library(libft STATIC ${SOURCES})