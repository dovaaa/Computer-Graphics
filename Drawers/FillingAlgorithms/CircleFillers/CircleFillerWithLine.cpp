//
// Created by Mohamed on 5/30/2022.
//

#include "CircleFillerWithLine.h"
#include "../../../Shapes/Circle.h"
#include "../../../Shapes/Line.h"
#include "../../LineAlgorithms/LineDrawerDDA.h"
#include <cmath>

Drawer *dr;

void CircleFillerWithLine::Draw2LinesQuarter1(HDC& hdc, int xc, int yc, int a, int b, COLORREF color) {
    Shape *line1 = new Line(xc, yc, xc+a, yc-b, color, dr);
    Shape *line2 = new Line(xc, yc, xc+b, yc-a, color, dr);
    line1->draw(hdc);
    line2->draw(hdc);
}

void CircleFillerWithLine::Draw2LinesQuarter2(HDC& hdc, int xc, int yc, int a, int b, COLORREF color) {
    Shape *line1 = new Line(xc, yc, xc-a, yc-b, color, dr);
    Shape *line2 = new Line(xc, yc, xc-b, yc-a, color, dr);
    line1->draw(hdc);
    line2->draw(hdc);
}

void CircleFillerWithLine::Draw2LinesQuarter3(HDC& hdc, int xc, int yc, int a, int b, COLORREF color) {
    Shape *line1 = new Line(xc, yc, xc-a, yc+b, color, dr);
    Shape *line2 = new Line(xc, yc, xc-b, yc+a, color, dr);
    line1->draw(hdc);
    line2->draw(hdc);
}

void CircleFillerWithLine::Draw2LinesQuarter4(HDC& hdc, int xc, int yc, int a, int b, COLORREF color) {
    Shape *line1 = new Line(xc, yc, xc+a, yc+b, color, dr);
    Shape *line2 = new Line(xc, yc, xc+b, yc+a, color, dr);
    line1->draw(hdc);
    line2->draw(hdc);
}


void CircleFillerWithLine::draw(Shape *circle, HDC &hdc) {
    Circle *circ = (Circle *) circle;
    int quarter;
    cout << "Enter the number of quarter you would like to fill (1 to 4 inclusive)\n-> ";
    cin >> quarter;
    cout << endl;
    int x=circ->r,y=0;
    double theta=0,dtheta=1.0/x;
    circ->Draw8Points(hdc,circ->cx,circ->cy,x,y,circ->c);
    while(x>y){
        theta+=dtheta;
        x=round(circ->r*cos(theta));
        y=round(circ->r*sin(theta));
        circ->Draw8Points(hdc,circ->cx,circ->cy,x,y,circ->c);
        switch (quarter){
            case 1:
                Draw2LinesQuarter1(hdc, circ->cx, circ->cy, x, y, circ->c);
                break;
            case 2:
                Draw2LinesQuarter2(hdc, circ->cx, circ->cy, x, y, circ->c);
                break;
            case 3:
                Draw2LinesQuarter3(hdc, circ->cx, circ->cy, x, y, circ->c);
                break;
            case 4:
                Draw2LinesQuarter4(hdc, circ->cx, circ->cy, x, y, circ->c);
                break;
        }
    }
}

Drawer *CircleFillerWithLine::copy() {
    return new CircleFillerWithLine();
}

CircleFillerWithLine::CircleFillerWithLine() {
    dr = new LineDrawerDDA();
    id = mp["CircleFillerWithLine"];
}
