cmake_minimum_required(VERSION 3.22)
project(Text)

set(CMAKE_CXX_STANDARD 17)

add_executable(Text main.cpp
        text.hpp
        text.cpp)
