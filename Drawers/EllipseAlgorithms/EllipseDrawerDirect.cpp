//
// Created by Mohamed on 5/29/2022.
//

#include "EllipseDrawerDirect.h"
#include "../../Shapes/ELLIPSE.h"
#include <cmath>

void EllipseDrawerDirect::draw(Shape *ellipse, HDC &hdc) {
    ELLIPSE *el = (ELLIPSE*) ellipse;
    int x =0 , y= el->b;
    el->Draw4Points(hdc,el->cx,el->cy,x,y,el->c);
    int b2= el->b*el->b,a2 = el->a*el->a;

    while(x*(b2)<y*a2){
        x++;
        y=round(sqrt(((b2)*((a2)-(x*x)))/(a2)));
        el->Draw4Points(hdc,el->cx,el->cy,x,y,el->c);
    }
    y = 0, x = el->a;
    el->Draw4Points(hdc,el->cx,el->cy,x,y,el->c);
    while(x*b2>a2*y){
        y++;
        x = round(sqrt(((a2)*((b2) - (y * y)))/(b2)));
        el->Draw4Points(hdc,el->cx,el->cy,x,y,el->c);
    }
}

Drawer *EllipseDrawerDirect::copy() {
    return nullptr;
}
