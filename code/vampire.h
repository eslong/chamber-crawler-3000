#ifndef __VAMPIRE_H__
#define __VAMPIRE_H__

#include "player.h"
#include <string>

class Vampire: public Player {
   public:
	Vampire()
	int* attack( std::string direction );
};

#endif
