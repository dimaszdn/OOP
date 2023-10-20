cmake_minimum_required(VERSION 3.24)
project(Task_3)

include_directories(inc/)
set(CMAKE_CXX_STANDARD 17)

add_executable(Task_3 main.cpp inc/ABC.h inc/Text.h)
