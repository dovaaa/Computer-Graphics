//
// Created by AmrMahmoud on 5/28/2022.
//

#include "Ellipse.h"

void Ellipse::draw() {
    drawer.draw(this);
}

Ellipse::Ellipse() {
    cx = 0;
    cy = 0;
    a = 0;
    b = 0;
}

Ellipse::Ellipse(int cx, int cy, int a, int b) {
    this->cx = cx;
    this->cy = cy;
    this->a = a;
    this->b = b;
}
