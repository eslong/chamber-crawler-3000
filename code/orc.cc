#include "orc.h"

Orc::Orc() {
    setGraphic('O');
    setHealth(180);
    setAttack(30);
    setDefense(25);
}

/*void Orc::attack( Player* p ) {
	if ( p->race == "Goblin" ) {
		p->damage( this->atk * 1.5 );
	} else {
		p->damage( this->atk );
	}
};*/
