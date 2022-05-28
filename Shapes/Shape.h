#ifndef GRAPHICS_SHAPE_H
#define GRAPHICS_SHAPE_H

#include "../Drawers/Drawer.h"
class Drawer;



class Shape {
public:
    Drawer *drawer;
    virtual void draw() = 0;
};


#endif //GRAPHICS_SHAPE_H
