#include "GameManager.h"
#include "Character/Character.h"
#include "CellOccupants/Enemy.h"
#include "CellOccupants/Loot.h"
#include "Strategies/HumanPlayerStrategy.h"
#include <iostream>
#include <algorithm>

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
bool compareInitiative(Actor* a, Actor* b) {
    return a->GetInitiative() > b->GetInitiative();
}

void GameManager::SetCampaign(Campaign* campaign) {
    currentCampaign = campaign;
}
void GameManager::StartCampaign() {
    // TODO character builder goes here 
    currentMap = currentCampaign->Start();
    enemies = currentMap->GetEnemies();
   
    // creating the character and rolling initiative
    character = new Character("Player", new Vector2(0, 0), new HumanPlayerStrategy(), 1, "Fighter");
    currentMap->SetCellOccupant(0, 0, character);
    cout << "Rolling everyone's initiative!" << endl;
    character->RollInitiative();
    // setting the target of the enemies to the player and rolling initiative
    for (int i = 0; i < enemies.size(); i++) {
        enemies[i]->RollInitiative();
        enemies[i]->SetCurrentTarget(character);
        enemies[i]->SetIndex(i);
    }
    // adding everything to initiative order and sorting it
    initiativeOrder.push_back(character);
    initiativeOrder.insert(initiativeOrder.end(), enemies.begin(), enemies.end());
    std::sort(initiativeOrder.begin(), initiativeOrder.end(), compareInitiative);
    cout << "*****************************" << endl;
    cout << "Here is the initiative order!" << endl;
    cout << "*****************************" << endl;
    for (int i = 0; i < initiativeOrder.size(); i++) {
        std::cout << i+1 << ". " << initiativeOrder[i]->ToString() << " with initiative " << initiativeOrder[i]->GetInitiative() << std::endl;
    }
    // GAME LOOP

    bool gameloop = true;
    int turnCounter = 1;

    cout << "STARTING THE GAME...\n" << endl;

    do {
        cout << "= TURN CYCLE " << turnCounter << " =\n" << endl;
        cout << currentMap->ToString() << endl;

        // run through the initiative order
        for (int i = 0; i < initiativeOrder.size(); i++) {
            Enemy* enemy = dynamic_cast<Enemy*>(initiativeOrder[i]);
            if (enemy != NULL) {
                if (enemy->GetCurrentHitPoints() <= 0) {
                    // remove the enemy from the enemy list
                    enemies.erase(enemies.begin() + enemy->GetIndex());
                    // turn the enemy cell into loot
                    currentMap->SetCellOccupant(enemy->GetPositionX(), enemy->GetPositionY(), new Loot(enemy->GetCurrentWeapon(), 10));
                }
            }
            cout << "============================" << endl;
            cout << initiativeOrder[i]->ToString() << endl;
            cout << "HP: " << initiativeOrder[i]->GetCurrentHitPoints() << endl;
            cout << "============================" << endl;
            initiativeOrder[i]->GetTurnStrategy()->ExecuteTurn(initiativeOrder[i]);
            
            cout << currentMap->ToString() << endl;
        }
        if (enemies.size() == 0) {
            currentMap->GetExitDoor()->Unlock();
            cout << "You have killed all the enemies! You can now progress to the next map." << endl;
        }

        if (character->GetCurrentHitPoints() <= 0) {
            cout << "\nCharacter is dead! Gameover :c" << endl;
            //break;
        }

        turnCounter++;
    } while (true);
}

bool GameManager::MoveActor(Actor* a, Vector2* oldPos, Vector2* newPos) {
    
    cout << "Attempted move: " << oldPos->ToString() << " to " << newPos->ToString() << endl;
    if (!IsInBounds(newPos)) {
        cout << "The move is invalid!\n";
        return false;
    }

    CellOccupant* occupant = currentMap->GetCellOccupant(newPos->GetX(), newPos->GetY());
    
    if (occupant != NULL) 
    {
        Character* chara = dynamic_cast<Character*>(a); // todo change to canInteract method?
        if (chara != NULL && occupant->Interact(chara)) 
        {
            cout << chara->ToString() << " interacted with an object.\n";
            return true;
        }

        cout << "There is an obstacle. The move is invalid!\n";
        return false;
    }
    
    cout << "The move is valid!\n";
    
    currentMap->SetCellOccupant(oldPos->GetX(), oldPos->GetY(), NULL);
	currentMap->SetCellOccupant(newPos->GetX(), newPos->GetY(), a);
    a->SetPosition(newPos);
	return true;
}


void GameManager::EnterNewMap() {
    currentMap = currentMap->GetExitDoor()->GetConnectedMap();
    if (currentMap == NULL) {
        cout << "*******************************************" << endl;
        cout << "You finished the campaign, congratulations!" << endl;
        cout << "*******************************************" << endl;
        cout << "Exiting..." << endl;
        exit(0);
    }
    character->SetPosition(new Vector2(0, 0));
}

bool GameManager::IsEmptyCell(Vector2* position) {
	return currentMap->GetCellOccupant(position) == NULL;
}

bool GameManager::IsInBounds(Vector2* position) {
    return position->GetX() < currentMap->GetColumns()
        && position->GetY() < currentMap->GetRows()
        && position->GetX() >= 0 && position->GetY() >= 0;
}

void GameManager::DisplayEnemiesInMap() {
    if (enemies.size() == 0) {
        cout << "No enemies on this map!" << endl;
    }
    else {
        cout << "*********************" << endl;
        cout << "Here are the enemies!" << endl;
        cout << "*********************" << endl;
        for (int i = 0; i < enemies.size(); i++) {
            cout << i << ". " << enemies[i]->ToString() << endl;
        }
    }
}
Character* GameManager::GetCharacterInMap() {  
    return character;
}

Enemy* GameManager::GetEnemyInMap(int i) {
    if (i >= enemies.size() || i < 0) return NULL;
    return enemies[i];
}

void GameManager::LogEvent(const std::string& event) {
    logEntry = event;
    NotifyObservers();
}

void GameManager::NotifyObservers() {
    Notify(logEntry);
}