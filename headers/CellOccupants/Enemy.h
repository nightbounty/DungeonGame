#pragma once
#include "Actor.h"
class Enemy :
    public Actor
{
private:
    int attackBonus;
    int initiativeBonus;
    int armorClass;
    int damageBonus;
    Weapon* currentWeapon;

public: 
    void Attack();
    void TakeDamage(int dmgTaken);
    void Interact();
    string GetTokenCode();
};

