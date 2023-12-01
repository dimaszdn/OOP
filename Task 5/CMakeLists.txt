cmake_minimum_required(VERSION 3.24)
project(Task_5)

include_directories(inc/)
set(CMAKE_CXX_STANDARD 17)

add_executable(Task_5 main.cpp inc/INotifyPropertyChanged.h
        inc/MyClassA.h
        inc/INotifyPropertyChanging.h
        inc/MyClassB.h
        inc/INotifyCollectionChanged.h
        inc/MyCollection.h inc/Func.h)
