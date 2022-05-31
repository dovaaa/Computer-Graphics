//
// Created by Dova on 05/31/22.
//

#include "Square.h"

Square::Square() {
    this->x1 = 0;
    this->y1 = 0;
    this->y2 = 0;
    this->x2 = 0;
    this->id = mp["square"];
}

Square::Square(int x1, int y1, int x2, int y2, COLORREF c, Drawer *dr) {
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    this->c = c;
    this->drawer = dr;
    this->id = mp["square"];
}

void Square::draw(HDC &hdc) {
    drawer->draw(this, hdc);
}

void Square::save(File &f) {
    string s =
            to_string(mp["square"]) + ':' + to_string(x1) + ',' + to_string(y1) + ',' + to_string(x2) +
            ',' +
            to_string(y2) + ',' +
            to_string(c) + ':' + to_string(drawer->id) + '\n';
    f.write(s);
}

Shape *Square::copy(string s) {
    vector<string> vec = UT::split(s, ',');
    return new Square(stoi(vec[0]), stoi(vec[1]), stoi(vec[2]), stoi(vec[3]), stoi(vec[4]), NULL);
}
