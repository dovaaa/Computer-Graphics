
#ifndef GRAPHICS_POINT_H
#define GRAPHICS_POINT_H

#include "Shape.h"
class Point : public Shape {
public:


    int x, y;
    Point();
    Point(int, int, COLORREF,Drawer*);
    Point(int, int, COLORREF);
    Point(int, int);
    void draw(HDC& hdc) override;
    void save(File &f) override;
    Shape* copy(string) override;
    string getSave();
};



#endif //GRAPHICS_POINT_H
