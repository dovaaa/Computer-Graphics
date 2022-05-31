
#ifndef GRAPHICS_RECTANGLE_H
#define GRAPHICS_RECTANGLE_H

#include "Shape.h"

class RECTANGLE : public Shape {
public:
    int xright, yright;
    int xleft, yleft;

    RECTANGLE();

    RECTANGLE(int, int, int, int, COLORREF, Drawer*);

    void draw(HDC& hdc) override;
    void save(File &f) override;
    Shape* copy(string) override;
};


#endif //GRAPHICS_RECTANGLE_H
