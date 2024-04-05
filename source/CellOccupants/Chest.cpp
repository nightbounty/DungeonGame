#include "CellOccupants/Chest.h"
#include <random>
#include "Character/Character.h"
void Chest::setContents() {
    if (chestLoot.empty()) {
        //If Chest is Empty
        itemLoot = nullptr;
        std::cout << "The Chest Is Empty!" << std::endl;
        return;
    }
    std::random_device rd;
    std::mt19937 eng(rd());
    // Random Num Generator
    std::uniform_int_distribution<> distr(0, 3); // i just set to 3 items for now

    int randomNumber=distr(eng);
    Item* selectedItem = chestLoot[randomNumber];

    // Assuming Item has a getName() method to return its name
    itemLoot = selectedItem;
}

Item* Chest::getContents(){
    return this->itemLoot;
}
/**
 * Method which lets the character acquire the contents of the chest when they land on it.
 * 
 * \param c The character
 */

void Chest::Interact(Character* character) { 
	cout << "You landed on a chest! You acquire " << itemLoot->getName() << endl;
	//c.acquireItems(this.getContents());
    // Place Item Into Inventory
    character->AddToInventory(Chest::getContents());
    
}

string Chest::GetTokenCode(){
	return "C";
}
