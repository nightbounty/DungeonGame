#include "Items/Weapon.h"

//Default Constructor
Weapon::Weapon() {}
// Constructor
Weapon::Weapon(const std::string &itemName, const std::string &damageDice, int range) {
    this->itemName = itemName;
    this->damageDice = damageDice;
    this->range = range;
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
// Check if Item is a Weapn
bool Weapon::isWeapon() {
    return true;
}

// toString method
std::string Weapon::toString() const {
    return "Weapon Name: " + getName();
}

void Weapon::SetDamageDice(std::string damageDice) {
    this->damageDice = damageDice;
}

std::string Weapon::GetDamageDice() {
    return this->damageDice;
}

int Weapon::GetRange() {
    return this->range;
}
void Weapon::SetRange(int range) {
    this->range = range;
}
