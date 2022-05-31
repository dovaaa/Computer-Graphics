//
// Created by Mohamed on 5/28/2022.
//

#include "CircleDrawerModifiedMidpoint.h"
#include "../../Shapes/Circle.h"

void CircleDrawerModifiedMidpoint::draw(Shape *circle, HDC& hdc) {
    Circle *circ = (Circle*) circle;
    int x=0,y=circ->r;
    int d = 1-y;
    int c1=3,c2=5-2*y;
    circ->Draw8Points(hdc,circ->cx,circ->cy,x,y,circ->c);
    while(x<y){
        if(d<0)
        {
            d+=c1;
            c2+=2;
        }
        else
        {
            d+=c2;
            c2+=4;
            y--;
        }
        c1+=2;
        x++;
        circ->Draw8Points(hdc,circ->cx,circ->cy,x,y,circ->c);
    }
}

Drawer *CircleDrawerModifiedMidpoint::copy() {
    return new CircleDrawerModifiedMidpoint();
}

CircleDrawerModifiedMidpoint::CircleDrawerModifiedMidpoint() {
    this->id = mp["CircleDrawerModifiedMidpoint"];
}
