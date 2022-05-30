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

Shape *Flood::copy(string s)
{
    return nullptr;
}

void Flood::save(File &f)
{

}



