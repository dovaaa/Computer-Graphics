//
// Created by Mohamed on 5/28/2022.
//

#include "CircleDrawerDirect.h"
#include "../../Shapes/Circle.h"
#include "cmath"

void CircleDrawerDirect::draw(Shape *circle, HDC& hdc) {

    Circle *circ = (Circle*) circle;
    int x =0, y = circ->r;
    int r2 = y*y;

    circ->Draw8Points(hdc,circ->cx,circ->cy,x,y,circ->c);
    while(x<y){
        x++;
        y=round(sqrt((double)(r2-(x*x))));
        circ->Draw8Points(hdc,circ->cx,circ->cy,x,y,circ->c);
    }
}

Drawer *CircleDrawerDirect::copy() {
    return nullptr;
}
