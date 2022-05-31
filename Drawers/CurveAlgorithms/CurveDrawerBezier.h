//
// Created by Mohamed on 5/30/2022.
//

#ifndef GRAPHICS_CURVEDRAWERBEZIER_H
#define GRAPHICS_CURVEDRAWERBEZIER_H

#include "../Drawer.h"
#include "../../Shapes/Curve.h"

class CurveDrawerBezier : public Drawer {
public:
    CurveDrawerBezier();
    void draw(Shape*, HDC&) override;
    Drawer* copy() override;
};


#endif //GRAPHICS_CURVEDRAWERBEZIER_H
