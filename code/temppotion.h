#ifndef __TEMPPOTION_H__
#define __TEMPPOTION_H__

#include "item.h"
#include "tmppotion.h"

class TempPotion: public Item {
    int attack, defense;
    public:
        TempPotion(int attack, int defense): attack(attack), defense(defense){
            setGraphic('P');
        };
        Player *action(Player *p) {
           Player *n  = new TmpPotion(p, attack, defense);
           return n;
        }
        ~TempPotion() {};
};

#endif
