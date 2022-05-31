//
// Created by Dova on 05/31/22.
//

#ifndef GRAPHICS_SQUAREFILLERWITHHERMITECURVE_H
#define GRAPHICS_SQUAREFILLERWITHHERMITECURVE_H

#include "../../Drawer.h"

class SquareFillerWithHermiteCurve: public Drawer{
public:
    void draw(Shape *curve, HDC &hdc) override;
    Drawer* copy() override;
};


#endif //GRAPHICS_SQUAREFILLERWITHHERMITECURVE_H
