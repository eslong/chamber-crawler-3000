#include "GObject.h"
#include "textdisplay.h"
#include "room.h"
#include "Character.h"
#include "enemy.h"
#include <iostream>
#include <string>
#include "floor.h"
#include "game.h"
using namespace std;

int main() {
  Game *g = new Game("Shade");
  g->resetFloor();
  g->gameLoop();
    return 0;
}
