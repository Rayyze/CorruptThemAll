cmake_minimum_required(VERSION 3.10)

project(CorruptThemAll)

set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/lib/cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_executable(CorruptThemAll src/main.cpp)

target_link_libraries(CorruptThemAll SDL2::SDL2main SDL2::SDL2 SDL2_image::SDL2_image)

message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
