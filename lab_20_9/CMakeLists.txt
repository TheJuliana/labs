cmake_minimum_required(VERSION 3.20)
project(BMP)

set(CMAKE_CXX_STANDARD 14)

add_executable(BMP main.cpp matrix.h BMP.cpp BMP.hpp)
