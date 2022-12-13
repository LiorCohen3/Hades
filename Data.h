#pragma once
#include "Map.h"

class Data
{
public:
	Data();
	~Data();

private:
	Map*	mapsData;
	Room*	roomsData;
};
