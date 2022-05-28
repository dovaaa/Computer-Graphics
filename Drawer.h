//
// Created by Mohamed on 5/28/2022.
//

#ifndef GRAPHICS_DRAWER_H
#define GRAPHICS_DRAWER_H

#include "Shape.h"
class Shape;

class Drawer {
public:
    virtual void draw(Shape*) = 0;
};


#endif //GRAPHICS_DRAWER_H
