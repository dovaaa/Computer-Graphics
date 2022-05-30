//
// Created by Mohamed on 5/30/2022.
//

#include "CurveDrawerBezier.h"

void CurveDrawerBezier::draw(Shape * c, HDC &hdc) {
    Curve *curve = (Curve *) c;

    Point s1( 3 * (curve->p2.x - curve->p1.x), 3 * (curve->p2.y - curve->p1.y) );
    Point s2( 3 * (curve->p4.x - curve->p3.x), 3 * (curve->p4.y - curve->p3.y) );

    double a0 = curve->p1.x, a1 = s1.x,
            a2 = -3 * curve->p1.x - 2 * s1.x + 3 * curve->p4.x - s2.x,
            a3 = 2 * curve->p1.x + s1.x - 2 * curve->p4.x + s2.x;

    double b0 = curve->p1.y, b1 = s1.y,
            b2 = -3 * curve->p1.y - 2 * s1.y + 3 * curve->p4.y - s2.y,
            b3 = 2 * curve->p1.y + s1.y - 2 * curve->p4.y + s2.y;

    for (double t = 0; t <= 1; t += 0.001)
    {
        double t2 = t*t, t3 = t2*t;
        double x = a0 + a1*t + a2*t2 + a3*t3;
        double y = b0 + b1*t + b2*t2 + b3*t3;

        SetPixel(hdc, (int) (x+0.5), (int) (y+0.5), c->c);
    }
}

Drawer *CurveDrawerBezier::copy() {
    return nullptr;
}
