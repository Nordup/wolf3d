cmake_minimum_required(VERSION 3.16)
project(Nordup C)
set(CMAKE_C_STANDARD 99)

FILE(GLOB SOURCES src/*.c src/*/*.c)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

include_directories(${CMAKE_PROJECT_NAME}
        libraries/SDL/sdl2/2.0.12_1/include/SDL2/
        libraries/SDL/sdl2_image/2.0.5/include/SDL2/
        libraries/SDL/sdl2_mixer/2.0.4/include/SDL2/
        libraries/SDL/sdl2_ttf/2.0.15/include/SDL2/
        include
        libraries/libft)

target_link_libraries(${CMAKE_PROJECT_NAME}
        ${PROJECT_SOURCE_DIR}/libraries/SDL/sdl2/2.0.12_1/lib/libSDL2-2.0.0.dylib
        ${PROJECT_SOURCE_DIR}/libraries/SDL/sdl2/2.0.12_1/lib/libSDL2.dylib
        ${PROJECT_SOURCE_DIR}/libraries/SDL/sdl2_image/2.0.5/lib/libSDL2_image-2.0.0.dylib
        ${PROJECT_SOURCE_DIR}/libraries/SDL/sdl2_image/2.0.5/lib/libSDL2_image.dylib
        ${PROJECT_SOURCE_DIR}/libraries/SDL/sdl2_mixer/2.0.4/lib/libSDL2_mixer-2.0.0.dylib
        ${PROJECT_SOURCE_DIR}/libraries/SDL/sdl2_mixer/2.0.4/lib/libSDL2_mixer.dylib
        ${PROJECT_SOURCE_DIR}/libraries/SDL/sdl2_ttf/2.0.15/lib/libSDL2_ttf-2.0.0.dylib
        ${PROJECT_SOURCE_DIR}/libraries/SDL/sdl2_ttf/2.0.15/lib/libSDL2_ttf.dylib)

add_subdirectory(libraries/libft)
target_link_libraries(${CMAKE_PROJECT_NAME} libft)