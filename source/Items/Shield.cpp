#include "Items/Shield.h"

//Default Constructor
Shield::Shield() {};

// Constructor
Shield::Shield(const std::string &itemName){
    this->itemName = itemName;
}

// IncreaseCharStats
void Shield::IncreaseCharStats() {
    charStats.increaseArmorClass(5);
}

// displayEnhancement
void Shield::displayEnhancement() {
    IncreaseCharStats();
    std::cout << "Armor Class: +" << charStats.getArmorClass() << std::endl;
}

// toString
std::string Shield::toString() const {
    return "Shield Name: " + getName();
}

// Check if Item is a Weapn
bool Shield::isShield() {
    return true;
}