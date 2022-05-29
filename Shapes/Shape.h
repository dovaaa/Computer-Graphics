#ifndef GRAPHICS_SHAPE_H
#define GRAPHICS_SHAPE_H

#include "../Drawers/Drawer.h"
#include <map>
#include <iostream>
using namespace std;
class Drawer;

class Shape {
public:
    static map<string, int> mp;
    Drawer *drawer;
    COLORREF c;
    virtual void draw() = 0;
};


#endif //GRAPHICS_SHAPE_H
