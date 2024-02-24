#include <Chest.h>


void Chest::setContents(string contents) {
	this->contents = contents;
}

string Chest::getContents() {
	return this->contents;
}

void CellOccupant::Interact(Character c) { // should this be celloccupant:: or chest::? 
	//c.acquireItems(this.getContents());
}