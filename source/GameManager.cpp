#include "GameManager.h"
#include "Character/Character.h"
#include "CellOccupants/Enemy.h"

GameManager* GameManager::instancePtr;
GameManager* GameManager::GetInstance() {
    {
        // If there is no instance then create one
        if (instancePtr == NULL)
        {
            instancePtr = new GameManager();
            return instancePtr;
        }
        else
        {
        // otherwise return the existing pointer
            return instancePtr;
        }
    }
}
void GameManager::SelectCampaign() {
    currentCampaign = CampaignManager::LoadCampaign();
    StartCampaign();
}
void GameManager::StartCampaign() {
    currentMap = currentCampaign->Start();
    enemies = currentMap->GetEnemies();
   
    // creating the party of characters. for now just one
    characters = new Character*[1];
    characters[0] = new Character(1, "Fighter");
    characters[0]->SetPosition(new Vector2(0,0));
    dynamic_cast<CellOccupant*>(characters[0]);
    currentMap->SetCellOccupant(0, 0, characters[0]);
    // setting the target of the enemies to the player
    for (int i = 0; i < enemies.size(); i++) {
        enemies[i]->SetCurrentTarget(characters[0]);
    }
    cout << "STARTING THE GAME...\n" << endl;
    cout << currentMap->ToString() << endl;
    cout << "\nCharacter's turn" << endl;
    MoveCharacterFromInput(0); 
    cout << "\nEnemy's turn" << endl;
    for (int i = 0; i < enemies.size(); i++) {
        cout << "enemy " + std::to_string(i)+ " turn start" << endl;
        enemies[i]->GetTurnStrategy()->ExecuteTurn(enemies[i]);
        cout << currentMap->ToString() << endl;
    }
    
}

void GameManager::MoveCharacterFromInput(int characterIndex) {
    char input;
    Vector2* oldPos = characters[characterIndex]->GetPosition();
    int newX = oldPos->GetX(), newY = oldPos->GetY();
    cout << "Enter direction of movement: WASD, QEZC for diagonals" << endl;
    cin >> input;
    switch (input) {
    case 'w':
    {
        newX -= 1;
        break;
    }
    case 'a':
    {
        newY -= 1;
        break;
    }
    case 's':
    {
        newX += 1;
        break;
    }
    case 'd':
    {
        newY += 1;
        break;
    }
    case 'q':
    {
        newX -= 1;
        newY += 1;
        break;
    }
    case 'e':
    {
        newX += 1;
        newY += 1;
        break;
    }
    case 'z':
    {
        newX -= 1;
        newY -= 1;
        break;
    }
    case 'c':
    {
        newX += 1;
        newY -= 1;
        break;
    }
    }
    Vector2* newPos = new Vector2(newX, newY);
    MoveActor(characters[characterIndex], oldPos, newPos);
    cout << currentMap->ToString() << endl;
    
}

bool GameManager::MoveActor(Actor* a, Vector2* oldPos, Vector2* newPos) {
    if (!IsValidMove(newPos)) return false;
	currentMap->SetCellOccupant(oldPos->GetX(), oldPos->GetY(), NULL);
    dynamic_cast<CellOccupant*>(a);
	currentMap->SetCellOccupant(newPos->GetX(), newPos->GetY(), a);
	return true;
}

bool GameManager::IsValidMove(Vector2* position) {
	return position->GetX() < currentMap->GetColumns()
		&& position->GetY() < currentMap->GetRows()
		&& position->GetX() >= 0 && position->GetY() >= 0;
}

void GameManager::DisplayEnemiesInMap() {
    if (enemies.size() == 0) {
        cout << "No enemies on this map!" << endl;
    }
    else {
        cout << "Here are the enemies!" << endl;
        for (int i = 0; i < enemies.size(); i++) {
            cout << enemies[i]->ToString();
        }
    }
}

void GameManager::InitiateCombat(Actor* enemy) { // TODO this should be an enemy
    // TODO check that it's an instance of enemy by dynamic casting 
    cout << "combat started" << endl;
    int playerInit = Dice::rollDice("1d20+" + characters[0]->GetInitiativeBonus());
    int enemyInit = Dice::rollDice("1d20+" + enemy->GetInitiativeBonus());
    
    if (playerInit > enemyInit) {

    }
    // while enemy health > 0 and player health > 0
    // firstPlayer.executeTurn()
    // secondPlayer.executeTurn()
}
