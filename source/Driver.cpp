#include "GameManager.h"
#include "GameManagerLogger.h" // Include other logger headers here
#include "MapLogger.h"
#include "CharacterLogger.h"
#include "DiceLogger.h"
#include "Character/Character.h"
#include "Items/Weapon.h"
#include "Items/ItemContainer.h"
#include "Items/Armor.h"
#include "Items/Shield.h"
#include "../ItemCreation.h"
#include "CellOccupants/Chest.h"

int main(){

	 // TESTING USER ITEMS
ItemCreation startingItems;
	startingItems.startingUserItems();
	// Get the Item Set Decided by User & Place into chet
	cout << "\nYour Chosen Items Have Been Loaded Into Chest!" << endl;
	std::vector<Item*> vectorStartingItems = startingItems.getUserItemChoice(); //this to get users vector of items
Chest::getInitialChestLoot(startingItems.getUserItemChoice());

//for (size_t i = 0; i < vectorStartingItems.size(); ++i) {
//	std::cout << vectorStartingItems[i]->getName() << " ";
//}
//std::cout << std::endl;

	int option;
	Campaign* campaign;
	cout << "=============================================" << endl;
	cout << "Welcome to Dungeons and Dragons Online!" << endl;
	cout << "=============================================" << endl;


	cout << "\n";

	cout << "\nWould you like to load a pre-existing campaign, or create a new campaign?" << endl;
	cout << "Press 1 to load, or 2 to create, 3 to quit: ";
	cin >> option;
	switch (option) {
	case 1: {
		campaign = CampaignManager::LoadCampaign();
		break;
	} case 2: {
		campaign = CampaignManager::CreateNewCampaign();
		break;
	} case 3: {
		cout << "Exiting the game..." << endl;
		return 0;
	}
	default: {
		cout << "wrong input!" << endl;
		return 0;
	}
	}
	GameManager::GetInstance()->SetCampaign(campaign);
	
	GameManager* gameManager = GameManager::GetInstance();

	gameManager->StartCampaign();


}