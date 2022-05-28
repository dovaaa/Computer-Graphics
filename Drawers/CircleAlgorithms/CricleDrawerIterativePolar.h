//
// Created by Mohamed on 5/28/2022.
//

#ifndef GRAPHICS_CRICLEDRAWERITERATIVEPOLAR_H
#define GRAPHICS_CRICLEDRAWERITERATIVEPOLAR_H

#include "../Drawer.h"
#include "../../Shapes/Circle.h"

class CricleDrawerIterativePolar : public Drawer{
public:
    void draw(Shape *circle) override;
};


#endif //GRAPHICS_CRICLEDRAWERITERATIVEPOLAR_H
