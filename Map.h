#pragma once
#include "Room.h"

class Map
{
public:
	Map();
	Map(const Map &map);
	~Map() {};
	void setHead(Room* new_head) { head = new_head; }
	Room* getHead() const { return head; }
	string getName() { return name; }
	Map& operator = (const Map& map);
	Map& operator += (const Map& map);
	Map operator + (const Map& map) const;
	Room* AddRoom(Room& room, Direction direction);
	Room* moveCurrentRoom(Direction direction);

private:
	string	name;
	Room*	head;
	Room*	currentRoom;
	int		number_of_rooms;
};
