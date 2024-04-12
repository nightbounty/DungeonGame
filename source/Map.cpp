#include <iostream>
#include "Map.h"
#include "CellOccupants/Enemy.h""
#include "Strategies/FriendlyStrategy.h""

Map::Map() {
	setMapLevel(mapLevel);
	std::string worldName;
	std::string worldTier;
	std::vector<Item*> items;
	std::vector<std::string> characters;
	//New
	std::string characterTier = "";
	std::string itemTier = "";
}

/**
 * @brief Adding an observer to the Map
 * 
 * @param observer 
 */
void Map::Attach(MapObserver* observer) {
	observers.push_back(observer);
}

/**
 * @brief Notifying all the observers when Map is updated
 * 
 */
void Map::Notify() {
	for (MapObserver* o : observers) {
        o->update(this);
    }
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

void DeleteGrid(Cell** grid, int rows) {
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

void Map::SetCellOccupant(int x, int y, CellOccupant* o) {
	if (grid[y][x]->IsWall()) grid[y][x]->SetWall(false);
	grid[y][x]->SetCellOccupant(o);
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
		
		//newPath[i]->Set(x, i);
		newPath[i] = new Vector2(x,i);

		grid[x][i]->SetOnPath(true);
		if(i == cols - 1){
			Door* exitDoor = new Door();
			grid[x][i]->SetCellOccupant(exitDoor);
			this->exitDoor = exitDoor;
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
				grid[i][j]->SetCellOccupant(new Chest(new Vector2(j,i), "Chest"));
			}
			else if (random > 0.16 && random < 0.2) {
				Enemy* enemy = new Enemy("Guard", new Vector2(j, i), new FriendlyStrategy(), 1); // TODO make dynamic enemy types
				enemies.push_back(enemy);
				grid[i][j]->SetCellOccupant(enemy);
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

void Map::SetName(string name) {
	this->name = name;
}
string Map::GetName() {
	return this->name;
}
void Map::SetDescription(string description) {
	this->description = description;
}
string Map::GetDescription() {
	return this->description;
}

Door* Map::GetExitDoor() {
	return this->exitDoor;
}

vector<Enemy*> Map::GetEnemies() {
	return this->enemies;
}

CellOccupant* Map::GetCellOccupant(Vector2* pos) {
	return grid[pos->GetY()][pos->GetX()]->GetCellOccupant();
}

CellOccupant* Map::GetCellOccupant(int x, int y) {
	return grid[y][x]->GetCellOccupant();
}

void Map::LogEvent(const std::string& event) {
    logEntry = event;
    NotifyObservers();
}

void Map::NotifyObservers() {
    Notify();
}

// additional features of the Map
void Map::displaySavedMap() {
	std::cout << "Your Saved Map Contains: " << std::endl;
	std::cout << "World Name: " << getWorldName() << "\n";
	std::cout << "World Difficulty: " << getWorldTier() << std::endl;

	std::cout << "\nItems: " << std::endl;
	for (const auto& item : items) {
		if (item != nullptr)
			std::cout << item->toString() << std::endl;
	}
	std::cout << "\nCharacters: " << std::endl;
	for (const auto& character : characters) {
		std::cout << character << std::endl;
	}

}

void Map::displayMapContents() {
	std::cout << "World Difficulty: " << getWorldTier() << "\n";
	std::cout << "Item Tier: " << getItemTier() << "\n";
	std::cout << "Enemy Tier (CR): " << getEnemyTier() << "\n";
	std::cout << "Character Tier: " << getCharacterTier() << std::endl;
}


