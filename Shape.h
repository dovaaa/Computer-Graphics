#ifndef GRAPHICS_SHAPE_H
#define GRAPHICS_SHAPE_H

class Shape {
public:
    Drawer drawer;
    virtual void draw() = 0;
};


#endif //GRAPHICS_SHAPE_H
