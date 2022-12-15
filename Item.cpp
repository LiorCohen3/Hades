#include "Item.h"

/*----------------------------------------------------------------------------------*/
void Item::Print(ostream& out = cout) const
{
	out << name << " Rarity: ";
	switch (rarity)
	{
	case Common:
		out << "Common" << endl;
		break;
	case Uncommon:
		out << "Unommon" << endl;
		break;
	case Epic:
		out << "Epic" << endl;
		break;
	case Legendary:
		out << "Legendary" << endl;
		break;
	}
}

/*----------------------------------------------------------------------------------*/
ostream& operator << (ostream& out, Item& item)
{
	item.Print(out);
	return out;
}