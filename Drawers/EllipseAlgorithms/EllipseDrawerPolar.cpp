//
// Created by Mohamed on 5/29/2022.
//

#include "EllipseDrawerPolar.h"
#include "../../Shapes/ELLIPSE.h"
#include <cmath>
void EllipseDrawerPolar::draw(Shape *ellipse, HDC& hdc) {

    ELLIPSE *el=(ELLIPSE *) ellipse;
    int b2=el->b * el->b, a2=el->a * el->a;
    int x=el->a, y=0;
    double theta = 0,dtheta=1.0/el->a;
    el->Draw4Points(hdc,el->cx,el->cy,x,y,el->c);
    while(theta<=el->a){
        theta+=dtheta;
        x=round(el->a* cos(theta));
        y=round(el->b* sin(theta));
        el->Draw4Points(hdc,el->cx,el->cy,x,y,el->c);
    }
}
