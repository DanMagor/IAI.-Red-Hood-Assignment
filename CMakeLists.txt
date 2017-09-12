cmake_minimum_required(VERSION 3.8)
project(Assignment1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Environment.cpp Environment.h Unit.cpp Unit.h Point.cpp Point.h RedHood.cpp RedHood.h Granny.cpp Granny.h AStar.cpp AStar.h Graph.cpp Graph.h SimulationController.cpp SimulationController.h Wolf.cpp Wolf.h Bear.cpp Bear.h Cutter.cpp Cutter.h Backtracking.cpp Backtracking.h)
add_executable(Assignment1 ${SOURCE_FILES})