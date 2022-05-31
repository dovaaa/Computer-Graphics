//
// Created by Dova on 05/31/22.
//

#ifndef GRAPHICS_POLYGONDRAWER_H
#define GRAPHICS_POLYGONDRAWER_H
#include "../Drawer.h"

class PolygonDrawer: public Drawer{
public:
    PolygonDrawer();
    void draw(Shape* polygon, HDC& hdc) override;
    Drawer* copy() override;
};


#endif //GRAPHICS_POLYGONDRAWER_H
