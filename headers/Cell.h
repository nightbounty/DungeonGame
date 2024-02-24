#pragma once
using namespace std;
#include <iostream>
#include "CellOccupant.h"


class Cell {
public:
	void SetCellOccupant(CellOccupant o);
	CellOccupant getCellOccupant();
	bool isWall();
	void setWall(bool wall);
	Cell(CellOccupant o, bool isItWall);
	Cell();
private:
	CellOccupant occupant;
	bool isWall;
};



