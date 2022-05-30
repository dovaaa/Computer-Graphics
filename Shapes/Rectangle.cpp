#include "Rectangle.h"

void Rectangle::draw(HDC& hdc) {
    drawer->draw(this, hdc);
}


Rectangle::Rectangle(int xleft, int yleft, int xright, int yright) {
    this->xleft = xleft;
    this->yleft = yleft;
    this->xright = xright;
    this->yright = yright;
    this->id = mp["rectangle"];
}

Rectangle::Rectangle() {
    xleft = 0;
    yleft = 0;
    xright = 0;
    yright = 0;
    this->id = mp["rectangle"];
}

void Rectangle::save() {
    string s =
            to_string(mp["rectangle"]) + ':' + to_string(xleft) + ',' + to_string(yleft) + ',' + to_string(xright) + ',' +
            to_string(yright) + ',' +
            to_string(c) + ' ';
   // f.write(s + drawer->save() + '\n');
}

Shape *Rectangle::copy() {
    return nullptr;
}
