#include "Monster.h"
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