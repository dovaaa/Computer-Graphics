//
// Created by AmrMahmoud on 5/28/2022.
//

#include "Ellipse.h"

void Ellipse::draw(HDC& hdc) {
    drawer->draw(this, hdc);
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

void Ellipse::save() {
    string s = to_string(mp["ellipse"]) + ':' + to_string(cx) + ',' + to_string(cy) + ',' + to_string(a) + ',' +
               to_string(b) + ',' +
               to_string(c) + ' ';
    //f.write(s + drawer->save() + '\n');
}
