#include "Character.h"
#include "cell.h"
#include <math.h>
using namespace std;

int Character::getHP() {
	return hp;
}

char Character::getGraphic() {
	return graphic;
}

int Character::damage( int dmg ) {
	int hit = ceil( ( 100 / ( 100 + def ) )  * dmg);
	hp -= hit;
	return hit;
}

int* Character::attack( string direction ) {
	Cell* temp = c->getNeighbor( direction );
	Character* enemy = temp->getOcc();
	if ( enemy ) {
		int combat[3];
		combat[0] = enemy->getGraphic();
		combat[1] = enemy->getHP();
		combat[2] = enemy->damage( this->atk );
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

void Character::setHit(int n) {
    hit = n;
}

void Character::addHealth(int h) {
    hp+=h;
}
