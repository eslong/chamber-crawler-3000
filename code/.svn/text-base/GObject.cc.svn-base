#include "GObject.h"
#include "cell.h"
char GObject::getSymbol() {
  return graphic;
}

void GObject::setCell(Cell *cp) {
  c = cp;
  c->notify(this);
}

int GObject::getX() {
  return x;
}

int GObject::getY() {
  return y;
}

void GObject::setGraphic(char g) {
    graphic = g;
}

void GObject::clearCell() {
    c->notify(0);
}

void GObject::setRoom(int n) {
    room = n;
}

int GObject::getRoom() {
    return room;
}

void GObject::dummy() {}
