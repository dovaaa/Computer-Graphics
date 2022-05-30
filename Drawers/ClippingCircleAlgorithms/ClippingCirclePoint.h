//
// Created by Dova on 05/30/22.
//

#ifndef GRAPHICS_CLIPPINGCIRCLEPOINT_H
#define GRAPHICS_CLIPPINGCIRCLEPOINT_H
#include "../Drawer.h"


class ClippingCirclePoint:public Drawer
{
public:
    void draw(Shape *Circle,Shape *point,HDC& hdc);
};



#endif //GRAPHICS_CLIPPINGCIRCLEPOINT_H
