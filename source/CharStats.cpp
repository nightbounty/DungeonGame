#ifndef CHARSTATS_H
#define CHARSTATS_H
#include <string>
#include <sstream>

//
class CharStats
{
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

    // constructor
public:
    CharStats()
    {
        intelligence = 0;
        wisdom = 0;
        armorClass = 0;
        strength = 0;
        constitution = 0;
        wisdom = 0;
        charisma = 0;
        dexterity = 0;
        attackBonus = 0;
        damageBonus = 0;
    }

    // methods
public:
    void increaseIntelligence(int amount)
    {
        intelligence += amount;
    }

    void increaseWisdom(int amount)
    {
        wisdom += amount;
    }

    void increaseArmorClass(int amount)
    {
        armorClass += amount;
    }

    void increaseStrength(int amount)
    {
        strength += amount;
    }

    void increaseConstitution(int amount)
    {
        constitution += amount;
    }

    void increaseCharisma(int amount)
    {
        charisma += amount;
    }

    void increaseAttackBonus(int amount)
    {
        attackBonus += amount;
    }

    void increaseDexterity(int amount)
    {
        dexterity += amount;
    }

    void increaseDamageBonus(int amount)
    {
        damageBonus += amount;
    }

    // getters
    int getIntelligence() const { return intelligence; }
    int getWisdom() const { return wisdom; }
    int getArmorClass() const { return armorClass; }
    int getStrength() const { return strength; }
    int getConstitution() const { return constitution; }
    int getCharisma() const { return charisma; }
    int getDexterity() const { return dexterity; }
    int getAttackBonus() const { return attackBonus; }
    int getDamageBonus() const { return damageBonus; }

    // toString method
    std::string toString() const
    {
        std::ostringstream oss;
        oss << "Intelligence: " << intelligence << "\n"
            << "Wisdom: " << wisdom << "\n"
            << "Armor Class: " << armorClass << "\n"
            << "Strength: " << strength << "\n"
            << "Constitution: " << constitution << "\n"
            << "Wisdom: " << wisdom << "\n"
            << "Charisma: " << charisma << "\n"
            << "Attack Bonus: "
            << attackBonus << "\nDexterity: " << dexterity;

        return oss.str();
    }
};

#endif // CHARSTATS_H