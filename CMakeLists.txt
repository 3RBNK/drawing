cmake_minimum_required(VERSION 3.28)
project(prjct)

set(CMAKE_CXX_STANDARD 17)

add_executable(prjct main.cpp
        point.h
        screen.h
        shape.h
        rotatable.h
        reflectable.h
        line.h
        cross.h
        square.h
        oblique_cross.h)
