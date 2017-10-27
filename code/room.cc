#include "room.h"
#include "tile.h"
#include "door.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

Room::Room(int x, int y, int type, TextDisplay *td): x(x), y(y) {
  tiles = new Cell **[y];
  cout<<"made the tiles"<<endl; 
  for(int i = 0; i < y; i++) {
    tiles[i] = new Cell *[x];
  }
  //cout<<"made the second row of tiles"<<endl;
  if(type == 0) initRoom0(td);
  //cout<<"inited the room!"<<endl;
  else if(type == 1) initRoom1(td);
  else if(type == 2) initRoom2(td);
  else if(type == 3) initRoom3(td);
  else if(type == 4) initRoom4(td);
    cout<<"inited the room!"<<endl;
  if(type != 5) addNeighbors();
}

Room::~Room() {
    for(int i = 0; i < y; i++) {
        for(int j = 0; j < x; j++) {
            delete tiles[i][j];
        }
        delete tiles[i];
    }
    delete tiles;
}

//bottom right
void Room::initRoom4(TextDisplay *td) {
    int offsetX = 36;
    int offsetY = 15;
    int x = 41;
    int y = 8;
    for(int i = 0; i < y; i++) {
        for(int j = 0; j < x; j++) {
            if((j == 0 && i > 2 && i != 5) || (j == 28 && i < 4) || j == x - 1) {
                tiles[i][j] = new Cell(0, td, offsetX, offsetY, '|', j, i);
            }
            else if((i == 3 && j < 28 && j != 7) || (i == 0 && j > 28 && j != 33) ||
                    i == y - 1) {
                tiles[i][j] = new Cell(0, td, offsetX, offsetY, '-', j, i);
            }
            else if((j == 0 && i == 5) || (i == 3 && j == 7) || (i == 0 && j == 33)) {
                tiles[i][j] = new Door(0, td, offsetX, offsetY, j, i);
            }
            else if(i > 3 || (i <= 3 && j > 28)) {
                tiles[i][j] = new Tile(0, td, offsetX, offsetY, j, i);
            }
            else {
                tiles[i][j] = new Cell(0, td, offsetX, offsetY, ' ', j, i);
                continue;
            }
            td->notify(j + offsetX, i + offsetY, tiles[i][j]->getDef());
        }
    }
}

//bottom left
void Room::initRoom3(TextDisplay *td) {
    int offsetX = 3;
    int offsetY = 14;
    int x = 23;
    int y = 9;
    for(int i = 0; i < y; i++) {
        for(int j = 0; j < x; j++) {
            if(j == 0 || (j == x - 1 && i != 6)) {
                tiles[i][j] = new Cell(0, td, offsetX, offsetY, '|', j, i);
            }
            else if((i == 0 && j != 10) || i == y - 1) {
                tiles[i][j] = new Cell(0, td, offsetX, offsetY, '-', j, i);
            }
            else if(j == x -1 || i == 0) {
                tiles[i][j] = new Door(0, td, offsetX, offsetY, j, i);
            }
            else {
                tiles[i][j] = new Tile(0, td, offsetX, offsetY, j, i);
            }
            td->notify(j + offsetX, i + offsetY, tiles[i][j]->getDef());
        }
    }
}

//small square
void Room::initRoom2(TextDisplay *td) {
    int offsetX = 37;
    int offsetY = 9;
    int x = 14;
    int y = 5;
    for(int i = 0; i < y; i++) {
        for(int j = 0; j < x; j++) {
            if(j == 0 || j == x - 1) {
                tiles[i][j] = new Cell(0, td, offsetX, offsetY, '|', j, i);
            }
            else if((i == 0 && j != 6) || (i == y - 1 && j != 6)) {
                tiles[i][j] = new Cell(0, td, offsetX, offsetY, '-', j, i);
            }
            else if(i == 0 || i == y - 1) {
                tiles[i][j] = new Door(0, td, offsetX, offsetY, j, i);
            }
            else {
                tiles[i][j] = new Tile(0, td, offsetX, offsetY, j, i);
            }
            td->notify(j + offsetX, i + offsetY, tiles[i][j]->getDef());
        }
    }
}

void Room::initRoom1(TextDisplay *td) {
  int offsetX = 38;
  int offsetY = 2;
  int x = 39;
  int y = 12;
  for(int i = 0; i < y; i++) {
    for(int j = 0; j < x; j++) {
      if((j == 0 && i < 6 && i != 2) || ( j == 22 && i > 4 && i != 9) ||
          (j == 24 && i < 3) || (j == 32 && i > 1 && i < 4) ||
          (j == 35 && i > 2 && i < 5) || (j == 38 && i > 3)) {
        tiles[i][j] = new Cell(0, td, offsetX, offsetY, '|', j, i);
      }
      else if((j == 0 && i == 2) || (j == 5 && i == 5) || (j == 22 && i == 9) ||
              (j == 31 && i == y - 1)) {
        tiles[i][j] = new Door(0, td, offsetX, offsetY, j, i);
      }
      else if((j >= 0 && j < 24 && i == 0) || (j > 24 && j < 32 && i == 2) ||
          (j > 32 && j < 35 && i == 3) || (j > 35 && j < 38 && i == 4) ||
          (j >= 0 && j < 22 && i == 5) || (j > 22 && j < 38 && i == 11)) {
        tiles[i][j] = new Cell(0, td, offsetX, offsetY, '-', j, i);
      }
      else if((i > 0 && i < 5 && j > 0 && j < 24) || (i > 2 && i < 11 && j >= 23 && j < 32) ||
          (i > 3 && j >= 32 && j < 35) || (i > 4 && j >= 35 && j < 38)) {
        tiles[i][j] = new Tile(0, td, offsetX, offsetY, j, i);
      }
      else {
        tiles[i][j] = new Cell(0, td, offsetX, offsetY, ' ', j, i);
        continue;
      }
      td->notify(j + offsetX, i + offsetY, tiles[i][j]->getDef());
    }
  }
}

void Room::initRoom0(TextDisplay *td) {
  int offsetX = 2;
  int offsetY = 2;
  int x = 28;
  int y = 6;
  //cout<<"Begin the loop with x = "<<x<<" and y = "<<y<<endl;
  for(int i = 0; i < y; i++) {
    for(int j = 0; j < x; j++) {
     // cout<<"at cell x = "<<j<<" and y = "<<i<<endl;
      if(j == 0 || (j == x - 1 && i != 2)) {
       // cout<<" | works!"<<endl;
        tiles[i][j] = new Cell(0, td, offsetX, offsetY, '|', j, i);
        //cout<<"at the end of | "<<endl;
        //cout<<tiles[i][j]->def<<endl;
      }
      else if((i == y - 1 && j == 11) || (i == 2 && j == x - 1)) {
        //cout<<" + works!"<<endl;
        tiles[i][j] = new Door(0, td, offsetX, offsetY, j, i);
      }
      else if(i == 0 || i == y - 1) {
        //cout<<" - works!"<<endl;
        tiles[i][j] = new Cell(0, td, offsetX, offsetY, '-', j, i);
      }
      else {
        tiles[i][j] = new Tile(0, td, offsetX, offsetY, j, i);
      }
      td->notify(j + offsetX, i + offsetY, tiles[i][j]->getDef());
    }
  }
}

void Room::addNeighbors() {
  //cout<<"Adding neighbors"<<endl;
  for(int i = 0; i < y; i++) {
    for(int j = 0; j < x; j++) {
      if(i != 0 && j!= 0 && i != y - 1 && j != x - 1) {
        tiles[i][j]->addNeighbor(tiles[i-1][j-1], 0);
        tiles[i][j]->addNeighbor(tiles[i-1][j], 1);
        tiles[i][j]->addNeighbor(tiles[i-1][j+1], 2);
        tiles[i][j]->addNeighbor(tiles[i][j-1], 3);
        tiles[i][j]->addNeighbor(tiles[i][j+1], 4);
        tiles[i][j]->addNeighbor(tiles[i+1][j-1], 5);
        tiles[i][j]->addNeighbor(tiles[i+1][j], 6);
        tiles[i][j]->addNeighbor(tiles[i+1][j+1], 7);
        continue;
      }
      else if(i == 0 && j == 0) {
          tiles[i][j]->addNeighbor(0, 0);
          tiles[i][j]->addNeighbor(0, 1);
          tiles[i][j]->addNeighbor(0, 2);
          tiles[i][j]->addNeighbor(0, 3);
          tiles[i][j]->addNeighbor(tiles[i][j+1], 4);
          tiles[i][j]->addNeighbor(0, 5);
          tiles[i][j]->addNeighbor(tiles[i+1][j], 6);
          tiles[i][j]->addNeighbor(tiles[i+1][j+1], 7);
      }
      else if(i == 0 && j > 0 && j < x - 1) {
        tiles[i][j]->addNeighbor(0, 0);
        tiles[i][j]->addNeighbor(0, 1);
        tiles[i][j]->addNeighbor(0, 2);
        tiles[i][j]->addNeighbor(tiles[i][j-1], 3);
        tiles[i][j]->addNeighbor(tiles[i][j+1], 4);
        tiles[i][j]->addNeighbor(tiles[i+1][j-1], 5);
        tiles[i][j]->addNeighbor(tiles[i+1][j], 6);
        tiles[i][j]->addNeighbor(tiles[i+1][j+1], 7);
      }
      else if(i == 0 && j == x - 1) {
        tiles[i][j]->addNeighbor(0, 0);
        tiles[i][j]->addNeighbor(0, 1);
        tiles[i][j]->addNeighbor(0, 2);
        tiles[i][j]->addNeighbor(tiles[i][j-1], 3);
        tiles[i][j]->addNeighbor(0, 4);
        tiles[i][j]->addNeighbor(tiles[i+1][j-1], 5);
        tiles[i][j]->addNeighbor(tiles[i+1][j], 6);
        tiles[i][j]->addNeighbor(0, 7);
      }
      else if(i == y - 1 && j == 0) {
        tiles[i][j]->addNeighbor(0, 0);
        tiles[i][j]->addNeighbor(tiles[i-1][j], 1);
        tiles[i][j]->addNeighbor(tiles[i-1][j+1], 2);
        tiles[i][j]->addNeighbor(0, 3);
        tiles[i][j]->addNeighbor(tiles[i][j+1], 4);
        tiles[i][j]->addNeighbor(0, 5);
        tiles[i][j]->addNeighbor(0, 6);
        tiles[i][j]->addNeighbor(0, 7);
      }
      else if(i == y - 1 && j == x - 1) {
        tiles[i][j]->addNeighbor(tiles[i-1][j-1], 0);
        tiles[i][j]->addNeighbor(tiles[i-1][j], 1);
        tiles[i][j]->addNeighbor(0, 2);
        tiles[i][j]->addNeighbor(tiles[i][j-1], 3);
        tiles[i][j]->addNeighbor(0, 4);
        tiles[i][j]->addNeighbor(0, 5);
        tiles[i][j]->addNeighbor(0, 6);
        tiles[i][j]->addNeighbor(0, 7);
      }
      else if(i == y - 1 && j > 0 && j < x - 1) {
        tiles[i][j]->addNeighbor(tiles[i-1][j-1], 0);
        tiles[i][j]->addNeighbor(tiles[i-1][j], 1);
        tiles[i][j]->addNeighbor(tiles[i-1][j+1], 2);
        tiles[i][j]->addNeighbor(tiles[i][j-1], 3);
        tiles[i][j]->addNeighbor(tiles[i][j+1], 4);
        tiles[i][j]->addNeighbor(0, 5);
        tiles[i][j]->addNeighbor(0, 6);
        tiles[i][j]->addNeighbor(0, 7);
      }
      else if(j == 0 && i > 0 && i < y - 1) {
        tiles[i][j]->addNeighbor(0, 0);
        tiles[i][j]->addNeighbor(tiles[i-1][j], 1);
        tiles[i][j]->addNeighbor(tiles[i-1][j+1], 2);
        tiles[i][j]->addNeighbor(0, 3);
        tiles[i][j]->addNeighbor(tiles[i][j+1], 4);
        tiles[i][j]->addNeighbor(0, 5);
        tiles[i][j]->addNeighbor(tiles[i+1][j], 6);
        tiles[i][j]->addNeighbor(tiles[i+1][j+1], 7);
      }
      else if(j == x - 1 && i > 0 && i < y - 1) {
        tiles[i][j]->addNeighbor(tiles[i-1][j-1], 0);
        tiles[i][j]->addNeighbor(tiles[i-1][j], 1);
        tiles[i][j]->addNeighbor(0, 2);
        tiles[i][j]->addNeighbor(tiles[i][j-1], 3);
        tiles[i][j]->addNeighbor(0, 4);
        tiles[i][j]->addNeighbor(tiles[i+1][j-1], 5);
        tiles[i][j]->addNeighbor(tiles[i+1][j], 6);
        tiles[i][j]->addNeighbor(0, 7);
      }
    }
  }
  //cout<<"done adding neighbors"<<endl;
}

Cell *Room::getCell(int x, int y) {
  return tiles[y][x];
}

Cell *Room::getCell() {
    Cell *ce = 0;
    int r, s;
    while(!ce || ce->getCurrent() != '.') {
        srand(time(0));
        r = rand() % x;
        s = rand() % y;
        ce = tiles[s][r];
    }
    return ce;
}
