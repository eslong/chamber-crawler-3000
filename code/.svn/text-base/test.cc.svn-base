#include "GObject.h"
#include "textdisplay.h"
#include "room.h"
#include "Character.h"
#include "enemy.h"
#include <iostream>
#include <string>
#include "floor.h"
#include "game.h"
#include "preset.h"
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
    string s;
    string race;

    // cin >> s;
    s = "s";

    if ( s == "s" ) { race = "Shade"; }
    else if ( s == "d" ) { race = "Drow"; }
    else if ( s == "v" ) { race = "Vampire"; }
    else if ( s == "g" ) { race = "Goblin"; }
    else if ( s == "t" ) { race = "Troll"; }

    if(argc == 1) {
        Game *g = new Game( race );
        cout<<"inited the game"<<endl;
        cout<<"reset the floor!"<<endl;
        g->gameLoop();
    }
    else {
        ifstream fi(argv[1]);
        Preset *p = new Preset(race, &fi);
        p->gameLoop();
    }
    return 0;
}
