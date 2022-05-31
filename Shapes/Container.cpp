//
// Created by Kofta on 5/31/2022.
//

#include "Container.h"

Shape *Container::copy(std::string) {
    return nullptr;
}

void Container::draw(HDC &hdc) {

}

void Container::save(File &f) {

}

Container::Container(Shape *pShape, Shape *pShape1, Drawer *pDrawer) {
    this->s1 = pShape;
    this->s2 = pShape1;
    this->drawer = pDrawer;
}
