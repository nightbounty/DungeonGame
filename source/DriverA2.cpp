#include <iostream>
using namespace std;
#include <string>
#include "Vector2.h"
#include "Map.h"
#include <fstream>

void SetMapCellOccupant(string type, Map* map);
Map* CreateNewMap();
	int main()
	{
		cout << "Welcome to the interactive campaign builder!" << endl;
		cout << "============================================" << endl;
		int currentOption;
		while (true) {
			cout << "Please select a menu option:" << endl;
			cout << "\t1. Create a new map" << endl;
			cout << "\t2. Create a new campaign" << endl;
			cout << "\t3. Load and edit an existing map" << endl;
			cout << "\t4. Load and edit an existing campaign" << endl;
			cout << "\t5. Exit the program" << endl;

			cin >> currentOption;
			switch (currentOption) {
			case 1:
			{
				Map* newMap = CreateNewMap();
				ofstream mapFile(newMap->GetName() + ".txt");
				mapFile.write((char*)&newMap, sizeof(newMap));
				mapFile.close();
				cout << "Your new map has been saved to a file!" << endl;
				break;
			}

			case 2:
			{
				cout << "Creating new campaign..." << endl;
				break;
			}

			case 3:
			{
				int mapEditOption;
				string mapToLoad;
				cout << "Enter the name of the map you want to load." << endl;
				cin >> mapToLoad;
				cin.ignore();
				ifstream loadedMapFile(mapToLoad + ".txt");
				Map* loadedMap;
				loadedMapFile.read((char*)&loadedMap, sizeof(loadedMap));
				cout << "This is the map you loaded!" << endl;
				cout << loadedMap->ToString() << endl;
				while (true) { // need to separate this into other function
					cout << "What would you like to change? Please select an option:" << endl;
					cout << "1. Set Enemy cells" << endl;
					cout << "2. Set Chests" << endl;
					cout << "3. Set Walls" << endl;
					cout << "4. Edit Description" << endl;
					cout << "5. Save and return to menu" << endl;
					cin >> mapEditOption;
					switch (mapEditOption) {
						case 1: {
							SetMapCellOccupant("Enemy", loadedMap);
							break;
						}
						case 2: {
							SetMapCellOccupant("Chest", loadedMap);
							break;
						}
						case 3: {
							SetMapCellOccupant("Chest", loadedMap);
							break;
						}
						case 4: {
							string newDescription;
							cout << "Enter the new description" << endl;
							getline(cin, newDescription);
							loadedMap->SetDescription(newDescription);
							break;
						} 
						case 5: {
							ofstream editedMap(mapToLoad + ".txt");
							// Need to make sure i'm in overwrite mode
							editedMap.write((char*)&loadedMap, sizeof(loadedMap));
							editedMap.close();
							return 0;
						}
					}
				}
				loadedMapFile.close();
				break;
			}

			case 4:
			{
				break;
			}
			case 5:
			{
				return 0;
			}

			}
		}

	}
	static inline void SetMapCellOccupant(string type, Map* map) {
		int row, col;
		cout << "Enter the row of the cell where an Enemy should be placed" << endl;
		cin >> row;
		cout << "Enter the column of the cell" << endl;
		cin >> col;
		if (type == "Enemy") {
			map->SetCellOccupant(row, col, new Enemy());
		}
		else if (type == "Chest") {
			map->SetCellOccupant(row, col, new Chest());
		}
		else if (type == "Wall") {
			map->GetGrid()[row][col]->SetWall(true);
		}
		else {
			cout << "Invalid type, sorry!" << endl;
		}
		
	}
	static inline Map* CreateNewMap() {
		int nbRows, nbColumns, startY;
		string mapTitle, mapDescription;
		cout << "Enter a title for your new map! (No spaces)" << endl;
		cin >> mapTitle;
		cin.ignore();
		cout << "Enter a description: " << endl;
		getline(cin, mapDescription);
		cout << "Enter the number of rows: " << endl;
		cin >> nbRows;
		cin.ignore();
		cout << "Enter the number of columns: " << endl;
		cin >> nbColumns;
		cout << "Please enter the y start coordinate: " << endl;
		cin >> startY;
		Map* newMap = new Map(nbRows, nbColumns, new Vector2(0, startY));
		newMap->SetName(mapTitle);
		cout << "\n=== LEGEND ===\nD: Door\nE: Enemy\nC: Chest\nO: Empty\nW: Wall";
		cout << "\n=== YOUR MAP!! *^* ===\n\n" << newMap->ToString();
		return newMap;
	}

