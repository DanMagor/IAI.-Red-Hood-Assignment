cmake_minimum_required(VERSION 3.8)
project(Assignment1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Environment.cpp Environment.h Unit.cpp Unit.h UnitActionController.h Point.cpp Point.h)
add_executable(Assignment1 ${SOURCE_FILES})