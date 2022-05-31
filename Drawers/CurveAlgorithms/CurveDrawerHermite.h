//
// Created by Mohamed on 5/31/2022.
//

#ifndef GRAPHICS_CURVEDRAWERHERMITE_H
#define GRAPHICS_CURVEDRAWERHERMITE_H

#include "../Drawer.h"
#include "../../Shapes/Curve.h"

class CurveDrawerHermite : public Drawer {
public:
    CurveDrawerHermite();
    void draw(Shape*, HDC&) override;
    Drawer* copy() override;
};


#endif //GRAPHICS_CURVEDRAWERHERMITE_H
