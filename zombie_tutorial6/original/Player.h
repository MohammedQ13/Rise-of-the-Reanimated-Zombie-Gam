#pragma once
#include "Undead.h"
#include "Weapon.h"

class Player
{
protected:
    Weapon* w;
    Mover position;
    int speed;
    int health;
public:
    Player(int x, int y);
    ~Player();

    // When attacking, pass EACH enemy into the attack function and 
    // damage/kill the enemy when appropriate.
    bool attack(Undead* p_enemy);
    int move(int xDist, int yDist);
    void printInfo();
    void setPosition(int xPos, int yPos);
    Mover getPosition();

    // When hit or hurt by a zombie, take off player health (for instant game loss
    // you can give the player one health point)
    int getHealth();
    void takeDamage(int ptsOff);
};

