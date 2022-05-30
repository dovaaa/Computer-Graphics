//
// Created by Mohamed on 5/31/2022.
//

#ifndef GRAPHICS_POINTDRAWER_H
#define GRAPHICS_POINTDRAWER_H

#include "../Drawer.h"
#include "../../Shapes/Shape.h"

class PointDrawer : public Drawer{
public:
    void draw(Shape* point, HDC& hdc) override;
};


#endif //GRAPHICS_POINTDRAWER_H
