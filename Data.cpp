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