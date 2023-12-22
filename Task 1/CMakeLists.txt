cmake_minimum_required(VERSION 3.24)
project(Task_1)

include_directories(inc/)
include_directories(src/)
set(CMAKE_CXX_STANDARD 17)

add_executable(Task_1 main.cpp
        inc/CentralDiff.h
        inc/Diff.h
        inc/Func.h
        inc/LeftDiff.h
        inc/RightDiff.h
        src/Diff.cpp)
