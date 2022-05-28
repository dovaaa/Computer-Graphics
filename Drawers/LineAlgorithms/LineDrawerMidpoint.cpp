//
// Created by Mohamed on 5/28/2022.
//

#include "LineDrawerMidpoint.h"
#include <Windows.h>
#include "../../Shapes/Line.h"


void LineDrawerMidpoint::draw(Shape *line,HDC hdc,COLORREF color) {

    Line *l = (Line*) line;
    int dx = l->edx-l->stx;
    int dy = l->edy - l->sty;

    if(dy<=dx){
        int d = dy-(dx/2);
        int x = l->stx, y= l->sty;
        SetPixel(hdc,x,y,color);
        while(x<l->edx){
            x++;
            if(d<0) d+=dy;
            else{
                d+=(dy-dx);
                y++;
            }
            SetPixel(hdc,x,y,color);

        }
    }else{
        int d = dx - (dy/2);
        int x = l->stx, y = l->sty;
        SetPixel(hdc,x,y,color);
        while(y<l->edy){
            y++;
            if(d<0)d+=dx;
            else{
                d+=(dx-dy);
                x++;
            }
            SetPixel(hdc,x,y,color);
        }
    }
}
