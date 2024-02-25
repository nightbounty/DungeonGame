#include "Items/Shield.h"
#include <iostream>

// Constructor implementation
Shield::Shield(const std::string &itemName) : Item(itemName) {}

// IncreaseCharStats implementation
void Shield::IncreaseCharStats() {
    charStats.increaseArmorClass(5);
}

// displayEnhancement implementation
void Shield::displayEnhancement() {
    IncreaseCharStats();
    std::cout << "Armor Class: +" << charStats.getArmorClass() << std::endl;
}

// toString implementation
std::string Shield::toString() const {
    return "Shield Name: " + getName();
}