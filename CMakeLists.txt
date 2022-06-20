cmake_minimum_required(VERSION 3.5)

project(debug LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(debug main.cpp)
