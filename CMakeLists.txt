cmake_minimum_required(VERSION 3.16)
project(MS3)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        MS3
        ms3.cpp
        CustomerOrder.cpp
        CustomerOrder.h
        Station.h
        Station.cpp
        Utilities.h
        Utilities.cpp
        Workstation.cpp
        Workstation.h LineManager.cpp LineManager.h)
