#include "Point.h"

void Point::draw(HDC& hdc) {
    drawer->draw(this, hdc);
}

Point::Point() {
    x = 0;
    y = 0;
    this->id = mp["point"];
}

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
    this->id = mp["point"];
}

void Point::save() {
    //TODO : implement save for point
}

Shape *Point::copy() {
    return nullptr;
}
