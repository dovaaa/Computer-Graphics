cmake_minimum_required(VERSION 3.15)
project(Graphics)

set(CMAKE_CXX_STANDARD 14)

add_executable(Graphics main.cpp Drawer.h CircleDrawerMidpoint.cpp CircleDrawerMidpoint.h CircleDrawerModifiedMidpoint.h CircleDrawerModifiedMidpoint.h Shape.cpp Shape.h Line.cpp Line.h Circle.cpp Circle.h Rectangle.cpp Rectangle.h Ellipse.cpp Ellipse.h Point.cpp Point.h)
