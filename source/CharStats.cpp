#include "CharStats.h"
#include <sstream>

// Constructor
CharStats::CharStats() {
    intelligence = 0;
    wisdom = 0;
    armorClass = 0;
    strength = 0;
    constitution = 0;
    charisma = 0;
    dexterity = 0;
    attackBonus = 0;
    damageBonus = 0;
}

// Methods to increase each enhancement class
void CharStats::increaseIntelligence(int amount) {
    intelligence += amount;
}

void CharStats::increaseWisdom(int amount) {
    wisdom += amount;
}

void CharStats::increaseArmorClass(int amount) {
    armorClass += amount;
}

void CharStats::increaseStrength(int amount) {
    strength += amount;
}

void CharStats::increaseConstitution(int amount) {
    constitution += amount;
}

void CharStats::increaseCharisma(int amount) {
    charisma += amount;
}

void CharStats::increaseAttackBonus(int amount) {
    attackBonus += amount;
}

void CharStats::increaseDexterity(int amount) {
    dexterity += amount;
}

void CharStats::increaseDamageBonus(int amount) {
    damageBonus += amount;
}

// getter methods
int CharStats::getIntelligence() const {
    return intelligence;
}

int CharStats::getWisdom() const {
    return wisdom;
}

int CharStats::getArmorClass() const {
    return armorClass;
}

int CharStats::getStrength() const {
    return strength;
}

int CharStats::getConstitution() const {
    return constitution;
}

int CharStats::getCharisma() const {
    return charisma;
}

int CharStats::getDexterity() const {
    return dexterity;
}

int CharStats::getAttackBonus() const {
    return attackBonus;
}

int CharStats::getDamageBonus() const {
    return damageBonus;
}

// toString method
std::string CharStats::toString() const {
    std::ostringstream oss;
    oss << "Intelligence: " << intelligence << "\n"
        << "Wisdom: " << wisdom << "\n"
        << "Armor Class: " << armorClass << "\n"
        << "Strength: " << strength << "\n"
        << "Constitution: " << constitution << "\n"
        << "Charisma: " << charisma << "\n"
        << "Dexterity: " << dexterity << "\n"
        << "Attack Bonus: " << attackBonus << "\n"
        << "Damage Bonus: " << damageBonus;
    return oss.str();
}
