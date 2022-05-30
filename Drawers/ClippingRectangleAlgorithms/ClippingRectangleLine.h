//
// Created by Dova on 05/30/22.
//

#ifndef GRAPHICS_CLIPPINGRECTANGLELINE_H
#define GRAPHICS_CLIPPINGRECTANGLELINE_H
#include "../Drawer.h"


class ClippingRectangleLine:public Drawer
{
public:
    void draw(Shape *rectangle,Shape *line,HDC& hdc);
    Drawer* copy() override;
};


#endif //GRAPHICS_CLIPPINGRECTANGLELINE_H
