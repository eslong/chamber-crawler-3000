#include "floor.h"
#include "cell.h"
#include "door.h"
#include "human.h"
#include "dwarf.h"
#include "halfling.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "healthpotion.h"
#include "treasure.h"
#include "stairs.h"
#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;

Floor::Floor() {
    enemyCount = 0;
   td = new TextDisplay(25, 79);
   rooms[0] = new Room(28, 6, 0, td);
   rooms[1] = new Room(39, 12, 1, td);
   rooms[2] = new Room(14, 5, 2, td);
   rooms[3] = new Room(23, 9, 3, td);
   rooms[4] = new Room(41, 8, 4, td);
   p = new Passage(57, 17, td);
   
   //To add the pointers from doors
   Cell *door;
   Cell *tile;
   //Room 0
   cout<<"ADDING ROOM 0"<<endl;
   door = rooms[0]->getCell(11, 5);
   tile = p->getCell(0, 4);
   door->setTile(tile);
   //cout<<"ADDED"<<endl;
   door = rooms[0]->getCell(27, 2);
   tile = p->getCell(17, 0);
   door->setTile(tile); //

   door = p->getCell(0, 3);
   tile = rooms[0]->getCell(11, 4);
   door->setTile(tile);
   //cout<<"ADDED"<<endl;
   door = p->getCell(16, 0);
   tile = rooms[0]->getCell(26, 2);
   door->setTile(tile);

   //Room 1
   //cout<<"ADDING ROOM !"<<endl;
   door = rooms[1]->getCell(0, 2);
   tile = p->getCell(24, 0);
   door->setTile(tile);
   door = rooms[1]->getCell(5, 5);
   tile = p->getCell(30, 4);
   door->setTile(tile);
   door = rooms[1]->getCell(22, 9);
   tile = p->getCell(46, 7);
   door->setTile(tile);
   door = rooms[1]->getCell(31, 11);
   tile = p->getCell(56, 10);
   door->setTile(tile);
   
   door = p->getCell(56, 9);
   tile = rooms[1]->getCell(31, 10);
   door->setTile(tile);
   door = p->getCell(47, 7);
   tile = rooms[1]->getCell(23, 9);
   door->setTile(tile);
   door = p->getCell(30, 3);
   tile = rooms[1]->getCell(5, 4);
   door->setTile(tile);
   door = p->getCell(25, 0);
   tile = rooms[1]->getCell(1, 2);
   door->setTile(tile);

   //Room 2
   door = rooms[2]->getCell(6, 0);
   tile = p->getCell(30, 4);
   door->setTile(tile);
   door = rooms[2]->getCell(6, 4);
   tile = p->getCell(30, 10);
   door->setTile(tile);
   door = p->getCell(30, 9);
   tile = rooms[2]->getCell(6, 3);
   door->setTile(tile);
   door = p->getCell(30, 5);
   tile = rooms[2]->getCell(6, 1);
   door->setTile(tile);

   //Room 3
   door = rooms[3]->getCell(10, 0);
   tile = p->getCell(0, 9);
   door->setTile(tile);
   door = rooms[3]->getCell(22, 6);
   tile = p->getCell(13, 16);
   door->setTile(tile);
   door = p->getCell(12, 16);
   tile = rooms[3]->getCell(21, 6);
   door->setTile(tile);
   door = p->getCell(0, 10);
   tile = rooms[3]->getCell(10, 1);
   door->setTile(tile);

   //Room 4
   door = rooms[4]->getCell(0, 5);
   tile = p->getCell(22, 16);
   door->setTile(tile);
   door = rooms[4]->getCell(7, 3);
   tile = p->getCell(30, 13);
   door->setTile(tile);
   door = rooms[4]->getCell(33, 0);
   tile = p->getCell(56, 10);
   door->setTile(tile);

   door = p->getCell(56, 11);
   tile = rooms[4]->getCell(33, 1);
   door->setTile(tile);
   door = p->getCell(30, 14);
   tile = rooms[4]->getCell(7, 4);
   door->setTile(tile);
   door = p->getCell(23, 16);
   tile = rooms[4]->getCell(1, 5);
   door->setTile(tile);
}

Floor::~Floor() {
    for(int i = 0; i < 20; i++) {
        delete enemies[i];
    }
    for(int i = 0; i < 10; i++) {
        delete potions[i];
    }
    for(int i = 0; i < 10; i++) {
        delete gold[i];
    }
    for(int i = 0; i < 5; i++) {
        delete rooms[i];
    }
    delete p;
}
ostream &operator<<(ostream &out, Floor &f) {
    out<<*(f.td);
    return out;
}

Cell *Floor::getCell() {
    srand(time(0));
    int n = rand()%5;
    return rooms[n]->getCell();
}

Cell *Floor::getACell(GObject *g) {
    srand(time(0));
    int n = rand()%5;
    g->setRoom(n);
    cout<<"Going to return a cell"<<endl;
    return rooms[n]->getCell();
}

void Floor::spawnStairs(int n) {
    Stairs *st = new Stairs();
    srand(time(0));
    int r = rand()%5;
    while(n == r) {
        r = rand()%5;
    }
    Cell *c = rooms[r]->getCell();
    while(c->getCurrent() != c->getDef()) {
        c = rooms[r]->getCell();
    }
    st->setCell(c);
    s = st;
}

void Floor::spawnEnemy() {
    Cell *c = getCell();
    while(c->getCurrent() != c->getDef()) {
        c = getCell();
    }
    srand(time(0));
    int n = rand()%18;
    Enemy *e;
    if(n >= 0 && n < 4) e = new Human();
    else if(n >= 4 && n < 7) e = new Dwarf();
    else if(n >= 7 && n < 12) e = new Halfling();
    else if(n >= 12 && n < 14) e = new Elf();
    else if(n >= 14 && n < 16) e = new Orc();
    else if(n >= 16 && n < 18) e = new Merchant();
    e->setCell(c);
    enemies[enemyCount] = e;
    enemyCount++; 
}

void Floor::spawnGold() {
    Cell *c = getCell();
    while(c->getDef() != c->getCurrent()) {
        c = getCell();
    }
    srand(time(0));
    int n = rand()%8;
    Treasure *g;
    if(n >= 0 && n < 5) {
        g = new Treasure(1);
    }
    else if(n >=5 && n < 7) {
        g = new Treasure(2);
    }
    else {
        g = new Treasure(6);
    }
    g->setCell(c);
    gold[goldCount] = g;
    goldCount++;
}

void Floor::spawnPotion() {
    Cell *c = getCell();
    while(c->getDef() != c->getCurrent()) {
        c = getCell();
    }
    srand(time(0));
    int n = rand()%6;
    HealthPotion *p = new HealthPotion();
    p->setCell(c);
    potions[potionCount] = p;
    potionCount++;
}

void Floor::moveEnemies() {
    for(int i = 0; i < 20; i++) {
        if(!enemies[i]) continue;
        while(!enemies[i]->pathfind());
    }
}

void Floor::clear() {
    for(int i = 0; i < 20; i++) {
        if(enemies[i]) enemies[i]->clearCell();
        delete enemies[i];
    }
    for(int i = 0; i < 10; i++) {
        if(potions[i]) potions[i]->clearCell();
        delete potions[i];
    }
    for(int i = 0; i < 10; i++) {
        if(gold[i]) gold[i]->clearCell();
        delete gold[i];
    }
    s->clearCell();
    delete s;
    goldCount = 0;
    potionCount = 0;
    enemyCount = 0;
}

void Floor::init() {
    for(int i = 0; i < 20; i++) {
        spawnEnemy();
    }
    for(int i = 0; i < 10; i++) {
        spawnPotion();
    }
    for(int i = 0; i < 10; i++) {
        spawnGold();
    }
}
