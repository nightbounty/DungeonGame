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

void Map::SetPath(Vector2** newPath){
	path = newPath; 
}

Vector2** Map::GetPath(){
	return path;
}

Vector2* Map::GetStartPt(){
	return this->startPt;
}

void Map::SetStartPt(Vector2* newPt){
	this->startPt = newPt;
}

void Map::SetCellOccupant(int row, int col, CellOccupant* o) {
	grid[row][col].SetCellOccupant(o);
}

int Map::GetColumns(){
	return columns;
}

int Map::GetRows(){
	return rows;
}

Vector2** Map::GeneratePath(){
	int y;
	float random;
	Vector2** newPath = new Vector2*[rows];
	// path[0] = startPt;
	for (int i = 1; i < columns; i++) {
		random = (float)rand();
		// if we are at top row, can only go straight or down
		if (y+1 >= columns){
			if (random > 0.5) y = y-1;
		}
		// if we are at bot row, can only go straight or up
		else if (y - 1 < 0){
			if (random > 0.5) y = y+1;
		}
		// otherwise can go up, straight or down
		else{
			if (random < 0.33){
				y = y - 1;
			}
			if (random > 0.66){
				y = y + 1;
			}
		}

		path[i] = new Vector2(i,y);
		grid[i][y].SetOnPath(true);
		if(i == columns - 1){
			grid[i][y].SetCellOccupant(new Door());
		}
	}
	return newPath;
}

void Map::RandomizeMap(){
	int random;
	for (int i = 0; i < rows; i++){
		random = rand();
		for (int j = 0; j < columns; j++){
			if (!grid[i][j].IsOnPath() && random < 0.1){
				grid[i][j].SetWall(true);
			} else if(0.1 < random && 0.15 > random){
				grid[i][j].SetCellOccupant(new Chest());
			} else if(0.16 < random && 0.2 < random){
				grid[i][j].SetCellOccupant(new Enemy());
			}
		}
	}

}