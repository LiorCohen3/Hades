#pragma once
#include "Item.h"
#include "Monster.h"
#include "IdGenerator.h"

enum Direction
{
	North = 1,
	East,
	South,
	West
};

class Room
{
public:
	Room();
	Room(string name);
	Room(const Room& room);
	~Room() {};
	Room& operator += (const Item& item);
	Room operator + (const Item& item) const;
	int getId() const { return ID; }
	bool getVisited() const { return visited; }
	void setVisited(bool new_visited) { visited = new_visited; }
	void setNorth(Room* new_north) { north = new_north; }
	Room* getNorth() const { return north; }
	void setSouth(Room* new_south) { south = new_south; }
	Room* getSouth() const { return south; }
	void setEast(Room* new_east) { east = new_east; }
	Room* getEast() const { return east; }
	void setWest(Room* new_west) { west = new_west; }
	Room* getWest() const { return west; }
	Room* getRoom(Direction direction);
	bool isSurrounded() { return north && south && east && west; }
	void Print(ostream& out = cout) const;

private:
	static IdGenerator	IDgen;
	int					ID;
	string				name;
	Item*				items;
	int					num_of_items;
	Monster*			monsters;
	int					num_of_monsters;
	Room*				north;
	Room*				south;
	Room*				east;
	Room*				west;
	bool				visited;
};

ostream& operator << (ostream& out, Room& room);
