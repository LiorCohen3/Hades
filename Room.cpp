#include "Room.h"
IdGenerator Room::IDgen(0);

/*----------------------------------------------------------------------------------*/
Room::Room()
	:
	north(NULL),
	south(NULL),
	east(NULL),
	west(NULL),
	ID(IDgen.createNewID()),
	name(),
	items(NULL),
	num_of_items(0),
	monsters(NULL),
	num_of_monsters(0),
	visited(false) {}

/*----------------------------------------------------------------------------------*/
Room::Room(string new_name)
	:
	north(NULL),
	south(NULL),
	east(NULL),
	west(NULL),
	ID(IDgen.createNewID()),
	name(new_name),
	items(NULL),
	num_of_items(0),
	monsters(NULL),
	num_of_monsters(0),
	visited(false) {}
/*----------------------------------------------------------------------------------*/
/*Copy Constructor*/
Room::Room(const Room& room)
	:
	north(NULL),
	south(NULL),
	east(NULL),
	west(NULL),
	ID(room.ID),
	name(room.name),
	num_of_items(room.num_of_items),
	num_of_monsters(room.num_of_monsters)
{
	for (int i = 0; i < num_of_items; i++)
	{
		items[i] = room.items[i];
	}
	for (int i = 0; i < num_of_monsters; i++)
	{
		monsters[i] = room.monsters[i];
	}

}

/*----------------------------------------------------------------------------------*/
Room& Room::operator += (const Item& item)
{
	for (int i = 0; i < num_of_items; i++)
	{
		if (items[i].getName() == item.getName())
		{
			if (items[i].getRarity() == Legendary)
			{
				items[num_of_items] = Item(item.getName(), Common);
				num_of_items++;
				return *this;
			}
		}
	}
	items[num_of_items] = item;
	num_of_items++;
	return *this;
}

/*----------------------------------------------------------------------------------*/
void Room::Print(ostream& out) const
{
	out << "Room content:" << endl;
	for (int i = 0; i < num_of_items; i++)
	{
		items[i].Print(out);
	}
	out << "Total number of items: " << num_of_items << endl;
	for (int i = 0; i < num_of_monsters; i++)
	{
		monsters[i].Print(out);
	}
	out << "Total number of monsters: " << num_of_items << endl;
}

/*----------------------------------------------------------------------------------*/
Room* Room::getRoom(Direction direction)
{
	switch (direction)
	{
	case North:
		return north;
		break;
	case East:
		return east;
		break;
	case South:
		return south;
		break;
	case West:
		return west;
		break;
	}
}

/*----------------------------------------------------------------------------------*/
ostream& operator << (ostream& out, Room& room)
{
	room.Print(out);
	return out;
}