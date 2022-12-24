#pragma once
#include <iostream>
using namespace std;

enum Rarity
{
	Common = 1,
	Uncommon,
	Epic,
	Legendary
};

class Item
{
public:
	Item();
	Item(string new_name, Rarity new_rarity);
	~Item() {};
	string getName() const { return name; }
	Rarity getRarity() { return rarity; }
	Item& operator = (const Item& item);
	Item& operator += (const Item& item);
	Item operator + (const Item& item) const;
	Item& operator ++ (); /*pre*/
	Item operator ++(int); /*post*/
	void Print(ostream& out = cout) const;

private:
	string		name;
	Rarity		rarity;
};

ostream& operator << (ostream& out, Item& item);