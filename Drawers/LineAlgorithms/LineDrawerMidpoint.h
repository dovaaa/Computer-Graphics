//
// Created by Mohamed on 5/28/2022.
//

#ifndef GRAPHICS_LINEDRAWERMIDPOINT_H
#define GRAPHICS_LINEDRAWERMIDPOINT_H

#include "../Drawer.h"
#include "../../Shapes/Shape.h"
#include <Windows.h>

class LineDrawerMidpoint : public Drawer{
public:
    LineDrawerMidpoint();
    void draw(Shape* line, HDC& hdc) override;
    void plotPixel(int x1, int y1, int x2, int y2, int dx, int dy, int decide,Shape*, HDC &hdc);
    Drawer* copy() override;
};


#endif //GRAPHICS_LINEDRAWERMIDPOINT_H
