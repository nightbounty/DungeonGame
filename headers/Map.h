#ifndef MAP
#define MAP

#pragma once
#include "Cell.h"
class Vector2;
#include "CellOccupants/CellOccupant.h"
#include "CellOccupants/Door.h"
#include "CellOccupants/Chest.h"
class Enemy;
#include "MapObserver.h"  
#include "GameLoggerSubject.h"
#include "Items/Item.h"
#include <string>
#include <vector>


class MapObserver; // Declaring the Obsrver for the Map object

class Map : public GameLoggerSubject
{
private:
	Cell*** grid;
	Vector2* startPt;
	Vector2** path;
	int rows;
	int cols;
	string name;
	string description;
	Door* exitDoor;
	std::vector<Enemy*> enemies;
	std::vector<MapObserver*> observers; // Where all the observers will be added
	std::string logEntry; // Game Log related member
	void NotifyObservers(); // Game Log related private function

	// additional features of the Map
	// attributes of a map
	int mapLevel;
	std::string worldName;
	std::string worldTier;
	std::vector<Item*> items;
	std::vector<std::string> characters;
	//new attributes
	std::string characterTier;
	std::string itemTier;
	std::string enemyTier;

public:
	Map(int rows, int cols, Vector2* startPt) {
		this->rows = rows;
		this->cols = cols;
		grid = CreateGrid(rows, cols);
		this->startPt = startPt;
		//RandomizeMap();
		//path = GeneratePath(); 
	}
	Map();
	Cell*** CreateGrid(int rows, int cols);

	void SetCellOccupant(int x, int y, CellOccupant* o);
	void SetWall(int x, int y);
	Vector2** GeneratePath(); 
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

	vector<Enemy*> GetEnemies();
	
	void SetDescription(string description);
	string GetDescription();

	void Attach(MapObserver* observer); // adding an observer
    void Notify(); // notifying all observers

	Door* GetExitDoor();
	void SetExitDoor(Door* door);
	CellOccupant* GetCellOccupant(Vector2* pos);
	CellOccupant* GetCellOccupant(int x, int y);

	void LogEvent(const std::string& event); // Game log related function

	// additional features of the Map
	void displaySavedMap();
	void displayMapContents();

	// generate getters
	int getMapLevel() const {
		return mapLevel;
	}

	const std::string getWorldName() const {
		return worldName;
	}

	const std::string getWorldTier() const {
		return worldTier;
	}

	const std::vector<Item*>& getItem() const {
		return items;
	}

	const std::vector<std::string> getCharacters() const {
		return characters;
	}
	std::string getCharacterTier() const {
		return characterTier;
	}
	std::string getItemTier() const {
		return itemTier;
	}
	std::string getEnemyTier() const {
		return enemyTier;
	}

	// generate setters
	void setMapLevel(int newMapLevel) {
		mapLevel = newMapLevel;
	}

	void setWorldName(const std::string& newWorldName) {
		worldName = newWorldName;
	}

	void setWorldTier(const std::string& newWorldTier) {
		worldTier = newWorldTier;
	}

	void setItems(const std::vector<Item*>& newItems) {
		items = newItems; // This line is necessary to actually set the items
	}

	void setCharacters(const std::vector<std::string> newCharacters) {
		characters = newCharacters;
	}
	void setCharacterTier(const std::string& tier) {
		characterTier = tier;
	}
	void setItemTier(const std::string& tier) {
		itemTier = tier;
	}
	void setEnemyTier(const std::string& tier) {
		enemyTier = tier;
	}
};

#endif