#include "vampire.h"
#include <sstream>
using namespace std;

Vampire::Vampire() {
	setRace( "Vampire" );
	setGraphic( '@' );
	setGold( 0 );
	setHealth( 50 );
	setAttack( 25 );
	setDefence( 25 );
}

string* Vampire::attack( string direction ) {
	Cell* temp = c->getNeighbor( direction );
	Character* target = temp->getTarget();
	if ( target ) {
		string* combat = new string[3];
		stringstream ss;
		ss << target->gamage( getAttack() );
		combat[2] = ss.str();
		char c = temp->getCurrent();
		ss.str( string() );
		ss << c;
		combat[0] = ss.str();
		ss.str( string() );
		ss << target->getHP();
		combat[1] = ss.str();
		addHealth( 5 );
		return combat;
	} else {
		return 0;
}
