//
// Created by Mohamed on 5/28/2022.
//

#include "LineDrawerMidpoint.h"
#include <Windows.h>
#include "../../Shapes/Line.h"

void LineDrawerMidpoint::draw(Shape *line, HDC &hdc)
{
    Line *l = (Line*) line;
    int x1=l->stx,y1=l->sty,x2=l->edx,y2=l->edy;
    int dx=abs(x2-x1),dy=abs(y2-y1);

    if(dx>dy){
        plotPixel(x1,y1,x2,y2,dx,dy,0,line,hdc);
    }else{
        plotPixel(y1,x1,y2,x2,dy,dx,1,line,hdc);
    }
}
void LineDrawerMidpoint::plotPixel(int x1, int y1, int x2, int y2, int dx, int dy, int decide,Shape *line,HDC &hdc) {
    Line *l = (Line*) line;
    int pk = 2 * dy - dx;
    for (int i = 0; i <= dx; i++)
    {

        //checking either to decrement or increment the value
        //if we have to plot from (0,100) to (100,0)
        x1 < x2 ? x1++ : x1--;
        if (pk < 0)
        {
            //decision value will decide to plot
            //either  x1 or y1 in x's position
            if (decide == 0)
            {
                // putpixel(x1, y1, RED);
                SetPixel(hdc,x1,y1,l->c);
                pk = pk + 2 * dy;
            }
            else
            {
                //(y1,x1) is passed in xt
                // putpixel(y1, x1, YELLOW);
                SetPixel(hdc,y1,x1,l->c);
                pk = pk + 2 * dy;
            }
        }
        else
        {
            y1 < y2 ? y1++ : y1--;
            if (decide == 0)
            {

                //putpixel(x1, y1, RED);
                SetPixel(hdc,x1,y1,l->c);
            }
            else
            {
                //  putpixel(y1, x1, YELLOW);
                SetPixel(hdc,y1,x1,l->c);
            }
            pk = pk + 2 * dy - 2 * dx;
        }
    }
}

Drawer *LineDrawerMidpoint::copy() {
    return new LineDrawerMidpoint();
}
