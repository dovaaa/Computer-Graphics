cmake_minimum_required(VERSION 3.15)
project(Graphics)

set(CMAKE_CXX_STANDARD 14)

add_executable(Graphics main.cpp Drawers/Drawer.h Drawers/CircleAlgorithms/CircleDrawerMidpoint.cpp Drawers/CircleAlgorithms/CircleDrawerMidpoint.h Drawers/CircleAlgorithms/CircleDrawerModifiedMidpoint.h Shapes/Shape.h Shapes/Line.cpp Shapes/Line.h Shapes/Circle.cpp Shapes/Circle.h Shapes/Rectangle.cpp Shapes/Rectangle.h Shapes/Ellipse.cpp Shapes/Ellipse.h Shapes/Point.cpp Shapes/Point.h Drawers/CircleAlgorithms/CircleDrawerModifiedMidpoint.cpp Drawers/CircleAlgorithms/CricleDrawerIterativePolar.cpp Drawers/CircleAlgorithms/CricleDrawerIterativePolar.h Drawers/CircleAlgorithms/CircleDrawerPolar.cpp Drawers/CircleAlgorithms/CircleDrawerPolar.h Drawers/CircleAlgorithms/CircleDrawerDirect.cpp Drawers/CircleAlgorithms/CircleDrawerDirect.h Drawers/LineAlgorithms/LineDrawerDDA.cpp Drawers/LineAlgorithms/LineDrawerDDA.h Drawers/LineAlgorithms/LineDrawerParametric.cpp Drawers/LineAlgorithms/LineDrawerParametric.h Drawers/LineAlgorithms/LineDrawerMidpoint.cpp Drawers/LineAlgorithms/LineDrawerMidpoint.h)
