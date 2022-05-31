//Shapes Imports
#include "Shapes/Shape.h"
#include "Drawers/Drawer.h"
#include "Shapes/Line.h"
#include "Shapes/ELLIPSE.h"
#include "Shapes/Circle.h"
#include "Shapes/Curve.h"
#include "Shapes/Rectangle.h"
#include "Shapes/Square.h"
#include "Shapes/Polygon.h"
#include "Shapes/Flood.h"

//Line Algorithms Imports
#include "Drawers/LineAlgorithms/LineDrawerDDA.h"
#include "Drawers/LineAlgorithms/LineDrawerParametric.h"
#include "Drawers/LineAlgorithms/LineDrawerMidpoint.h"

//Circle Algorithms Imports
#include "Drawers/CircleAlgorithms/CircleDrawerDirect.h"
#include "Drawers/CircleAlgorithms/CircleDrawerPolar.h"
#include "Drawers/CircleAlgorithms/CircleDrawerIterativePolar.h"
#include "Drawers/CircleAlgorithms/CircleDrawerMidpoint.h"
#include "Drawers/CircleAlgorithms/CircleDrawerModifiedMidpoint.h"

//Shapes Algorithm Import
#include "Drawers/PointAlgorithm/PointDrawer.h"
#include "Drawers/RectangleAlgorithms/RectangleDrawer.h"

//Ellipse Algorithms Imports
#include "Drawers/EllipseAlgorithms/EllipseDrawerDirect.h"
#include "Drawers/EllipseAlgorithms/EllipseDrawerPolar.h"
#include "Drawers/EllipseAlgorithms/EllipseDrawerMidpoint.h"

//Curve Algorithms Imports
#include "Drawers/CurveAlgorithms/CurveDrawerBezier.h"
#include "Drawers/CurveAlgorithms/CurveDrawerHermite.h"

//Filling Algorithms Imports
#include "Drawers/FillingAlgorithms/CircleFillers/CircleFillerWithLine.h"
#include "Drawers/FillingAlgorithms/CircleFillers/CircleFillerWithCircle.h"
#include "Drawers/FillingAlgorithms/RectangleFilling/RectangleFillerWithBezierCurve.h"
#include "Drawers/FillingAlgorithms/SquareFilling/SquareFillerWithHermiteCurve.h"
#include "Drawers/FillingAlgorithms/FloodFill/FloodFillNonRecursive.h"
#include "Drawers/FillingAlgorithms/FloodFill/FloodFillRecursive.h"
#include "Drawers/FillingAlgorithms/PolygonFillers/ConvexFiller.h"
#include "Drawers/FillingAlgorithms/PolygonFillers/NonConvexFiller.h"

//Clipping Imports
#include "Drawers/ClippingRectangleAlgorithms/ClippingRectanglePoint.h"
#include "Drawers/ClippingRectangleAlgorithms/ClippingRectangleLine.h"

#include "Drawers/ClippingCircleAlgorithms/ClippingCirclePoint.h"
#include "Drawers/ClippingCircleAlgorithms/ClippingCircleLine.h"
#include "Drawers/PolygonAlgorithms/PolygonDrawer.h"
#include "Drawers/ClippingRectangleAlgorithms/ClippingRectanglePolygon.h"


//Utility Imports
#include <stack>
#include <Windowsx.h>
#include <cmath>

//DEFINITIONS
#define CHANGE_CURSOR 10001
#define DISABLE_KEYBOARD 10002
#define SAVE_DATA 10004
#define LOAD_DATA 10005
#define DRAW_LINE_DDA 10006
#define DRAW_LINE_PARAMETRIC 10007
#define DRAW_LINE_MIDPOINT 10008
#define DRAW_CIRCLE_DIRECT 10009
#define DRAW_CIRCLE_POLAR 10010
#define DRAW_CIRCLE_ITERATIVE_POLAR 10011
#define DRAW_CIRCLE_MIDPOINT 10012
#define DRAW_CIRCLE_MODIFIED_MIDPOINT 10013
#define FILL_CIRCLE_WITH_LINE 10014
#define FILL_CIRCLE_WITH_CIRCLE 10015
#define FILL_SQUARE_WITH_HERMITE_CURVE 10016
#define FILL_RECTANGLE_WITH_BEZIER_CURVE 10017
#define CONVEX_FILLING 10018
#define NON_CONVEX_FILLING 10019
#define RECURSIVE_FLOOD_FILL 10020
#define NON_RECURSIVE_FLOOD_FILL 10021
#define CARDINAL_SPLINE_CURVE 10022
#define DRAW_ELLIPSE_DIRECT 10023
#define DRAW_ELLIPSE_POLAR 10024
#define DRAW_ELLIPSE_MIDPOINT 10025
#define CLIP_RECTANGLE_POINT 10026
#define CLIP_RECTANGLE_LINE 10027
#define CLIP_RECTANGLE_POLYGON 10028
#define CLIP_SQUARE_POINT 10029
#define CLIP_SQUARE_LINE 10030
#define CLIP_CIRCLE_POINT 10031
#define CLIP_CIRCLE_LINE 10032
#define CLEAR_WINDOW 10033
#define EXIT_WINDOW 10034

//COLORS DEFINITIONS
#define COLOR_RED 10035
#define COLOR_BLUE 10036
#define COLOR_GREEN 10037
#define COLOR_CYAN 10038
#define COLOR_MAGENTA 10039
#define COLOR_YELLOW 10040
#define COLOR_BLACK 10041

HCURSOR cursor = LoadCursorA(NULL, IDC_ARROW);

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

void AddMenu(HWND hWnd);

HMENU hMenu;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hprevInst, LPSTR args, int ncmdshow) {

    WNDCLASSW wc = {0};
    wc.hbrBackground = (HBRUSH) COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"myWindowClass";
    wc.lpfnWndProc = WindowProcedure;

    if (!RegisterClassW(&wc))
        return -1;

    CreateWindowW(L"myWindowClass", L"My Window", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 750, 250, 800, 800, NULL, NULL,
                  NULL, NULL);

    MSG msg = {0};
    while (GetMessage(&msg, NULL, NULL, NULL)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

bool firstCreate = true;
vector<Shape *> shapes;
File file("mangaSave");
bool flag = false;

COLORREF currentColor = RGB(255, 128, 53);

void init() {
    if (flag)
        return;
    flag = true;
    Shape::addShape("point", new Point());
    Shape::addShape("line", new Line());
    Shape::addShape("rectangle", new RECTANGLE());
    Shape::addShape("circle", new Circle());
    Shape::addShape("ellipse", new ELLIPSE());
    Shape::addShape("curve", new Curve());
    Shape::addShape("polygon", new POLYGON());
    Shape::addShape("square", new Square());
    Shape::addShape("flood", new Flood());

    /* Line Drawer Algorithms */
    Drawer::addDrawer("LineDrawerDDA", new LineDrawerDDA());
    Drawer::addDrawer("LineDrawerMidpoint", new LineDrawerMidpoint());
    Drawer::addDrawer("LineDrawerParametric", new LineDrawerParametric());

    /* Circle Drawer Algorithms */
    Drawer::addDrawer("CircleDrawerDirect", new CircleDrawerDirect());
    Drawer::addDrawer("CircleDrawerIterativePolar", new CircleDrawerIterativePolar());
    Drawer::addDrawer("CircleDrawerMidpoint", new CircleDrawerMidpoint());
    Drawer::addDrawer("CircleDrawerModifiedMidpoint", new CircleDrawerModifiedMidpoint());
    Drawer::addDrawer("CircleDrawerPolar", new CircleDrawerPolar());

    /* Ellipse Drawer Algorithms */
    Drawer::addDrawer("EllipseDrawerDirect", new EllipseDrawerDirect());
    Drawer::addDrawer("EllipseDrawerMidpoint", new EllipseDrawerMidpoint());
    Drawer::addDrawer("EllipseDrawerPolar", new EllipseDrawerPolar());


    /* Curve Drawer Algorithms */
    Drawer::addDrawer("CurveDrawerBezier", new CurveDrawerBezier());
    Drawer::addDrawer("CurveDrawerBezier", new CurveDrawerHermite());

    /* Filling Algorithms */
    Drawer::addDrawer("CircleFillerWithCircle", new CircleFillerWithCircle());
    Drawer::addDrawer("CircleFillerWithLine", new CircleFillerWithLine());
    Drawer::addDrawer("FloodFillRecursive", new FloodFillRecursive());
    Drawer::addDrawer("FloodFillNonRecursive", new FloodFillNonRecursive());
    Drawer::addDrawer("ConvexFiller", new ConvexFiller());
    Drawer::addDrawer("NonConvexFiller", new NonConvexFiller());
    Drawer::addDrawer("SquareFillerWithHermiteCurve", new SquareFillerWithHermiteCurve());
    Drawer::addDrawer("RectangleFillerWithBezierCurve", new RectangleFillerWithBezierCurve());


}

stack <int> xInputs;
stack <int> yInputs;

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    int x1, x2, x3, x4;
    int y1, y2, y3, y4;
    int a, b;
    HDC hdc;
    Shape *shape;
    Drawer *dr;
    init();
    switch (msg)                  /* handle the messages */
    {
        case WM_COMMAND:
            switch (wp) {
                case CHANGE_CURSOR:
                    cursor = LoadCursorA(NULL, IDC_CROSS);
                    SetCursor(cursor);
                    break;
                case DISABLE_KEYBOARD:
                    break;
                case COLOR_RED:
                    currentColor = RGB(255, 0, 0);
                    break;
                case COLOR_BLUE:
                    currentColor = RGB(0, 0, 255);
                    break;
                case COLOR_GREEN:
                    currentColor = RGB(0, 255, 0);
                    break;
                case COLOR_CYAN:
                    currentColor = RGB(0, 255, 255);
                    break;
                case COLOR_MAGENTA:
                    currentColor = RGB(255, 0, 255);
                    break;
                case COLOR_YELLOW:
                    currentColor = RGB(255, 255, 0);
                    break;
                case COLOR_BLACK:
                    currentColor = RGB(0, 0, 0);
                    break;
                case SAVE_DATA:
                    file.clear();
                    for (int i = 0; i < shapes.size(); ++i) {
                        shapes[i]->save(file);
                    }
                    break;
                case LOAD_DATA: {
                    string s = file.get();
                    hdc = GetDC(hWnd);
                    vector<string> vec = UT::split(s, '\n');
                    for (int i = 0; i < vec.size(); ++i) {
                        vector<string> cur = UT::split(vec[i], ':');
                        shape = Shape::shapes[stoi(cur[0])]->copy(cur[1]);
                        shape->drawer = Drawer::drawers[stoi(cur[2])]->copy();
                        shape->draw(hdc);
                        shapes.push_back(shape);
                    }
                    ReleaseDC(hWnd, hdc);
                }
                    break;
                case DRAW_LINE_DDA:
                    if (xInputs.size() < 2){
                        std :: cout << "You need at least 2 points to draw  a line\n";
                        return 0;
                    }
                    //Extracting Line Input
                    x1 = xInputs.top(); y1 = yInputs.top();
                    xInputs.pop(); yInputs.pop();

                    x2 = xInputs.top(); y2 = yInputs.top();
                    xInputs.pop(); yInputs.pop();

                    dr = new LineDrawerDDA();
                    shape = new Line(x1, y1, x2, y2, currentColor, dr);
                    hdc = GetDC(hWnd);
                    shape->draw(hdc);
                    ReleaseDC(hWnd, hdc);
                    shapes.push_back(shape);

                    break;
                case DRAW_LINE_PARAMETRIC:
                    if (xInputs.size() < 2){
                        std :: cout << "You need at least 2 points to draw  a line\n";
                        return 0;
                    }
                    //Extracting Line Input
                    x1 = xInputs.top(); y1 = yInputs.top();
                    xInputs.pop(); yInputs.pop();

                    x2 = xInputs.top(); y2 = yInputs.top();
                    xInputs.pop(); yInputs.pop();

                    dr = new LineDrawerParametric();
                    shape = new Line(x1, y1, x2, y2, currentColor, dr);
                    hdc = GetDC(hWnd);
                    shape->draw(hdc);
                    ReleaseDC(hWnd, hdc);
                    shapes.push_back(shape);
                    break;
                case DRAW_LINE_MIDPOINT:
                    if (xInputs.size() < 2){
                        std :: cout << "You need at least 2 points to draw  a line\n";
                        return 0;
                    }
                    //Extracting Line Input
                    x1 = xInputs.top(); y1 = yInputs.top();
                    xInputs.pop(); yInputs.pop();

                    x2 = xInputs.top(); y2 = yInputs.top();
                    xInputs.pop(); yInputs.pop();
                    dr = new LineDrawerMidpoint();

                    shape = new Line(x1, y1, x2, y2, currentColor, dr);
                    hdc = GetDC(hWnd);
                    shape->draw(hdc);
                    ReleaseDC(hWnd, hdc);
                    shapes.push_back(shape);
                    break;
                case DRAW_CIRCLE_DIRECT:
                    if (xInputs.size() < 2){
                        std :: cout << "You need to register at least 2 input points in order to draw a circle\n";
                        return 0; //TODO difference between break; and return 0;???
                    }
                    //Extracting Circle Input
                    x1 = xInputs.top();
                    y1 = yInputs.top();
                    xInputs.pop(); yInputs.pop();
                    x2 = xInputs.top();
                    y2 = yInputs.top();
                    xInputs.pop(); yInputs.pop();
                    a = sqrt( (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) );

                    dr = new CircleDrawerDirect();
                    shape = new Circle(x1, y1, a, currentColor, dr);
                    hdc = GetDC(hWnd);
                    shape->draw(hdc);
                    ReleaseDC(hWnd, hdc);
                    shapes.push_back(shape);
                    break;
                case DRAW_CIRCLE_POLAR:
                    if (xInputs.size() < 2){
                        std :: cout << "You need to register at least 2 input points in order to draw a circle\n";
                        return 0;
                    }
                    //Extracting Circle Input
                    x1 = xInputs.top();
                    y1 = yInputs.top();
                    xInputs.pop(); yInputs.pop();
                    x2 = xInputs.top();
                    y2 = yInputs.top();
                    xInputs.pop(); yInputs.pop();
                    a = sqrt( (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) );

                    dr = new CircleDrawerPolar();
                    shape = new Circle(x1, y1, a, currentColor, dr);
                    hdc = GetDC(hWnd);
                    shape->draw(hdc);
                    ReleaseDC(hWnd, hdc);
                    shapes.push_back(shape);
                    break;
                case DRAW_CIRCLE_ITERATIVE_POLAR:
                    if (xInputs.size() < 2){
                        std :: cout << "You need to register at least 2 input points in order to draw a circle\n";
                        return 0;
                    }
                    //Extracting Circle Input
                    x1 = xInputs.top();
                    y1 = yInputs.top();
                    xInputs.pop(); yInputs.pop();
                    x2 = xInputs.top();
                    y2 = yInputs.top();
                    xInputs.pop(); yInputs.pop();
                    a = sqrt( (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) );

                    dr = new CircleDrawerIterativePolar();
                    shape = new Circle(x1, y1, a, currentColor, dr);
                    hdc = GetDC(hWnd);
                    shape->draw(hdc);
                    ReleaseDC(hWnd, hdc);
                    shapes.push_back(shape);
                    break;
                case DRAW_CIRCLE_MIDPOINT:
                    if (xInputs.size() < 2){
                        std :: cout << "You need to register at least 2 input points in order to draw a circle\n";
                        return 0;
                    }
                    //Extracting Circle Input
                    x1 = xInputs.top();
                    y1 = yInputs.top();
                    xInputs.pop(); yInputs.pop();
                    x2 = xInputs.top();
                    y2 = yInputs.top();
                    xInputs.pop(); yInputs.pop();
                    a = sqrt( (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) );
                    //Constructing objects needed for circle
                    dr = new CircleDrawerMidpoint();
                    shape = new Circle(x2, y2, a, currentColor, dr);
                    //Drawing Circle
                    hdc = GetDC(hWnd);
                    shape->draw(hdc);
                    ReleaseDC(hWnd, hdc);
                    shapes.push_back(shape);
                    break;
                case DRAW_CIRCLE_MODIFIED_MIDPOINT:
                    if (xInputs.size() < 2){
                        std :: cout << "You need to register at least 2 input points in order to draw a circle\n";
                        return 0;
                    }
                    //Extracting Circle Input
                    x1 = xInputs.top();
                    y1 = yInputs.top();
                    xInputs.pop(); yInputs.pop();
                    x2 = xInputs.top();
                    y2 = yInputs.top();
                    xInputs.pop(); yInputs.pop();
                    a = sqrt( (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) );

                    dr = new CircleDrawerModifiedMidpoint();
                    shape = new Circle(x1, y1, a, currentColor, dr);
                    hdc = GetDC(hWnd);
                    shape->draw(hdc);
                    ReleaseDC(hWnd, hdc);
                    shapes.push_back(shape);
                    break;

                case FILL_CIRCLE_WITH_LINE:
                    if (xInputs.size() < 2){
                        std :: cout << "You need to register at least 2 input points in order to draw a circle\n";
                        return 0;
                    }
                    //Extracting Circle Input
                    x1 = xInputs.top();
                    y1 = yInputs.top();
                    xInputs.pop(); yInputs.pop();
                    x2 = xInputs.top();
                    y2 = yInputs.top();
                    xInputs.pop(); yInputs.pop();
                    a = sqrt( (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) );

                    cout << "Enter the number of quarter you would like to fill (1 to 4 inclusive)\n-> ";
                    cin >> x3;
                    cout << endl;

                    dr = new CircleFillerWithLine();
                    shape = new Circle(x1, y1, a, currentColor, dr);
                    hdc = GetDC(hWnd);
                    shape->draw(hdc);
                    ReleaseDC(hWnd, hdc);
                    shapes.push_back(shape);
                    break;
                case FILL_CIRCLE_WITH_CIRCLE:
                    if (xInputs.size() < 2){
                        std :: cout << "You need to register at least 2 input points in order to draw a circle\n";
                        return 0;
                    }
                    //Extracting Circle Input
                    x1 = xInputs.top();
                    y1 = yInputs.top();
                    xInputs.pop(); yInputs.pop();
                    x2 = xInputs.top();
                    y2 = yInputs.top();
                    xInputs.pop(); yInputs.pop();
                    a = sqrt( (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) );

                    cout << "Enter the number of quarter you would like to fill (1 to 4 inclusive)\n-> ";
                    cin >> x3;
                    cout << endl;

                    dr = new CircleFillerWithCircle();
                    shape = new Circle(x1, y1, a, currentColor, dr);
                    hdc = GetDC(hWnd);
                    shape->draw(hdc);
                    ReleaseDC(hWnd, hdc);
                    shapes.push_back(shape);
                    break;
                case FILL_SQUARE_WITH_HERMITE_CURVE:
                    //TODO : Fix Input
                    if (xInputs.size() < 2){
                        std :: cout << "You need to register at least 2 input points in order to draw a square\n";
                        return 0;
                    }
                    //Extracting Circle Input
                    x1 = xInputs.top();
                    y1 = yInputs.top();
                    xInputs.pop(); yInputs.pop();
                    x2 = xInputs.top();
                    y2 = yInputs.top();
                    xInputs.pop(); yInputs.pop();
                    a = sqrt( (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) );

                    dr = new SquareFillerWithHermiteCurve();
                    hdc = GetDC(hWnd);
                    shape = new Square(x1, y1, x1+a, y1+a, currentColor, dr);
                    shape->draw(hdc);
                    ReleaseDC(hWnd, hdc);
                    shapes.push_back(shape);
                    break;
                case FILL_RECTANGLE_WITH_BEZIER_CURVE:
                    if (xInputs.size() < 2){
                        std :: cout << "You need to register at least 2 input points in order to draw a rectangle\n";
                        return 0;
                    }
                    //Extracting Circle Input
                    x1 = xInputs.top();
                    y1 = yInputs.top();
                    xInputs.pop(); yInputs.pop();
                    x2 = xInputs.top();
                    y2 = yInputs.top();
                    xInputs.pop(); yInputs.pop();

                    dr = new RectangleFillerWithBezierCurve();
                    hdc = GetDC(hWnd);
                    shape = new RECTANGLE(x1, y1, x2, y2, currentColor, dr);
                    shape->draw(hdc);
                    ReleaseDC(hWnd, hdc);
                    shapes.push_back(shape);
                    break;
                case CONVEX_FILLING:{
                    //need number of points for polygon
                    int n;
                    cout << "enter number of points needed";
                    cin >> n;
                    if(xInputs.size() < n&&n>3)
                    {
                        std::cout << "You need to register at least " << n
                                  <<" or at least 3" <<" input points in order to draw a Polygon of Size " << n << "\n";
                        return 0;
                    }
                    dr=new ConvexFiller();
                    hdc=GetDC(hWnd);
                    Point *points = new Point[n];
                    for(int i=0; i < n; ++i)
                    {
                        x1 = xInputs.top();
                        y1 = yInputs.top();
                        xInputs.pop(); yInputs.pop();
                        points[i].x = x1; points[i].y=y1;
                    }
                    shape = new POLYGON(points,n);
                    dr->draw(shape,hdc);
                    ReleaseDC(hWnd, hdc);
                    shapes.push_back(shape);
                    break;
                }
                case NON_CONVEX_FILLING:{
                    //need number of points for polygon
                    int n;
                    cout << "enter number of points needed";
                    cin >> n;
                    if(xInputs.size() < n&&n>3)
                    {
                        std::cout << "You need to register at least " << n
                                  <<" or at least 3" <<" input points in order to draw a Polygon of Size " << n << "\n";
                        return 0;
                    }
                    dr=new NonConvexFiller();
                    hdc=GetDC(hWnd);
                    Point *points = new Point[n];
                    for(int i=0; i < n; ++i)
                    {
                        x1 = xInputs.top();
                        y1 = yInputs.top();
                        xInputs.pop(); yInputs.pop();
                        points[i].x = x1; points[i].y=y1;
                    }
                    shape = new POLYGON(points,n);
                    dr->draw(shape,hdc);
                    ReleaseDC(hWnd, hdc);
                    shapes.push_back(shape);
                    break;
                }
                case RECURSIVE_FLOOD_FILL:
                {
                    if (xInputs.size() < 1){
                        std :: cout << "You need to register at least 1 input point in order to Fill\n";
                        return 0;
                    }
                    x1 = xInputs.top();
                    y1 = yInputs.top();
                    xInputs.pop(); yInputs.pop();
                    Point p(x1,y1);
                    dr=new FloodFillRecursive();
                    shape = new Flood(p,currentColor,dr);
                    shape->c=currentColor;
                    hdc=GetDC(hWnd);
                    shape->draw(hdc);
                    ReleaseDC(hWnd, hdc);
                    shapes.push_back(shape);
                    break;
                }
                case NON_RECURSIVE_FLOOD_FILL:
                {
                    if (xInputs.size() < 1){
                        std :: cout << "You need to register at least 1 input point in order to Fill\n";
                        return 0;
                    }
                    x1 = xInputs.top();
                    y1 = yInputs.top();
                    xInputs.pop(); yInputs.pop();
                    Point p(x1,y1);
                    dr=new FloodFillNonRecursive();
                    shape = new Flood(p,currentColor,dr);
                    shape->c=currentColor;
                    hdc=GetDC(hWnd);
                    shape->draw(hdc);
                    ReleaseDC(hWnd, hdc);
                    shapes.push_back(shape);
                    break;
                }
                case CARDINAL_SPLINE_CURVE:
                    if (xInputs.size() < 4){
                        std :: cout << "You need to register at least 4 input points in order to draw a curve\n";
                        return 0;
                    }
                    //Extracting Circle Input
                    x1 = xInputs.top();
                    y1 = yInputs.top();
                    xInputs.pop(); yInputs.pop();
                    x2 = xInputs.top();
                    y2 = yInputs.top();
                    xInputs.pop(); yInputs.pop();
                    x3 = xInputs.top();
                    y3 = yInputs.top();
                    xInputs.pop(); yInputs.pop();
                    x4 = xInputs.top();
                    y4 = yInputs.top();
                    xInputs.pop(); yInputs.pop();

                    dr = new CurveDrawerBezier();
                    shape = new Curve(x1, y1, x2, y2, x3, y3, x4, y4, currentColor, dr);
                    hdc = GetDC(hWnd);
                    shape->draw(hdc);
                    ReleaseDC(hWnd, hdc);
                    shapes.push_back(shape);
                    break;
                case DRAW_ELLIPSE_DIRECT:
                    if (xInputs.size() < 3){
                        std :: cout << "You need to register at least 3 input points in order to draw an ellipse\n";
                        return 0;
                    }
                    x1 = xInputs.top();
                    y1 = yInputs.top();
                    xInputs.pop(); yInputs.pop();
                    x2 = xInputs.top();
                    y2 = yInputs.top();
                    xInputs.pop(); yInputs.pop();
                    x3 = xInputs.top();
                    y3 = yInputs.top();
                    xInputs.pop(); yInputs.pop();
                    a = sqrt( (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) );
                    b = sqrt( (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3) );


                    dr = new EllipseDrawerDirect();
                    shape = new ELLIPSE(x1, y1, b, a, currentColor, dr);
                    hdc = GetDC(hWnd);
                    shape->draw(hdc);
                    ReleaseDC(hWnd, hdc);
                    shapes.push_back(shape);
                    break;
                case DRAW_ELLIPSE_POLAR:
                    if (xInputs.size() < 3){
                        std :: cout << "You need to register at least 3 input points in order to draw an ellipse\n";
                        return 0;
                    }
                    x1 = xInputs.top();
                    y1 = yInputs.top();
                    xInputs.pop(); yInputs.pop();
                    x2 = xInputs.top();
                    y2 = yInputs.top();
                    xInputs.pop(); yInputs.pop();
                    x3 = xInputs.top();
                    y3 = yInputs.top();
                    xInputs.pop(); yInputs.pop();
                    a = sqrt( (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) );
                    b = sqrt( (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3) );

                    dr = new EllipseDrawerPolar();
                    shape = new ELLIPSE(x1, y1, b, a, currentColor, dr);
                    hdc = GetDC(hWnd);
                    shape->draw(hdc);
                    ReleaseDC(hWnd, hdc);
                    shapes.push_back(shape);
                    break;
                case DRAW_ELLIPSE_MIDPOINT:
                    if (xInputs.size() < 3){
                        std :: cout << "You need to register at least 3 input points in order to draw an ellipse\n";
                        return 0;
                    }
                    x1 = xInputs.top();
                    y1 = yInputs.top();
                    xInputs.pop(); yInputs.pop();
                    x2 = xInputs.top();
                    y2 = yInputs.top();
                    xInputs.pop(); yInputs.pop();
                    x3 = xInputs.top();
                    y3 = yInputs.top();
                    xInputs.pop(); yInputs.pop();
                    a = sqrt( (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) );
                    b = sqrt( (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3) );

                    dr = new EllipseDrawerMidpoint();
                    shape = new ELLIPSE(x1, y1, b, a, currentColor, dr);
                    hdc = GetDC(hWnd);
                    shape->draw(hdc);
                    ReleaseDC(hWnd, hdc);
                    shapes.push_back(shape);
                    break;
                case CLIP_RECTANGLE_POINT:
                {
                    if(xInputs.size() < 3)
                    {
                        std::cout
                                << "You need to register at least 3 input points in order to clip a point on a rectangle\n";
                        return 0;
                    }
                    x1=xInputs.top();
                    y1=yInputs.top();
                    xInputs.pop();
                    yInputs.pop();
                    x2=xInputs.top();
                    y2=yInputs.top();
                    xInputs.pop();
                    yInputs.pop();
                    x3=xInputs.top();
                    y3=yInputs.top();
                    dr=new RectangleDrawer();
                    Shape *rect=new RECTANGLE(x1, y1, x2, y2, currentColor, dr);
                    hdc=GetDC(hWnd);
                    shape->draw(hdc);
                    shapes.push_back(rect);
                    dr=new PointDrawer();
                    Shape *point=new Point(x3, y3, currentColor, dr);
                    dr=new ClippingRectanglePoint();
                    ((ClippingRectanglePoint *) dr)->draw(rect, point, hdc);


                    break;
                }
                case CLIP_RECTANGLE_LINE:
                {
                    if(xInputs.size() < 4)
                    {
                        std::cout
                                << "You need to register 4 input points in order to clip a line on a rectangle\n";
                        return 0;
                    }
                    x1=xInputs.top();
                    y1=yInputs.top();
                    xInputs.pop();
                    yInputs.pop();
                    x2=xInputs.top();
                    y2=yInputs.top();
                    xInputs.pop();
                    yInputs.pop();
                    x3=xInputs.top();
                    y3=yInputs.top();
                    xInputs.pop();
                    yInputs.pop();
                    x4=xInputs.top();
                    y4=yInputs.top();

                    dr=new RectangleDrawer();
                    Shape *rect=new RECTANGLE(x1, y1, x2, y2, currentColor, dr);
                    hdc=GetDC(hWnd);
                    shape->draw(hdc);
                    shapes.push_back(rect);
                    dr=new LineDrawerDDA();
                    Shape *line=new Line(x3, y3, x4, y4, currentColor, dr);
                    dr=new ClippingRectangleLine();
                    ((ClippingRectangleLine *) dr)->draw(rect, line, hdc);
                    break;
                }

                case CLIP_RECTANGLE_POLYGON:
                {
                    int n;
                    cout << "enter number of points needed";
                    cin >> n;
                    if(xInputs.size() < n && n > 5)
                    {
                        std::cout << "You need to register at least " << n
                                  << " or at least 5" << " input points in order to draw a Polygon of Size " << n
                                  << "\n";
                        return 0;
                    }
                    x1=xInputs.top();
                    y1=yInputs.top();
                    xInputs.pop();
                    yInputs.pop();
                    x2=xInputs.top();
                    y2=yInputs.top();
                    hdc=GetDC(hWnd);
                    Point *points=new Point[n];
                    for(int i=0; i < n; ++i)
                    {
                        x1=xInputs.top();
                        y1=yInputs.top();
                        xInputs.pop();
                        yInputs.pop();
                        points[i].x=x1;
                        points[i].y=y1;
                    }
                    dr=new RectangleDrawer();
                    Shape *rect=new RECTANGLE(x1, y1, x2, y2, currentColor, dr);
                    rect->draw(hdc);
                    shapes.push_back(rect);
                    dr=new PolygonDrawer();
                    Shape *poly= new POLYGON(points,n,currentColor,dr);
                    dr = new ClippingRectanglePolygon();
                    ((ClippingRectanglePolygon *) dr)->draw(rect, poly, hdc);
                    break;
                }
                case CLIP_SQUARE_POINT:

                    break;
                case CLIP_SQUARE_LINE:
                    break;
                case CLIP_CIRCLE_POINT:
                {
                    if(xInputs.size() < 3)
                    {
                        std::cout
                                << "You need to register at least 3 input points in order to clip a point on a Circle\n";
                        return 0;
                    }
                    x1=xInputs.top();
                    y1=yInputs.top();
                    xInputs.pop();
                    yInputs.pop();
                    x2=xInputs.top();
                    y2=yInputs.top();
                    xInputs.pop();
                    yInputs.pop();
                    x3=xInputs.top();
                    y3=yInputs.top();
                    dr=new CircleDrawerDirect();
                    a=sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
                    Shape *circle=new Circle(x1, y1, a, currentColor, dr);
                    hdc=GetDC(hWnd);
                    shape->draw(hdc);
                    shapes.push_back(circle);
                    dr=new PointDrawer();
                    Shape *point=new Point(x3, y3, currentColor, dr);
                    dr=new ClippingCirclePoint();
                    ((ClippingCirclePoint *) dr)->draw(circle, point, hdc);
                    break;
                }
                case CLIP_CIRCLE_LINE:
                {
                    if(xInputs.size() < 4)
                    {
                        std::cout
                                << "You need to register at least 4 input points in order to clip a Line on a Circle\n";
                        return 0;
                    }
                    x1=xInputs.top();
                    y1=yInputs.top();
                    xInputs.pop();
                    yInputs.pop();
                    x2=xInputs.top();
                    y2=yInputs.top();
                    xInputs.pop();
                    yInputs.pop();
                    x3=xInputs.top();
                    y3=yInputs.top();
                    xInputs.pop();
                    yInputs.pop();
                    x4=xInputs.top();
                    y4=yInputs.top();

                    dr=new CircleDrawerDirect();
                    a=sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
                    Shape *circle=new Circle(x1, y1, a, currentColor, dr);
                    hdc=GetDC(hWnd);
                    shape->draw(hdc);
                    shapes.push_back(circle);
                    dr=new LineDrawerMidpoint();
                    Shape *line=new Line(x3, y3, x4, y4, currentColor, dr);
                    dr=new ClippingCircleLine();
                    ((ClippingCircleLine *) dr)->draw(circle, line, hdc);
                    break;
                }
                case CLEAR_WINDOW:
                    shapes.clear();
                    InvalidateRect(hWnd, NULL, true);
                    break;
                case EXIT_WINDOW:
                    DestroyWindow(hWnd);
                    break;
                default:
                    break;
            }

            break;
        case WM_CREATE:
            if (firstCreate) {
                firstCreate = false;
                AddMenu(hWnd);
            }
            break;
        case WM_DESTROY:
            PostQuitMessage(0);       /* send a WM_QUIT to the message queue */
            break;
        case WM_LBUTTONDOWN:
            //Circles are generated to keep track of the clicking position
            xInputs.push(GET_X_LPARAM(lp));
            yInputs.push(GET_Y_LPARAM(lp));

            break;
        case WM_PAINT: {
            PAINTSTRUCT ps;
            RECT rc;
            HDC hdc = BeginPaint(hWnd, &ps);
            GetClientRect(hWnd, &rc);
            SetDCBrushColor(hdc, RGB(255, 255, 255));
            FillRect(hdc, &rc, (HBRUSH) GetStockObject(DC_BRUSH));
            EndPaint(hWnd, &ps);
            return 0;
        }
        case WM_SETCURSOR:
            if (LOWORD(lp) == HTCLIENT) {
                ::SetCursor(cursor);
                return TRUE;
            }
            break;
        default:
            return DefWindowProcW(hWnd, msg, wp, lp);

    }

}

void AddMenu(HWND hWnd) {
    hMenu = CreateMenu();
    HMENU mainList = CreateMenu();

    /* Draw Line SubList */
    HMENU drawLineSubList = CreateMenu();
    AppendMenu(drawLineSubList, MF_STRING, DRAW_LINE_DDA, "DDA");
    AppendMenu(drawLineSubList, MF_STRING, DRAW_LINE_PARAMETRIC, "Parametric");
    AppendMenu(drawLineSubList, MF_STRING, DRAW_LINE_MIDPOINT, "Midpoint");

    /* Draw Circle SubList */
    HMENU drawCircleSubList = CreateMenu();
    AppendMenu(drawCircleSubList, MF_STRING, DRAW_CIRCLE_DIRECT, "Direct");
    AppendMenu(drawCircleSubList, MF_STRING, DRAW_CIRCLE_POLAR, "Polar");
    AppendMenu(drawCircleSubList, MF_STRING, DRAW_CIRCLE_ITERATIVE_POLAR, "Iterative Polar");
    AppendMenu(drawCircleSubList, MF_STRING, DRAW_CIRCLE_MIDPOINT, "Midpoint");
    AppendMenu(drawCircleSubList, MF_STRING, DRAW_CIRCLE_MODIFIED_MIDPOINT, "Modified midpoint");


    /* Filling SubList */
    HMENU fillingSubList = CreateMenu();
    AppendMenu(fillingSubList, MF_STRING, FILL_CIRCLE_WITH_LINE, "Fill circle with line");
    AppendMenu(fillingSubList, MF_STRING, FILL_CIRCLE_WITH_CIRCLE, "Fill with circle with circle");
    AppendMenu(fillingSubList, MF_STRING, FILL_SQUARE_WITH_HERMITE_CURVE, "Fill square with hermite curve");
    AppendMenu(fillingSubList, MF_STRING, FILL_RECTANGLE_WITH_BEZIER_CURVE, "Fill rectangle with bezier curve");
    AppendMenu(fillingSubList, MF_STRING, CONVEX_FILLING, "Convex filling");
    AppendMenu(fillingSubList, MF_STRING, NON_CONVEX_FILLING, "Non convex filling");
    AppendMenu(fillingSubList, MF_STRING, RECURSIVE_FLOOD_FILL, "Recursive flood fill");
    AppendMenu(fillingSubList, MF_STRING, NON_RECURSIVE_FLOOD_FILL, "Non recursive flood fill");

    /* Ellipse SubList */
    HMENU ellipseSubList = CreateMenu();
    AppendMenu(ellipseSubList, MF_STRING, DRAW_ELLIPSE_DIRECT, "Direct");
    AppendMenu(ellipseSubList, MF_STRING, DRAW_ELLIPSE_POLAR, "Polar");
    AppendMenu(ellipseSubList, MF_STRING, DRAW_ELLIPSE_MIDPOINT, "Midpoint");

    /* Clipping SubList */
    HMENU clippingSubList = CreateMenu();

    /* Rectangle Clipping SubList */
    HMENU rectangleClippingSubList = CreateMenu();
    AppendMenu(rectangleClippingSubList, MF_STRING, CLIP_RECTANGLE_POINT, "Point");
    AppendMenu(rectangleClippingSubList, MF_STRING, CLIP_RECTANGLE_LINE, "Line");
    AppendMenu(rectangleClippingSubList, MF_STRING, CLIP_RECTANGLE_POLYGON, "POLYGON");

    /* Square Clipping SubList */
    HMENU squareClippingSubList = CreateMenu();
    AppendMenu(squareClippingSubList, MF_STRING, CLIP_SQUARE_POINT, "Point");
    AppendMenu(squareClippingSubList, MF_STRING, CLIP_SQUARE_LINE, "Line");

    /* Circle Clipping SubList */
    HMENU circleClippingSubList = CreateMenu();
    AppendMenu(circleClippingSubList, MF_STRING, CLIP_CIRCLE_POINT, "Point");
    AppendMenu(circleClippingSubList, MF_STRING, CLIP_CIRCLE_LINE, "Line");


    AppendMenu(clippingSubList, MF_POPUP, (UINT_PTR) rectangleClippingSubList, "Rectangle");
    AppendMenu(clippingSubList, MF_POPUP, (UINT_PTR) squareClippingSubList, "Square");
    AppendMenu(clippingSubList, MF_POPUP, (UINT_PTR) circleClippingSubList, "Circle");

    /* Shape Color Menu */
    HMENU shapeColorSubList = CreateMenu();
    AppendMenu(shapeColorSubList, MF_STRING, COLOR_BLUE, "Blue");
    AppendMenu(shapeColorSubList, MF_STRING, COLOR_RED, "Red");
    AppendMenu(shapeColorSubList, MF_STRING, COLOR_GREEN, "Green");
    AppendMenu(shapeColorSubList, MF_STRING, COLOR_CYAN, "Cyan");
    AppendMenu(shapeColorSubList, MF_STRING, COLOR_MAGENTA, "Magenta");
    AppendMenu(shapeColorSubList, MF_STRING, COLOR_YELLOW, "Yellow");
    AppendMenu(shapeColorSubList, MF_STRING, COLOR_BLACK, "Black");


    /* Demo List */
    AppendMenu(mainList, MF_STRING, CHANGE_CURSOR, "Change Cursor");
    AppendMenu(mainList, MF_STRING, DISABLE_KEYBOARD, "Disable keyboard");
    AppendMenu(mainList, MF_POPUP, (UINT_PTR) shapeColorSubList, "Shape Color");
    AppendMenu(mainList, MF_STRING, SAVE_DATA, "Save data");
    AppendMenu(mainList, MF_STRING, LOAD_DATA, "Load data");
    AppendMenu(mainList, MF_POPUP, (UINT_PTR) drawLineSubList, "Draw Line");
    AppendMenu(mainList, MF_POPUP, (UINT_PTR) drawCircleSubList, "Draw Circle");
    AppendMenu(mainList, MF_POPUP, (UINT_PTR) fillingSubList, "Filling algorithms");
    AppendMenu(mainList, MF_STRING, CARDINAL_SPLINE_CURVE, "Cardinal spline curve");
    AppendMenu(mainList, MF_POPUP, (UINT_PTR) ellipseSubList, "Draw Ellipse");
    AppendMenu(mainList, MF_POPUP, (UINT_PTR) clippingSubList, "Clip");
    AppendMenu(mainList, MF_STRING, CLEAR_WINDOW, "Clear");
    AppendMenu(mainList, MF_STRING, EXIT_WINDOW, "Exit");

    AppendMenu(hMenu, MF_POPUP, (UINT_PTR) mainList, "Demo");

    SetMenu(hWnd, hMenu);
}
