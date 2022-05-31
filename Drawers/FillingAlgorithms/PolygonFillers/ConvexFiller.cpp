//
// Created by Dova on 05/30/22.
//

#include <cmath>
#include <climits>
#include "ConvexFiller.h"
#include "../../../Shapes/Polygon.h"
#define MAXENTRIES 600
struct Entry
{
    int xmin,xmax;
};
void InitEntries(Entry table[])
{
    for(int i=0;i<MAXENTRIES ; i++)
    {
        table[i].xmin = INT_MAX;
        table[i].xmax = INT_MIN;
    }
}
void ScanEdge(POINT v1,POINT v2,Entry table[])
{
    if(v1.y==v2.y)return;
    if(v1.y>v2.y)swap(v1,v2);
    double minv=(double)(v2.x-v1.x)/(v2.y-v1.y);
    double x=v1.x;
    int y=v1.y;
    while(y<v2.y)
    {
        if(x<table[y].xmin)table[y].xmin=(int)ceil(x);
        if(x>table[y].xmax)table[y].xmax=(int)floor(x);
        y++;
        x+=minv;
    }
}
void DrawSanLines(HDC hdc,Entry table[],COLORREF color)
{
    for(int y=0;y<MAXENTRIES;y++)
        if(table[y].xmin<table[y].xmax)
            for(int x=table[y].xmin;x<=table[y].xmax;x++)
                SetPixel(hdc,x,y,color);
}

void ConvexFiller::draw(Shape *polygon, HDC &hdc)
{
    class POLYGON *poly = (class POLYGON*) polygon;
    Entry *table=new Entry[MAXENTRIES];
    InitEntries(table);
    Point t = poly->points[poly->n-1];
    POINT v1;
    v1.x = t.x; v1.y=t.y;
    for(int i=0; i < poly->n; ++i)
    {
        t = poly->points[i];
        POINT v2;
        v2.x = t.x;v2.y=t.y;
        ScanEdge(v1,v2,table);
        v1.x=t.x;v1.y=t.y;
    }
    DrawSanLines(hdc,table,poly->c);
    delete table;

}
Drawer *ConvexFiller::copy()
{
    return new ConvexFiller();
}