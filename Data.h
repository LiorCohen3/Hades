#pragma once
#include "Map.h"

class Data
{
public:
	Data();
	~Data() {};
	Map* addMap(Map* map);
	Map* findMapByName(string name);
private:
	Map**	mapsData;
	int		num_of_maps;
	Room*	roomsData;
	int		num_of_rooms;
};
