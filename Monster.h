#pragma once
#include <iostream>
using namespace std;

class Monster
{
public:
	Monster();
	~Monster();
	Monster& operator = (const Monster& monster);
	Monster& operator += (const Monster& monster);
	Monster operator + (const Monster& monster) const;
	Monster& operator ++ (); /*pre*/
	Monster operator ++(int); /*post*/
	void Print(ostream& out = cout) const;
private:
	string	name;
	int		level;
};

ostream& operator << (ostream& out, Monster& monster);