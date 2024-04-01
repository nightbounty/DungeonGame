#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include "Character/CharStats.h" 
#include "Item.h" 
#include <sstream>

class Weapon : public Item
{
public:
    CharStats charStats;

    // Default constructor
    Weapon();

    // Constructor
    Weapon(const std::string &itemName, const std::string& , int range);

    // Method
    void IncreaseCharStats();
    void displayEnhancement() override;
    std::string toString() const override;
    void SetDamageDice(std::string damageDice);
    std::string GetDamageDice();
    int GetRange();
    void SetRange(int range);
    //check if its a weapon item
    bool isWeapon();
private:
    std::string damageDice;
    int range;
    
};

#endif