//
// Created by Mohamed on 5/30/2022.
//

#ifndef GRAPHICS_CIRCLEFILLERWITHLINE_H
#define GRAPHICS_CIRCLEFILLERWITHLINE_H

#include "../../Drawer.h"
#include "../../../Shapes/Shape.h"


class CircleFillerWithLine : public Drawer {
public:
    void draw(Shape* circle, HDC& hdc) override;
    void Draw2LinesQuarter1(HDC &hdc, int xc, int yc, int a, int b, COLORREF color);
    void Draw2LinesQuarter2(HDC &hdc, int xc, int yc, int a, int b, COLORREF color);
    void Draw2LinesQuarter3(HDC &hdc, int xc, int yc, int a, int b, COLORREF color);
    void Draw2LinesQuarter4(HDC &hdc, int xc, int yc, int a, int b, COLORREF color);
};


#endif //GRAPHICS_CIRCLEFILLERWITHLINE_H
