#include "Weapon.h"
#include "Zombie.h"

#pragma once

class Zombie28 : public Zombie
{
public:
	Zombie28();
	Zombie28(int newx, int newy);
	//Zombie28(int newx, int newy, weaponType t);
	~Zombie28(void);

	int takeTurn();
	int hit();
	void printInfo();
	void setFast(bool isFast);

	void setRealDead(bool isRealDead);
};


