cmake_minimum_required(VERSION 3.17)
project(Test1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Test1
        Include/Agent.h
        Include/Graph.h
        Include/json.hpp
        src/main.cpp
        Include/Session.h
        Include/Tree.h src/Graph.cpp src/Tree.cpp src/Agent.cpp src/Session.cpp TreeOrri.cpp Talclass.cpp)
