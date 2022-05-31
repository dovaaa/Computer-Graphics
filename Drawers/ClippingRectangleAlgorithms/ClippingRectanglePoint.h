//
// Created by Dova on 05/30/22.
//

#ifndef GRAPHICS_CLIPPINGRECTANGLEPOINT_H
#define GRAPHICS_CLIPPINGRECTANGLEPOINT_H
#include "../Drawer.h"


class ClippingRectanglePoint :public Drawer
{
public:
    void draw(Shape *rectangle,Shape *point,HDC& hdc);
    void draw(Shape*, HDC&);
    Drawer* copy() override;
};


#endif //GRAPHICS_CLIPPINGRECTANGLEPOINT_H
