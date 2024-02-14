#include "../headers/Cell.h"
#include <iostream>

using namespace std;

void Cell::SetOccupant(CellOccupant o)
{
	occupant = o;
}

CellOccupant Cell::getOccupant()
{
	return occupant;
}

bool Cell::isWall()
{
	return occupant == Wall;
}
