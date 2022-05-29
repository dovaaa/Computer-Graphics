//
// Created by AmrMahmoud on 5/28/2022.
//

#include "Circle.h"

void Circle::draw(HDC& hdc) {
    drawer->draw(this, hdc);
}

Circle::Circle() {
    cx = 0;
    cy = 0;
    r = 0;
}

Circle::Circle(int cx, int cy, int r, Drawer* circleDrawer) {
    this->drawer = circleDrawer;
    this->cx = cx;
    this->cy = cy;
    this->r = r;
}

void Circle::save() {
    string s = to_string(mp["circle"]) + ':' + to_string(cx) + ',' + to_string(cy) + ',' + to_string(r) + ',' +
            to_string(c) + ' ';
    //f.write(s + drawer->save() + '\n');
}
