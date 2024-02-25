#pragma once
using namespace std;
#include <iostream>
#include "CellOccupants/CellOccupant.h"


class Cell {
public:
	Cell();
	Cell(CellOccupant* o, bool isItWall);
	void SetCellOccupant(CellOccupant* o);
	CellOccupant* GetCellOccupant();
	bool IsWall();
	bool IsOnPath();
	bool IsEmpty();
	void SetWall(bool wall);
	void SetOnPath(bool onPath);
	
private:
	CellOccupant* occupant;
	bool isWall;
	bool isOnPath;
};



