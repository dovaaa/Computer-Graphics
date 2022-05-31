//
// Created by Dova on 05/31/22.
//

#include "FloodFillNonRecursive.h"
#include "../../../Shapes/Flood.h"

#include <stack>
#include <iostream>
#include <utility>

using namespace std;

void FloodFillNonRecursive::NRFloodFill(HDC &hdc, int x, int y, COLORREF Cb, COLORREF Cf) {
    stack<pair<int, int>> S;
    S.push(make_pair(x, y));
    while (!S.empty()) {
        pair<int, int> v = S.top();
        S.pop();
        COLORREF c = GetPixel(hdc, v.first, v.second);
        if (c == Cb || c == Cf)continue;
        SetPixel(hdc, v.first, v.second, Cf);
        S.push(make_pair(v.first + 1, v.second));
        S.push(make_pair(v.first - 1, v.second));
        S.push(make_pair(v.first, v.second + 1));
        S.push(make_pair(v.first, v.second - 1));
    }
}

void FloodFillNonRecursive::draw(Shape *Flood, HDC &hdc) {
    class Flood *fl = (class Flood *) Flood;
    NRFloodFill(hdc, fl->p.x, fl->p.y, fl->borderColor, fl->c);
}

Drawer *FloodFillNonRecursive::copy() {
    return new FloodFillNonRecursive();
}

FloodFillNonRecursive::FloodFillNonRecursive() {
    this->id = mp["FloodFillNonRecursive"];
}
