// Zork.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <string>
using namespace std;

// TODO: Reference additional headers your program requires here.

enum Direction {
	NORTH = 1,
	SOUTH,
	EAST,
	WEST
};

enum EnemyType {
	OGRE,
	GOBLIN
};

class Character {
	private:
		string name{ "Character" };
		int health{ 20 };
		Direction direction{ NORTH };
		int steps{ 0 };
	public:
		int move(Direction direction);
		void attack(Character& target);
		void flee(Character& enemy);

		// friend int move(Direction direction, int steps)
		// {
		// 	int ret = 0;
		// 	if ((direction == NORTH || direction == SOUTH) && steps > 0 )
		// 	{
		// 		cout << "Weary Traveler you are trying to go " << steps << " steps!" << endl;	
		// 	}
		// 	else if ((direction == EAST || direction == WEST) && steps > 0)
		// 	{
		// 		if (steps % 2 == 0)
		// 		{
		// 			ret = OGRE;
		// 		}
		// 		else
		// 		{
		// 			ret = GOBLIN;
		// 		}
		// 	}
		// }

		int getHealth() { return health; }

		Character (string name) :
			name(name) {}
};