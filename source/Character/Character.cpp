#include "../headers/Character/Character.h"
#include "../headers/Character/CharacterObserver.h"
#include "Strategies/HumanPlayerStrategy.h"

#include <iostream>
#include <random>
#include <cstdlib> // srand()
#include <ctime>   // For time()
#include <algorithm>
#include "../../headers/Items/Weapon.h"
#include "../../headers/Dice.h"
#include "Character/CharContainer.h"
#include "Items/ItemContainer.h"

using namespace std;

Character::Character(string name, Vector2* pos, TurnStrategy* ts, int lvl, string cls, Actor* target) :
    Actor(name, pos, ts, lvl, cls, target) {
    /**
     * Seed the random number generator
     * It avoids generating the same numbers when running the program
     */
    srand(static_cast<unsigned int>(time(0)));

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

 void Character::equipItem(Item* item){
   //    equippedItems.push_back(item);
   // cout << "Equipped Item to Character\n";
}

void Character::displayCharInventory() const{
    std::cout << "Character Inventory:" << '\n';
      for (const auto* itemInside : equippedItems) {
       std::cout << itemInside->getName();
        }
}


/** Remove an Item */
bool Character::removeItem(Item* item) {
        auto i = std::find(equippedItems.begin(), equippedItems.end(), item);
        if (i != equippedItems.end()) {
            equippedItems.erase(i);
            std::cout << "\n Removed item from Character's inventory: " << item->getName() << "\n";
            return true;
        }
        return false;
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

string Character::ToString() {
    return characterClass + " at (" +
        std::to_string(GetPositionX()) + ", " +
        std::to_string(GetPositionY()) + ")";
}
string Character::GetTokenCode() {
    return "P";
}

void Character::LogEvent(const std::string& event) {
    logEntry = event;
    NotifyObservers();
}

void Character::NotifyObservers() {
    Notify(logEntry);
}


