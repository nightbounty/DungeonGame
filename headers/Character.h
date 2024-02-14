#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <array>

using namespace std;

class Character {
public:
    int level;
    string characterClass;
    array<int, 6> abilityScores; // Str, Dex, Con, Int, Wis, Cha
    array<int, 6> abilityModifiers;
    int hitPoints;
    int armorClass;
    int attackBonus;
    int damageBonus;

    Character(int level, string characterClass);

    void displayStats();
    void wearItem(string item);

};

#endif 