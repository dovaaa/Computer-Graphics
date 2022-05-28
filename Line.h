#include "Shape.h"

#ifndef GRAPHICS_LINE_H
#define GRAPHICS_LINE_H


class Line : public Shape {
public:
    int stx, sty;
    int edx, edy;
    Line();
    Line(int, int, int, int);
    void draw() override;
};


#endif //GRAPHICS_LINE_H
