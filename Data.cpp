#include "Data.h"

/*----------------------------------------------------------------------------------*/
Data::Data()
	:
	mapsData(NULL),
	num_of_maps(0),
	roomsData(NULL),
	num_of_rooms(0){}

/*----------------------------------------------------------------------------------*/
Map* Data::addMap(Map* map)
{
	for (int i = 0; i < num_of_maps; i++)
	{
		if (mapsData[i]->getName() == map->getName())
		{
			cout << "Error! Map is already in data" << endl;
			return NULL;
		}
	}
	mapsData[num_of_maps] = map;
	num_of_maps++;
	return map;
}

/*----------------------------------------------------------------------------------*/
Map* Data::findMapByName(string name)
{
	for (int i = 0; i < num_of_maps; i++)
	{
		if (mapsData[i]->getName() == name)
		{
			return mapsData[i];
		}
	}
	cout << "Map not in data!" << endl;
	return NULL;
}

/*----------------------------------------------------------------------------------*/
bool Data::isRoomInData(int id)
{
	for (int i = 0; i < num_of_rooms; i++)
	{
		if (roomsData[i].getId() == id)
		{
			return true;
		}
	}
	return false;
}
/*----------------------------------------------------------------------------------*/
Room Data::getRoom(int id)
{
	bool res = isRoomInData(id);
	if (res == false)
	{
		cout << "Room not in data!" << endl;
		return;
	}
	
	for (int i = 0; i < num_of_rooms; i++)
	{
		if (roomsData[i].getId() == id)
		{
			return roomsData[i];
		}
	}
}
/*----------------------------------------------------------------------------------*/
bool Data::addRoom(Room room)
{
	bool res = isRoomInData(room.getId());
	if (res == true)
	{
		cout << "Room is already in data!" << endl;
		return false;	//room not added
	}

	roomsData[num_of_rooms] = room;
	num_of_rooms++;
	return true; 		//room added


}
/*----------------------------------------------------------------------------------*/