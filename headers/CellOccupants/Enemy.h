#pragma once
#include "CellOccupant.h"
class Enemy :
    public Actor
{
private:
    int atkBonus;
    int initiativeBonus;
    // a hit dice object

public: 
    void Attack();
    void TakeDamage();
    void Interact(Character c);
    string GetTokenCode();
};

