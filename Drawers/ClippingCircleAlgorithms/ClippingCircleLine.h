//
// Created by Dova on 05/30/22.
//

#ifndef GRAPHICS_CLIPPINGCIRCLELINE_H
#define GRAPHICS_CLIPPINGCIRCLELINE_H

#include "../Drawer.h"

class ClippingCircleLine : public Drawer {
public:
    ClippingCircleLine();
    void draw(Shape *Circle, Shape *line, HDC &hdc);
    void draw(Shape *, HDC &) override;
    Drawer *copy() override;
};


#endif //GRAPHICS_CLIPPINGCIRCLELINE_H
