#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "GObject.h"
#include <string>

class Character: public GObject {
  protected:
    int hp, atk, def;
    void setAttack(int a);
    void setHealth(int h);
    void setDefense(int d);
    bool en;
    virtual void notifyReset() { };
  public:
	int getHP();
	char getGraphic();
	void damage( int dmg );
	virtual int* attack( std::string direction );
	bool move(std::string direction);
        void addHealth(int h);
};

#endif
