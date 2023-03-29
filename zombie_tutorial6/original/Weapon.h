#pragma once
typedef enum
{
	shotgun = 1,
	butterKnife = 2,
	katana = 3,
	handgun = 4,
} weaponType;

class Weapon
{
protected:
	weaponType type;
	int force;
	int range;

public:
	Weapon(void);
	Weapon(weaponType t);
	~Weapon(void);

	void setType(weaponType t) {type = t;}
	weaponType getType() { return type;}
	int getForce() { return force; }
	int getRange() { return range; }
	const char* getWeaponName();
};

	