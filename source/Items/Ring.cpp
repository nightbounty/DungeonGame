#include "Items/Ring.h"
#include <iostream>

// Constructor
Ring::Ring(const std::string &itemName) : Item(itemName) {}

// Method to Increase Ring Stats
void Ring::IncreaseCharStats() {
    charStats.increaseArmorClass(2);
    charStats.increaseStrength(2);
    charStats.increaseConstitution(2);
    charStats.increaseWisdom(2);
    charStats.increaseCharisma(2);
}

// Display playerStats implementation
void Ring::displayEnhancement() {
    IncreaseCharStats();
    std::cout << "Strength: +" << charStats.getStrength() << ", Wisdom: +" << charStats.getWisdom() <<
        ", Armor Class: +" << charStats.getArmorClass()<< ", Constitution: +" << charStats.getConstitution()<< 
        ", Charisma: " << charStats.getCharisma() <<std::endl;
}

// toString implementation
std::string Ring::toString() const {
    return "Ring Name: " + getName();
}