cmake_minimum_required(VERSION 3.24)
project(Task_7)

include_directories(inc/)
set(CMAKE_CXX_STANDARD 17)

add_executable(Task_7 main.cpp inc/IRepository.h
        inc/User.h
        inc/IUserRepository.h
        inc/MemoryRepository.h
        inc/MemoryUserRepository.h)
