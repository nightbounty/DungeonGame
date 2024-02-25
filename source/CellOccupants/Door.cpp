#include <Door.h>
void Door::Interact(Character c){
    // Set the Game's current map to the door's connected map
    // Game.setMap(this,getConnectedMap()
}

Door::Door(){
    connectedMap = new Map(4,5,new Vector2());
}
