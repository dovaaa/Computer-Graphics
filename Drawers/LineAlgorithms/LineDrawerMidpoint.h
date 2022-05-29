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
    void draw(Shape* line, HDC& hdc) override;
};


#endif //GRAPHICS_LINEDRAWERMIDPOINT_H
