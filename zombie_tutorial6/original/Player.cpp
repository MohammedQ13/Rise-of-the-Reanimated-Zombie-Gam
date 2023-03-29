#include "Player.h"
#include <iostream>
#include <assert.h>
using namespace std;


Player::Player(int x, int y)
{
    w = new Weapon(katana);
    position.xPos = 1;
    position.yPos = 1;
    speed = 5;
    health = 5;
}

Player::~Player()
{
    if(w) 
    {
    	delete w;
	    w = NULL;
    }
}

// When attacking, pass EACH enemy into the attack function and 
// damage/kill the enemy when appropriate. Return true if the enemy is killed
bool Player::attack(Undead* p_enemy)
{
    Mover enemyPos = p_enemy->getPosition();
    bool inRange = enemyPos.checkRange( position.xPos,
                                        position.yPos, 
                                        w->getRange());
    if (inRange)
    {
        p_enemy->takeDamage(w->getForce());
        return (p_enemy->getHealth() <= 0);
    }
    return false;
}

int Player::move(int xDist, int yDist)
{
    return position.walk(xDist + position.xPos, yDist + position.yPos, speed);
}

void Player::setPosition(int xPos, int yPos)
{
    position.xPos = xPos;
    position.yPos = yPos;
}

Mover Player::getPosition()
{
    return position;
}

void Player::printInfo()
{
    cout << "You are in position " << position.xPos << ", " << position.yPos << " with a " << w->getWeaponName() << endl;
}

// When hit or hurt by a zombie, take off player health (for instant game loss
// you can give the player one health point)
int Player::getHealth()
{
    return health;
}

void Player::takeDamage(int ptsOff)
{
    health -= ptsOff;
    if (health < 0)
    {
        health = 0;
    }
}

