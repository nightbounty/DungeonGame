#include <iostream>
using namespace std;
#include <string>
#include "Vector2.h"
#include "Map.h"
#include "ConcreteMapObserver.h"
#include <fstream>
#include "Campaign.h"
#include "CampaignManager.h"


void DisplayMainMenu();

	int main()
	{
		// PART 2 MAP OBSERVER
		int rows, columns, startY;

		cout << "\n======================================" << endl;
		cout << "Next, let's test the map creation!~";
		cout << "\n======================================\n" << endl;
		
		cout << "Please enter the number of rows for the map: \n";
		cin >> rows;

		cout << "Please enter the number of columns for the map: \n";
		cin >> columns;

		cout << "Please enter the y start coordinate for the map: \n";
		cin >> startY;

		cout << "Generating a map based on your input! :D" << endl;
		Map* testMap = new Map(rows, columns, new Vector2(0, startY));
	
		cout << "\n=== LEGEND ===\nD: Door\nE: Enemy\nC: Chest\nO: Empty\nW: Wall";
		
		cout << "\n=== YOUR MAP!! *^* ===\n\n" << testMap->ToString();

		ConcreteMapObserver concreteMapObserver;
		testMap->Attach(&concreteMapObserver);

		testMap->SetCellOccupant(1, 1, new Chest());
		testMap->SetStartPt(new Vector2(2, 2));
		testMap->Notify();

		//////////////////////////////////////////////////////////////////

		cout << "Welcome to the interactive campaign builder!" << endl;
		cout << "============================================" << endl;
		int currentOption;
		while (true) {
			DisplayMainMenu();

			cin >> currentOption;
			switch (currentOption) {
			case 1: // Creating a new map
			{
				Map* newMap = new Map(5, 6, new Vector2(2, 0));
				newMap->SetName("testMap");
				//Map* newMap = CreateNewMap();
				ofstream mapFile(".\\source\\UserCreatedMaps\\" + newMap->GetName() + ".txt");
				mapFile.write((char*)&newMap, sizeof(newMap));
				mapFile.close();
				cout << "Your new map has been saved to a file!" << endl;
				break;
			}

			case 2: // Creating a new campaign
			{
				string title;
				cout << "Enter the title of your campaign: (No spaces)" << endl;
				cin >> title;
				cin.ignore();
				vector<Map*> maps;
				bool stillAddingMaps = true;
				int createOrLoad, campaignSize=0;
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
				// if i+1 < size, maps[i].GetExitDoor().SetConnectedMap(maps[i+1])
				// else, maps[i].GetExitDoor.SetConnectedMap(NULL) <- end of campaign
				// TODO: map get exit door function and be able to set the connected map
				break;
			}

			case 3: // Loading and editing a map
			{
				Map* loadedMap = CampaignManager::LoadMap();
				CampaignManager::EditLoadedMap(loadedMap);
				break;
			}

			case 4:
			{
				Campaign* loadedCampaign = CampaignManager::LoadCampaign();
				// EditLoadedCampaign(loadedCampaign);
				break;
			}
			case 5:
			{
				cout << "Thank you for using the campaign builder! Exiting the software now..." << endl;
				return 0;
			}

			}
		}

	}
	static inline void EditLoadedCampaign(Campaign* loadedCampaign) {
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
					// loadedCampaign.Remove(mapToRemove);
					break;
				}
				case 2: {
					
					cout << "Would you like to create a new map or load an existing map? 1 to create, 2 to load" << endl;
					cin >> createOrLoad;
					cin.ignore();
					Campaign* campaignToAdd;
					if (createOrLoad == 1) {
						// campaignToAdd = CampaignManager::CreateCampaign();
					}
					else if (createOrLoad == 2) {
						campaignToAdd = CampaignManager::LoadCampaign();
					}
					break;
				}
				case 3: {
					ofstream editedCampaign(campaignToLoad + ".txt");
					// Need to make sure i'm in overwrite mode
					editedCampaign.write((char*)&loadedCampaign, sizeof(loadedCampaign));
					editedCampaign.close();
					stillEditing = false;
				}
			}
		}
	}
	static inline void DisplayMainMenu() {
		cout << "Please select a menu option:" << endl;
		cout << "\t1. Create a new map" << endl;
		cout << "\t2. Create a new campaign" << endl;
		cout << "\t3. Load and edit an existing map" << endl;
		cout << "\t4. Load and edit an existing campaign" << endl;
		cout << "\t5. Exit the program" << endl;
	}
	
	
	
	
	



