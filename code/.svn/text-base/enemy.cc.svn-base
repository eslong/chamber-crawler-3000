#include "enemy.h"
#include "cell.h"
#include <string>
#include <cstdlib>
using namespace std;

bool Enemy::pathfind() {
	string dir;		
	int n = rand() % 8;
	Character* target;

	string cardinals[8] = { "no", "so", "ea", "we", "ne", "nw", "se", "sw" };
	for ( int i = 0; i < 8; i++ ) {
		dir = cardinals[i];
		if ( ( target = c->getNeighbor( dir )->getTarget() ) && !(target->isEnemy() ) ) {
			if ( n % 2 == 0 ) {
				string* combat = this->attack( dir );
				return setAction( combat );
			}
		}
	}

	dir = cardinals[n];

	return move(dir);
}

bool Enemy::setAction( string* combat ) { action = combat[0] + " deals " + combat[2] + " damage to PC."; return true; }

string Enemy::getAction() { return action; }

