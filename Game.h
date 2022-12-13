#pragma once
#include "Data.h"
#include "Map.h"

class Game
{
public:
	Game();
	~Game();

private:
	Map*	currentMap;
	Data	data;
};
