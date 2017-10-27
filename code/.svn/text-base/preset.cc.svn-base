#include "preset.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
Preset::Preset(string race, ifstream *i): Game(race), fi(i) {
    //floorCount = 0;
}

void Preset::loadFloor() {
    delete floor;
    floor = new Floor();
    string map[25];
    for(int n = 0; n < 25; n++) {
        getline(*fi, map[n]);
    }
    for(int y = 2; y < 8; y++) {
        for(int x = 2; x < 30; x++) {
            if(map[y][x] == '@') {
                pc = floor->getCell(0, x-2, y-2);
                continue;
            }
            floor->addObject(0, x - 2, y - 2, map[y][x]);
        }
    }
    for(int y = 2; y < 14; y++) {
        for(int x = 38; x < 77; x++) {
            if((y <= 7 && x <= 63) || (y > 4 && x > 60 && x < 76)) {
                if(map[y][x] != '.' && map[y][x] != '-' && map[y][x] != '|') {
                    cout<<map[y][x]<<" X: "<<x<<" Y: "<<y<<endl;
                }
                if(map[y][x] == '@') {
                    pc = floor->getCell(1, x-38, y-2);
                    continue;
                }
                floor->addObject(1, x-38, y-2, map[y][x]);
            }
        }
    }
    for(int y = 9; y < 14; y++) {
        for(int x = 37; x < 51; x++) {
            if(map[y][x] == '@') {
                pc = floor->getCell(2, x-37, y-9);
                continue;
            }
            floor->addObject(2, x-37, y-9, map[y][x]);
        }
    }
    for(int y = 14; y < 23; y++) {
        for(int x =3; x < 26; x++) {
            if(map[y][x] == '@') {
                pc = floor->getCell(3, x-3, y-14);
                continue;
            }
            floor->addObject(3, x-3, y-14, map[y][x]);
        }
    }
    for(int y = 15; y < 23; y++) {
        for(int x = 36; x < 77; x++) {
            if(map[y][x] == '@') {
                pc = floor->getCell(4, x-36, y-15);
                continue;
            }
            floor->addObject(4, x-36, y-15, map[y][x]);
        }
    }
}


void Preset::resetFloor() {
    floorCount++;
    loadFloor();
    player->setCell(pc);
    cout<<*floor;
}

Preset::~Preset() {
}
