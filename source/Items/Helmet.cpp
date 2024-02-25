#include "Items/Helmet.h"
#include "CharStats.h"

// Constructor
Helmet::Helmet(const std::string &itemName) : Item(itemName) {}

// Method that increases charStats
void Helmet::IncreaseCharStats() {
    charStats.increaseIntelligence(1);
    charStats.increaseWisdom(1);
    charStats.increaseArmorClass(2);
}

// Displays the increased Enhancements
void Helmet::displayEnhancement() {
    IncreaseCharStats();
    std::cout << "Intelligence: +" << charStats.getIntelligence() 
              << ", Wisdom: +" << charStats.getWisdom()
              << ", Armor Class: +" << charStats.getArmorClass() << std::endl;
}

// Returns Helmet Name String
std::string Helmet::toString() const {
    return "Helmet Name: " + getName();
}
