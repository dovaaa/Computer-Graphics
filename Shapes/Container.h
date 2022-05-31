//
// Created by Kofta on 5/31/2022.
//

#ifndef GRAPHICS_CONTAINER_H
#define GRAPHICS_CONTAINER_H


#include "Shape.h"

class Container : public Shape {
public:
    Container(Shape *pShape, Shape *pShape1, Drawer *pDrawer);

    Shape *s1, *s2;
    Shape* copy(std::string) override;
    void draw(HDC& hdc) override;
    void save(File &f) override;
};


#endif //GRAPHICS_CONTAINER_H
