#include "Shape.h"

#ifndef GRAPHICS_ELLIPSE_H
#define GRAPHICS_ELLIPSE_H


class Ellipse : public Shape {
public:
    int cx, cy;
    int a, b;
    Ellipse();
    Ellipse(int, int, int, int);
    void draw(HDC& hdc) override;
    void save() override;
    void Draw4Points(HDC , int , int , int , int , COLORREF);
};



#endif //GRAPHICS_ELLIPSE_H
