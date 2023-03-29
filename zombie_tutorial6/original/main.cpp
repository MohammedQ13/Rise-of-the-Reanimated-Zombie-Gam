#include "zombie.h"
#include "Player.h"
#include <iostream>
#include "Zombie28.h"
using namespace std;

bool enemyTurn(Player* p, Undead** ap_enemies, int numEnemies)
{
	Mover playerPos = p->getPosition();
	int damageGiven = 0;
	for (int i = 0; i < numEnemies; i++)
	{
		ap_enemies[i]->setDestination(playerPos.xPos, playerPos.yPos);
		damageGiven += ap_enemies[i]->takeTurn();		
	}
	p->takeDamage(damageGiven);
	return p->getHealth() > 0;
}

int playerTurn(Player* p, Undead** ap_enemies, int numEnemies)
{
	for (int i = 0; i < numEnemies; i++)
	{
		bool killed = p->attack(ap_enemies[i]);
		if (killed)
		{
			cout << "******The enemy: "; 
			ap_enemies[i]->printInfo();
			cout << " was defeated *******" << endl;

			// Now remove the enemy character
			// We need to evaluation position i again
			Undead* p_toRemove = ap_enemies[i];
			ap_enemies[i] = ap_enemies[numEnemies - 1];
			numEnemies--;
			i--;
		}
	}
	return numEnemies;
}
void printGameState(Player* p, Undead** ap_enemies, int numEnemies)
{
	cout << "---The current game state is the following----" << endl;
	p->printInfo();
	for (int i = 0; i < numEnemies; i++)
	{
		ap_enemies[i]->printInfo();
	}
}


int main() 
{
	Player*  player = new Player(2, 2);
	player->printInfo();
	player->move(42, 0);
	player->printInfo();

	cout << "1. Zombie z1" << endl;
	Zombie z1;
	z1.setDestination(3, 4);
	z1.printInfo();

	cout << endl << "2. Zombie z2" << endl;
	Zombie* z2 = new Zombie(8, 8);
	z2->setDestination(5, 5);

	cout << endl << "3. Zombie z3" << endl;
	//Zombie z3(22, 2, shotgun);
	Zombie z3(22, 2);
	z3.setFast(true);
	z3.setDestination(2, 2);

	// Now run through a batch of actions (without user input)
	Undead* ap_enemies[3];
	ap_enemies[0] = &z1;
	ap_enemies[1] = z2;
	ap_enemies[2] = &z3;
	int numEnemies = 3;
	for (int i = 0; i < 10; i++)
	{
		numEnemies = playerTurn(player, ap_enemies, numEnemies);
		if (!enemyTurn(player, ap_enemies, numEnemies))
		{
			cout << "The player has been killed.  Try harder next time" << endl;
			delete z2;
			return 0;
		}
		printGameState(player, ap_enemies, numEnemies);
	}
	// Create an array of 7 Undead objects
	Undead** myUndeadObj = new Undead * [7];


	// Initialize the first 3 elements of the array with Zombie instances
	for (int i = 0; i < 3; i++) {
		myUndeadObj[i] = new Zombie(10 * i, 20 * i);
	}

	// Initialize the remaining 4 elements of the array with Zombie28 instances
	for (int i = 3; i < 7; i++) {
		myUndeadObj[i] = new Zombie28(10 * i, 20 * i);
	}

	//using the undead objects
	for (int i = 0; i < 7; i++) {
		myUndeadObj[i]->hit();
		myUndeadObj[i]->setDestination(5, 10);
		myUndeadObj[i]->printInfo();
	}

	// Set the destination for all enemies to (15, 15) and call takeTurn on each
	for (int i = 0; i < 7; i++) {
		myUndeadObj[i]->setDestination(15, 15);
		myUndeadObj[i]->takeTurn();
	}

	for (int i = 0; i < 7; i++) {
		myUndeadObj[i]->printInfo();
	}

	
	

	// Clean up. />

	// Deallocate the memory for undead onjects
	for (int i = 0; i < 7; i++) {
		delete myUndeadObj[i];
	}

	delete z2;
	delete myUndeadObj;
	return 0;
}
