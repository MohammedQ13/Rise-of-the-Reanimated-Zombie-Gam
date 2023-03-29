#include "Weapon.h"
#include "Undead.h"
#pragma once

class Zombie : public Undead
{
protected:
	bool speed;
	bool dead;
	//Weapon *w;

public:
	Zombie(void);
	Zombie(int newx, int newy);
	//Zombie(int newx, int newy, weaponType t);
	~Zombie(void);

	virtual int takeTurn();
	int hit();
	virtual void printInfo();
	//Weapon* getWeapon() {return w;}

	void setFast(bool isFast);

	void setRealDead(bool isRealDead);
};

