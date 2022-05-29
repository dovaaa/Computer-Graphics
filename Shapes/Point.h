#include "Shape.h"

#ifndef GRAPHICS_POINT_H
#define GRAPHICS_POINT_H

class Point : public Shape {
public:
    int x, y;
    Point();
    Point(int, int);
    void draw(HDC& hdc) override;
};



#endif //GRAPHICS_POINT_H
