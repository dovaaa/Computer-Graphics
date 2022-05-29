//
// Created by AmrMahmoud on 5/28/2022.
//

#include "ELLIPSE.h"

void ELLIPSE::draw(HDC& hdc) {
    drawer->draw(this, hdc);
}

ELLIPSE::ELLIPSE() {
    cx = 0;
    cy = 0;
    a = 0;
    b = 0;
}

ELLIPSE::ELLIPSE(int cx, int cy, int a, int b) {
    this->cx = cx;
    this->cy = cy;
    this->a = a;
    this->b = b;
}

void ELLIPSE::save() {
    string s = to_string(mp["ellipse"]) + ':' + to_string(cx) + ',' + to_string(cy) + ',' + to_string(a) + ',' +
               to_string(b) + ',' +
               to_string(c) + ' ';
    //f.write(s + drawer->save() + '\n');
}

void ELLIPSE::Draw4Points(HDC hdc, int xc, int yc, int x, int y, COLORREF color) {
    SetPixel(hdc, x + xc, y + yc, color);
    SetPixel(hdc, -x + xc, y + yc, color);
    SetPixel(hdc, x + xc, -y + yc, color);
    SetPixel(hdc, -x + xc, -y + yc, color);

}
