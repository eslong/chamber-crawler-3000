#include "game.h"
#include <string>
#include <iostream>
#include "shade.h"
#include <iomanip>
using namespace std;

Game::Game( string race ): floor( new Floor() ), floorCount(0) {
	if ( race == "Shade" ) {
		player = new Shade();
        player->setGame(this);
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
}

void Game::gameLoop() {
	string s;
	int n;
	while ( cin >> s ) {
		action == "";
		if ( s == "no" || s == "so" || s == "ea" || s == "we" ||
		     s == "ne" || s == "se" || s == "nw" || s == "sw" ) {
			player->move( s );
		} else if ( s == "u" ) {
			while ( cin >> s ) {
				if ( s == "no" || s == "so" || s == "we" || s == "ea" ||
				     s == "ne" || s == "nw" || s == "se" || s == "sw" ) {
					// player->useItem( s );
					break;
				}
			}
		} else if ( s == "a" ) {
			while ( cin >> s ) {
				if ( s == "no" || s == "so" || s == "ea" || s == "we" ||
				     s == "ne" || s == "nw" || s == "se" || s == "sw" ) {
					if ( int* combat = player->attack( s ) ) {
						char enemy = combat[0];
						action += " PC deals " + combat[2] + " to " + enemy + " (" + combat[1] + "). ";
						break;
					}
					cout << "Invalid target, please choose another target direction." << endl;
				}
			}
		} else if ( s == "r" ) {
			floorCount = 1;
			// floor->clear();
			delete player;
			player = new Player();
		}
        endTurn();
	}
}

void Game::endTurn() {
	floor->moveEnemies();
	cout << *floor << endl;
	cout << "Race: " << player->getRace() << " Gold: " << player->getGold() << setw(30) << "Floor: " << floorCount << endl;
	cout << "HP: " << player->getHP() << endl;
	cout << "Atk: " << player->getAttack() << endl;
	cout << "Def: " << player->getDefence() << endl;
	cout << "Action:" << action << endl;
}

void Game::resetFloor() {
    floorCount++;
    floor->clear();
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
