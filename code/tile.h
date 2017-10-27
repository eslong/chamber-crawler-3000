#ifndef __TILE_H__
#define __TILE_H__
#include "cell.h"

class Tile: public Cell {
    public:
        Tile(GObject *g, TextDisplay *td, int offsetX, int offsetY, int x, int y):
            Cell(g, td, offsetX, offsetY, '.', x, y) { };
};
#endif
