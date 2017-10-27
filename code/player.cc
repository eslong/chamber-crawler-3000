#include "player.h"
#include "game.h"
using namespace std;

void Player::notifyReset() {
   g->resetFloor();
}

int Player::getAttack() {
	return this->atk;
}

int Player::getDefence() {
	return this->def;
}

int Player::getGold() {
	return this->gold;
}

string Player::getRace() {
	return this->race;
}

void Player::setRace( string race ) {
	this->race = race;
}

void Player::setGold( int n ) {
	this->gold = n;
}

void Player::setGame(Game *game) {
    g = game;
}
