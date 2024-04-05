#include <iostream>
#include "CellOccupants/Door.h"
#include "Map.h"
#include "GameManager.h"

/**
 * Method which will generate a new map when the character reaches a door
 *
 * \param c The character
 */
bool Door::Interact(Character* character) {
    if (isLocked) {
        cout << "You can't pass through yet. Kill all enemies first!" << endl;
        return false;
    }
    else {
        cout << "You killed all the enemies! Entering a new map now...";
        GameManager::GetInstance()->EnterNewMap();
        return true;
    }
}


string Door::GetTokenCode()
{
    return "D";
}

Door::Door(){
    isLocked = true;
}

void Door::Unlock() {
    isLocked = false;
}

bool Door::IsLocked() {
    return isLocked;
}

void Door::SetConnectedMap(Map* map) {
    this->connectedMap = map;
}
Map* Door::GetConnectedMap() {
    return this->connectedMap;
}

string Door::ToString() {
    return "This door connects to: " + this->connectedMap->GetName() + "\n";
}
