#include "Shape.h"

#ifndef GRAPHICS_POINT_H
#define GRAPHICS_POINT_H

class Point : public Shape {
public:
    double x, y;
    Point();
    Point(double, double);
    void draw(HDC& hdc) override;
    void save(File &f) override;
    Shape* copy(string) override;
    string getSave();
};



#endif //GRAPHICS_POINT_H
