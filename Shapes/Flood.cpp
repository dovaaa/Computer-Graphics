//
// Created by Dova on 05/31/22.
//

#include "Flood.h"

Flood::Flood()
{

}

Flood::Flood(Point p, COLORREF borderColor,Drawer* dr)
{
    this->p=p;
    this->borderColor=borderColor;
    this->drawer=dr;
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



