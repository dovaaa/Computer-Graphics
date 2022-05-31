//
// Created by Mohamed on 5/30/2022.
//

#include "Curve.h"

#include <utility>

Curve::Curve() {
    p1 = Point(0, 0);
    p2 = Point(0, 0);
    p3 = Point(0, 0);
    p4 = Point(0, 0);
    this->id = mp["curve"];
}

Curve::Curve(double x1, double y1, double x2, double y2, double s1x, double s1y, double s2x, double s2y, COLORREF c,
             Drawer *dr) {
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
    string s = to_string(mp["curve"]) + ':' + p1.getAsteriskSave() + '|' + p2.getAsteriskSave() + '|' + p3.getAsteriskSave() + '|' +
               p4.getAsteriskSave() + ',' +
               to_string(c) + ':' + to_string(drawer->id) + '\n';
    f.write(s);
}

Shape *Curve::copy(string s) {
    vector<string> vec = UT::split(s, ',');
    vector<string> points = UT::split(s, '|');
    Point *p[4];
    for (int i = 0; i < points.size(); ++i) {
        vector<string> tmp = UT::split(points[i], '*');
        p[i] = new Point(stoi(tmp[0]), stoi(tmp[1]));
    }
    return new Curve(*p[0], *p[1], *p[2], *p[3], stoi(vec[1]), NULL);
}

Curve::Curve(Point p1, Point p2, Point p3, Point p4, COLORREF c, Drawer *d) {
    this->p1 = std::move(p1);
    this->p2 = std::move(p2);
    this->p3 = std::move(p3);
    this->p4 = std::move(p4);
    this->c = c;
    this->drawer = drawer;
    this->id = mp["curve"];
}




