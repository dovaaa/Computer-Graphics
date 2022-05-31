//
// Created by Dova on 05/31/22.
//

#include "Flood.h"

Flood::Flood() {

}

Flood::Flood(Point p, COLORREF borderColor, Drawer *dr) {
    this->p = p;
    this->borderColor = borderColor;
    this->drawer = dr;
}

Flood::Flood(Point p, COLORREF c, COLORREF borderColor, Drawer * dr) {
    this->p = p;
    this->borderColor = borderColor;
    this->c = c;
    this->drawer = dr;
}

void Flood::draw(HDC &hdc) {
    drawer->draw(this, hdc);
}

Shape *Flood::copy(string s) {
    vector<string> vec = UT::split(s, ',');
        vector<string> tmp = UT::split(vec[0], '-');
    Point pp(stoi(tmp[0]), stoi(tmp[1]));
    return new Flood(pp, stoi(vec[1]), stoi(vec[2]), NULL);
}

void Flood::save(File &f) {
    string s = to_string(mp["flood"]) + ':' + p.getSave() + ',' +
               to_string(c) + ',' + to_string(borderColor) + ':' + to_string(drawer->id) + '\n';
    f.write(s);
}




