#pragma once
#include "Weapon.h"

class AmmoWeapon : public Weapon
{
private:
	int numRounds;

public:
	AmmoWeapon(void);
	AmmoWeapon(weaponType t);
	~AmmoWeapon(void);
	int getForce();
	int getNumRounds() { return numRounds; }
};
