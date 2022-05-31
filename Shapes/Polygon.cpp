//
// Created by Dova on 05/30/22.
//

#include "Polygon.h"

void Polygon::draw(HDC &hdc) {
    drawer->draw(this, hdc);
}

Polygon::Polygon() {
    this->points = new Point;
    this->n = 0;
    this->id = mp["Polygon"];
}

Polygon::Polygon(Point *points, int n) {
    this->points = points;
    this->n = n;
    this->id = mp["Polygon"];
}

void Polygon::save(File &f) {
    string s = to_string(mp["polygon"]) + ':' + to_string(n) + ',';
    for (int i = 0; i < n; ++i) {
        s += points[i].getSave();
        if (i + 1 != n)
            s += '|';
    }
    s += ':' + to_string(drawer->id) + '\n';
    f.write(s);
}

Shape *Polygon::copy(string s) {
    vector<string> vec = UT::split(s, ',');
    vector<string> ps = UT::split(vec[1], '|');
    int nn = stoi(vec[0]);
    Point *p = new Point[nn];
    for (int i = 0; i < nn; ++i) {
        vector<string> tmp = UT::split(ps[i], '-');
        p[i] = Point(stoi(tmp[0]), stoi(tmp[1]));
    }
    return new Polygon(p, nn);
}
