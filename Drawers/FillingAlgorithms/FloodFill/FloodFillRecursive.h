//
// Created by Dova on 05/30/22.
//

#ifndef GRAPHICS_FLOODFILLRECURSIVE_H
#define GRAPHICS_FLOODFILLRECURSIVE_H

#include "../../Drawer.h"
class FloodFillRecursive: public Drawer
{
    void draw(Shape *Flood, HDC &hdc);
    void FloodFill(HDC hdc,int x,int y,COLORREF Cb,COLORREF Cf);
    Drawer* copy() override;

};


#endif //GRAPHICS_FLOODFILLRECURSIVE_H
