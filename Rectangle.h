#include "Shape.h"

#ifndef GRAPHICS_RECTANGLE_H
#define GRAPHICS_RECTANGLE_H


class Rectangle : public Shape {
public:
    int length, width;
    int stx, sty;

    Rectangle();

    Rectangle(int, int, int, int);

    void draw() override;
};


#endif //GRAPHICS_RECTANGLE_H
