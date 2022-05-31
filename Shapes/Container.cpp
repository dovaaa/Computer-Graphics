//
// Created by Kofta on 5/31/2022.
//

#include "Container.h"

Shape *Container::copy(std::string s) {
    vector<string> vec = UT::split(s, '|');
    Shape *sh[2];
    for (int i = 0; i < vec.size(); ++i) {
        vector<string> cur = UT::split(vec[i], '-');
        sh[i]=Shape::shapes[stoi(cur[0])]->copy(cur[1]);
        sh[i]->drawer=Drawer::drawers[stoi(cur[2])]->copy();
    }
    return new Container(sh[0], sh[1], NULL);
}

void Container::draw(HDC &hdc) {
    drawer->draw(this, hdc);
}

void Container::save(File &f) {
    string s = to_string(mp["container"]) + ':' + s1->getSave() + '|' + s2->getSave() + ':' + to_string(drawer->id) + '\n';
    f.write(s);
}

Container::Container(Shape *pShape, Shape *pShape1, Drawer *pDrawer) {
    this->s1 = pShape;
    this->s2 = pShape1;
    this->drawer = pDrawer;
}
