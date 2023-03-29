#include "Zombie28.h"
#include <iostream>
#include <assert.h>
using namespace std;

// Default parameterless constructor which gives the Zombie object all default values
Zombie28::Zombie28(void) : Zombie()
{
	cout << "constructor: Zombie28()" << endl;
}

// This is referred to as "overloading" and it's a form of polymorphism.
// (discussed soon)
Zombie28::Zombie28(int newx, int newy) : Zombie(newx, newy)
{
	cout << "constructor: Zombie28(int, int)" << endl;
}

/*
// Zombie constructor with a given starting position and weapon type.
Zombie28::Zombie28(int newx, int newy, weaponType t) : Zombie(newx, newy, t)
{
	cout << "constructor: Zombie28(int, int, int)" << endl;
}
*/

// Destructor for the Zombie class.
Zombie28::~Zombie28(void)
{
	cout << "destructor: ~Zombie28()" << endl;
}


// Zombie28's turn means it moves (slowly) to destination position and attacks the player
// if it can be reached that turn.
int Zombie28::takeTurn()
{

	int maxDist = 5;
	int distLeft = position.walk(dstX, dstY, maxDist);

	//int distFromPlayer = absVal(x - dstX) + absVal(y - dstY);
	// ASSUMING the destination location is where the player is located.
	if (distLeft == 0)
	{
		// Attack the player
		return hit();
	}
	return 0;
}


// If the zombi28e is in range of the player, it will give out damage to the player
// (indicated by the integer value returned).
int Zombie28::hit()
{
	cout << "The zombie28 attacks for 2 damage." << endl;
	return 2;
}

// Text output regarding the zombie's CURRENT position
void Zombie28::printInfo()
{
	cout << "The Zombie28 is now at position (" << position.xPos << "," << position.yPos << ")." << endl;
}

// Set whether the zombie moves quickly (for a zombie) or really slow). If isFast is
// true then the zombie will move 3 positions a turn rather than 2.
void Zombie28::setFast(bool isFast)
{
	// Zombie28s are always fast and never realDead
}

// Indicate whether the zombie is freshly dead (can attack) or really dead (no damage
// when it attacks).
void Zombie28::setRealDead(bool isRealDead)
{
	// Zombie28s are always fast and never realDead
}