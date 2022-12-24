#include "Item.h"

/*----------------------------------------------------------------------------------*/
Item::Item()
	:
	name("New Item"),
	rarity(Common){}

/*----------------------------------------------------------------------------------*/
Item::Item(string new_name, Rarity new_rarity)
	:
	name(new_name),
	rarity(new_rarity) {}

/*----------------------------------------------------------------------------------*/
Item& Item::operator = (const Item& item)
{
	if (this != &item)
	{
		name = item.name;
		rarity = item.rarity;
	}
	return *this;
}

/*----------------------------------------------------------------------------------*/
Item& Item::operator ++ ()
{
	if (rarity != Legendary)
	{
		switch (rarity)
		{
		case Common:
			rarity = Uncommon;
			break;
		case Uncommon:
			rarity = Epic;
			break;
		case Epic:
			rarity = Legendary;
			break;
		}
	}
	else
	{
		cout << "Item is at maximum rarity" << endl;
	}
	return *this;
}
/*----------------------------------------------------------------------------------*/
Item Item::operator ++(int)
{
	Item temp(name, Legendary);
	if (rarity != Legendary)
	{
		temp.rarity = rarity;
		switch (rarity)
		{
		case Common:
			rarity = Uncommon;
			break;
		case Uncommon:
			rarity = Epic;
			break;
		case Epic:
			rarity = Legendary;
			break;
		}
	}
	else
	{
		cout << "Cant increase, item is at maximum rarity" << endl;
	}
	return temp;
}

/*----------------------------------------------------------------------------------*/
void Item::Print(ostream& out) const
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