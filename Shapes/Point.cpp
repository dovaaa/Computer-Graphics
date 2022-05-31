#include "Point.h"

void Point::draw(HDC &hdc) {
    drawer->draw(this, hdc);
}

Point::Point() {
    x = 0;
    y = 0;
    this->id = mp["point"];
}

Point::Point(int x, int y, COLORREF c,Drawer *dr) {
    this->x = x;
    this->y = y;
    this->c = c;
    this->id = mp["point"];
    this->drawer=dr;
}


Point::Point(int x, int y) {
    // todo curve drawer use this constructor without color
    this->x = x;
    this->y = y;
    this->id = mp["point"];
}
Point::Point(int x, int y,COLORREF color) {
    // todo curve drawer use this constructor without color
    this->x = x;
    this->y = y;
    this->id = mp["point"];
    this->c=color;
}

void Point::save(File &f) {
    string s = to_string(mp["point"]) + ':' + to_string(x) + ',' + to_string(y) + ',' +
               to_string(c) + ':' + to_string(drawer->id) + '\n';
    f.write(s);
}

Shape *Point::copy(string s) {
    vector<string> vec = UT::split(s, ',');
    return new Point(stoi(vec[0]), stoi(vec[1]), stoi(vec[2]));
}

string Point::getAsteriskSave() {
    return to_string(x) + '*' + to_string(y);
}

string Point::getSave() {
    string s =
            to_string(mp["point"]) + '-' + to_string(x) + ',' + to_string(y) + ',' +
            to_string(c) + '-' + to_string(drawer->id);
    return s;}

