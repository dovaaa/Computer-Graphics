#include <windows.h>
#include "Shapes/Shape.h"
#include "Drawers/Drawer.h"
#include "Drawers/LineAlgorithms/LineDrawerDDA.h"
#include "Shapes/Line.h"

#include <iostream>


#define WHITE_BACKGROUND 999
#define CHANGE_CURSOR 1
#define DISABLE_KEYBOARD 2
#define SET_SHAPE_COLOR 3
#define SAVE_DATA 4
#define LOAD_DATA 5
#define DRAW_LINE_DDA 6
#define DRAW_LINE_PARAMETRIC 7
#define DRAW_LINE_MIDPOINT 8
#define DRAW_CIRCLE_DIRECT 9
#define DRAW_CIRCLE_POLAR 10
#define DRAW_CIRCLE_ITERATIVE_POLAR 11
#define DRAW_CIRCLE_MIDPOINT 12
#define DRAW_CIRCLE_MODIFIED_MIDPOINT 13
#define FILL_CIRCLE_WITH_LINE 14
#define FILL_CIRCLE_WITH_CIRCLE 15
#define FILL_SQUARE_WITH_HERMITE_CURVE 16
#define FILL_RECTANGLE_WITH_BEZIER_CURVE 17
#define CONVEX_FILLING 18
#define NON_CONVEX_FILLING 19
#define RECURSIVE_FLOOD_FILL 20
#define NON_RECURSIVE_FLOOD_FILL 21
#define CARDINAL_SPLINE_CURVE 22
#define DRAW_ELLIPSE_DIRECT 23
#define DRAW_ELLIPSE_POLAR 24
#define DRAW_ELLIPSE_MIDPOINT 25
#define CLIP_RECTANGLE_POINT 26
#define CLIP_RECTANGLE_LINE 27
#define CLIP_RECTANGLE_POLYGON 28
#define CLIP_SQUARE_POINT 29
#define CLIP_SQUARE_LINE 30
#define CLIP_CIRCLE_POINT 31
#define CLIP_CIRCLE_LINE 32
#define CLEAR_WINDOW 33
#define EXIT_WINDOW 34

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

bool background_flag = false;
bool firstCreate = true;

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {

    HDC hdc;
    HBRUSH hbrBkgnd = NULL;
    Line line;
    Drawer *dr;
    switch (msg)                  /* handle the messages */
    {
        case WM_COMMAND:

            switch (wp) {
                case WHITE_BACKGROUND:
                    // todo 1- save the date 2- change the background 3- load the data, take care to not change the save of the user
                    // leave it to me (Kofta)
                    background_flag = true;
                    SendMessage(hWnd, WM_PAINT, wp, lp);
                    break;
                case CHANGE_CURSOR:
                    break;
                case DISABLE_KEYBOARD:
                    break;
                case SET_SHAPE_COLOR:
                    break;
                case SAVE_DATA:
                    break;
                case LOAD_DATA:
                    break;
                case DRAW_LINE_DDA:
                    dr = new LineDrawerDDA();
                    line = Line(0, 0, 100, 100, RGB(0, 0, 0), dr);
                    hdc = GetDC(hWnd);
                    line.draw(hdc);
                    ReleaseDC(hWnd, hdc);

                    break;
                case DRAW_LINE_PARAMETRIC:
                    break;
                case DRAW_LINE_MIDPOINT:
                    break;
                case DRAW_CIRCLE_DIRECT:
                    break;
                case DRAW_CIRCLE_POLAR:
                    break;
                case DRAW_CIRCLE_ITERATIVE_POLAR:
                    break;
                case DRAW_CIRCLE_MIDPOINT:
                    break;
                case DRAW_CIRCLE_MODIFIED_MIDPOINT:
                    break;
                case FILL_CIRCLE_WITH_LINE:
                    break;
                case FILL_CIRCLE_WITH_CIRCLE:
                    break;
                case FILL_SQUARE_WITH_HERMITE_CURVE:
                    break;
                case FILL_RECTANGLE_WITH_BEZIER_CURVE:
                    break;
                case CONVEX_FILLING:
                    break;
                case NON_CONVEX_FILLING:
                    break;
                case RECURSIVE_FLOOD_FILL:
                    break;
                case NON_RECURSIVE_FLOOD_FILL:
                    break;
                case CARDINAL_SPLINE_CURVE:
                    break;
                case DRAW_ELLIPSE_DIRECT:
                    break;
                case DRAW_ELLIPSE_POLAR:
                    break;
                case DRAW_ELLIPSE_MIDPOINT:
                    break;
                case CLIP_RECTANGLE_POINT:
                    break;
                case CLIP_RECTANGLE_LINE:
                    break;
                case CLIP_RECTANGLE_POLYGON:
                    break;
                case CLIP_SQUARE_POINT:
                    break;
                case CLIP_SQUARE_LINE:
                    break;
                case CLIP_CIRCLE_POINT:
                    break;
                case CLIP_CIRCLE_LINE:
                    break;
                case CLEAR_WINDOW:
                    break;
                case EXIT_WINDOW:
                    DestroyWindow(hWnd);
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
        case WM_PAINT: {
            if (LOWORD(wp) == WHITE_BACKGROUND || background_flag) {
                PAINTSTRUCT ps;
                RECT rc;
                HDC hdc = BeginPaint(hWnd, &ps);
                GetClientRect(hWnd, &rc);
                SetDCBrushColor(hdc, RGB(255, 255, 255));
                FillRect(hdc, &rc, (HBRUSH) GetStockObject(DC_BRUSH));
                EndPaint(hWnd, &ps);
            }
                return 0;
        }
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
    AppendMenu(rectangleClippingSubList, MF_STRING, CLIP_RECTANGLE_POLYGON, "Polygon");

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


    /* Demo List */
    AppendMenu(mainList, MF_STRING, WHITE_BACKGROUND, "White background");
    AppendMenu(mainList, MF_STRING, CHANGE_CURSOR, "Change Cursor");
    AppendMenu(mainList, MF_STRING, DISABLE_KEYBOARD, "Disable keyboard");
    AppendMenu(mainList, MF_STRING, SET_SHAPE_COLOR, "Set shape color");
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