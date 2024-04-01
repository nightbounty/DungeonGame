#include "GameManager.h"
#include "GameManagerLogger.h" // Include other logger headers here
#include "MapLogger.h"
#include "CharacterLogger.h"
#include "DiceLogger.h"
#include "Character/Character.h"
#include "Items/Weapon.h"
#include "Items/ItemContainer.h"
#include "Items/Armor.h"

int main(){
	// Create a character
	Character* hero = new Character();
	// Create an Item
	Weapon* bow = new Weapon("Bow", "1d8", 5);
	Armor* armor = new Armor();

	// add to inventory
	hero->AddToInventory(bow);
	//diplay inventory
	hero->displayInventory();

	//skip line
	std::cout << "\n";
	//skip line
	std::cout << "\n";

	//take Weapon from Inventory
	Item* takeWeapon = hero->takeItem("Bow");
	// Equip Item to Character
	hero->equipItem(takeWeapon);
	//display Equipped items
	hero->displayEquippedItems();
	//diplay inventory
	hero->displayInventory(); // should have nothing
	hero->DisplayStats(); // Increase the character stats
	hero->unEquipItem(takeWeapon);
	// display Character stats
	hero->DisplayStats();
	hero->displayInventory(); // should have the bow back
	
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
	// Game Logger 
	GameManager* gameManager = GameManager::GetInstance();

	GameManagerLogger gameManagerLogger;
	MapLogger mapLogger;
    CharacterLogger characterLogger;
    DiceLogger diceLogger;

	gameManager->Attach(&gameManagerLogger);

	// Initialize a Character
	// then attach the CharacterLogger as observer
	// character->Attach(&characterLogger);

	// Initialize a Map
	// then attach the MapLogger as observer
	// map->Attach(&mapLogger);

	// Initialize a Dice
	// then attach the DiceLogger as observer
	// dice->Attach(&diceLogger);
	GameManager::GetInstance()->StartCampaign();

    //Remove Item from hero
    //hero->removeItem(armor);
    //hero->displayCharInventory();
}