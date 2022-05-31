//
// Created by Dova on 05/30/22.
//

#include "ClippingRectanglePoint.h"
#include "../../Shapes/Rectangle.h"
#include "../../Shapes/Point.h"

void ClippingRectanglePoint::draw(Shape *rectangle, Shape *point, HDC &hdc) {
    RECTANGLE *rect = (RECTANGLE *) rectangle;
    Point *point1 = (Point *) point;
    if (point1->x >= rect->xleft && point1->x <= rect->xright && point1->y >= rect->yleft && point1->y <= rect->yright)
        SetPixel(hdc, point1->x, point1->y, point->c);
//    else SetPixel(hdc, point1->x, point1->y, RGB(255,0,0));
}

Drawer *ClippingRectanglePoint::copy() {
    return new ClippingRectanglePoint();
}

void ClippingRectanglePoint::draw(Shape *, HDC &) {

}
