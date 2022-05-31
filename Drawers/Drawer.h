//
// Created by Mohamed on 5/28/2022.
//

#ifndef GRAPHICS_DRAWER_H
#define GRAPHICS_DRAWER_H
#include <Windows.h>

#include "../Shapes/Shape.h"
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Shape;

class Drawer {
public:
    static map<std::string, int> mp;
    static void addDrawer(std::string, Drawer*);
    int id;
    static vector<Drawer*> drawers;
    virtual Drawer* copy() = 0;
    virtual void draw(Shape*, HDC&) = 0;
    //virtual std::string save() = 0;
};


#endif //GRAPHICS_DRAWER_H
