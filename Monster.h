#pragma once
#include <iostream>
using namespace std;

class Monster
{
public:
	Monster();
	Monster(string new_name, int new_level);
	~Monster() {};
	Monster& operator = (const Monster& monster);
	Monster& operator ++ (); /*pre*/
	Monster operator ++(int); /*post*/
	string getName() const { return name; }
	int getLevel() { return level; }
	void Print(ostream& out = cout) const;
private:
	string	name;
	int		level;
};

ostream& operator << (ostream& out, Monster& monster);