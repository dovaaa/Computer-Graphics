//
// Created by Mohamed on 5/29/2022.
//

#ifndef GRAPHICS_ELLIPSEDRAWERMIDPOINT_H
#define GRAPHICS_ELLIPSEDRAWERMIDPOINT_H
#include "../Drawer.h"
#include "../../Shapes/Shape.h"

class EllipseDrawerMidpoint : public Drawer {
    void draw(Shape *ellipse, HDC& hdc) override;
};


#endif //GRAPHICS_ELLIPSEDRAWERMIDPOINT_H
