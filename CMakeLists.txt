cmake_minimum_required(VERSION 3.16)
project(Nordup C)
set(CMAKE_C_STANDARD 99)

FILE(GLOB SOURCES src/*.c src/*/*.c)

include_directories(${CMAKE_PROJECT_NAME}
        libraries/SDL/sdl2/2.0.12_1/include/SDL2/
        libraries/SDL/sdl2_image/2.0.5/include/SDL2/
        libraries/SDL/sdl2_mixer/2.0.4/include/SDL2/
        libraries/SDL/sdl2_ttf/2.0.15/include/SDL2/
        libraries/SDL2.framework/Headers
        include
        libraries/libft)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME}
        ${CMAKE_SOURCE_DIR}/libraries/SDL/sdl2/2.0.12_1/lib/libSDL2-2.0.0.dylib
        ${CMAKE_SOURCE_DIR}/libraries/SDL/sdl2/2.0.12_1/lib/libSDL2.dylib
        ${CMAKE_SOURCE_DIR}/libraries/SDL/sdl2_image/2.0.5/lib/libSDL2_image-2.0.0.dylib
        ${CMAKE_SOURCE_DIR}/libraries/SDL/sdl2_image/2.0.5/lib/libSDL2_image.dylib
        ${CMAKE_SOURCE_DIR}/libraries/SDL/sdl2_mixer/2.0.4/lib/libSDL2_mixer-2.0.0.dylib
        ${CMAKE_SOURCE_DIR}/libraries/SDL/sdl2_mixer/2.0.4/lib/libSDL2_mixer.dylib
        ${CMAKE_SOURCE_DIR}/libraries/SDL/sdl2_ttf/2.0.15/lib/libSDL2_ttf-2.0.0.dylib
        ${CMAKE_SOURCE_DIR}/libraries/SDL/sdl2_ttf/2.0.15/lib/libSDL2_ttf.dylib)

add_subdirectory(libraries/libft)
target_link_libraries(${CMAKE_PROJECT_NAME} libft)