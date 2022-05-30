//
// Created by Dova on 05/31/22.
//

#ifndef GRAPHICS_FLOOD_H
#define GRAPHICS_FLOOD_H
#include "Shape.h"
#include "Point.h"

class Flood:public Shape {
public:
    COLORREF borderColor;
    Point p;
    Flood();
    Flood(Point,COLORREF);
    void draw(HDC& hdc) override;
    void save(File &f) override;
    Shape* copy(string s) override;

};


#endif //GRAPHICS_FLOOD_H
