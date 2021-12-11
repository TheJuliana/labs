cmake_minimum_required(VERSION 3.20)
project(lab9)

set(CMAKE_CXX_STANDARD 17)
include_directories("c:/SFML/include/")	# добавляем директории
include_directories("inc/")
link_directories("c:/SFML/lib/")

add_executable(lab9 main.cpp images)
add_definitions(-DSFML_STATIC) # дефайны

target_link_libraries(lab9 sfml-graphics-s-d
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
