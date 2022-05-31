#include "Drawer.h"

map<string, int> Drawer::mp = map<string, int>();

vector<Drawer*> Drawer::drawers = vector<Drawer*>();

void Drawer::addDrawer(string str, Drawer* d) {
    mp[str] = drawers.size();
    drawers.push_back(d);
}