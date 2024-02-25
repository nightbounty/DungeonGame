#pragma once
#include <Cell.h>
#include "Vector2.h"
class Map
{
private:
	Cell** grid;
	Vector2 startPt;
	Vector2 path[];
public:
	Map(int rows, int cols, Vector2 startPt) {
		grid = createGrid(rows, cols);
		this->startPt = startPt;
		RandomizeMap();
		GeneratePath();
	}
	void SetCellOccupant(int row, int col, CellOccupant o);
	void GeneratePath();
	void RandomizeMap();
	void SetPath();
	Vector2 SetStartPt();
	void getStartPt();

};

