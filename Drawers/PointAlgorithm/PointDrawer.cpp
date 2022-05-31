//
// Created by Mohamed on 5/31/2022.
//

#include "PointDrawer.h"
#include "../../Shapes/Point.h"

void PointDrawer::draw(Shape *point, HDC &hdc) {
    Point *p = (Point *) point;
    SetPixel(hdc, p->x, p->y, p->c);
}

Drawer *PointDrawer::copy() {
    return new PointDrawer();
}

PointDrawer::PointDrawer() {
    id = mp["PointDrawer"];
}

