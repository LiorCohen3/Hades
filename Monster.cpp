#include "Monster.h"


/*----------------------------------------------------------------------------------*/
Monster::Monster()
	:
	name("New Monster"),
	level(1) {}

/*----------------------------------------------------------------------------------*/
Monster::Monster(string new_name, int new_level)
	:
	name(new_name),
	level(new_level){}

/*----------------------------------------------------------------------------------*/
Monster& Monster::operator = (const Monster& monster)
{
	if (this != &monster)
	{
		name = monster.name;
		level = monster.level;
	}
	return *this;
}

/*----------------------------------------------------------------------------------*/
Monster& Monster::operator ++ () /*pre*/
{
	if (level != 5)
	{
		level++;
	}
	return *this;
}

/*----------------------------------------------------------------------------------*/
Monster Monster::operator ++(int) /*post*/
{
	Monster temp(name, level);
	if (level != 5)
	{
		level++;
	}
	return temp;
}
/*----------------------------------------------------------------------------------*/
void Monster::Print(ostream& out) const
{
	out << name << " Level:" << level << endl;
}

/*----------------------------------------------------------------------------------*/
ostream& operator << (ostream& out, Monster& monster)
{
	monster.Print(out);
	return out;
}