//
// Created by Dova on 05/31/22.
//

#include "Flood.h"

Flood::Flood()
{

}

Flood::Flood(Point p, COLORREF borderColor)
{
    this->p=p;
    this->borderColor=borderColor;
}

void Flood::draw(HDC &hdc)
{
    drawer->draw(this, hdc);
}

void Flood::save()
{

}

Shape *Flood::copy()
{
    return nullptr;
}
