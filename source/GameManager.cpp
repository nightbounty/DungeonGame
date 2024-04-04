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

    std::cout << "Would you like to use a pre-generated character or create a character?\n";
    std::cout << "Press 1 to load, or 2 to create:";
    int loadOrCreate;
    std::cin >> loadOrCreate;

    switch (loadOrCreate) {
    case 1:
        std::cout << "Here are a set of character that you can choose:\n";
        std::cout << "1. Brick Malone, The Bully: Brick, with his intimidating presence, rules the back alleys, using brute force to get his way.\n";
        std::cout << "2. Lila Vale, The Nimble: Silent and swift, Lila strikes from the shadows, always one step ahead.\n";
        std::cout << "3. Garrick Thorvald, The Tank: An armored fortress, Garrick stands tall, unfazed by the chaos of battle.\n";
        std::cout << "Which one would you like to use? (1-3)\n";
        int choice;
        std::cin >> choice;
        switch (choice) {
        case 1:
            character = new Character("Brick Malone", new Vector2(0, 0), new HumanPlayerStrategy(), 3, "Bully");
            break;
        case 2:
            character = new Character("Lila Vale", new Vector2(0, 0), new HumanPlayerStrategy(), 3, "Nimble");
            break;
        case 3:
            character = new Character("Garrick Thorvald", new Vector2(0, 0), new HumanPlayerStrategy(), 3, "Tank");
            break;
        }
        std::cout << "\nHere is your selected character:\n";
        character->DisplayStats();
        break;
    case 2:
        std::string name;
        std::string cls;
        int classChoice;
        int lvl = 1; // Starting level, adjust as needed

        std::cout << "Let's create your character for the game!\n\n";
        std::cout << "Enter character's name: ";
        std::cin >> name;
        std::cout << "\nChoose a class:\n";
        std::cout << "1. Bully\n";
        std::cout << "2. Nimble\n";
        std::cout << "3. Tank\n";
        std::cout << "Enter choice (1-3): ";
        std::cin >> classChoice;

        switch (classChoice) {
        case 1:
            cls = "Bully";
            break;
        case 2:
            cls = "Nimble";
            break;
        case 3:
            cls = "Tank";
            break;
        default:
            std::cout << "Invalid choice. Defaulting to Bully.\n";
            cls = "Bully";
        }
        character = new Character(name, new Vector2(0, 0), new HumanPlayerStrategy(), lvl, cls);
        std::cout << "\nCharacter Creation COMPLETED!\n";
        character->DisplayStats();
        break;

    }
    std::cout << "\nWhat weapon would you like to start with?\n";
    std::cout << "Press 1 for a bow, or 2 for a sword:";
    int weaponChoice;
    std::cin >> weaponChoice;
    switch (weaponChoice) {
    case 1:
    {
        Weapon* bow = new Weapon("Bow", "1d8", 5);
        character->AddToInventory(bow);
        Item* takeBow = character->takeItem("Bow");
        character->equipItem(takeBow);
        character->displayEquippedItems();
        break;
    }
    case 2:
    {
        Weapon* sword = new Weapon("Sword", "1d12", 2);
        character->AddToInventory(sword);
        Item* takeSword = character->takeItem("Sword");
        character->equipItem(takeSword);
        character->displayEquippedItems();
        break;
    }
    }
    std::cout << "\nYou have sucessfully equipped your weapon!\n";
    
    currentMap = currentCampaign->Start();
    enemies = currentMap->GetEnemies();
   
    // creating the rolling initiative
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
    if (!IsValidMove(newPos)) {
        CellOccupant* occupant = currentMap->GetCellOccupant(newPos->GetX(), newPos->GetY());
        Character* chara = dynamic_cast<Character*>(a);
        Door* door = dynamic_cast<Door*>(occupant);
        if (door != NULL && chara != NULL) {
            if (door->IsLocked()) {
                cout << "You can't pass through yet. Kill all enemies first!" << endl;
                return false;
            }
            else {
                cout << "You killed all the enemies! Entering a new map now...";
                EnterNewMap();
                return true;
            }
        }
        Loot* loot = dynamic_cast<Loot*>(occupant);
        if (loot != NULL && chara != NULL) {
            string option;
            // show what loot was acquired
            cout << "You picked up a " << loot->GetItem()->toString() << endl;
            character->AddToInventory(loot->GetItem());
            // equipping the item if the player wants
            cout << "Would you like to equip it? y or n" << endl;
            cin >> option;
            if (option == "y") {
                character->unEquipItem(character->GetCurrentWeapon());
                character->equipItem(loot->GetItem());
            }
            character->displayInventory();
            // removing the loot from the map
            currentMap->SetCellOccupant(newPos->GetX(), newPos->GetY(), NULL);
        }
       
        cout << "The move is invalid!\n";
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