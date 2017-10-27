#include "halfling.h"
#include "cell.h"
#include <cstdlib>
#include <math.h>
using namespace std;

Halfling::Halfling() {
    setGraphic('L');
    setHealth(100);
    setAttack(15);
    setDefense(20);
}

int Halfling::damage( int dmg ) {
	int hit = ceil( ( 100 / ( 100 + getDefense() ) ) * dmg );
	int n = rand() % 2;
	if ( n == 1 ) {
		hp -= hit;
		return hit;
	} else {
		return 0;
	}
}
