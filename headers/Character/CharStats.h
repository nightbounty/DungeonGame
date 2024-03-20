#ifndef CHARSTATS_H
#define CHARSTATS_H
#include <string>

class CharStats {
private:
    int intelligence;
    int wisdom;
    int armorClass;
    int strength;
    int constitution;
    int charisma;
    int dexterity;
    int attackBonus;
    int damageBonus;

public:
    // Constructor
    CharStats();

    // Methods to Increase the Char's Strength Through The Item
    void increaseIntelligence(int amount);
    void increaseWisdom(int amount);
    void increaseArmorClass(int amount);
    void increaseStrength(int amount);
    void increaseConstitution(int amount);
    void increaseCharisma(int amount);
    void increaseAttackBonus(int amount);
    void increaseDexterity(int amount);
    void increaseDamageBonus(int amount);

    // Returns the Int of Each Enhancement class
    int getIntelligence() const;
    int getWisdom() const;
    int getArmorClass() const;
    int getStrength() const;
    int getConstitution() const;
    int getCharisma() const;
    int getDexterity() const;
    int getAttackBonus() const;
    int getDamageBonus() const;

    std::string toString() const;
};

#endif
