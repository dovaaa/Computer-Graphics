//
// Created by Dova on 05/31/22.
//

#include <algorithm>
#include "RectangleFillerWithBezierCurve.h"
#include "../../LineAlgorithms/LineDrawerParametric.h"
#include "../../../Shapes/Rectangle.h"
#include "../../../Shapes/Line.h"

void RectangleFillerWithBezierCurve::draw(Shape *rectangle, HDC &hdc) {
    RECTANGLE *rect = (RECTANGLE *) rectangle;
    int x1 = rect->xleft, y1 = rect->yleft,
            x2 = rect->xright, y2 = rect->yleft,
            x3 = rect->xright, y3 = rect->yright,
            x4 = rect->xleft, y4 = rect->yright;

    Drawer *dr = new LineDrawerParametric();
    Line line;

    //Right & Left Side
    line = Line(x2, y2, x3, y3, rect->c, dr);
    line.draw(hdc);
    line.stx = x4; line.sty = y4;
    line.edx = x1; line.edy = y1;
    line.draw(hdc);

    if (y1 > y2){
        swap(y1, y2);
        swap(x1, y2);
    }
    line.stx = x1; line.sty = y1;
    line.edx = x2; line.edy = y2;
    line.draw(hdc);
    for (int i = y1; i <= y2; i++) ;
//    line = new Line(x1, y1, x2, y2, RGB(255, 255, 0), dr);
//    line->draw(hdc);
//    line = new Line(x3, y3, x4, y4, RGB(255, 255, 0), dr);
//    line->draw(hdc);

}

Drawer *RectangleFillerWithBezierCurve::copy() {
    return new RectangleFillerWithBezierCurve();
}
