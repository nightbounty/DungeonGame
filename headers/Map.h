#pragma once
#include "Cell.h"
class Vector2;
#include "CellOccupants/CellOccupant.h"
#include "CellOccupants/Door.h"
#include "CellOccupants/Chest.h"
class Enemy;
#include "MapObserver.h"  
#include "GameLoggerSubject.h"
#include <vector>

#ifndef MAP
#define MAP
#endif

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
	CellOccupant* GetCellOccupant(int x, int y);

	void LogEvent(const std::string& event); // Game log related function
};

