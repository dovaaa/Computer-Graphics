#ifndef GRAPHICS_SHAPE_H
#define GRAPHICS_SHAPE_H

#include "../Drawers/Drawer.h"
#include "../File.h"
#include <map>
#include <iostream>
using namespace std;
class Drawer;


class Shape {
public:
    File f;
    static map<string, int> mp;
    Drawer *drawer;
    COLORREF c;
    virtual void draw(HDC& hdc) = 0;
    virtual void save() = 0;
};


#endif //GRAPHICS_SHAPE_H
