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
private:
	Map*	currentMap;
	Data	data;
};
