#pragma once
using namespace std;
#include <iostream>
#include "CellOccupant.h"


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
	bool IsOnPath();
	
private:
	CellOccupant* occupant;
	bool isWall;
	bool isOnPath;
};



