//
// Created by Mohamed on 5/28/2022.
//

#ifndef GRAPHICS_LINEDRAWERPARAMETRIC_H
#define GRAPHICS_LINEDRAWERPARAMETRIC_H

#include "../Drawer.h"
#include "../../Shapes/Shape.h"

class LineDrawerParametric : public Drawer {
public:
    void draw(Shape *line) override;
};


#endif //GRAPHICS_LINEDRAWERPARAMETRIC_H
