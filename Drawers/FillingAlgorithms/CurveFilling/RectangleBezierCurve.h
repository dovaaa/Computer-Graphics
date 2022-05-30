//
// Created by Dova on 05/31/22.
//

#ifndef GRAPHICS_RECTANGLEBEZIERCURVE_H
#define GRAPHICS_RECTANGLEBEZIERCURVE_H

#include "../../Drawer.h"
class RectangleBezierCurve: public Drawer
{
    void draw(Shape *curve, HDC &hdc);
    Drawer* copy() override;

};


#endif //GRAPHICS_RECTANGLEBEZIERCURVE_H
