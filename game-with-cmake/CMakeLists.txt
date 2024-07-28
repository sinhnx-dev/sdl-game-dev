cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)

project(SDL3Game VERSION 1.0.0)
add_executable(SDL3Game main.cpp)

add_subdirectory(external/SDL)