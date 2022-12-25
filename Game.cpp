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
/*----------------------------------------------------------------------------------*/
void Game::addRoomToGame(Room room)
{
	data.addRoom(room);
}
/*----------------------------------------------------------------------------------*/
Room Game::getRoomFromData(int id)
{
	Room room = data.getRoom(id);
	return room;
}
/*----------------------------------------------------------------------------------*/
