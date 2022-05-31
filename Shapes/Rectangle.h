
#ifndef GRAPHICS_RECTANGLE_H
#define GRAPHICS_RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
public:
    int xright, yright;
    int xleft, yleft;

    Rectangle();

    Rectangle(int, int, int, int, Drawer*);

    void draw(HDC& hdc) override;
    void save(File &f) override;
    Shape* copy(string) override;
};


#endif //GRAPHICS_RECTANGLE_H
