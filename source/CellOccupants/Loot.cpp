#include "CellOccupants/Loot.h"

Loot::Loot(Item* item, int gold) {
	this->loot = item;
	this->nbGold = gold;
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
