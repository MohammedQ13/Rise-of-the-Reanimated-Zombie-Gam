#include "Zombie.h"
#include <iostream>
#include <assert.h>
using namespace std;

// Default parameterless constructor which gives the Zombie object all default values
Zombie::Zombie(void) : Undead()
{
	//w = NULL;
	speed = false;
	dead = false;
	cout << "constructor: Zombie()" << endl;
}

// This is referred to as "overloading" and it's a form of polymorphism.
// (discussed soon)
Zombie::Zombie(int newx, int newy) : Undead(newx, newy)
{
	//w = NULL;
	speed = false;
	dead = false;
	cout << "constructor: Zombie(int, int)" << endl;
}

/*
// Zombie constructor with a given starting position and weapon type.
Zombie::Zombie(int newx, int newy, weaponType t) : Undead(newx, newy)
{
	w = new Weapon(t);
	speed = false;
	dead = false;
	cout << "constructor: Zombie(int, int, int)" << endl;
}
*/

// Destructor for the Zombie class.
Zombie::~Zombie(void)
{
	cout << "destructor: ~Zombie()" << endl;
	//if(w) {
	//	delete w;
	//	w = NULL;
	//}

}


// Zombie's turn means it moves (slowly) to destination position and attacks the player
// if it can be reached that turn.
int Zombie::takeTurn()
{
	int maxDist = 2;
	if (speed)
	{
		maxDist = 3;
	}
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

// If the zombie is in range of the player, it will give out damage to the player
// (indicated by the integer value returned).  If the zombie is really dead, the damage
// is 0.
int Zombie::hit()
{
	if (dead)
	{
		cout << "The zombie attacks but does 0 damage." << endl;
		return 0;
	}
	cout << "The zombie attacks for 2 damage." << endl;
	return 2;
}

// Text output regarding the zombie's CURRENT position
void Zombie::printInfo() 
{
	cout << "The Zombie is now at position (" << position.xPos << "," << position.yPos << ")." << endl;
}

// Set whether the zombie moves quickly (for a zombie) or really slow). If isFast is
// true then the zombie will move 3 positions a turn rather than 2.
void Zombie::setFast(bool isFast)
{
	speed = isFast;
}

// Indicate whether the zombie is freshly dead (can attack) or really dead (no damage
// when it attacks).
void Zombie::setRealDead(bool isRealDead)
{
	dead = isRealDead;
}