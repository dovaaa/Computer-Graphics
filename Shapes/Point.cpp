#include "Point.h"

void Point::draw(HDC &hdc) {
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

void Point::save(File &f) {
    string s = to_string(mp["point"]) + ':' + to_string(x) + ',' + to_string(y) + ',' +
               to_string(c) + ':' + to_string(drawer->id) + '\n';
    f.write(s);
}

Shape *Point::copy(string s) {
    return nullptr;
}

string Point::getSave() {
    return to_string(x) + '-' + to_string(y);
}
