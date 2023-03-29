
#include "Mover.h"
#pragma once

class Undead
{
protected:
	Mover position;
	int dstX;
	int dstY;
	int health;
public:
	Undead(void);
	Undead(int newx, int newy);
	~Undead(void);

	virtual int takeTurn() = 0;
	virtual int hit() = 0;
	virtual void setDestination(int nx, int ny);
	Mover getPosition();
	virtual void printInfo() = 0;
	int getHealth();
	void takeDamage(int ptsOff);
};

