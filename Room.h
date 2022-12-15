#pragma once
#include "Item.h"
#include "Monster.h"

class Room
{
public:
	Room();
	~Room();
	void Print(ostream& out = cout) const;

private:
	string		name;
	Item*		items;
	int			num_of_items;
	Monster*	monsters;
	int			num_of_monsters;
	Room*		north;
	Room*		south;
	Room*		east;
	Room*		west;
};

ostream& operator << (ostream& out, Room& room);
