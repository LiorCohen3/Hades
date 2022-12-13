#pragma once
#include "Item.h"
#include "Monster.h"

class Room
{
public:
	Room();
	~Room();

private:
	char*		name;
	Item*		items;
	Monster*	monsters;
	Room*		north;
	Room*		south;
	Room*		east;
	Room*		west;
};
