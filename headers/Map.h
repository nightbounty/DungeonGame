#pragma once
#include "Cell.h"
class Vector2;
#include "CellOccupants/CellOccupant.h"
#include "CellOccupants/Door.h"
#include "CellOccupants/Chest.h"
#include "CellOccupants/Enemy.h"

#ifndef MAP
#define MAP
#endif

class Map
{
private:
	Cell*** grid;
	Vector2* startPt;
	Vector2** path;
	int rows;
	int cols;
	string name;
	string description;
public:
	Map(int rows, int cols, Vector2* startPt) {
		this->rows = rows;
		this->cols = cols;
		grid = CreateGrid(rows, cols);
		this->startPt = startPt;
		RandomizeMap();
		path = GeneratePath(); 
	}
	Map();
	Cell*** CreateGrid(int rows, int cols);
	void SetCellOccupant(int row, int col, CellOccupant* o);
	Vector2** GeneratePath(); // this should return a vector2[] but idk how qwq
	void RandomizeMap();
	void SetPath(Vector2** newPath);
	Vector2** GetPath();
	void SetStartPt(Vector2* newPt);
	Vector2* GetStartPt();
	int GetColumns();
	int GetRows();
	Cell*** GetGrid();
	string ToString();
	void SetName(string name);
	string GetName();
	void SetDescription(string description);
	string GetDescription();
};

