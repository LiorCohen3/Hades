#pragma once
#include <iostream>
using namespace std;

class Monster
{
public:
	Monster();
	~Monster();
	void Print(ostream& out = cout) const;
private:
	string	name;
	int		level;
};

ostream& operator << (ostream& out, Monster& monster);