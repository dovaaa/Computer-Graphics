//
// Created by Dova on 05/31/22.
//

#include "PolygonDrawer.h"
#include "../../Shapes/Polygon.h"
#include "../../Shapes/Line.h"
#include "../LineAlgorithms/LineDrawerParametric.h"


void PolygonDrawer::draw(Shape *polygon, HDC &hdc)
{
    class POLYGON *poly = (class POLYGON*) polygon;

    for(int i=0; i < poly->n-1; ++i)
    {
        Drawer *dr = new LineDrawerParametric();
        Shape *line = new Line(poly->points[i].x, poly->points[i].y
                               , poly->points[i+1].x, poly->points[i+1].y, poly->c, dr);
        line->draw(hdc);

    }
}


Drawer *PolygonDrawer::copy()
{
    return nullptr;
}

PolygonDrawer::PolygonDrawer() {
    id = mp["PolygonDrawer"];
}

