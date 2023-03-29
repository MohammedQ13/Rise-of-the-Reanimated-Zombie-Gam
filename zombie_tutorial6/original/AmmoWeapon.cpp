#include "AmmoWeapon.h"
#include "Weapon.h"
#include <malloc.h>
#include <iostream>
using namespace std;

AmmoWeapon::AmmoWeapon(void) : Weapon()
{
	type = shotgun;
	range = 3;
	force = 3;
	numRounds = 1;
	cout << "constructor: AmmoWeapon()" << endl;
}

AmmoWeapon::AmmoWeapon(weaponType t)
{
	type = t;
	switch (t)
	{
	case shotgun:
		range = 3;
		force = 3;
		numRounds = 1;
		break;
	// The only other ammo weapon is a handgun
	default:
		range = 5;
		force = 1;
		numRounds = 10;
		break;
	}
	cout << "constructor: AmmoWeapon(int)" << endl;
}

AmmoWeapon::~AmmoWeapon(void)
{
	cout << "destructor: ~AmmoWeapon()" << endl;
}

int AmmoWeapon::getForce()
{
	if (numRounds <= 0)
	{
		return 0;
	}
	return force;
}
