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