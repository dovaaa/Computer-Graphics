//
// Created by Mohamed on 5/28/2022.
//

#ifndef GRAPHICS_LINEDRAWERMIDPOINT_H
#define GRAPHICS_LINEDRAWERMIDPOINT_H

#include "../Drawer.h"
#include "../../Shapes/Shape.h"

class LineDrawerMidpoint : public Drawer{
public:
    void draw(Shape* line) override;
};


#endif //GRAPHICS_LINEDRAWERMIDPOINT_H
