//
// Created by Mohamed on 5/28/2022.
//

#include "CircleDrawerPolar.h"
#include "../../Shapes/Circle.h"
#include "cmath"
void CircleDrawerPolar::draw(Shape *circle, HDC& hdc) {

    Circle *circ = (Circle*) circle;
    int x=circ->r,y=0;
    double theta=0,dtheta=1.0/x;
    circ->Draw8Points(hdc,circ->cx,circ->cy,x,y,circ->c);
    while(x>y){
        theta+=dtheta;
        x=round(circ->r*cos(theta));
        y=round(circ->r*sin(theta));
        circ->Draw8Points(hdc,circ->cx,circ->cy,x,y,circ->c);
    }
}
