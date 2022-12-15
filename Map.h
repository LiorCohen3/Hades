#pragma once
#include "Room.h"

class Map
{
public:
	Map();
	~Map();
	Map& operator = (const Map& str);
	Map& operator += (const Map& str);
	Map operator + (const Map& str) const;

private:
	char*	name;
	Room*	rooms;
	int		numberOfRooms;
};
