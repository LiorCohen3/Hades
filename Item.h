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
	~Item();
	void Print(ostream& out = cout) const;

private:
	string		name;
	Rarity		rarity;
};

ostream& operator << (ostream& out, Item& item);