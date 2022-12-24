#include "Map.h"

/*----------------------------------------------------------------------------------*/
Map::Map() :
	head(NULL),
	currentRoom(NULL),
	name(""),
	number_of_rooms(0) {}

/*----------------------------------------------------------------------------------*/
Map::Map(const Map& map)
{
	name = map.name;
	number_of_rooms = map.number_of_rooms;

}

/*----------------------------------------------------------------------------------*/
void copyRooms(Map& dest, Room* src)
{
	if (src == nullptr || src->getVisited())
	{
		return; // the source map is empty or the room has already been visited
	}

	src->setVisited(true);

	Room* destRoom = new Room();
	if (dest.getHead() == nullptr)
	{
		// this is the first room being copied
		dest.setHead(destRoom);
	}

	// copy the rooms in the north direction
	if (src->getNorth() != nullptr)
	{
		Map northDest;
		copyRooms(northDest, src->getNorth());
		destRoom->setNorth(northDest.getHead());
	}

	// copy the rooms in the south direction
	if (src->getSouth() != nullptr)
	{
		Map southDest;
		copyRooms(southDest, src->getSouth());
		destRoom->setSouth(southDest.getHead());
	}

	// copy the rooms in the east direction
	if (src->getEast() != nullptr)
	{
		Map eastDest;
		copyRooms(eastDest, src->getEast());
		destRoom->setEast(eastDest.getHead());
	}

	// copy the rooms in the west direction
	if (src->getWest() != nullptr)
	{
		Map westDest;
		copyRooms(westDest, src->getWest());
		destRoom->setWest(westDest.getHead());
	}
}

/*----------------------------------------------------------------------------------*/
Map& Map::operator = (const Map& map)
{
	if (this != &map)
	{
		name = map.name;
		number_of_rooms = map.number_of_rooms;
		head = map.head;
		currentRoom = map.currentRoom;
		copyRooms(*this, map.currentRoom);
	}
	return *this;
}
/*----------------------------------------------------------------------------------*/
Map& Map::operator += (const Map& map)
{
	if (this != &map)
	{
		number_of_rooms += map.number_of_rooms;
		currentRoom = map.currentRoom;
		copyRooms(*this, map.currentRoom);
	}
	return *this;
}
/*----------------------------------------------------------------------------------*/
Map Map::operator + (const Map& map) const
{
	Map new_map = *this;
	new_map += map;
	return new_map;
}

/*----------------------------------------------------------------------------------*/
Room* Map::AddRoom(Room& room, Direction direction)
{
	if (head == NULL)
	{
		Room *new_room = new Room();
		*new_room = room;
		head = new_room;
		currentRoom = new_room;
		number_of_rooms++;
	}
	else if (currentRoom->getRoom(direction) == NULL)
	{
		Room* new_room = new Room();
		*new_room = room;
		switch (direction)
		{
		case North:
			currentRoom->setNorth(new_room);
			break;
		case East:
			currentRoom->setEast(new_room);
			break;
		case South:
			currentRoom->setSouth(new_room);
			break;
		case West:
			currentRoom->setWest(new_room);
			break;
		}
		number_of_rooms++;
	}
	else if (currentRoom->isSurrounded())
	{
		cout << "Error, room is surrounded" << endl;
	}
	else
	{
		cout << "Error, cant add room in this direction" << endl;
	}
	return head;
}
/*----------------------------------------------------------------------------------*/
Room* Map::moveCurrentRoom(Direction direction)
{
	if (currentRoom == NULL)
	{
		cout << "Error! No room in map yet" << endl;
	}
	else
	{
		if (currentRoom->getRoom(direction))
		{
			currentRoom = currentRoom->getRoom(direction);
		}
		else
		{
			cout << "Error! no room in that direction" << endl;
		}
	}
	return currentRoom;
}