#include "Enemy.h"
#include <iostream>
#include <assert.h>
using namespace std;

// Default parameterless constructor which gives the Enemy object all default values
Enemy::Enemy(void) : Undead()
{
	//w = NULL;
	speed = false;
	dead = false;
	cout << "constructor: Zombie()" << endl;
}

// This is referred to as "overloading" and it's a form of polymorphism.
// (discussed soon)
Enemy::Enemy(int newx, int newy) : Undead(newx, newy)
{
	//w = NULL;
	speed = false;
	dead = false;
	cout << "constructor: Enemy(int, int)" << endl;
}

/*
// Enemy constructor with a given starting position and weapon type.
Enemy::Enemy(int newx, int newy, weaponType t) : Undead(newx, newy)
{
	w = new Weapon(t);
	speed = false;
	dead = false;
	cout << "constructor: Zombie(int, int, int)" << endl;
}
*/

// Destructor for the Enemy class.
Enemy::~Enemy(void)
{
	cout << "destructor: ~Enemy()" << endl;
	//if(w) {
	//	delete w;
	//	w = NULL;
	//}

}


// Enemy's turn means it moves (slowly) to destination position and attacks the player
// if it can be reached that turn.
int Enemy::takeTurn()
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
int Enemy::hit()
{
	if (dead)
	{
		cout << "The Enemy attacks but does 0 damage." << endl;
		return 0;
	}
	cout << "The Enemy attacks for 2 damage." << endl;
	return 2;
}

// Text output regarding the Enemy's CURRENT position
void Enemy::printInfo()
{
	cout << "The Enemy is now at position (" << position.xPos << "," << position.yPos << ")." << endl;
}

// Set whether the zombie moves quickly (for a zombie) or really slow). If isFast is
// true then the Enemy will move 3 positions a turn rather than 2.
void Enemy::setFast(bool isFast)
{
	speed = isFast;
}

// Indicate whether the Enemy is freshly dead (can attack) or really dead (no damage
// when it attacks).
void Enemy::setRealDead(bool isRealDead)
{
	dead = isRealDead;
}