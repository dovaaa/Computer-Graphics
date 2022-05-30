//
// Created by Mohamed on 5/28/2022.
//

#ifndef GRAPHICS_LINEDRAWERDDA_H
#define GRAPHICS_LINEDRAWERDDA_H
#include "../Drawer.h"
#include "../../Shapes/Shape.h"
#include <Windows.h>

class LineDrawerDDA : public Drawer {
public:
    void draw(Shape *line, HDC& hdc) override;
    Drawer* copy() override;
};


#endif //GRAPHICS_LINEDRAWERDDA_H
