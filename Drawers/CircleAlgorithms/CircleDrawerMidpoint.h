//
// Created by Mohamed on 5/28/2022.
//

#ifndef GRAPHICS_CIRCLEDRAWERMIDPOINT_H
#define GRAPHICS_CIRCLEDRAWERMIDPOINT_H
#include "../Drawer.h"
#include "../../Shapes/Circle.h"


class CircleDrawerMidpoint : public Drawer{
public:
    CircleDrawerMidpoint();
    void draw(Shape *circle, HDC& hdc) override;
    Drawer* copy() override;
};


#endif //GRAPHICS_CIRCLEDRAWERMIDPOINT_H
