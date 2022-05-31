//
// Created by Mohamed on 5/28/2022.
//

#ifndef GRAPHICS_CIRCLEDRAWERMODIFIEDMIDPOINT_H
#define GRAPHICS_CIRCLEDRAWERMODIFIEDMIDPOINT_H
#include "../Drawer.h"

class CircleDrawerModifiedMidpoint : public Drawer{
public:
    CircleDrawerModifiedMidpoint();
    void draw(Shape *circle, HDC& hdc) override;
    Drawer* copy() override;
};

#endif //GRAPHICS_CIRCLEDRAWERMODIFIEDMIDPOINT_H
