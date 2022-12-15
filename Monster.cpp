#include "Monster.h"

/*----------------------------------------------------------------------------------*/
void Monster::Print(ostream& out = cout) const
{
	out << name << " Level:" << level << endl;
}

/*----------------------------------------------------------------------------------*/
ostream& operator << (ostream& out, Monster& monster)
{
	monster.Print(out);
	return out;
}