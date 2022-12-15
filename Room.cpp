#include "Room.h"

/*----------------------------------------------------------------------------------*/
void Room::Print(ostream& out = cout) const
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
ostream& operator << (ostream& out, Room& room)
{
	room.Print(out);
	return out;
}