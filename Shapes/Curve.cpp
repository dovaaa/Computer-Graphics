//
// Created by Mohamed on 5/30/2022.
//

#include "Curve.h"

Curve::Curve() {
    p1 = Point(0, 0);
    p2 = Point(0, 0);
    p3 = Point(0, 0);
    p4 = Point(0, 0);
}

Curve::Curve(double x1, double y1, double x2, double y2, double s1x, double s1y, double s2x, double s2y, Drawer *dr) {
    p1 = Point(x1, y1);
    p2 = Point(x2, y2);
    p3 = Point(s1x, s1y);
    p4 = Point(s2x, s2y);
    drawer = dr;
}

void Curve::draw(HDC &hdc) {
    this->drawer->draw(this, hdc);
}

void Curve::save() {
    //TODO : implement save for curve
}




