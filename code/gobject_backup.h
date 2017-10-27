#ifndef __GOBJECT_H__
#define __GOBJECT_H__

#include <string>

class Cell;

class GObject {
  int x, y;
  protected:
    Cell *c;
    char graphic;
    int room;
    void setGraphic(char g);
  public:
    GObject() {
      x = 0;
      y = 0;
      graphic = '1';
      c = 0;
    }
    char getSymbol();
    void setCell(Cell *cp);
    void clearCell();
    int getY();
    int getX();
    void setRoom(int n);
    int getRoom();
    virtual void dummy();
};

#endif
