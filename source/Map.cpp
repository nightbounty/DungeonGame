#include "../headers/Map.h"
#include <iostream>
#include "../headers/Cell.h"

Cell** createGrid(int rows, int cols) {
	// Allocate memory for an array of pointers to rows
	Cell** grid = new Cell*[rows];
	for (int i = 0; i < rows; i++) {
		grid[i] = new Cell[cols];
	}
	
	return grid;
}

void deleteGrid(Cell** grid, int rows) {
	// Free memory for each row
	for (int i = 1; i < rows; i++) {
		delete[] grid[i];
	}
	delete[] grid;
}

void Map::SetCellOccupant(int row, int col, CellOccupant o) {
	grid[row][col].SetCellOccupant(o);
}

/*void Map::GeneratePath(){
	int y;
	int rand = Math.Random(0,grid.columns)
	for int i = 1; i < grid.columns; i++ {
		if y+1 >= grid.columns
			if rand > 0.5, y = y-1
		else if y - 1 < 0
			if rand > 0.5, y = y+1
		else
			if rand < 0.33
				y = y - 1
			if rand > 0.66
				y = y + 1
		path[i]=new Vector2(i,y);
	}
}*/