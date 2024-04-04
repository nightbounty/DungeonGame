#include <iostream>
#include "CellOccupants/Door.h"
#include "Map.h"

/**
 * Method which will generate a new map when the character reaches a door
 *
 * \param c The character
 */
void Door::Interact(Character* character) {
    //not sure how u want this
}

void Door::Interact(){
    cout << "Landed on the door! Ready to move to next map." << endl ;
    connectedMap = new Map(4, 5, new Vector2());
    // Set the Game's current map to the door's connected map
    // Game.setMap(this,getConnectedMap()
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
