//
// Created by Dova on 05/31/22.
//

#include "RectangleDrawer.h"
#include "../../Shapes/Line.h"
#include "../LineAlgorithms/LineDrawerParametric.h"

void RectangleDrawer::draw(Shape *rectangle, HDC &hdc) {
    RECTANGLE *rect = (RECTANGLE *) rectangle;
    int x1 = rect->xleft, y1 = rect->yleft, x2 = rect->xright, y2 = rect->yleft
    , x3 = rect->xright, y3 = rect->yright, x4 = rect->xleft, y4 = rect->yright;
    Drawer *dr = new LineDrawerParametric();
    Shape *line = new Line(x1, y1, x2, y2, rect->c, dr);
    line->draw(hdc);
    line = new Line(x2, y2, x3, y3, rect->c, dr);
    line->draw(hdc);
    line = new Line(x3, y3, x4, y4, rect->c, dr);
    line->draw(hdc);
    line = new Line(x4, y4, x1, y1, rect->c, dr);
    line->draw(hdc);
}

Drawer *RectangleDrawer::copy() {
    return new RectangleDrawer();
}
