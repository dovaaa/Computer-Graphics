//
// Created by Mohamed on 5/28/2022.
//

#ifndef GRAPHICS_DRAWER_H
#define GRAPHICS_DRAWER_H
#include <Windows.h>

#include "../Shapes/Shape.h"
#include <iostream>
class Shape;

class Drawer {
public:
    virtual void draw(Shape*, HDC&) = 0;
    //virtual std::string save() = 0;
};


#endif //GRAPHICS_DRAWER_H
