#include "Weapon.h"
#include <malloc.h>
#include <iostream>
using namespace std;

Weapon::Weapon(void)
{
	type = butterKnife;
	range = 1;
	force = 1;
	cout << "constructor: Weapon()" << endl;
}

Weapon::Weapon(weaponType t)
{
	type = t;
	switch (t)
	{
	case shotgun:
		range = 3;
		force = 3;
		break;
	case katana:
		range = 1;
		force = 7;
		break;
	default:
		range = 1;
		force = 1;
		break;
	}
	cout << "constructor: Weapon(int)" << endl;
}

Weapon::~Weapon(void)
{
	cout << "destructor: ~Weapon()" << endl;
}

const char* Weapon::getWeaponName()
{
	switch (type)
	{
	case katana:
		return "katana";
	case shotgun:
		return "shotgun";
	case butterKnife:
		return "butter knife";
	default:
		return "handgun";
	}
}
