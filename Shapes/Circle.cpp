//
// Created by AmrMahmoud on 5/28/2022.
//

#include "Circle.h"

void Circle::draw(HDC &hdc) {
    drawer->draw(this, hdc);
}

Circle::Circle() {
    cx = 0;
    cy = 0;
    r = 0;
    this->id = mp["circle"];
}

Circle::Circle(int cx, int cy, int r, COLORREF c, Drawer *circleDrawer) {
    this->drawer = circleDrawer;
    this->cx = cx;
    this->cy = cy;
    this->r = r;
    this->c = c;
    this->id = mp["circle"];
}

void Circle::Draw8Points(HDC &hdc, int xc, int yc, int a, int b, COLORREF color) {
    SetPixel(hdc, xc + a, yc + b, color);
    SetPixel(hdc, xc - a, yc + b, color);
    SetPixel(hdc, xc - a, yc - b, color);
    SetPixel(hdc, xc + a, yc - b, color);
    SetPixel(hdc, xc + b, yc + a, color);
    SetPixel(hdc, xc - b, yc + a, color);
    SetPixel(hdc, xc - b, yc - a, color);
    SetPixel(hdc, xc + b, yc - a, color);
}

void Circle::save(File &f) {
    string s = to_string(mp["circle"]) + ':' + to_string(cx) + ',' + to_string(cy) + ',' + to_string(r) + ',' +
               to_string(c) + ':' + to_string(drawer->id) + '\n';
    f.write(s);
}

Shape *Circle::copy(string s) {
    vector<string> vec = UT::split(s, ',');
    return new Circle(stoi(vec[0]), stoi(vec[1]), stoi(vec[2]), stoi(vec[3]), NULL);
}


