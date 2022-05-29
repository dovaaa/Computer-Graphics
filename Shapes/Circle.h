#ifndef GRAPHICS_CIRCLE_H
#define GRAPHICS_CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
public:
    int cx, cy, r;
    Circle();
    Circle(int, int, int, Drawer*);
    void draw() override;
    void save() override;
};



#endif //GRAPHICS_CIRCLE_H
