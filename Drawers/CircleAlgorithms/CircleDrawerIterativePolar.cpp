//
// Created by Mohamed on 5/28/2022.
//

#include "CircleDrawerIterativePolar.h"
#include "../../Shapes/Circle.h"
#include "cmath"
void CircleDrawerIterativePolar::draw(Shape *circle, HDC& hdc) {

    Circle *circ = (Circle*) circle;
    double x=circ->r,y=0;
    double dtheta=1.0/x;
    double cdtheta=cos(dtheta),sdtheta=sin(dtheta);
    circ->Draw8Points(hdc,circ->cx,circ->cy,circ->r,0,circ->c);
    while(x>y){
        double x1=x*cdtheta-y*sdtheta;
        y=x*sdtheta+y*cdtheta;
        x=x1;
        circ->Draw8Points(hdc,circ->cx,circ->cy,round(x),round(y),circ->c);
    }
}

Drawer *CircleDrawerIterativePolar::copy() {
    return nullptr;
}
