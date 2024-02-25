#ifndef HELMET_H
#define HELMET_H

#include <iostream>
#include "CharStats.h"
#include <string>
#include "Item.h"

class Helmet : public Item
{

    // constructor
public:
    std::string helmetType;
    CharStats charStats;
    /**
 * Constructor implementation for Helmet.
 * Initializes the armor item with a name.
 * @param itemName The name of the armor item.
 */
    Helmet(const std::string &itemName) : Item(itemName)
    {
    }

    // method that increases charStats
    void IncreaseCharStats()
    {
        charStats.increaseIntelligence(1);
        charStats.increaseWisdom(1);
        charStats.increaseArmorClass(2);
    }

    // Displays the increased Enhancements
    void displayEnhancement() override
    {
        IncreaseCharStats();
        std::cout << "Intelligence: +" << charStats.getIntelligence() << ", Wisdom: +" << charStats.getWisdom() <<
        ", Armor Class: +" << charStats.getArmorClass()<< std::endl;
    }

    /**
    * @return Returns Helmet Name String
    */
    std::string Armor::toString() const {
    return "Helmet Name: " + getName();
}
};

#endif // HELMET_H