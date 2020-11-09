cmake_minimum_required(VERSION 3.17)
project(Test1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Test1
        Agent.h
        Graph.h
        json.hpp
        main.cpp
        Session.h
        Tree.h Graph.cpp Tree.cpp Agent.cpp Session.cpp TreeOrri.cpp Talclass.cpp Talclass.h)
