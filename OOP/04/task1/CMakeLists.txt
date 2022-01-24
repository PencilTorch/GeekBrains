cmake_minimum_required(VERSION 3.5)

project(task1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set( project_sources
   main.cpp
   ArrayInt.cpp
)

add_executable(task1 main.cpp)


