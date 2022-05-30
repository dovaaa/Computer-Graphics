//
// Created by Dova on 05/30/22.
//

#ifndef GRAPHICS_CLIPPINGCIRCLELINE_H
#define GRAPHICS_CLIPPINGCIRCLELINE_H
#include "../Drawer.h"

class ClippingCircleLine:public Drawer
{
public:
    void draw(Shape *Circle,Shape *line,HDC& hdc);
};


#endif //GRAPHICS_CLIPPINGCIRCLELINE_H
