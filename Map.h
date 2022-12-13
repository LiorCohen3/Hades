#pragma once
#include "Room.h"

class Map
{
public:
	Map();
	~Map();

private:
	char*	name;
	Room*	rooms;
	int		numberOfRooms;
};
