#ifndef __FLOOR_H_
#define __FLOOR_H_
#include "room.h"
#include "textdisplay.h"
#include <iostream>
#include "passage.h"
#include "enemy.h"
#include "item.h"

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
    Item *potions[10];
    int potionCount;
    Stairs *s;
    public:
       Floor();
       ~Floor();
       Cell *getCell();
       Cell *getACell(GObject *g);
       void spawnEnemy();
       void spawnGold();
       void spawnPotion();
       void moveEnemies();
       void spawnStairs(int n);
       void clear();
       void init();
    friend std::ostream &operator<<(std::ostream &out, Floor &f);
};
#endif
