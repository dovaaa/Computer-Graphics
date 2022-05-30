//
// Created by Mohamed on 5/30/2022.
//

#include "Curve.h"

Curve::Curve() {
    p1 = Point(0, 0);
    p2 = Point(0, 0);
    p3 = Point(0, 0);
    p4 = Point(0, 0);
    this->id = mp["curve"];
}

Curve::Curve(double x1, double y1, double x2, double y2, double s1x, double s1y, double s2x, double s2y, COLORREF c, Drawer *dr) {
    p1 = Point(x1, y1);
    p2 = Point(x2, y2);
    p3 = Point(s1x, s1y);
    p4 = Point(s2x, s2y);
    this->c = c;
    drawer = dr;
    this->id = mp["curve"];
}

void Curve::draw(HDC &hdc) {
    this->drawer->draw(this, hdc);
}

void Curve::save(File &f) {
    string s = to_string(mp["curve"]) + ':' + p1.getSave() + ',' + p2.getSave() + ',' + p3.getSave() + ',' +
               p4.getSave() + ',' +
               to_string(c) + ':' + to_string(drawer->id) + '\n';
    f.write(s);
}

Shape *Curve::copy(string s) {
    return nullptr;
}




