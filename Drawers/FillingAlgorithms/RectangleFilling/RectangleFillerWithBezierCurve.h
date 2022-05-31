//
// Created by Dova on 05/31/22.
//

#ifndef GRAPHICS_RECTANGLEFILLERWITHBEZIERCURVE_H
#define GRAPHICS_RECTANGLEFILLERWITHBEZIERCURVE_H

#include "../../Drawer.h"

class RectangleFillerWithBezierCurve: public Drawer{
public:
    void draw(Shape *, HDC &hdc) override;
    Drawer* copy() override;
};


#endif //GRAPHICS_RECTANGLEFILLERWITHBEZIERCURVE_H
