//
// Created by Mohamed on 5/30/2022.
//

#include "CircleFillerWithCircle.h"
#include "../../../Shapes/Circle.h"
#include <math.h>


void CircleFillerWithCircle::Draw2PointsQuarter1(HDC& hdc, int xc, int yc, int a, int b, COLORREF color) {
    SetPixel(hdc, xc+a, yc-b, color);
    SetPixel(hdc, xc+b, yc-a, color);
}

void CircleFillerWithCircle::Draw2PointsQuarter2(HDC& hdc, int xc, int yc, int a, int b, COLORREF color) {
    SetPixel(hdc, xc-a, yc-b, color);
    SetPixel(hdc, xc-b, yc-a, color);
}

void CircleFillerWithCircle::Draw2PointsQuarter3(HDC& hdc, int xc, int yc, int a, int b, COLORREF color) {
    SetPixel(hdc, xc-a, yc+b, color);
    SetPixel(hdc, xc-b, yc+a, color);
}

void CircleFillerWithCircle::Draw2PointsQuarter4(HDC& hdc, int xc, int yc, int a, int b, COLORREF color) {
    SetPixel(hdc, xc+a, yc+b, color);
    SetPixel(hdc, xc+b, yc+a, color);
}


void CircleFillerWithCircle::draw(Shape *circle, HDC &hdc) {
    Circle *temp = (Circle *) circle;
    Circle *circ = new Circle(temp->cx, temp->cy, 0, temp->c, temp->drawer);
    int quarter;
    cout << "Enter the number of quarter you would like to fill (1 to 4 inclusive)\n-> ";
    cin >> quarter;
    cout << endl;
    while (circ->r <= temp->r){
        int x=circ->r,y=0;
        double theta=0,dtheta=1.0/x;
        if (circ->r == temp->r) circ->Draw8Points(hdc,circ->cx,circ->cy,x,y,circ->c);
        while(x>y){
            theta+=dtheta;
            x=round(circ->r*cos(theta));
            y=round(circ->r*sin(theta));
            if (circ->r == temp->r) circ->Draw8Points(hdc,circ->cx,circ->cy,x,y,circ->c);
            switch (quarter){
                case 1:
                    Draw2PointsQuarter1(hdc, circ->cx, circ->cy, x, y, circ->c);
                    break;
                case 2:
                    Draw2PointsQuarter2(hdc, circ->cx, circ->cy, x, y, circ->c);
                    break;
                case 3:
                    Draw2PointsQuarter3(hdc, circ->cx, circ->cy, x, y, circ->c);
                    break;
                case 4:
                    Draw2PointsQuarter4(hdc, circ->cx, circ->cy, x, y, circ->c);
                    break;
            }
        }
        circ->r++;
    }

}

Drawer *CircleFillerWithCircle::copy() {
    return nullptr;
}
