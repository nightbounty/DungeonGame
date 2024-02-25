
#include "../headers/Cell.h"
#include <iostream>

using namespace std;

Cell::Cell(CellOccupant o, bool isItWall){
	this->isWall=isItWall;
	this->occupant=o;
}

Cell::Cell(){
	this->isWall = false;
	//this->occupant = null; but for some reason it doesn't work :c
}
void Cell::SetCellOccupant(CellOccupant o)
{
	occupant = o;
}

CellOccupant Cell::getCellOccupant()
{
	return occupant;
}

/* bool Cell::isWall() // WHY??
{
	return this->isWall;
} */


void Cell::setWall(bool wall)
{
	this->isWall = wall;
}
