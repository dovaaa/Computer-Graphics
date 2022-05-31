//
// Created by Dova on 05/31/22.
//

#ifndef GRAPHICS_SQUARE_H
#define GRAPHICS_SQUARE_H

#include "Shape.h"
#include "../Drawers/Drawer.h"

class Square : public Shape {
public:
    int x1, y1;
    int x2, y2;
    Drawer* drawer;

    Square();

    Square(int, int, int, int, COLORREF, Drawer *);

    void draw(HDC &hdc) override;

    void save(File &f) override;

    Shape *copy(string) override;
};


#endif //GRAPHICS_SQUARE_H
