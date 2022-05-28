//
// Created by AmrMahmoud on 5/28/2022.
//

#include "Circle.h"

void Circle::draw() {
    drawer->draw(this);
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
