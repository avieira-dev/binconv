cmake_minimum_required(VERSION 3.28)

project(binconv VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(BINCONV_SOURCES
    src/main.c
    src/menu.c
)

add_executable(binconv ${BINCONV_SOURCES})

target_include_directories(binconv PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_options(binconv PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)