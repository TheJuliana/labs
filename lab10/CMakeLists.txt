cmake_minimum_required(VERSION 3.20)
project(lab10)

set(CMAKE_CXX_STANDARD 17)

include_directories("c:/SFML/include/")
include_directories("inc/")
#include_directories("images/")
link_directories("c:/SFML/lib/")
link_directories("c:/SFML/lib/")

add_executable(lab10 main.cpp triangle.cpp triangle.hpp )
add_definitions(-DSFML_STATIC)

target_link_libraries(lab10 sfml-graphics-s-d
        sfml-window-s-d
        sfml-system-s-d
        opengl32
        freetype
        winmm
        gdi32
        sfml-audio-s-d
        openal32
        flac
        vorbisenc
        vorbisfile
        vorbis
        ogg)
