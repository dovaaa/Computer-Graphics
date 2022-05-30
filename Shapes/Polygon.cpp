//
// Created by Dova on 05/30/22.
//

#include "Polygon.h"

void Polygon::draw(HDC& hdc) {
    drawer->draw(this, hdc);
}
Polygon::Polygon()
{
    this->points = new Point;
    this->n=0;
    this->id = mp["Polygon"];
}

Polygon::Polygon(Point *points,int n)
{
    this->points = points;
    this->n = n;
    this->id = mp["Polygon"];
}

void Polygon::save(File &f)
{

}

Shape *Polygon::copy(string s)
{
    return nullptr;
}
