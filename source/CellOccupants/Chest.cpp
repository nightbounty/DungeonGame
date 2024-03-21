#include <CellOccupants/Chest.h>


void Chest::setContents(string contents) {
	this->contents = contents;
}

string Chest::getContents() {
	return this->contents;
}
/**
 * Method which lets the character acquire the contents of the chest when they land on it.
 * 
 * \param c The character
 */
void Chest::Interact() { 
	cout << "You landed on a chest! You acquire its contents." << endl;
	//c.acquireItems(this.getContents());
}

string Chest::GetTokenCode(){
	return "C";
}
