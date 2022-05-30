//
// Created by Mohamed on 5/30/2022.
//

#ifndef GRAPHICS_CIRCLEFILLERWITHCIRCLE_H
#define GRAPHICS_CIRCLEFILLERWITHCIRCLE_H

#include "../../Drawer.h"
#include "../../../Shapes/Shape.h"

class CircleFillerWithCircle : public Drawer{
public:
    void draw(Shape* circle, HDC& hdc) override;
    void Draw2PointsQuarter1(HDC&, int, int, int, int, COLORREF);
    void Draw2PointsQuarter2(HDC&, int, int, int, int, COLORREF);
    void Draw2PointsQuarter3(HDC&, int, int, int, int, COLORREF);
    void Draw2PointsQuarter4(HDC&, int, int, int, int, COLORREF);
};


#endif //GRAPHICS_CIRCLEFILLERWITHCIRCLE_H
