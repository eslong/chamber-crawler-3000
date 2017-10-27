#include "game.h"
#include <string>
#include <iostream>
#include "shade.h"
#include <iomanip>
using namespace std;

Game::Game( string race ): floor( new Floor() ), floorCount(0) {
	if ( race == "Shade" ) {
		player = new Shade();
	}
	/* else if ( race == "Drow" ) {
		player = new Drow();
	} else if ( race == "Vampire" ) {
		player = new Vampire();
	} else if ( race == "Troll" ) {
		player = new Troll();
	} else if ( race == "Goblin" ) {
		player = new Goblin();
	} */
	player->setGame(this);
}

void Game::gameLoop() {
	string s;
	resetFloor();
	while ( cin >> s ) {
		action = "";
		string dir;
		if ( s == "no" || s == "so" || s == "ea" || s == "we" ||
		     s == "ne" || s == "se" || s == "nw" || s == "sw" ) {
			player->move( s );
			if ( s == "no" ) { dir = "North"; }
			else if ( s == "so" ) { dir = "South"; }
			else if ( s == "ea" ) { dir = "East"; }
			else if ( s == "we" ) { dir = "West"; }
			else if ( s == "ne" ) { dir = "North-East"; }
			else if ( s == "nw" ) { dir = "North-West"; }
			else if ( s == "se" ) { dir = "South-East"; }
			else if ( s == "sw" ) { dir = "South-West"; }
			action += "PC moves " + dir;
		} else if ( s == "u" ) {
			cin >> s;
			if ( s == "no" || s == "so" || s == "we" || s == "ea" ||
			     s == "ne" || s == "nw" || s == "se" || s == "sw" ) {
				player = player->useItem( s );
			}
		} else if ( s == "a" ) {
			cin >> s;
			if ( s == "no" || s == "so" || s == "ea" || s == "we" ||
			     s == "ne" || s == "nw" || s == "se" || s == "sw" ) {
				string* combat = player->attack( s );
				if ( combat ) {
					action += "PC deals " + combat[2] + " damage to " + combat[0] + " (" + combat[1] + " HP)";	
					if ( combat[1] == "0" ) {
						action += combat[0] + " has been defeated.";
					}
					delete [] combat;
				}
			}
		} else if ( s == "r" ) {
			floorCount = 0;
			resetFloor();
            //floor->clear();
			delete player;
			player = new Player();
		}
        endTurn();
	}
}

void Game::endTurn() {
	floor->moveEnemies();
	cout << *floor << endl;
	cout << "Race: " << player->getRace() << " Gold: " << setw(3) << player->getGold() << setw(50) << "Floor: " << floorCount << endl;
	cout << "HP: " << player->getHP() << endl;
	cout << "Atk: " << player->getAttack() << endl;
	cout << "Def: " << player->getDefense() << endl;
	cout << "Action: " << action << "." << floor->getAction() << endl;
	cout << "Command? ";
}

void Game::resetFloor() {
    floorCount++;
    cout<<"About to clear the floor!"<<endl;
    floor->clear();
    cout<<"Cleared the floor!"<<endl;
    floor->init();
    Cell *c; 
    c = floor->getACell(player);
    while(c->getDef() != c->getCurrent()) {
        c = floor->getACell(player);
    }
    player->setCell(c);
    floor->spawnStairs(player->getRoom());
    cout<<*floor;
}

Game::~Game() {
    delete floor;
    delete player;
}
