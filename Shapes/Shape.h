#ifndef GRAPHICS_SHAPE_H
#define GRAPHICS_SHAPE_H

#include "../Drawers/Drawer.h"
#include "../File.h"
#include <map>
#include <vector>
#include <iostream>
using namespace std;
class Drawer;


class Shape {
public:
    Shape(){

    };
    static map<string, int> mp;
    static void addShape(string, Shape*);
    static int idx;
    static vector<Shape*> shapes;
    int id;
    Drawer *drawer;
    COLORREF c;
    virtual Shape* copy(string) = 0;
    virtual void draw(HDC& hdc) = 0;
    virtual void save(File &f) = 0;
};


#endif //GRAPHICS_SHAPE_H
