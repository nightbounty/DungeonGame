#ifndef SHIELD_H
#define SHIELD_H

#include <string>
#include "Item.h"
#include "Character/CharStats.h"
#include <iostream>

class Shield : public Item {
public:
    CharStats charStats;

    // Default Constructor
    Shield();
    // Constructor
    Shield(const std::string &itemName);
    
    // Method that increases charStats
    void IncreaseCharStats();

    // Display playerStats
    void displayEnhancement() override;

    // toString method
    std::string toString() const override;

    //check if its a weapon item
    bool isShield();
};

#endif
