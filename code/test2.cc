#include "game.h"
using namespace std;

int main() {
	Game* game = new Game( "Shade" );
	game->gameLoop();
	delete game;
	return 0;
}
