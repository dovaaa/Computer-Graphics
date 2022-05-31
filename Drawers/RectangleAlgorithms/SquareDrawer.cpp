//
// Created by Dova on 05/31/22.
//

#include "SquareDrawer.h"
#include "cmath"
#include "../../Shapes/Line.h"
#include "../LineAlgorithms/LineDrawerParametric.h"

Drawer *SquareDrawer::copy() {
    return new SquareDrawer();
}

void SquareDrawer::draw(Shape *square, HDC &hdc) {
    Square *sq = (Square *) square;
    int x1 = sq->x1, x2 = sq->x2, y1 = sq->y1, y2 = sq->y2;
    int r = sqrt((x2 - x1) * (x2 - x1) + ((y2 - y1) * (y2 - y1)));
    Drawer *dr = new LineDrawerParametric();
    Shape *line = new Line(x1, y1, x1 + r, y1, sq->c, dr);
    line->draw(hdc);
    line = new Line(x1 + r, y1, x1 + r, y1 + r, sq->c, dr);
    line->draw(hdc);
    line = new Line(x1 + r, y1 + r, x1, y1 + r, sq->c, dr);
    line->draw(hdc);
    line = new Line(x1, y1 + r, x1, y1, sq->c, dr);
    line->draw(hdc);
}
