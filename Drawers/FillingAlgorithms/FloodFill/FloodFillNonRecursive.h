//
// Created by Dova on 05/31/22.
//

#ifndef GRAPHICS_FLOODFILLNONRECURSIVE_H
#define GRAPHICS_FLOODFILLNONRECURSIVE_H

#include "../../Drawer.h"
class FloodFillNonRecursive: public Drawer
{
    void draw(Shape *point, HDC &hdc);
    void NRFloodFill(HDC hdc,int x,int y,COLORREF Cb,COLORREF Cf);
    Drawer* copy() override;
};


#endif //GRAPHICS_FLOODFILLNONRECURSIVE_H
