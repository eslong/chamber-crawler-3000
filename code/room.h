#ifndef __ROOM_H__
#define __ROOM_H__
#include "cell.h"

class Room {
  int x, y;
  void initRoom0(TextDisplay *td);
  void initRoom1(TextDisplay *td);
  void initRoom2(TextDisplay *td);
  void initRoom3(TextDisplay *td);
  void initRoom4(TextDisplay *td);
    protected:
  void addNeighbors();
  Cell ***tiles;
  public:
    Room(int x, int y, int type, TextDisplay *td);
    ~Room();
    Cell *getCell(int x, int y);
    Cell *getCell();
};

#endif
