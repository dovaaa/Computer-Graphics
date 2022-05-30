#include "Shape.h"

#ifndef GRAPHICS_ELLIPSE_H
#define GRAPHICS_ELLIPSE_H


class ELLIPSE : public Shape {
public:
    int cx, cy;
    int a, b;
    ELLIPSE();
    ELLIPSE(int, int, int, int, COLORREF, Drawer*);
    void draw(HDC& hdc) override;
    void save(File &f) override;
    void Draw4Points(HDC , int , int , int , int , COLORREF);
    Shape* copy(string) override;
};



#endif //GRAPHICS_ELLIPSE_H
