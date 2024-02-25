#include "Items/Belt.h"
#include <iostream>
#include <sstream>
#include "CharStats.h"
/**
 * Constructor
 * @param itemName The name of the belt item.
 */
Belt::Belt(const std::string &itemName) : Item(itemName) {
}

/**
 * Method to increase the Armor Class Stat
 */
void Belt::IncreaseCharStats() {
    charStats.increaseStrength(3);
    charStats.increaseConstitution(3);
}

/**
 * Displays the enhanced stats of the belt
 */
void Belt::displayEnhancement() {
    IncreaseCharStats();
    std::cout << "Constitution: " << charStats.getConstitution() << ", Strength: " << charStats.getStrength() << std::endl;
}

/**
 * @return String displays Belt's name
 */
std::string Belt::toString() const {
    return "Belt Name: " + getName();
}