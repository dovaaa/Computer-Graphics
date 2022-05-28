#include "Point.h"

void Point::draw() {
    drawer.draw(this);
}

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}
