//
// Created by Dova on 05/30/22.
//

#ifndef GRAPHICS_CLIPPINGRECTANGLEPOLYGON_H
#define GRAPHICS_CLIPPINGRECTANGLEPOLYGON_H
#include "../Drawer.h"


class ClippingRectanglePolygon:public Drawer
{
public:

    void draw(Shape *rectangle, POINT *points, int n, HDC &hdc);
    Drawer* copy() override;
};


#endif //GRAPHICS_CLIPPINGRECTANGLEPOLYGON_H
