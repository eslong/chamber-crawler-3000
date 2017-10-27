#ifndef __PASSAGE_H__
#define __PASSAGE_H__
#include "room.h"
#include "door.h"
class Passage: public Room{
    public:
    Passage(int x, int y, TextDisplay *td): Room(x, y, 5, td) {
        int offsetX = 13;
        int offsetY = 4;
        for(int i = 0; i < y; i++) {
            for(int j = 0; j < x; j++) {
                if((j == 0 && i == 3) || (j == 0 && i == 10) || (j == 16 && i == 0) ||
                   (j == 25 && i == 0) || (j == 30 && i == 3) || (j == 30 && i == 5) ||
                   (i == 16 && j == 12) || (i == 16 && j == 23) ||
                   (j == 30 && i == 9) || (j == 30 && i == 14) || (j == 47 && i == 7) ||
                   (j == 56 && i == 9) || (j == 56 && i == 11)) {
                    tiles[i][j] = new Door(0, td, offsetX, offsetY, j, i);
                    td->notify(j + offsetX, i + offsetY, tiles[i][j]->getDef());
                }
                else if((j == 0 && i > 3 && i < 10) || (j > 0 && j < 18 && i == 7) ||
                   (j == 18 && i > 3 && i < 16) || (i == 4 && j > 18 && j < 31) ||
                   (j == 20 && i > 0 && i < 4) || (i == 0 && j > 16 && j < 25) ||
                   (i == 16 && j > 12 && j < 23) || (i == 12 && j > 18 && j < 42) ||
                   (j == 30 && i > 9 && i < 14) || (j == 41 && i < 13 && i > 7) ||
                   (i == 7 && j > 40 && j < 47) || (j == 56 && i == 10)) {
                    tiles[i][j] = new Cell(0, td, offsetX, offsetY, '#', j, i);
                    td->notify(j + offsetX, i + offsetY, tiles[i][j]->getDef());
                }
                else {
                    tiles[i][j] = new Cell(0, td, offsetX, offsetY, ' ', j, i);
                }
            }
        }
        addNeighbors();
    }
};
#endif
