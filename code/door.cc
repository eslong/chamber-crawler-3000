#include "door.h"

void Door::setTile(Cell *c) {
    tile = c;
}

Cell *Door::getTile() {
    return tile;
}
