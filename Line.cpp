#include "Line.h"

void Line::draw() {
    drawer.draw(this);
}

Line::Line(int stx, int sty, int edx, int edy) {
    this->stx = stx;
    this->sty = sty;
    this->edx = edx;
    this->edy = edy;
}

Line::Line() {
    stx = 0;
    sty = 0;
    edx = 0;
    edy = 0;
}
