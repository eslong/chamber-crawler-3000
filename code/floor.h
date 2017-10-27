#ifndef __FLOOR_H_
#define __FLOOR_H_
#include "room.h"
#include "textdisplay.h"
#include <iostream>
#include "passage.h"
#include "enemy.h"
#include "item.h"
#include <string>

class Treasure;
class Stairs;
class Floor {
    Room *rooms[5];
    Passage *p;
    TextDisplay *td;
    Enemy *enemies[20];
    int enemyCount;
    Treasure *gold[10];
    int goldCount;
    Item *potions[11];
    int potionCount;
    Stairs *s;
    std::string action;
    public:
       Floor();
       ~Floor();
       Cell *getCell();
       Cell *getACell(GObject *g);
       Cell *getCell(int room, int x, int y);
       void spawnEnemy();
       void spawnGold();
       void spawnPotion();
       void moveEnemies();
       void spawnStairs(int n);
       void clear();
       void init();
       void addObject(int room, int x, int y, char c);
       std::string getAction();
    friend std::ostream &operator<<(std::ostream &out, Floor &f);
};
#endif
