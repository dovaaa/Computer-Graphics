//
// Created by Dova on 05/31/22.
//

#include "Square.h"

Square::Square()
{
    this->x1=0;
    this->y1=0;
    this->y2=0;
    this->x2=0;
}

Square::Square(int x1, int y1, int x2, int y2, Drawer *dr)
{
    this->x1=x1;
    this->y1=y1;
    this->x2=x2;
    this->y2=y2;
}

void Square::draw(HDC &hdc)
{
    drawer->draw(this, hdc);
}

void Square::save(File &f)
{

}

Shape *Square::copy(string)
{
    return nullptr;
}
