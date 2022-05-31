//
// Created by Dova on 05/30/22.
//

#include <vector>
#include <cmath>
#include "ClippingRectanglePolygon.h"
#include "../../Shapes/Rectangle.h"
#include "../../Shapes/Point.h"
#include "../../Shapes/Polygon.h"

struct Vertex {
    double x, y;

    Vertex(int x1 = 0, int y1 = 0) {
        x = x1;
        y = y1;
    }
};

typedef vector<Vertex> VertexList;

typedef bool (*IsInFunc)(Vertex &v, int edge);

typedef Vertex (*IntersectFunc)(Vertex &v1, Vertex &v2, int edge);

VertexList ClipWithEdge(VertexList p, int edge, IsInFunc In, IntersectFunc Intersect) {
    VertexList OutList;
    Vertex v1 = p[p.size() - 1];
    bool v1_in = In(v1, edge);
    for (int i = 0; i < (int) p.size(); i++) {
        Vertex v2 = p[i];
        bool v2_in = In(v2, edge);
        if (!v1_in && v2_in) {
            OutList.push_back(Intersect(v1, v2, edge));
            OutList.push_back(v2);
        } else if (v1_in && v2_in) OutList.push_back(v2);
        else if (v1_in) OutList.push_back(Intersect(v1, v2, edge));
        v1 = v2;
        v1_in = v2_in;
    }
    return OutList;
}

bool InLeft(Vertex &v, int edge) {
    return v.x >= edge;
}

bool InRight(Vertex &v, int edge) {
    return v.x <= edge;
}

bool InTop(Vertex &v, int edge) {
    return v.y >= edge;
}

bool InBottom(Vertex &v, int edge) {
    return v.y <= edge;
}

Vertex VIntersect(Vertex &v1, Vertex &v2, int xedge) {
    Vertex res;
    res.x = xedge;
    res.y = v1.y + (xedge - v1.x) * (v2.y - v1.y) / (v2.x - v1.x);
    return res;
}

Vertex HIntersect(Vertex &v1, Vertex &v2, int yedge) {
    Vertex res;
    res.y = yedge;
    res.x = v1.x + (yedge - v1.y) * (v2.x - v1.x) / (v2.y - v1.y);
    return res;
}

void PolygonClip(HDC hdc, POINT *p, int n, int xleft, int ytop, int xright, int ybottom) {
    VertexList vlist;
    for (int i = 0; i < n; i++)vlist.push_back(Vertex(p[i].x, p[i].y));
    vlist = ClipWithEdge(vlist, xleft, InLeft, VIntersect);
    vlist = ClipWithEdge(vlist, ytop, InTop, HIntersect);
    vlist = ClipWithEdge(vlist, xright, InRight, VIntersect);
    vlist = ClipWithEdge(vlist, ybottom, InBottom, HIntersect);
    Vertex v1 = vlist[vlist.size() - 1];
    for (int i = 0; i < (int) vlist.size(); i++) {
        Vertex v2 = vlist[i];
        MoveToEx(hdc, round(v1.x), round(v1.y), NULL);
        LineTo(hdc, round(v2.x), round(v2.y));
        v1 = v2;
    }
}

void ClippingRectanglePolygon::draw(Shape *rectangle, Shape *polygon, HDC &hdc) {

    RECTANGLE *rect = (class RECTANGLE *) rectangle;
    class POLYGON *poly = (class POLYGON *) polygon;
    POINT points[poly->n];
    for (int i = 0; i < poly->n; ++i) {
        POINT p;
        p.x = poly->points[i].x;
        p.y = poly->points[i].y;
        points[i] = p;
    }
    PolygonClip(hdc, points, poly->n, rect->xleft, rect->yleft, rect->xright, rect->yright);
}

Drawer *ClippingRectanglePolygon::copy() {
    return new ClippingRectanglePolygon();
}

void ClippingRectanglePolygon::draw(Shape *, HDC &) {

}
