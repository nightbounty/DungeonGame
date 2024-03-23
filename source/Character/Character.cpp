#include "../headers/Character/Character.h"
#include "../headers/Character/CharacterObserver.h"
#include "Strategies/HumanPlayerStrategy.h"

#include <iostream>
#include <random>
#include <cstdlib> // srand()
#include <ctime>   // For time()
#include <algorithm>
#include <Items/Weapon.h>
#include <Dice.h>

using namespace std;

Character::Character(string name, Vector2* pos, TurnStrategy* ts, int lvl, string cls, Actor* target) :
    Actor(name, pos, ts, lvl, cls, target) {
    /**
     * Seed the random number generator
     * It avoids generating the same numbers when running the program
     */
    srand(static_cast<unsigned int>(time(0)));

    /**
     * Initialize ability scores with random numbers between 3 and 18
     */
    for (int i = 0; i < abilityScores.size(); ++i) {
        abilityScores[i] = rand() % 16 + 3; // rand() % 16 will give us a range 0-15 we need to add 3 for 3-18
    }

    /**
     * Initialize ability modifiers based on ability scores
     * Formula from https://d20modern.fandom.com/wiki/Ability#:~:text=The%20modifier%20can%20be%20calculated,modifier%20is%20called%20a%20penalty.
     */
    for (int i = 0; i < abilityModifiers.size(); ++i) {
        abilityModifiers[i] = (abilityScores[i] / 2) - 5;
    }

    /**
     * Initialize other attributes based on ability scores and modifiers
     */
    SetTotalHitPoints(abilityModifiers[2] + 10); // Based on constitution modifier and level
    SetCurrentHitPoints(GetTotalHitPoints());
    armorClass = abilityModifiers[1] + 10; // Based on dexterity modifier
    attackBonus = level + abilityModifiers[0]; // Based on level and strength/dexterity modifiers
    damageBonus = abilityModifiers[0]; // Based on strength modifier
    SetInitiativeBonus(abilityModifiers[1]); // dex
}

/**
 * Wear an item for a character
 */
void Character::WearItem(string item) {
    cout << characterClass << " is wearing " << item << endl;
}


/**
 * Equip a weapon from the player's weapon selection
 */
void Character::EquipWeapon(Weapon* weapon) {
    this->currentWeapon = weapon;
}

void Character::AttachObserver(CharacterObserver* observer) {
    observers.push_back(observer);
}

void Character::DetachObserver(CharacterObserver* observer) {
    observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
}

void Character::NotifyObservers() {
    for (CharacterObserver* observer : observers) {
        observer->update(this);
    }
}

string Character::ToString() {
    return characterClass + " at (" +
        std::to_string(GetPositionX()) + ", " +
        std::to_string(GetPositionY()) + ")";
}
string Character::GetTokenCode() {
    return "P";
}


