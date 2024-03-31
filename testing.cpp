#include "Character/Character.h"
#include "Items/Weapon.h"
#include "Items/ItemContainer.h"
#include "Items/Armor.h"

int main() {

	// Create a character
	Character* hero = new Character();
	// Create an Item
	Weapon* bow = new Weapon("Bow", "1d8", 5);
	Armor* armor = new Armor();

	// add to inventory
	hero->AddToInventory(bow);
	//diplay inventory
	hero->displayInventory();

	//skip line
	std::cout << "\n";
	//skip line
	std::cout << "\n";

	//take Weapon from Inventory
	Item* takeWeapon = hero->takeItem("Bow");
	// Equip Item to Character
	hero->equipItem(takeWeapon);
	//display Equipped items
	hero->displayEquippedItems();
	//diplay inventory
	hero->displayInventory(); // should have nothing
	hero->DisplayStats(); // Increase the character stats
	hero->unEquipItem(takeWeapon);
	// display Character stats
	hero->DisplayStats();
	hero->displayInventory(); // should have the bow back
	return 0;
}