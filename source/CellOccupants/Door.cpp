#include <iostream>
#include "CellOccupants/Door.h"
#include "Map.h"

/**
 * Method which will generate a new map when the character reaches a door
 *
 * \param c The character
 */

void Door::Interact(Character* c){
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
    
}