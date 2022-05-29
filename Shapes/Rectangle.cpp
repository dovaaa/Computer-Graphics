#include "Rectangle.h"

void Rectangle::draw(HDC& hdc) {
    drawer->draw(this, hdc);
}

Rectangle::Rectangle(int stx, int sty, int length, int width) {
    this->stx = stx;
    this->sty = sty;
    this->length = length;
    this->width = width;
}

Rectangle::Rectangle() {
    stx = 0;
    sty = 0;
    length = 0;
    width = 0;
}

void Rectangle::save() {
    string s =
            to_string(mp["rectangle"]) + ':' + to_string(stx) + ',' + to_string(sty) + ',' + to_string(length) + ',' +
            to_string(width) + ',' +
            to_string(c) + ' ';
   // f.write(s + drawer->save() + '\n');
}
