#include "game.h"
#include <string>
#include <iostream>
#include "shade.h"
#include <iomanip>
#include <sstream>
using namespace std;

Game::Game( string race ): floor( new Floor() ), floorCount(0) {
	if ( race == "Shade" ) {
		player = new Shade();
        player->setGame(this);
        cout<<"made the new plauer"<<endl;
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
					int* combat = player->attack( s );
					if ( combat ) {
						string str;
						stringstream ss;
						ss << combat[2];
						ss >> str;
						action += "PC deals " + str + " damage to ";
						char c = combat[0];
						ss << c;
						ss >> str;
						action += str + " (";
						ss << combat[1];
						ss >> str;
						action += str + ")";
						delete [] combat;
						break;
					}
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
	cout << "Action:  " << action << "." << endl;
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
