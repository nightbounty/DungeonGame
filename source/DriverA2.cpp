#include <iostream>
using namespace std;
#include <string>
#include "Vector2.h"
#include "Map.h"
#include <fstream>


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
				cout << "Enter the name of the map you want to load." << endl;
				// try to create file object based on the file name
				// read Map object from the file
				// what do you want to change?
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

