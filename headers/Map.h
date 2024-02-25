#pragma once
#include <Cell.h>
#include <Vector2.h>
#include <CellOccupant.h>
#include <Door.h>
#include <Chest.h>
#include <Enemy.h>

class Map
{
private:
	Cell** grid;
	Vector2* startPt;
	Vector2** path;
	int rows;
	int columns;
public:
	Map(int rows, int cols, Vector2* startPt) {
		grid = createGrid(rows, cols);
		this->startPt = startPt;
		RandomizeMap();
		path = GeneratePath(); 
	}
	void SetCellOccupant(int row, int col, CellOccupant* o);
	Vector2** GeneratePath(); // this should return a vector2[] but idk how qwq
	void RandomizeMap();
	void SetPath(Vector2** newPath);
	Vector2** GetPath();
	void SetStartPt(Vector2* newPt);
	Vector2* GetStartPt();
	int GetColumns();
	int GetRows();

};

