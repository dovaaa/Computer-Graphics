//
// Created by Dova on 05/30/22.
//

#include "FloodFillRecursive.h"
#include "../../../Shapes/Flood.h"

void FloodFillRecursive::FloodFill(HDC hdc,int x,int y,COLORREF Cb,COLORREF Cf)
{
    COLORREF C=GetPixel(hdc,x,y);
    if(C==Cb || C==Cf)return;
    SetPixel(hdc,x,y,Cf);
    FloodFill(hdc,x+1,y,Cb,Cf);
    FloodFill(hdc,x-1,y,Cb,Cf);
    FloodFill(hdc,x,y+1,Cb,Cf);
    FloodFill(hdc,x,y-1,Cb,Cf);
}
void FloodFillRecursive::draw(Shape *Flood, HDC &hdc)
{
    class Flood *fl =  (class Flood*) Flood;
    FloodFill(hdc,fl->p.x,fl->p.y,fl->borderColor,fl->c);
}

Drawer *FloodFillRecursive::copy()
{
    return new FloodFillRecursive();
}

FloodFillRecursive::FloodFillRecursive() {
    this->id = mp["FloodFillRecursive"];
}
