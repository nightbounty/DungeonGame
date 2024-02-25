#pragma once
#include "CellOccupant.h"
class Enemy :
    public CellOccupant
{
private:
    int atkBonus;
    int initiativeBonus;
    // a hit dice object

public: 
    void Battle(Character c);
    void Interact(Character c);
};

