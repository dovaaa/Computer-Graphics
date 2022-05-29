//
// Created by AmrMahmoud on 5/28/2022.
//

#include "ELLIPSE.h"

void ELLIPSE::draw() {
    drawer->draw(this);
}

ELLIPSE::ELLIPSE(){
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

void ELLIPSE::Draw4Points(HDC hdc, int xc, int yc, int x, int y, COLORREF color) {
    SetPixel(hdc, x + xc, y + yc, color);
    SetPixel(hdc, -x + xc, y + yc, color);
    SetPixel(hdc, x + xc, -y + yc, color);
    SetPixel(hdc, -x + xc, -y + yc, color);

}