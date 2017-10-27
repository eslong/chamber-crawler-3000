#include "Character.h"
#include "cell.h"
#include <math.h>
#include <iostream>
#include <sstream>
using namespace std;

int Character::getHP() {
	if ( hp <= 0 ) { return 0; }
	else { return hp; }
}

int Character::damage( int dmg ) {
	float hit = ceil( ( (float)100 / ( (float)100 + (float)getDefense() ) )  * (float)dmg);
    int ihit = (int)hit;
    hp -= ihit;
	return ihit;
}

string* Character::attack( string direction ) {
	Cell* temp = c->getNeighbor( direction );
	Character* target = temp->getTarget();
	if ( target ) {
		string* combat = new string[4];
		string str;
		stringstream ss;
		ss << target->damage( getAttack() );
		combat[2] = ss.str();
		char c = temp->getCurrent();
		ss.str( string() );
		ss << c;
		combat[0] = ss.str();
		ss.str( string() );
		ss << target->getHP();
		combat[1] = ss.str();
		ss.str( string() );
		ss << target->getGold();
		combat[3] = ss.str();
		return combat;
	} else {
		return 0;
	}
}

bool Character::move(string direction) {
	if(direction == "0") {
        c->notify(0);
        return true;
    }
    Cell *temp = c->getNeighbor(direction);
	if(!temp ||  temp->getCurrent() == ' ' || temp->getCurrent() == '|' || 
        temp->getCurrent() == '-' || 
        (temp->getCurrent() != temp->getDef() && temp->getCurrent() != '\\') ||
        (en && temp->getCurrent() == '+') || (en && temp->getCurrent() == '\\')) {
		return false;
	}
	c->notify(0);
    if(temp->getCurrent() == '+' && !en) {
        c = temp->getTile();
    }
    else if(temp->getCurrent() == '\\' && !en) {
        notifyReset();
        return true;
    }
    else {
        c = temp;
    }
	c->notify(this);
 	return true;
}

void Character::setAttack(int a) {
    atk = a;
}

void Character::setDefense(int d) {
    def = d;
}

void Character::setHealth(int h) {
    hp = h;
}

void Character::addHealth(int h) {
    hp+=h;
}

bool Character::isEnemy() {
	return en;
}

int Character::getAttack() {
	return atk;
}

int Character::getDefense() {
	return def;
}

int Character::getGold() {
	return gold;
}
