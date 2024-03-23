#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
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
     * Character Constructor
     */

    Character(string name, Vector2* pos, TurnStrategy* ts = NULL, int level = 1, string cls = "", Actor* target = NULL);

    /**
     * Equipping items
     */
    void WearItem(string item);
    void AddToInventory(Item* item); // todo
    void EquipWeapon(Weapon* weapon); // todo make an overload that takes an index for the inventory :3

    /** 
     * Observer management
     */
    void AttachObserver(CharacterObserver* observer);
    void DetachObserver(CharacterObserver* observer);
    void NotifyObservers();

    string ToString();
    string GetTokenCode();
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