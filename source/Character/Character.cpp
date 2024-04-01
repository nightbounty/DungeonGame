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

using namespace std;

    /** equippedItems : body Inventory of 7 Slots that holds Equipped Items
    index0 : Weapon //tested with only Weapon now (like bow)
    Item Inventory (Unlimited)
     Character Backpack Inventory
    */
// Default constructor
Character::Character() {
    this->inventory = inventory;
    this->backpack = backpack;
    equippedItems.assign(7, nullptr);
}

Character::Character(string name, Vector2* pos, TurnStrategy* ts, int lvl, string cls, Actor* target) :
    Actor(name, pos, ts, lvl, cls, target){
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

    equippedItems.assign(7, nullptr); // 7 slots of Body Character Inventory
}

/**
 * Wear an item for a character
 */
void Character::WearItem(string item) {
    cout << characterClass << " is wearing " << item << endl;
}

//Equip an Item
void Character::equipItem(Item* item) {
    if (item->isWeapon()) {
        Weapon* weapon = dynamic_cast<Weapon*>(item);
        equippedItems[0] = weapon;
        weapon->IncreaseCharStats();
        attackBonus += weapon->charStats.getAttackBonus();
        damageBonus += weapon->charStats.getDamageBonus();
    }
    cout << "Equipped Item to Character \n";
}

// Unequip an Item
bool Character::unEquipItem(Item* item) {
        auto i = std::find(equippedItems.begin(), equippedItems.end(), item);
    if (i != equippedItems.end()) {
        if (item->isWeapon()) {
            Weapon* weapon = dynamic_cast<Weapon*>(item);
            inventory.addToContainer(item); // Re-add Item to Inventory 
            equippedItems.erase(i);
            std::cout << "\n Removed item from Character's Slot inventory: " << item->getName() << "\n";
            attackBonus -= weapon->charStats.getAttackBonus();
            damageBonus -= weapon->charStats.getDamageBonus();
            return true;
        }
    }
    return false;
}

// Add item to inventory
void Character::AddToInventory(Item* item) {
    inventory.addToContainer(item);
}

// Take Item out of Inventory
Item* Character::takeItem(const std::string& itemName) {
    return inventory.takeItem(itemName);
}

// display Inventory
void Character::displayInventory() {
    inventory.displayItems();
}

// Display Equipped Items
void Character::displayEquippedItems() {
    cout << "Equipped Items \n";
    for (const auto* itemInside : equippedItems) {
        if (itemInside != nullptr) {
            // If the item pointer is not null, display its name.
            std::cout << itemInside->getName() << std::endl;
        }
        else {
            // If the item pointer is null, indicate the slot is empty.
            std::cout << "empty slot" << std::endl;
        }
    }
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


//itemcontainer character::getinventory() {
//    return inventory;
//}