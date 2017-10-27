#ifndef __CELL_H__
#define __CELL_H__

#include <string.h>
#include "textdisplay.h"
#include "Character.h"
#include "item.h"

class GObject;

class Cell {
  Cell *neighbors[8];
  GObject *g;
  int x, y;
  TextDisplay *td;
  char def;
  char current;
  int offsetX, offsetY;
  public:
    virtual void setTile(Cell *c) {};
    virtual Cell *getTile() { return 0;}
    Cell();
    Cell(GObject *g, TextDisplay *td, int offsetX, int offsetY,  char def, int x, int y);
    void addNeighbor(Cell *c, int i);
    void notify(GObject *go);
    Cell *getNeighbor(std::string direction);
    char getCurrent();
    char getDef();
    Character* getTarget();
    Item *getPotion();
};

#endif
