cmake_minimum_required(VERSION 3.24)
project(Task_1)

include_directories(inc/)
include_directories(src/)
set(CMAKE_CXX_STANDARD 17)

add_executable(Task_1 main.cpp inc/Diff.h src/Diff.cpp inc/LeftDiff.h src/LeftDiff.cpp inc/RightDiff.h src/RightDiff.cpp inc/CentralDiff.h src/CentralDiff.cpp inc/Func.h)
