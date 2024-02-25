#include "Armor.h"
#include <iostream>
#include "CharStats.h"

/**
 * Constructor implementation for Armor.
 * Initializes the armor item with a name.
 * @param itemName The name of the armor item.
 */
Armor::Armor(const std::string &itemName) : Item(itemName) {

}

/**
 * Method to increase the Armor Class Stat
 */
void Armor::IncreaseCharStats() {
    charStats.increaseArmorClass(3);
}

/**
 * Displays the increased Enhancement in Armor Class
 */
void Armor::displayEnhancement() {
    IncreaseCharStats();
    std::cout << "Armor Class: +" << charStats.getArmorClass() << std::endl;
}

/**
 * @return Returns Armor Name String
 */
std::string Armor::toString() const {
    return "Armor Name: " + getName();
}