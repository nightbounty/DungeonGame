#include "Boots.h"
#include <sstream>
#include "CharStats.h"

/**
 * @brief Constructor for Boots
 * @param itemName Name of the boots.
 */
Boots::Boots(const std::string &itemName) : Item(itemName)
{
}

/**
 * Method that increases the character's stats.
 */
void Boots::IncreaseCharStats()
{
    charStats.increaseArmorClass(4);
    charStats.increaseDexterity(4);
}

/**
 * Displays the stat enhancements provided by the boots.
 */
void Boots::displayEnhancement()
{
    IncreaseCharStats();
    std::cout << "Armor Class: +" << charStats.getArmorClass() << ",Dexterity: +" << charStats.getDexterity() << std::endl;
}

/**
 * @return Returns Boots Item Name
 */
std::string Boots::toString() const {
    return "Boots Name: " + getName();
}