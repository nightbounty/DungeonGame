#include "Items/Armor.h"

Armor::Armor() {}
/**
 * Constructor
 */
Armor::Armor(const std::string &itemName) {
    this->itemName = itemName;
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
 *Returns Armor Name String
 */
std::string Armor::toString() const {
    return "Armor Name: " + getName();
}
