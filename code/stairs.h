#ifndef __STAIRS_H__
#define __STAIRS_H__
#include "item.h"

class Stairs: public Item {
    public:
        Stairs() {
            setGraphic('\\');
        }
        void action();
};

#endif
