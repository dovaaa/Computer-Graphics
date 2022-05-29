#include "Shape.h"

#ifndef GRAPHICS_RECTANGLE_H
#define GRAPHICS_RECTANGLE_H


class Rectangle : public Shape {
public:
    int length, width;
    int stx, sty;

    Rectangle();

    Rectangle(int, int, int, int);

    void draw(HDC& hdc) override;
    void save() override;
};


#endif //GRAPHICS_RECTANGLE_H
