#include "Rectangle.h"

void RECTANGLE::draw(HDC &hdc) {
    drawer->draw(this, hdc);
}


RECTANGLE::RECTANGLE(int xleft, int yleft, int xright, int yright, COLORREF c, Drawer *d) {
    this->xleft = xleft;
    this->yleft = yleft;
    this->xright = xright;
    this->yright = yright;
    this->drawer = d;
    this->c = c;
    this->id = mp["rectangle"];
}

RECTANGLE::RECTANGLE() {
    xleft = 0;
    yleft = 0;
    xright = 0;
    yright = 0;
    this->id = mp["rectangle"];
}

void RECTANGLE::save(File &f) {
    string s =
            to_string(mp["rectangle"]) + ':' + to_string(xleft) + ',' + to_string(yleft) + ',' + to_string(xright) +
            ',' +
            to_string(yright) + ',' +
            to_string(c) + ':' + to_string(drawer->id) + '\n';
    f.write(s);
}

Shape *RECTANGLE::copy(string s) {
    vector<string> vec = UT::split(s, ',');
    return new RECTANGLE(stoi(vec[0]), stoi(vec[1]), stoi(vec[2]), stoi(vec[3]), stoi(vec[4]), NULL);
}

string RECTANGLE::getSave() {
    string s =
            to_string(mp["rectangle"]) + '-' + to_string(xleft) + ',' + to_string(yleft) + ',' + to_string(xright) +
            ',' +
            to_string(yright) + ',' +
            to_string(c) + '-' + to_string(drawer->id);
    return s;
}
