//
// Created by Mohamed on 5/29/2022.
//

#ifndef GRAPHICS_ELLIPSEDRAWERPOLAR_H
#define GRAPHICS_ELLIPSEDRAWERPOLAR_H
#include "../Drawer.h"
#include "../../Shapes/Shape.h"

class EllipseDrawerPolar : public Drawer{
    void draw(Shape *ellipse, HDC& hdc) override;
    Drawer* copy() override;
};


#endif //GRAPHICS_ELLIPSEDRAWERPOLAR_H
