//
// Created by Mohamed on 5/28/2022.
//

#include "CircleDrawerMidpoint.h"
#include "../../Shapes/Circle.h"
#include "../../Shapes/Circle.h"

void CircleDrawerMidpoint::draw(Shape* circle, HDC& hdc) {

    Circle *circ = (Circle*) circle;
    int x=0,y=circ->r;
    int d = 1-y;
    circ->Draw8Points(hdc,circ->cx,circ->cy,x,y,circ->c);
    while(x<y)
    {
        if(d < 0)
            d+=2 * x + 2;
        else
        {
            d+=2 * (x - y) + 5;
            y--;

        }
        x++;
        circ->Draw8Points(hdc,circ->cx,circ->cy,x,y,circ->c);
    }
}
