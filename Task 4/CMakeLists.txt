cmake_minimum_required(VERSION 3.24)
project(Task_4)

include_directories(inc/)
set(CMAKE_CXX_STANDARD 17)

add_executable(Task_4 main.cpp
               inc/TextConsole.h
               inc/VirtualKeyboard.h
               inc/Commands.h
               inc/Key.h inc/Global.h)
