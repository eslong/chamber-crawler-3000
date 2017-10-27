#ifndef __ITEM_H__
#define __ITEM_H__

#include "GObject.h"
class Character;
class Item: public GObject {
    public:
        virtual void action(Character *c) = 0;
};

#endif
