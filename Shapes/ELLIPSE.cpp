//
// Created by AmrMahmoud on 5/28/2022.
//

#include "ELLIPSE.h"

void ELLIPSE::draw(HDC &hdc) {
    drawer->draw(this, hdc);
}

ELLIPSE::ELLIPSE() {
    cx = 0;
    cy = 0;
    a = 0;
    b = 0;
    this->id = mp["ellipse"];
}

ELLIPSE::ELLIPSE(int cx, int cy, int a, int b, COLORREF c, Drawer *ellipseDrawer) {
    this->drawer = ellipseDrawer;
    this->cx = cx;
    this->cy = cy;
    this->a = a;
    this->b = b;
    this->c = c;
    this->id = mp["ellipse"];
}

void ELLIPSE::save(File &f) {
    string s = to_string(mp["ellipse"]) + ':' + to_string(cx) + ',' + to_string(cy) + ',' + to_string(a) + ',' +
               to_string(b) + ',' +
               to_string(c) + ':' + to_string(drawer->id) + '\n';
    f.write(s);
}

void ELLIPSE::Draw4Points(HDC hdc, int xc, int yc, int x, int y, COLORREF color) {
    SetPixel(hdc, x + xc, y + yc, color);
    SetPixel(hdc, -x + xc, y + yc, color);
    SetPixel(hdc, x + xc, -y + yc, color);
    SetPixel(hdc, -x + xc, -y + yc, color);

}

Shape *ELLIPSE::copy(string s) {
    vector<string> vec = UT::split(s, ',');
    int x = stoi(vec[0]);
    int y = stoi(vec[1]);
    int rad = stoi(vec[2]);
    COLORREF cc = stoi(vec[3]);
    return new ELLIPSE(stoi(vec[0]), stoi(vec[0]), stoi(vec[0]), stoi(vec[0]), stoi(vec[0]), NULL);
}
