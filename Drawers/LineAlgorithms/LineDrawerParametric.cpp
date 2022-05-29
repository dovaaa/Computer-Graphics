//
// Created by Mohamed on 5/28/2022.
//
#include <Windows.h>
#include "LineDrawerParametric.h"
#include "../../Shapes/Line.h"
#include <iostream>
#include <cmath>


void LineDrawerParametric::draw(Shape *line, HDC& hdc) {
    //TODO : FIX
    Line *l = (Line*) line;
    int dx=l->edx-l->stx;
    int dy =l->edy-l->sty;

    if(abs(dy)<=abs(dx)){
        double slope = (double)dy/dx;
        if(l->stx>l->edx){
            std::swap(l->stx,l->edx);
            std::swap(l->sty,l->edy);
        }
        for (int x = l->stx; x < l->edx; ++x) {
            int y = round(l->sty+(x-l->stx)*slope);
            SetPixel(hdc, x, y, line->c);
        }
    }else{
        double islope = (double)dx/dy;
        if(l->sty>l->edy){
            std::swap(l->stx,l->edx);
            std::swap(l->sty,l->edy);
        }
        for (int y = l->sty; y < l->edy; ++y) {
            int x = round(l->stx+(y-l->sty)*islope);
            SetPixel(hdc, x, y, line->c);
        }
    }

}

