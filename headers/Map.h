#pragma once
#include "../headers/Cell.h"
#include "../headers/Map.h"
class Map
{
private:
	Cell** grid;
public:
	Map(int rows, int cols) {
		grid = createGrid(rows, cols);
	}
	bool IsValid();
	void SetCellOccupant(int row, int col, CellOccupant o);
};

