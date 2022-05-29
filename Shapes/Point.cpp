#include "Point.h"

void Point::draw(HDC& hdc) {
    drawer->draw(this, hdc);
}

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}
