#pragma once

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

private:
	char*		name;
	Rarity		rarity;
};