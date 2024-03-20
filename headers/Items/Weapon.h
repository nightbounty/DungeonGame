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

    // Constructor
    Weapon(const std::string &itemName);

    // Method
    void IncreaseCharStats();
    void displayEnhancement() override;
    std::string toString() const override;
};

#endif