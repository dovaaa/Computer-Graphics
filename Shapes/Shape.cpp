//
// Created by Mohamed on 5/29/2022.
//

#include "Shape.h"

map<string, int> Shape::mp = map<string, int>();


vector<Shape*> Shape::shapes = vector<Shape*>();

void Shape::addShape(string str, Shape* s) {
    shapes.push_back(s);
    mp[str] = idx++;
}

int Shape::idx = 0;