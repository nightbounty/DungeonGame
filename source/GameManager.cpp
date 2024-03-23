#include "GameManager.h"
#include "Character/Character.h"
#include "CellOccupants/Enemy.h"
#include "Strategies/HumanPlayerStrategy.h"
#include <iostream>

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
}
void GameManager::StartCampaign() {
    currentMap = currentCampaign->Start();
    enemies = currentMap->GetEnemies();
   
    // creating the party of characters. for now just one
    characters.push_back(new Character("Player", new Vector2(0, 0), new HumanPlayerStrategy(), 1, "Fighter"));
    currentMap->SetCellOccupant(0, 0, characters[0]);
    // setting the target of the enemies to the player
    for (int i = 0; i < enemies.size(); i++) {
        enemies[i]->SetCurrentTarget(characters[0]);
    }

    // GAME LOOP

    bool gameloop = true;
    int turnCounter = 1;

    cout << "STARTING THE GAME...\n" << endl;

    do {
        cout << "= TURN " << turnCounter << " =\n" << endl;
        cout << currentMap->ToString() << endl;

        cout << "\nCharacter's turn" << endl;
        //cout << "Turn strategy: " << (characters[0]->GetTurnStrategy()->ToString()) << endl;
        characters[0]->GetTurnStrategy()->ExecuteTurn(characters[0]);

        cout << "\nEnemy's turn" << endl;
        for (int i = 0; i < enemies.size(); i++) {
            cout << "enemy " + std::to_string(i) + " turn start" << endl;
            cout << "AC: " << (enemies[i]->GetArmorClass()) << endl;
            enemies[i]->GetTurnStrategy()->ExecuteTurn(enemies[i]);
            cout << currentMap->ToString() << endl;
        }

        if (characters[0]->GetCurrentHitPoints() <= 0) {
            cout << "\nCharacter is dead! Gameover :c" << endl;
            //break;
        }

        turnCounter++;
    } while (true);
}

bool GameManager::MoveActor(Actor* a, Vector2* oldPos, Vector2* newPos) {
    cout << "Attempted move: " << oldPos->ToString() << " to " << newPos->ToString() << endl;
    if (!IsValidMove(newPos)) {
        cout << "The move is invalid!\n";
        return false;
    }
    cout << "The move is valid!\n";
    currentMap->SetCellOccupant(oldPos->GetX(), oldPos->GetY(), NULL);
	currentMap->SetCellOccupant(newPos->GetX(), newPos->GetY(), a);
    a->SetPosition(newPos);
	return true;
}

bool GameManager::IsValidMove(Vector2* position) {
	return position->GetX() < currentMap->GetColumns()
		&& position->GetY() < currentMap->GetRows()
		&& position->GetX() >= 0 && position->GetY() >= 0
        && currentMap->GetCellOccupant(position) == NULL;
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
Character* GameManager::GetCharacterInMap(int i) {
    if (i >= characters.size() || i < 0) return NULL;
    return characters[i];
}

Enemy* GameManager::GetEnemyInMap(int i) {
    if (i >= enemies.size() || i < 0) return NULL;
    return enemies[i];
}

void GameManager::InitiateCombat(Actor* actor) { 
    cout << "Combat initiated" << endl;

    /*
    
    // make sure the actor in parameter is an enemy
    Enemy* enemy = dynamic_cast<Enemy*>(actor);
    if (enemy == NULL)return;
    cout << "combat started" << endl;
    // rolling initiative and determining turn order
    // int playerInit = Dice::rollDice("1d20+" + characters[0]->GetInitiativeBonus());
    // int enemyInit = Dice::rollDice("1d20+" + enemy->GetInitiativeBonus());
    int playerInit = 20;
    int enemyInit = 1;
    Actor* firstPlayer;
    Actor* secondPlayer;
    if (playerInit > enemyInit) {
        firstPlayer = characters[0];
        secondPlayer = enemy;
    }
    else {
        firstPlayer = enemy;
        secondPlayer = characters[0];
    }
    while (enemy->GetCurrentHitPoints() > 0 && characters[0]->GetCurrentHitPoints() > 0) {
        firstPlayer->GetTurnStrategy()->ExecuteTurn(firstPlayer);
        secondPlayer->GetTurnStrategy()->ExecuteTurn(secondPlayer);
        // MoveFriendlyEnemies()
    }
    if (enemy->GetCurrentHitPoints() <= 0) {
        cout << "Enemy has been defeated! Combat is over. :D" << endl;
    }
    else {
        // TODO should be death saving throws
        cout << "You have been defeated. Game over :(" << endl;
    }

    */
}

void GameManager::LogEvent(const std::string& event) {
    logEntry = event;
    NotifyObservers();
}

void GameManager::NotifyObservers() {
    Notify(logEntry);
}