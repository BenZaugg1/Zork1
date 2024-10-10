// Zork.cpp : Defines the entry point for the application.
//

#include "Zork.h"
#include <iostream>

using namespace std;

void Character::attack(Character& target)
{
	int playerAttack = rand() % 21;
	int enemyAttack = rand() % 21;

	if (playerAttack > enemyAttack) {
		cout << name << " attacks " << target.name << " and hits." << endl;
		target.health -= 20;
	}
	else {
		cout << name << " attacks " << target.name << " and misses. " << target.name << " runs away!" << endl;
	}
}

int Character::move(Direction direction)
{
	int ret = 0;
	steps += rand() % 6;
	switch (direction) {
		case NORTH:
			if (!(steps % 2 == 0)) {
				ret = GOBLIN;
			}
			else{
				ret = OGRE;
			}
			break;
		case SOUTH:
			if (!(steps % 3 == 0)) {
				ret = OGRE;
			}
			else{
				ret = GOBLIN;
			}
			break;
		case EAST:
			if (!(steps % 4 == 0)) {
				ret = GOBLIN;
			}
			else{
				ret = OGRE;
			}
			break;
		case WEST:
			if (!(steps % 5 == 0)) {
				ret = OGRE;
			}
			else{
				ret = GOBLIN;
			}
			break;
	}

	return ret;
}

void Character::flee(Character& enemy)
{
	int flee = rand() % 9;

	if (flee % 2 == 0) {
		cout << name << " successfully flees." << endl;
	}
	else {
		cout << name << " fails to flee." << endl;
		enemy.attack(*this);
	}

	cout << name << " flees." << endl;
}



int main()
{
	string enemyName;
	Character player("Player");
	Character ogre("Ogre");
	Character goblin("Goblin");

	cout << "You find yourself in a lone and dreary forest..." << endl;
	for (;;) {
		cout << "What direction do you want to go? (1 = North, 2 = South, 3 = East, 4 = West)" << endl;
		int direction;
		cin >> direction;

		if (direction < 1 || direction > 4) {
			cout << "Invalid direction." << endl;
			continue;
		}

		const EnemyType enemy = static_cast<EnemyType>(player.move(static_cast<Direction>(direction)));

		if (enemy == OGRE) {
			enemyName = "Ogre";
		}
		else {
			enemyName = "Goblin";
		}

		cout << "You encounter a " << enemyName << endl;
		cout << "What do you want to do? (1 = Attack, 2 = Flee)" << endl;
		int action;
		cin >> action;

		if (action == 1) {
			player.attack(enemy == OGRE ? ogre : goblin);
		}
		else {
			player.flee(enemy == OGRE ? ogre : goblin);
		}

		if (ogre.getHealth() <= 0) {
			cout << "You have defeated the Ogre!" << endl;
			break;
		}
		else if (goblin.getHealth() <= 0) {
			cout << "You have defeated the Goblin!" << endl;
			break;
		}
		else if (player.getHealth() <= 0) {
			cout << "You have been defeated!" << endl;
			break;
		}



	}

	return 0;
}
