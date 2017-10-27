#include "player.h"
#include "game.h"
using namespace std;

void Player::notifyReset() {
   g->resetFloor();
}

string Player::getRace() {
	return this->race;
}

void Player::setRace( string race ) {
	this->race = race;
}

void Player::setGold( int g ) {
	this->gold = g;
}

void Player::setGame(Game *game) {
    g = game;
}

Player *Player::useItem(string direction) {
   Cell *temp = c->getNeighbor(direction);
    Item *i = temp->getPotion();
    if(i) return i->action(this);
    else return this;
}


