
#include "../headers/Cell.h"
#include <iostream>

using namespace std;

Cell::Cell(){
	this->isWall = false;
	this->occupant = NULL;
}

Cell::Cell(CellOccupant* o, bool isItWall){
	this->isWall=isItWall;
	this->occupant=o;
}


void Cell::SetCellOccupant(CellOccupant* o)
{
	occupant = o;
}

CellOccupant* Cell::GetCellOccupant()
{
	return occupant;
}

bool Cell::IsWall() 
{
	return this->isWall;
} 


void Cell::SetWall(bool wall)
{
	this->isWall = wall;
}
