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
     * Equipping items
     */
    void wearItem(string item);
    void EquipWeapon(Weapon* weapon); // later this should take an index from the array of weapons
    void AddToInventory(Item* item);
    /** 
     * Observer management
     */
    void attachObserver(CharacterObserver* observer);
    void detachObserver(CharacterObserver* observer);
    void notifyObservers();
    
    /**
     * Attacking and damagina.
     */
 
    void TakeDamage(int damageTaken);
    void Attack();

    void SetCurrentWeapon(Weapon* weapon);
    Weapon* GetCurrentWeapon();
private:
    /**
     * List of observers
     */
    vector<CharacterObserver*> observers;
    Item* inventory; // later should be an array of inventory items
    vector<Weapon*> weapons;
    Weapon* currentWeapon;
};

#endif 