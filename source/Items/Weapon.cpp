#include "Items/Weapon.h"
#include <sstream>

// Constructor
Weapon::Weapon(const std::string &itemName) : Item(itemName) {
}

// IncreaseCharStats method 
void Weapon::IncreaseCharStats() {
    charStats.increaseAttackBonus(5);
    charStats.increaseDamageBonus(4);
}

// displayEnhancement method
void Weapon::displayEnhancement() {
    IncreaseCharStats();
    std::cout << "Attack Bonus: +" << charStats.getAttackBonus() << 
    ", Damage Bonus: +" << charStats.getDamageBonus() << std::endl;
}

// toString method
std::string Weapon::toString() const {
    return "Weapon Name: " + getName();
}