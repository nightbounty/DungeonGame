#pragma once
#include "CellOccupant.h"
#include "Items/Item.h"
class Loot :
    public CellOccupant
{
private:
    Item* loot;
    int nbGold;
public:
    Loot(Item* loot, int nbGold);
    string GetTokenCode();
    Item* GetItem();
    int GetGold();
    
};

