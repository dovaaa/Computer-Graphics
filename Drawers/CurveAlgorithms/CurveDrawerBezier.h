//
// Created by Mohamed on 5/30/2022.
//

#ifndef GRAPHICS_CURVEDRAWERBEZIER_H
#define GRAPHICS_CURVEDRAWERBEZIER_H

#include "../Drawer.h"
#include "../../Shapes/Curve.h"

class CurveDrawerBezier : public Drawer {
public:
    void draw(Shape*, HDC&) override;
};


#endif //GRAPHICS_CURVEDRAWERBEZIER_H
