#include "CellOccupants/Loot.h"
#include "Character/Character.h"

Loot::Loot(Item* item, int gold) {
	this->loot = item;
	this->nbGold = gold;
}

bool Loot::Interact(Character* c) {
    string option;
    // show what loot was acquired
    cout << "You picked up a " << loot->toString() << endl;
    c->AddToInventory(loot);
    // equipping the item if the player wants
    cout << "Would you like to equip it? y or n" << endl;
    cin >> option;
    if (option == "y") {
        c->unEquipItem(c->GetCurrentWeapon());
        c->equipItem(loot);
    }
    c->displayInventory();

    // removing the loot from the map
    GameManager::GetInstance()->currentMap->SetCellOccupant(position->GetX(), position->GetY(), NULL);
    return true;
}

string Loot::GetTokenCode() {
	return "L";
}

Item* Loot::GetItem() {
	return loot;
}

int Loot::GetGold() {
	return nbGold;
}
