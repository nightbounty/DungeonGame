#include <iostream>
#include "Map.h"
#include "Cell.h"

Map::Map() {
	this->rows = 2;
	this->cols = 2;
	this->path = GeneratePath();
	this->startPt = new Vector2();
}
/**
 * Method which creates a 2D grid of Cell objects.
 * 
 * \param rows Rows of the grid
 * \param cols Columns of the grid
 * \return The newly created grid
 */
Cell*** Map::CreateGrid(int rows, int cols) {
	// Allocate memory for an array of pointers to rows
	Cell*** grid = new Cell**[rows];
	for (int i = 0; i < rows; i++) {
		grid[i] = new Cell*[cols];
		for (int j = 0; j < cols; j++) {
			grid[i][j] = new Cell();
		}
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
	grid[row][col]->SetCellOccupant(o);
}

int Map::GetColumns(){
	return cols;
}

int Map::GetRows(){
	return rows;
}

Cell*** Map::GetGrid()
{
	return this->grid;
}
/**
 * Method which generates a randomized path to keep free.
 * 
 * \return 
 */
Vector2** Map::GeneratePath(){
	int x = 0;
	float random;
	Vector2** newPath = new Vector2*[rows];
	newPath[0] = startPt;
	for (int i = 1; i < cols; i++) {
		random = (float)rand()/(RAND_MAX);
		// if we are at top row, can only go straight or down
		if (x+1 >= cols){
			if (random > 0.5) x = x-1;
		}
		// if we are at bot row, can only go straight or up
		else if (x - 1 < 0){
			if (random > 0.5) x = x+1;
		}
		// otherwise can go up, straight or down
		else{
			if (random < 0.33){
				x = x - 1;
			}
			if (random > 0.66){
				x = x + 1;
			}
		}
		
		newPath[i] = new Vector2(x,i);

		grid[x][i]->SetOnPath(true);
		if(i == cols - 1){
			grid[x][i]->SetCellOccupant(new Door());
		}
	}

	return newPath;
}
/**
 * Method which randomizes all of the cells on the map.
 * 
 */
void Map::RandomizeMap(){
	
	float random;
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			random = ((float) rand() / (RAND_MAX));

			if (!grid[i][j]->IsOnPath() && random < 0.1){
				grid[i][j]->SetWall(true);
			} 
			else if(random > 0.1 && random < 0.15){
				grid[i][j]->SetCellOccupant(new Chest());
			}
			else if (random > 0.16 && random < 0.2) {
				grid[i][j]->SetCellOccupant(new Enemy());
			}
		}
	}

}

string Map::ToString(){
	string mapStr;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (grid[i][j]->IsWall()) {
				mapStr += "W\t";
			}
			else if (grid[i][j]->GetCellOccupant() != NULL) {
				mapStr += grid[i][j]->GetCellOccupant()->GetTokenCode() + "\t";
			}
			else {
				mapStr += "O\t";
			}
		}
		mapStr += "\n";
	}
	return mapStr;
}