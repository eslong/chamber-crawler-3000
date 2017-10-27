#ifndef __DOOR_H__
#define __DOOR_H__
#include "cell.h"

class Door: public Cell {
    Cell *tile;
    public:
        Door(GObject *g, TextDisplay *td, int offsetX, int offsetY, int x, int y):
            Cell(g, td, offsetX, offsetY, '+', x, y) {
            tile= 0;
        }
        void setTile(Cell *c);
        Cell *getTile();
};
#endif
