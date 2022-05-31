//
// Created by Mohamed on 5/28/2022.
//

#ifndef GRAPHICS_CIRCLEDRAWERDIRECT_H
#define GRAPHICS_CIRCLEDRAWERDIRECT_H
#include "../Drawer.h"
#include "../../Shapes/Circle.h"

class CircleDrawerDirect : public Drawer{
public:
    CircleDrawerDirect();
    void draw(Shape *circle, HDC& hdc) override;
    Drawer* copy() override;
};


#endif //GRAPHICS_CIRCLEDRAWERDIRECT_H
