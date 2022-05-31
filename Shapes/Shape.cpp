//
// Created by Mohamed on 5/29/2022.
//

#include "Shape.h"

map<string, int> Shape::mp = map<string, int>();


vector<Shape*> Shape::shapes = vector<Shape*>();

void Shape::addShape(string str, Shape* s) {
    mp[str] = shapes.size();
    shapes.push_back(s);
}

std::string Shape::getSave() {
    return std::string();
}
