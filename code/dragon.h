#ifndef __DRAGON_H__
#define __DRAGON_H__
#include "enemy.h"
class Dragon: public Enemy {
    public:
        Dragon();
        bool move(std::string direction) { return true;}
};

#endif
