//
// Created by Dova on 05/31/22.
//

#ifndef GRAPHICS_RECTANGLEDRAWER_H
#define GRAPHICS_RECTANGLEDRAWER_H
#include "../Drawer.h"
#include "../../Shapes/Rectangle.h"

class RectangleDrawer: public Drawer{
public:
    void draw(Shape *rectangle, HDC& hdc) override;
    Drawer* copy() override;
};


#endif //GRAPHICS_RECTANGLEDRAWER_H
