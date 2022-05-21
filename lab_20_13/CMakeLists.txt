cmake_minimum_required(VERSION 3.15)
project(3d_engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories("inc/")
include_directories("c:/SFML/include/")	# добавляем директории
link_directories("c:/SFML/lib/")



add_executable(3d_engine
        main.cpp
        inc/matrix.hpp
        inc/camera.hpp
        inc/scene.hpp
        src/camera.cpp
        src/scene.cpp
       )

add_definitions(-DSFML_STATIC)

target_link_libraries("${PROJECT_NAME}" sfml-graphics-s
        sfml-window-s
        sfml-system-s
        opengl32
        freetype
        winmm
        gdi32
        sfml-audio-s
        openal32
        flac
        vorbisenc
        vorbisfile
        vorbis
        ogg)

target_link_libraries("${PROJECT_NAME}"
        debug sfml-graphics-s-d
        debug sfml-window-s-d
        debug sfml-system-s-d
        debug sfml-audio-s-d)

target_link_libraries("${PROJECT_NAME}"
        optimized sfml-graphics-s
        optimized sfml-window-s
        optimized sfml-system-s
        optimized sfml-audio-s)

target_link_libraries("${PROJECT_NAME}" opengl32 freetype winmm gdi32 openal32 flac vorbisenc vorbisfile vorbis ogg)

file(COPY "points.txt" DESTINATION "/")