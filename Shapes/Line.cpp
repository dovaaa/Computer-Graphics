#include "Line.h"

void Line::draw(HDC& hdc) {
    drawer->draw(this, hdc);
}

Line::Line(int stx, int sty, int edx, int edy, COLORREF c, Drawer* dr) {
    this->stx = stx;
    this->sty = sty;
    this->edx = edx;
    this->edy = edy;
    this->c = c;
    this->drawer = dr;
}

Line::Line() {
    stx = 0;
    sty = 0;
    edx = 0;
    edy = 0;
}

void Line::save() {
    string s = to_string(mp["line"]) + ':' + to_string(stx) + ',' + to_string(sty) + ',' + to_string(edx) + ',' +
               to_string(edy) + ',' +
               to_string(c) + ' ';
 //   f.write(s + drawer->save() + '\n');
}
