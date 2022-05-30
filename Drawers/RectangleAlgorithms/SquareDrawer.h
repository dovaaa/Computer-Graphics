//
// Created by Dova on 05/31/22.
//

#ifndef GRAPHICS_SQUAREDRAWER_H
#define GRAPHICS_SQUAREDRAWER_H

#include "../Drawer.h"
#include "../../Shapes/Square.h"

class SquareDrawer : public Drawer
{
public:
    void draw(Shape *square, HDC& hdc) override;
    Drawer* copy() override;
};


#endif //GRAPHICS_SQUAREDRAWER_H
