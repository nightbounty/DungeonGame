#ifndef ARMOR_H
#define ARMOR_H

#include <string>
#include "Item.h"
#include "Character/CharStats.h"
#include <iostream>

/**
 * @class Armor
 * @brief Item and its enhancements
 */
class Armor : public Item {

public:
CharStats charStats; 
    /**
     * Constructor for Armor
     * @param itemName The name of the armor item
     */
    Armor(const std::string &itemName);

    Armor();

    /**
     * Increases the character's stats
     */
    void IncreaseCharStats();

    /**
     * Displays the enhancement types
     */
    void displayEnhancement() override;

    /**
     * @return The Armor itemName String
     */
    std::string toString() const override;

    //check if its a weapon item
    bool isArmor();

};

#endif
