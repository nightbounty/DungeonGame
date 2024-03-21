/*
* #include <iostream>
using namespace std;
#include <string>
#include "Vector2.h"
#include "Map.h"
#include "ConcreteMapObserver.h"
#include <fstream>
#include "Campaign.h"
#include "CampaignManager.h"
int driver4();
#include "../headers/Character/Character.h"
#include "../headers/Character/CharacterObserver.h"


void DisplayMainMenu();

	int main()
	{	

		cout << "Welcome to the GAME! +_+\n";
		cout << "************************\n";

		cout << "Let's create your character...\n";
		cout << "***************************\n";

		// Seed the random number generator once
		srand(static_cast<unsigned int>(time(0)));

		// Prompt for character creation details
		string name;
		string characterClass = "Fighter";
		int level;

		cout << "Enter your Fighter's name: ";
		cin >> name;

		cout << "Enter your character's level: ";
		cin >> level;

		// Create the character
		cout << "\nCreating your character...\n";
		Character myCharacter(level, characterClass);

		// Attach observer to character
		CharacterObserver observer;
		myCharacter.attachObserver(&observer);

		// Display initial character stats
		cout << "\nDisplaying initial character stats...\n";
		myCharacter.displayStats();

		// Prompt the player about adding extra levels
		cout << "\nDo you want to add extra levels to your character? (yes/no): ";
		string response;
		cin >> response;

		if (response == "yes" || response == "Yes") {
			int extraLevels;
			cout << "How many levels do you want to add?: ";
			cin >> extraLevels;

			cout << "\nAdding " << extraLevels << " levels to your character...\n";
			myCharacter.level += extraLevels; // Add extra levels

			// Increment each ability score by 1 for each level added
			for (int level = 0; level < extraLevels; ++level) {
				for (int& score : myCharacter.abilityScores) {
					score += 1;
				}
			}
			myCharacter.attackBonus += extraLevels;
			// Notify observers of the change to re-display updated stats
			cout << "\nNow we are notifying the character observers if there was any changes...\n";
			myCharacter.notifyObservers();
		}
		else {
			cout << "No levels added. Keeping the character as is.\n";
		}

		cout << "\nCharacter setup complete! Proceed with your adventure.\n";
		// PART 4: MAP BUILDER
		driver4();
		// PART 2 MAP OBSERVER
		int rows, columns, startY;

		cout << "\n======================================" << endl;
		cout << "Next, let's test the map observer!~";
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
		cout << "\n Now we will update te map and see if the observer updates the display!";
		testMap->SetCellOccupant(1, 1, new Chest());
		testMap->SetStartPt(new Vector2(2, 2));
		testMap->Notify();

		//////////////////////////////////////////////////////////////////
		// creating a test campaign
		vector<Map*> maps;
		Map* barovia = new Map(5, 6, new Vector2(3, 0));
		barovia->SetName("Barovia");
		Map* vallaki = new Map(6, 7, new Vector2(4, 0));
		vallaki->SetName("vallaki");
		Map* ravenloft = new Map(4, 5, new Vector2(2, 0));
		ravenloft->SetName("ravenloft");
		maps.push_back(barovia);
		maps.push_back(vallaki);
		maps.push_back(ravenloft);

		Campaign* testCampaign = new Campaign(maps, "CurseOfStrahd");
		// Campaign* newCampaign = CampaignManager::CreateNewCampaign();
		ofstream campaignFile(".\\source\\UserCreatedCampaigns\\" + testCampaign->GetTitle() + ".txt");
		campaignFile.write((char*)&testCampaign, sizeof(testCampaign));
		campaignFile.close();
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
				Campaign* newCampaign = CampaignManager::CreateNewCampaign();
				ofstream campaignFile(".\\source\\UserCreatedCampaigns\\" + newCampaign->GetTitle() + ".txt");
				campaignFile.write((char*)&newCampaign, sizeof(newCampaign));
				campaignFile.close();
				
				break;
			}

			case 3: // Loading and editing a map
			{
				Map* loadedMap = CampaignManager::LoadMap();
				CampaignManager::EditLoadedMap(loadedMap);
				break;
			}

			case 4: // loading and editing a campaign
			{
				Campaign* loadedCampaign = CampaignManager::LoadCampaign();
				CampaignManager::EditLoadedCampaign(loadedCampaign);
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
	
	static inline void DisplayMainMenu() {
		cout << "Please select a menu option:" << endl;
		cout << "\t1. Create a new map" << endl;
		cout << "\t2. Create a new campaign" << endl;
		cout << "\t3. Load and edit an existing map" << endl;
		cout << "\t4. Load and edit an existing campaign" << endl;
		cout << "\t5. Exit the program" << endl;
	}
	
*/

	
	
	
	



