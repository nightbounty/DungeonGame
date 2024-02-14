#pragma once
using namespace std;
#include <iostream>


class Cell {
public:
	void SetOccupant(CellOccupant o);
	CellOccupant getOccupant();
	bool isWall();

private:
	CellOccupant occupant;
};

enum CellOccupant {
	Wall,
	Empty,
	Monster,
	Chest,
	Door
};

