#include "GameManager.h"
#include "GameManagerLogger.h" // Include other logger headers here
#include "MapLogger.h"
#include "CharacterLogger.h"
#include "DiceLogger.h"
#include "Character/CharContainer.h"
#include "Items/Armor.h"
#include "Strategies/HumanPlayerStrategy.h"
#include "Character/Character.h"
#include <Items/Armor.h>


int main(){
	// ASSIGNMENT 3 : Part 3
	
	
	// Create a Character
	Character* hero = new Character("Himmel", new Vector2(0, 0), new HumanPlayerStrategy(), 1, "fighter", NULL);

	// Create Items
	Armor* armor = new Armor("Basic Armor");

	// Add item to hero
	hero->equipItem(armor);
	hero->displayCharInventory();

	//Remove Item from hero
	hero->removeItem(armor);
	hero->displayCharInventory();

	//Character* myCharacter = CharacterFactory::createCharacter("BOB", 5, "Bully");

	GameManager::GetInstance()->SelectCampaign();

	// Game Logger 
	GameManager* gameManager = GameManager::GetInstance();

	GameManagerLogger gameManagerLogger;
	MapLogger mapLogger;
    CharacterLogger characterLogger;
    DiceLogger diceLogger;

	gameManager->Attach(&gameManagerLogger);

	
	// then attach the CharacterLogger as observer
	hero->Attach(&characterLogger);

	Map* m = new Map();
	
	
	// then attach the MapLogger as observer
	// m->Attach(&mapLogger);

	// Initialize a Dice
	// then attach the DiceLogger as observer
	// dice->Attach(&diceLogger);
	
	GameManager::GetInstance()->StartCampaign();

    
}
