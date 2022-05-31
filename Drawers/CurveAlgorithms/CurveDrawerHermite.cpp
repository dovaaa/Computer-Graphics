//
// Created by Mohamed on 5/31/2022.
//

#include "CurveDrawerHermite.h"

CurveDrawerHermite::CurveDrawerHermite() {
    id = mp["CurveDrawerHermite"];
}

void CurveDrawerHermite::draw(Shape *curve, HDC &hdc) {
    Curve* cur = (Curve *) curve;

    int arr1[] = {cur->p1.x, cur->p1.y};
    int arr2[] = {cur->p4.x, cur->p4.y};
    long long T1[] = {cur->p2.x, cur->p2.y};
    long long T2[] = {cur->p3.x, cur->p3.y};

    double a0 = arr1[0], a1 = T1[0],
            a2 = -3 * arr1[0] - 2 * T1[0] + 3 * arr2[0] - T2[0],
            a3 = 2 * arr1[0] + T1[0] - 2 * arr2[0] + T2[0];
    double b0 = arr1[1], b1 = T1[1],
            b2 = -3 * arr1[1] - 2 * T1[1] + 3 * arr2[1] - T2[1],
            b3 = 2 * arr1[1] + T1[1] - 2 * arr2[1] + T2[1];

    for (double t = 0; t <= 1; t += 0.001)
    {
        double t2 = t*t, t3 = t2*t;
        double x = a0 + a1*t + a2*t2 + a3*t3;
        double y = b0 + b1*t + b2*t2 + b3*t3;

        SetPixel(hdc, (int) (x+0.5), (int) (y+0.5), cur->c);
    }
}

Drawer *CurveDrawerHermite::copy() {
    return new CurveDrawerHermite();
}
