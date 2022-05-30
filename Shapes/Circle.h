#ifndef GRAPHICS_CIRCLE_H
#define GRAPHICS_CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
public:
    int cx, cy, r;
    Circle();
    Circle(int, int, int, Drawer*);
    void draw(HDC& hdc) override;
    void save(File &f) override;
    void Draw8Points(HDC&, int, int, int, int, COLORREF);
    Shape* copy(string) override;
};



#endif //GRAPHICS_CIRCLE_H
