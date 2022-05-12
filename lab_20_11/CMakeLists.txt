cmake_minimum_required(VERSION 3.20)
project(lab_20_11)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab_20_11 main.cpp Languages.hpp CodeGenerator.hpp Java.hpp C_PLUS_PLUS.hpp PHP.hpp)
