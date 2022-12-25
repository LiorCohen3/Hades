#pragma once
#include "Data.h"
#include "Map.h"

class Game
{
public:
	Game();
	~Game() {};
	void changeMap(string name);
	void addMapToGame(Map* map);
	void addRoomToGame(Room room);
	Room getRoomFromData(int id);

private:
	Map*	currentMap;
	Data	data;
};
