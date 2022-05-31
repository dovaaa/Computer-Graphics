
#ifndef GRAPHICS_LINE_H
#define GRAPHICS_LINE_H


#include "Shape.h"
class Line : public Shape {
public:
    int stx, sty;
    int edx, edy;
    Line();
    Line(int, int, int, int, COLORREF, Drawer* dr);
    void draw(HDC& hdc) override;
    void save(File &f) override;
    Shape* copy(string) override;
    string getSave() override;
};


#endif //GRAPHICS_LINE_H
