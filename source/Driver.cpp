#include "GameManager.h"
#include "GameManagerLogger.h" // Include other logger headers here
#include "MapLogger.h"
#include "CharacterLogger.h"
#include "DiceLogger.h"
/**
int main(){

	int option;
	Campaign* campaign;
	cout << "=============================================" << endl;
	cout << "Welcome to Dungeons and Dragons Online!" << endl;
	cout << "=============================================" << endl;
	cout << "\nWould you like to load a pre-existing campaign, or create a new campaign?" << endl;
	cout << "Press 1 to load, or 2 to create: ";
	cin >> option;
	switch (option) {
	case 1: {
		campaign = CampaignManager::LoadCampaign();
		break;
	} case 2: {
		campaign = CampaignManager::CreateNewCampaign();
		break;
	} default: {
		cout << "wrong input!" << endl;
		return 0;
	}
	}
	GameManager::GetInstance()->SetCampaign(campaign);

	//Character* myCharacter = CharacterFactory::createCharacter("BOB", 5, "Bully");
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
*/