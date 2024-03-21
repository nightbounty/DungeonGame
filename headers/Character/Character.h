#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <array>
#include <vector>
#include "Actor.h"


class CharacterObserver;

using namespace std;

/**
 * Class Character
 * Class that allow the generation of player characters following the d20 game rules
 */

class Character : public Actor{
public:

    /**
     * Character Stats
     */
    int level;
    string characterClass;
    array<int, 6> abilityScores; // Str, Dex, Con, Int, Wis, Cha
    array<int, 6> abilityModifiers;
    int hitPoints;
    int armorClass;
    int attackBonus;
    int damageBonus;

    /**
     * Character Constructor
     */

    Character(int level, string characterClass);
    
    /**
     * Display the Character Stats
     */

    void displayStats();

    /**
     * Wear an item and display it
     */
    void wearItem(string item);

    /** 
     * Observer management
     */
    void attachObserver(CharacterObserver* observer);
    void detachObserver(CharacterObserver* observer);
    void notifyObservers();

    /**
     * Attacking and damagina.
     */
    void Attack();
    void TakeDamage();

private:
    /**
     * List of observers
     */
    vector<CharacterObserver*> observers;
};

#endif 