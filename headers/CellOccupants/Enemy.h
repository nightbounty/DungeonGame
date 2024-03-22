#pragma once
#include "Actor.h"
class Enemy :
    public Actor
{
private:
    int attackBonus;
    int armorClass;
    int damageBonus;
    Weapon* currentWeapon;
    string name;

public: 
    Enemy(string name);
    void Attack();
    void TakeDamage(int dmgTaken);
    void Interact();
    string GetTokenCode();
    string ToString();
};

