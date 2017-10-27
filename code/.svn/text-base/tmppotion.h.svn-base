#ifndef __TMPPOTION_H__
#define __TMPPOTION_H__

#include "potiondecorator.h"

class TmpPotion: public PotionDecorator {
    Player *p;
    int atkVal;
    int defVal;
    public:
        TmpPotion(Player *p, int atkVal, int defVal): p(p), atkVal(atkVal), defVal(defVal) {
            setHealth(p->getHP());
            setDefense(p->getDefense());
        };
        int getAttack() {
            return atkVal + p->getAttack();
        }
        int getDefense() {
            return defVal + p->getDefense();
        }
};
#endif
