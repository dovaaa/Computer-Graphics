#include "Shape.h"

#ifndef GRAPHICS_RECTANGLE_H
#define GRAPHICS_RECTANGLE_H


class Rectangle : public Shape {
public:
    int xright, yright;
    int xleft, yleft;

    Rectangle();

    Rectangle(int, int, int, int);

    void draw(HDC& hdc) override;
    void save() override;
};


#endif //GRAPHICS_RECTANGLE_H
