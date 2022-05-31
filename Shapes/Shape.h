#ifndef GRAPHICS_SHAPE_H
#define GRAPHICS_SHAPE_H


#include "../Drawers/Drawer.h"
#include "../File.h"
#include <map>
#include "../Utility.h"
class Drawer;


class Shape {
public:
    Shape(){

    };
    static std::map<std::string, int> mp;
    static void addShape(std::string, Shape*);
    static std::vector<Shape*> shapes;
    int id;
    Drawer *drawer;
    COLORREF c;
    virtual std::string getSave();
    virtual Shape* copy(std::string) = 0;
    virtual void draw(HDC& hdc) = 0;
    virtual void save(File &f) = 0;
};


#endif //GRAPHICS_SHAPE_H
