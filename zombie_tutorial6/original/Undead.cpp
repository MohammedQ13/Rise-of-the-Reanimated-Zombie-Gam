#include "Undead.h"
#include <iostream>
#include <assert.h>
using namespace std;

// Default parameterless constructor which gives the Zombie object all default values
Undead::Undead()
{
	// Ideally this would be a semi-random starting position.
	position.xPos = position.MAX_X;
	position.yPos = (position.MAX_Y + position.MIN_Y) / 2;

	dstX = position.xPos;
	dstY = position.yPos;
	cout << "constructor: Undead()" << endl;
}

// This is referred to as "overloading" and it's a form of polymorphism.
// (discussed soon)
Undead::Undead(int newx, int newy)
{
	position.xPos = newx;
	position.yPos = newy;
	dstX = position.xPos;
	dstY = position.yPos;
	cout << "constructor: Undead(int int)" << endl;
}

// Destructor for the Undead class.
Undead::~Undead(void)
{
	cout << "destructor: ~Undead()" << endl;	
}

// Give the zombie a destination target to walk to (normally player's position).
void Undead::setDestination(int nx, int ny) 
{
	dstX = nx;
	dstY = ny;
}

Mover Undead::getPosition()
{
	return position;
}

// Text output regarding the zombie's CURRENT position
void Undead::printInfo()
{
	cout << "The Undead is now at position (" << position.xPos << "," << position.yPos << ")." << endl;
}

int Undead::getHealth()
{
	return health;
}

void Undead::takeDamage(int ptsOff)
{
	health -= ptsOff;
	if (health < 0)
	{
		health = 0;
	}
}