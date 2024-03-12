#include "CampaignManager.h"

Campaign* CampaignManager::LoadCampaign() {
	string campaignToLoad;
	cout << "Enter the name of the map you want to load." << endl;
	cin >> campaignToLoad;
	cin.ignore();
	ifstream loadedCampaignFile(".\\source\\UserCreatedCampaigns\\" + campaignToLoad + ".txt");
	Campaign* loadedCampaign;
	loadedCampaignFile.read((char*)&loadedCampaign, sizeof(loadedCampaign));
	cout << "This is the campaign you loaded!" << endl;
	cout << loadedCampaign->ToString() << endl;
	loadedCampaignFile.close();
	return loadedCampaign;
}
void CampaignManager::EditLoadedMap(Map* loadedMap) {
	int mapEditOption;
	string mapToLoad = loadedMap->GetName();
	bool stillEditing = true;
	while (stillEditing) {
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
			stillEditing = false;
			break;
		}
		}
	}
}

	void CampaignManager::SetMapCellOccupant(string type, Map * map) {
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


	Map* CampaignManager::LoadMap(){
		string mapToLoad;
		cout << "Enter the name of the map you want to load." << endl;
		cin >> mapToLoad;
		cin.ignore();
		ifstream loadedMapFile(".\\source\\UserCreatedMaps\\" + mapToLoad + ".txt");
		Map* loadedMap;
		loadedMapFile.read((char*)&loadedMap, sizeof(loadedMap));
		cout << "This is the map you loaded!" << endl;
		cout << loadedMap->ToString() << endl;
		loadedMapFile.close();
		return loadedMap;
	}

	Map* CampaignManager::CreateNewMap() {
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

	Campaign* CampaignManager::CreateNewCampaign() {
		string title;
		cout << "Enter the title of your campaign: (No spaces)" << endl;
		cin >> title;
		cin.ignore();
		vector<Map*> maps;
		bool stillAddingMaps = true;
		int createOrLoad, campaignSize = 0;
		Map* mapToAdd;
		while (stillAddingMaps) {
			cout << "Create or load a map to add? 1 to create, 2 to load, 3 to exit" << endl;
			cin >> createOrLoad;
			cin.ignore();
			if (createOrLoad == 1) {
				mapToAdd = CampaignManager::CreateNewMap();
				maps.push_back(mapToAdd);
				campaignSize++;
			}
			else if (createOrLoad == 2) {
				mapToAdd = CampaignManager::LoadMap();
				maps.push_back(mapToAdd);
				campaignSize++;
			}
			else if (createOrLoad == 3) {
				stillAddingMaps = false;
			}
		}
		Campaign* newCampaign = new Campaign(maps, title, campaignSize);
		cout << "Campaign successfully created!" << endl;
		cout << newCampaign->ToString() << endl;
		return newCampaign;
	}

	void CampaignManager::EditLoadedCampaign(Campaign* loadedCampaign) {
		int campaignEditOption, mapToRemove, createOrLoad;
		string campaignToLoad = loadedCampaign->GetTitle();
		bool stillEditing = true;
		while (stillEditing) {
			cout << "What would you like to change? Please select an option:" << endl;
			cout << "1. Remove a map" << endl;
			cout << "2. Add a map" << endl;
			cout << "3. Save and return to menu" << endl;
			cin >> campaignEditOption;
			switch (campaignEditOption) {
			case 1: {
				cout << "Enter the index of the map you would like to remove:" << endl;
				cin >> mapToRemove;
				cin.ignore();
				loadedCampaign->RemoveMap(mapToRemove);
				break;
			}
			case 2: {

				cout << "Would you like to create a new map or load an existing map? 1 to create, 2 to load" << endl;
				cin >> createOrLoad;
				cin.ignore();
				Map* mapToAdd;
				if (createOrLoad == 1) {
					mapToAdd = CampaignManager::CreateNewMap();
				}
				else if (createOrLoad == 2) {
					mapToAdd = CampaignManager::LoadMap();
				}
				
				break;
			}
			case 3: {
				ofstream editedCampaign(campaignToLoad + ".txt");
				editedCampaign.write((char*)&loadedCampaign, sizeof(loadedCampaign));
				editedCampaign.close();
				stillEditing = false;
			}
			}
		}
	}
