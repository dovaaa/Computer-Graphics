//
// Created by Dova on 05/31/22.
//

#include <algorithm>
#include "RectangleFillerWithBezierCurve.h"
#include "../../CurveAlgorithms/CurveDrawerBezier.h"
#include "../../../Shapes/Rectangle.h"
#include "../../../Shapes/Curve.h"

void RectangleFillerWithBezierCurve::draw(Shape *rectangle, HDC &hdc) {
    RECTANGLE *rect = (RECTANGLE *) rectangle;
    int     x1 = min(rect->xleft, rect->xright), y1 = min(rect->yleft, rect->yright),
            x2 = max(rect->xleft, rect->xright), y2 = y1,
            x3 = x2, y3 = max(rect->yright, rect->yleft),
            x4 = x1, y4 = y3;

    Drawer *dr = new CurveDrawerBezier();
    Curve curve;

    //Right & Left Side
    curve = Curve(x2, y2, x3, y3, x2, y2, x3, y3, rect->c, dr);
    curve.draw(hdc);
    curve.p1.x = x4; curve.p1.y = y4;
    curve.p2.x = x1; curve.p2.y = y1;
    curve.p3.x = x4; curve.p3.y = y4;
    curve.p4.x = x1; curve.p4.y = y1;
    curve.draw(hdc);

    curve.p1.x = x1; curve.p2.x = x1;
    curve.p3.x = x2; curve.p4.x = x2;
    for (int y = y1; y <= y3; y++){
        std :: cout << y << "\n";
        curve.p1.y = y; curve.p2.y = y;
        curve.p3.y = y; curve.p4.y = y;
        curve.draw(hdc);
    }
}

Drawer *RectangleFillerWithBezierCurve::copy() {
    //TODO
    return nullptr;
}
