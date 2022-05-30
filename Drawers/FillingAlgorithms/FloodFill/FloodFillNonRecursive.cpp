//
// Created by Dova on 05/31/22.
//

#include "FloodFillNonRecursive.h"
#include "../../../Shapes/Flood.h"

#include <stack>
using namespace std;

struct Vertex
{
    int x,y;
    Vertex(int x,int y):x(x),y(y)
    {
    }
};
void FloodFillNonRecursive::NRFloodFill(HDC hdc,int x,int y,COLORREF Cb,COLORREF Cf)
{
    stack<Vertex> S;
    S.push(Vertex(x,y));
    while(!S.empty())
    {
        Vertex v=S.top();
        S.pop();
        COLORREF c=GetPixel(hdc,v.x,v.y);
        if(c==Cb || c==Cf)continue;
        SetPixel(hdc,v.x,v.y,Cf);
        S.push(Vertex(v.x+1,v.y));
        S.push(Vertex(v.x-1,v.y));
        S.push(Vertex(v.x,v.y+1));
        S.push(Vertex(v.x,v.y-1));
    }
}
void FloodFillNonRecursive::draw(Shape *Flood, HDC &hdc)
{
    class Flood *fl =  (class Flood*) Flood;
    NRFloodFill(hdc,fl->p.x,fl->p.y,fl->borderColor,fl->c);
}

Drawer *FloodFillNonRecursive::copy()
{
    return nullptr;
}
