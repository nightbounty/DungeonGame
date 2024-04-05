/** Chest only gives 1 loot prize */

#pragma once
#include "CellOccupant.h"
#include <iostream>
#include <string>
#include <vector>
#include "Items/Item.h"
#include "Items/Armor.h"
#include "Items/Shield.h"
#include "Items/Weapon.h"
#include "Items/Ring.h"

using namespace std;

class Chest : public CellOccupant
{
private:
    Item* itemLoot;
    Shield* shieldLoot = new Shield("Medium Shield");
    Weapon* bowLoot = new Weapon("Light Bow", "1d8", 1);
    Armor* armorLoot = new Armor("Medium Armor");
    Ring* ringLoot = new Ring("Basic Ring");
    vector<Item*> chestLoot = { shieldLoot, bowLoot, armorLoot, ringLoot };

public:
    Chest(Vector2* position, string name);
    Item* GetContents();
    void SetContents();
    bool Interact(Character* character);
    string GetTokenCode();
};

