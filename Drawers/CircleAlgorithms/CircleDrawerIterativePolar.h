//
// Created by Mohamed on 5/28/2022.
//

#ifndef GRAPHICS_CIRCLEDRAWERITERATIVEPOLAR_H
#define GRAPHICS_CIRCLEDRAWERITERATIVEPOLAR_H

#include "../Drawer.h"
#include "../../Shapes/Circle.h"

class CircleDrawerIterativePolar : public Drawer{
public:
    CircleDrawerIterativePolar();
    void draw(Shape *circle, HDC& hdc) override;
    Drawer* copy() override;
};


#endif //GRAPHICS_CIRCLEDRAWERITERATIVEPOLAR_H
