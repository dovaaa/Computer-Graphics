//
// Created by Dova on 05/31/22.
//

#ifndef GRAPHICS_SQUAREHERMITECURVE_H
#define GRAPHICS_SQUAREHERMITECURVE_H

#include "../../Drawer.h"
class SquareHermiteCurve: public Drawer
{
    void draw(Shape *curve, HDC &hdc);
    Drawer* copy() override;

};


#endif //GRAPHICS_SQUAREHERMITECURVE_H
