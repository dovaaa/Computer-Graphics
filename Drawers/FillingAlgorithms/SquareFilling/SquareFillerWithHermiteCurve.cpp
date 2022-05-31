//
// Created by Dova on 05/31/22.
//

#include <algorithm>
#include <cmath>
#include "SquareFillerWithHermiteCurve.h"
#include "../../CurveAlgorithms/CurveDrawerHermite.h"
#include "../../../Shapes/Square.h"


void SquareFillerWithHermiteCurve::draw(Shape *square, HDC &hdc) {
    Square *sq = (Square *) square;

    int x1 = min(sq->x1, sq->x2), y1 = min(sq->y1, sq->y2),
            x2 = max(sq->x1, sq->x2), y2 = max(sq->y1, sq->y2);
    int r = sqrt((x2 - x1) * (x2 - x1) + ((y2 - y1) * (y2 - y1)));

    Drawer *dr = new CurveDrawerHermite();


    Curve curve = Curve(x1 + r, y1, 0, 0, 0, 0, x1 + r, y1 + r, sq->c, dr);
    curve.draw(hdc);

    curve.p1.x = x1;
    curve.p1.y = y1 + r;
    curve.p4.x = x1;
    curve.p4.y = y1;
    curve.draw(hdc);

    curve.p1.y = y1;
    curve.p4.y = y1 + r;

    for (int x = y1; x <= x1 + r; x++) {
        curve.p1.x = x;
        curve.p4.x = x;
        curve.draw(hdc);
    }
}

Drawer *SquareFillerWithHermiteCurve::copy() {
    return new SquareFillerWithHermiteCurve;
}

SquareFillerWithHermiteCurve::SquareFillerWithHermiteCurve() {
    this->id = mp["SquareFillerWithHermiteCurve"];
}