#include "GameManager.h"
#include "GameManagerLogger.h" // Include other logger headers here
#include "MapLogger.h"
#include "CharacterLogger.h"
#include "DiceLogger.h"
#include "Character.h"
#include "CharContainer.h"
#include "Armor.h"

int main(){

	//Character* myCharacter = CharacterFactory::createCharacter("BOB", 5, "Bully");

	GameManager::GetInstance()->SelectCampaign();

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

    // ASSIGNMENT 3 : Part 3
    
    // Create a Character
    Character* hero = new Character();

    // Create Items
    Armor* armor = new Armor("Basic Armor");

    // Add item to hero
    hero->equipItem(armor);
    hero->displayCharInventory();

    //Remove Item from hero
    hero->removeItem(armor);
    hero->displayCharInventory();
}
