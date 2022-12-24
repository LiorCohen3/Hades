#include "Game.h"

/*----------------------------------------------------------------------------------*/
Game::Game()
	:
	currentMap(NULL){}

/*----------------------------------------------------------------------------------*/
void Game::changeMap(string name)
{
	if (data.findMapByName(name) != NULL)
	{
		currentMap = data.findMapByName(name);
	}
}

/*----------------------------------------------------------------------------------*/
void Game::addMapToGame(Map* map)
{
	Map* m = data.addMap(map);
	if (m != NULL && currentMap == NULL)
	{
		currentMap = m;
	}
}
