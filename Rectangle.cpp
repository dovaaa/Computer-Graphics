#include "Rectangle.h"

void Rectangle::draw() {
    drawer.draw(this);
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
