#ifndef __ITEM_H__
#define __ITEM_H__

#include "GObject.h"
class Character;
class Player;
class Item: public GObject {
    public:
        virtual void action() {};
        //virtual Character *action(Character *c) {return c;}
        virtual Player *action(Player *p) {return p;}
};

#endif
