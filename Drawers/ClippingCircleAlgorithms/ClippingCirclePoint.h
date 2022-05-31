//
// Created by Dova on 05/30/22.
//

#ifndef GRAPHICS_CLIPPINGCIRCLEPOINT_H
#define GRAPHICS_CLIPPINGCIRCLEPOINT_H

#include "../Drawer.h"


class ClippingCirclePoint : public Drawer {
public:
    ClippingCirclePoint();
    void draw(Shape *Circle, Shape *point, HDC &hdc);
    void draw(Shape *, HDC &);
    Drawer *copy() override;
};


#endif //GRAPHICS_CLIPPINGCIRCLEPOINT_H
