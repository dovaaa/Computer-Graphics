//
// Created by Mohamed on 5/29/2022.
//

#include "EllipseDrawerMidpoint.h"
#include "../../Shapes/ELLIPSE.h"
#include <cmath>
void EllipseDrawerMidpoint::draw(Shape *ellipse, HDC &hdc)
{
    ELLIPSE *el=(ELLIPSE *) ellipse;
    float dx, dy, d1, d2, x, y;
    x=0;
    y=el->b;
    int b2=el->b * el->b, a2=el->a * el->a;
    d1=(b2) - (a2 * el->b) + (0.25 * a2);
    dx=2 * b2 * x;
    dy=2 * a2 * y;

    while(dx < dy)
    {
        el->Draw4Points(hdc, el->cx, el->cy, round(x), round(y), el->c);

        if(d1 < 0)
        {
            x++;
            dx=dx + (2 * b2);
            d1=d1 + dx + (b2);
        } else
        {
            x++;
            y--;
            dx = dx + (2 * b2);
            dy = dy - (2 * a2);
            d1 = d1 + dx - dy + (b2);
        }
    }
    d2 = ((b2) * ((x + 0.5) * (x + 0.5))) +((a2) * ((y - 1) * (y - 1))) -(a2 * b2);
    while (y >= 0) {
        el->Draw4Points(hdc,el->cx,el->cy, round(x), round(y),el->c);
        if (d2 > 0) {
            y--;
            dy = dy - (2 * a2);
            d2 = d2 + (a2) - dy;
        }
        else {
            y--;
            x++;
            dx = dx + (2 * b2);
            dy = dy - (2 * a2);
            d2 = d2 + dx - dy + (a2);
        }
    }
}

Drawer *EllipseDrawerMidpoint::copy() {
    return nullptr;
}
