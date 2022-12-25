#pragma once
#include "Map.h"

class Data
{
public:
	Data();
	~Data() {};
	Map* addMap(Map* map);
	Map* findMapByName(string name);
	Room getRoom (int id);
	bool isRoomInData(int id);
	bool addRoom(Room room);
private:
	Map**	mapsData;
	int		num_of_maps;
	Room*	roomsData;
	int		num_of_rooms;
};
