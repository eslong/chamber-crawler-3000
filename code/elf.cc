#include "elf.h"

Elf::Elf() {
    setGraphic('E');
    setHealth(140);
    setAttack(30);
    setDefense(10);
}

/*void Elf::attack( Player* p ) {
	if ( p->race != "Drow" ) p->damage( this->atk );
	p->damage( this->atk );
}*/
