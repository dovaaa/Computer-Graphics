//
// Created by Mohamed on 5/28/2022.
//

#include <Windows.h>
#include "LineDrawerDDA.h"
#include "../../Shapes/Line.h"
#include <iostream>
#include <cmath>

void LineDrawerDDA::draw(Shape *line,HDC hdc,COLORREF color) {//todo fix
    Line *l = (Line*) line;
    int dx = l->edx-l->stx;
    int dy = l->edy-l->sty;
    SetPixel(hdc,l->stx,l->sty,color);
    if(abs(dx)>=abs(dy)){
        int x = l->stx,xinc = dx>0?1:-1;
        double y = l->sty,yinc=(double)dy/dx*xinc;
        while(x!=l->edx){
            x+=xinc;
            y+=yinc;
            SetPixel(hdc,x,round(y),color);
        }
    }else{
        int y=l->sty,yinc= dy>0?1:-1;
        double x=l->stx,xinc=(double)dx/dy*yinc;
        while(y!=l->edy){
            x+=xinc;
            y+=yinc;
            SetPixel(hdc,round(x),y,color);
        }
    }

}


