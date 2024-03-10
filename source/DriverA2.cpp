#include <iostream>
using namespace std;
#include <string>
#include "Vector2.h"
#include "Map.h"

Map* CreateNewMap();
	int main()
	{
		int currentOption;
		cout << "Welcome to the interactive campaign builder!" << endl;
		cout << "============================================" << endl;
		cout << "Please select a menu option:" << endl;
		cout << "\t1. Create a new map" << endl;
		cout << "\t2. Create a new campaign" << endl;
		cout << "\t3. Load and edit an existing map" << endl;
		cout << "\t4. Load and edit an existing campaign" << endl;

		cin >> currentOption;
		switch (currentOption) {
		case 1:
		{
			Map* newMap = CreateNewMap();
			// write it to file
			break;
		}
			
		case 2:
		{
			break;
		}
			
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
		cout << "\n=== LEGEND ===\nD: Door\nE: Enemy\nC: Chest\nO: Empty\nW: Wall";
		cout << "\n=== YOUR MAP!! *^* ===\n\n" << newMap->ToString();
		return newMap;
	}

