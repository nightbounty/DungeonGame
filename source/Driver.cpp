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

int main(){

	/*
	
	// Create a character
	Character* hero = new Character();
	// Create an Item
	Weapon* bow = new Weapon("Bow", "1d8", 5);
	Armor* armor = new Armor("Light Armor");
	Shield* shield = new Shield("Light Shield");

	// add to inventory
	hero->AddToInventory(bow);
	hero->AddToInventory(armor);
	hero->AddToInventory(shield);
	//diplay inventory
	hero->displayInventory();

	//skip line
	std::cout << "\n";
	//skip line
	std::cout << "\n";

	//take Weapon from Inventory
	Item* takeWeapon = hero->takeItem("Bow");
	Item* takeArmor = hero->takeItem("Light Armor");
	// Equip Item to Character
	hero->equipItem(takeWeapon);
	hero->equipItem(takeArmor);
	//display Equipped items
	hero->displayEquippedItems();
	//diplay inventory
	hero->displayInventory(); // should have nothing
	hero->DisplayStats(); // Increase the character stats
	hero->unEquipItem(takeWeapon);
	// display Character stats
	hero->DisplayStats();
	hero->displayInventory(); // should have the bow back
	*/

	int option;
	Campaign* campaign;
	cout << "=============================================" << endl;
	cout << "Welcome to Dungeons and Dragons Online!" << endl;
	cout << "=============================================" << endl;
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