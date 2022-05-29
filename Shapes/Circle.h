#ifndef GRAPHICS_CIRCLE_H
#define GRAPHICS_CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
public:
    int cx, cy, r;
    Circle();
    Circle(int, int, int, Drawer*);
    void draw(HDC& hdc) override;
    void save() override;
    void Draw8Points(HDC ,int ,int , int , int ,COLORREF );
};



#endif //GRAPHICS_CIRCLE_H
