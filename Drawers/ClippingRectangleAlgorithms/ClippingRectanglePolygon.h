//
// Created by Dova on 05/30/22.
//

#ifndef GRAPHICS_CLIPPINGRECTANGLEPOLYGON_H
#define GRAPHICS_CLIPPINGRECTANGLEPOLYGON_H
#include "../Drawer.h"


class ClippingRectanglePolygon:public Drawer
{
public:

    void draw(Shape *rectangle, Shape *polygon, HDC &hdc);
    Drawer* copy() override;
};


#endif //GRAPHICS_CLIPPINGRECTANGLEPOLYGON_H
