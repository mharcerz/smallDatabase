cmake_minimum_required(VERSION 3.10)
project(smallDatabase)

set(CMAKE_CXX_STANDARD 17)

add_executable(main.cpp
        Person.h Person.cpp
        Add.h Add.cpp
        Show.h Show.cpp
        Search.h Search.cpp
        Menu.h Menu.cpp
        Remove.h Remove.cpp
        FileOperations.h FileOperations.cpp)
