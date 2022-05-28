#include "Shape.h"

#ifndef GRAPHICS_CIRCLE_H
#define GRAPHICS_CIRCLE_H


class Circle : public Shape {
public:
    int cx, cy, r;
    Circle();
    Circle(int, int, int);
    void draw() override;
};



#endif //GRAPHICS_CIRCLE_H
