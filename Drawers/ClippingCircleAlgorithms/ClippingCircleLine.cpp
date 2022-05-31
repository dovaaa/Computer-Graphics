//
// Created by Dova on 05/30/22.
//

#include "ClippingCircleLine.h"
#include "../../Shapes/Line.h"
#include "../../Shapes/Circle.h"
#include "cmath"
#include "../../Shapes/Container.h"

bool CllipWithCircle2(int xc, int yc, int rx, int ry, int px, int py) {
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
    //test
}
void CllipLineCircle(HDC hdc, int x1, int y1, int x2, int y2, int xc, int yc, int rx, int ry, COLORREF color) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    if (abs(dx) >= abs(dy)) {
        int x = x1, xinc = dx > 0 ? 1 : -1;
        double y = y1, yinc = (double) dy / dx * xinc;
        while (x != x2) {
            x += xinc;
            y += yinc;
            if (CllipWithCircle2(xc, yc, rx, ry, x, round(y)))
                SetPixel(hdc, x, round(y), color);
        }
    } else {
        int y = y1, yinc = dy > 0 ? 1 : -1;
        double x = x1, xinc = (double) dx / dy * yinc;
        while (y != y2) {
            x += xinc;
            y += yinc;
            if (CllipWithCircle2(xc, yc, rx, ry, round(x), y))
                SetPixel(hdc, round(x), y, color);
        }
    }


}

void ClippingCircleLine::draw(Shape *circle, Shape *line, HDC &hdc)
{
    Circle *circ = (Circle*) circle;
    circ->draw(hdc);
    Line *l = (Line*) line;
    CllipLineCircle( hdc,l->stx,l->sty,l->edx,l->edy,
                     circ->cx,circ->cy,circ->cx+circ->r,circ->cy, l->c);
}

Drawer *ClippingCircleLine::copy() {
    return new ClippingCircleLine();
}

void ClippingCircleLine::draw(Shape *sh, HDC &hdc) {
    Container *cr = (Container*) sh;
    draw(cr->s1, cr->s2, hdc);
}

ClippingCircleLine::ClippingCircleLine() {
    id = mp["ClippingCircleLine"];
}
