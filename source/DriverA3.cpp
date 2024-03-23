#include "GameManager.h"
#include "GameManagerLogger.h" // Include other logger headers here
#include "MapLogger.h"
#include "CharacterLogger.h"
#include "DiceLogger.h"
int main(){

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
}
