#include "enemy.h"
#include "cell.h"
#include <string>
#include <cstdlib>
using namespace std;

bool Enemy::pathfind() {
	string dir;		
	int n = rand() % 8;
	if ( n == 0 ) {
		dir = "no";
	} else if ( n == 1 ) {
		dir = "so";
	} else if ( n == 2 ) {
		dir = "ea";
	} else if ( n == 3 ) {
		dir = "we";
	} else if ( n == 4 ) {
		dir = "ne";
	} else if ( n == 5 ) {
		dir = "nw";
	} else if ( n == 6 ) {
		dir = "se";
	} else if ( n == 7 ) {
		dir = "sw";
	}
    return move(dir);
}
