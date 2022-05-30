//
// Created by Dova on 05/30/22.
//

#include "ClippingCirclePoint.h"
#include "../../Shapes/Circle.h"
#include "../../Shapes/Point.h"

bool CllipWithCircle(int xc, int yc, int rx, int ry, int px, int py) {
    int dx = rx - xc, dy = ry - yc;
    dx *= dx;
    dy *= dy;

    int r = dx + dy;

    int d = (px - xc) * (px - xc) + (py - yc) * (py - yc);
    //inside or in on the circle
    if (d <= r)
        return true;
    //else
    return false;

}
void ClippingCirclePoint::draw(Shape *circle, Shape *point, HDC &hdc)
{
    Circle *circ = (Circle*) circle;
    Point *p = (Point*) point;
    if (CllipWithCircle(circ->cx, circ->cy, circ->cx + circ->r, circ->cy,
                         p->x, p->y))
        SetPixel(hdc, p->x, p->y, p->c);
}

Drawer *ClippingCirclePoint::copy() {
    return nullptr;
}
