//
// Created by Mohamed on 5/28/2022.
//

#ifndef GRAPHICS_CIRCLEDRAWERPOLAR_H
#define GRAPHICS_CIRCLEDRAWERPOLAR_H
#include "../Drawer.h"
#include "../../Shapes/Circle.h"

class CircleDrawerPolar : public Drawer{
public:
    void draw(Shape *circle) override;
};


#endif //GRAPHICS_CIRCLEDRAWERPOLAR_H
