//
// Created by Dova on 05/30/22.
//

#ifndef GRAPHICS_CONVEXFILLER_H
#define GRAPHICS_CONVEXFILLER_H


#include "../../Drawer.h"

class ConvexFiller: public Drawer
{
    void draw(Shape *polygon, HDC &hdc);
    Drawer* copy() override;

};


#endif //GRAPHICS_CONVEXFILLER_H
