//
// Created by Dova on 05/30/22.
//

#ifndef GRAPHICS_POLYGON_H
#define GRAPHICS_POLYGON_H

#include "Shape.h"
#include "Point.h"

class Polygon:public Shape
{
public:
    Point* points;
    int n;
    Polygon();
    Polygon(Point*,int);
    void draw(HDC& hdc) override;
    void save() override;
    Shape* copy() override;
};


#endif //GRAPHICS_POLYGON_H
