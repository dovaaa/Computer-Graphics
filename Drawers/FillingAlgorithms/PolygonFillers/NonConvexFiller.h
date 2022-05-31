//
// Created by Dova on 05/30/22.
//

#ifndef GRAPHICS_NONCONVEXFILLER_H
#define GRAPHICS_NONCONVEXFILLER_H
#include "../../Drawer.h"

class NonConvexFiller: public Drawer
{
public:

    void draw(Shape *polygon, HDC &hdc);
    Drawer* copy() override;
    NonConvexFiller();

};

#endif //GRAPHICS_NONCONVEXFILLER_H
