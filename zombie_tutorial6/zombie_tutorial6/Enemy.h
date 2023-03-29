#include "Weapon.h"
#include "Undead.h"
#pragma once

class Enemy : public Undead
{
protected:
	bool speed;
	bool dead;
	//Weapon *w;

public:
	Enemy(void);
	Enemy(int newx, int newy);
	//Enemy(int newx, int newy, weaponType t);
	~Enemy(void);

	virtual int takeTurn();
	int hit();
	virtual void printInfo();
	//Weapon* getWeapon() {return w;}

	void setFast(bool isFast);

	void setRealDead(bool isRealDead);
};
