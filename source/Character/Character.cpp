#include "../headers/Character/Character.h"
#include "../headers/Character/CharacterObserver.h"
#include "Strategies/HumanPlayerStrategy.h"

#include <iostream>
#include <random>
#include <cstdlib> // srand()
#include <ctime>   // For time()
#include <algorithm>
#include "../../headers/Items/Weapon.h"
#include "../../headers/Items/Armor.h"
#include "../../headers/Items/Shield.h"
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
    Actor(name, pos, ts, lvl, cls, target) {
    /**
     * Ability Scores
     */

     // generate Score that will help us determine ability scores later
    std::array<int, 6> scores;

    for (int& score : scores) {
        std::vector<int> rolls(4);

        // Simulate rolling 4d6 four times
        for (int i = 0; i < 4; ++i) {
            rolls[i] = Dice::rollDice("1d6"); // Roll a single d6
        }

        // Sort rolls to pick the top three
        std::sort(rolls.begin(), rolls.end(), std::greater<int>());

        // Sum the top three rolls for this ability score
        score = rolls[0] + rolls[1] + rolls[2];
    }
    // Attribute Ability scores depending on classes
    std::sort(scores.begin(), scores.end(), std::greater<int>());

    if (cls == "Bully") {
        // Bully: Strength, Constitution, Dexterity, Intelligence, Charisma, Wisdom
        abilityScores[0] = scores[0]; // Highest score to Strength
        abilityScores[2] = scores[1]; // Next highest to Constitution
        abilityScores[1] = scores[2]; // Dexterity
        abilityScores[3] = scores[3]; // Intelligence
        abilityScores[5] = scores[4]; // Charisma
        abilityScores[4] = scores[5]; // Lowest score to Wisdom
    }
    else if (cls == "Nimble") {
        // Nimble: Dexterity, Constitution, Strength, Intelligence, Charisma, Wisdom
        abilityScores[1] = scores[0]; // Dexterity gets the highest score
        abilityScores[2] = scores[1]; // Constitution
        abilityScores[0] = scores[2]; // Strength
        abilityScores[3] = scores[3]; // Intelligence
        abilityScores[5] = scores[4]; // Charisma
        abilityScores[4] = scores[5]; // Wisdom
    }
    else if (cls == "Tank") {
        // Tank: Constitution, Dexterity, Strength, Intelligence, Charisma, Wisdom
        abilityScores[2] = scores[0]; // Constitution gets the highest score
        abilityScores[1] = scores[1]; // Dexterity
        abilityScores[0] = scores[2]; // Strength
        abilityScores[3] = scores[3]; // Intelligence
        abilityScores[5] = scores[4]; // Charisma
        abilityScores[4] = scores[5]; // Wisdom
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
     if (item->isArmor()) {
        Armor* armor = dynamic_cast<Armor*>(item);
        equippedItems[1] = armor;
        armor->IncreaseCharStats();
        armorClass += armor->charStats.getArmorClass();
    }
     if (item->isShield()) {
        Shield* shield = dynamic_cast<Shield*>(item);
        equippedItems[2] = shield;
        shield->IncreaseCharStats();
        armorClass += shield->charStats.getArmorClass();
    }

    cout << "Equipped " << item->getName() << " to Character \n";
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
    cout << "Items Inside Inventory: \n";
    inventory.displayItems();
}

// Display Equipped Items
void Character::displayEquippedItems() {
    cout << " Character's Current Equipped Items: \n";
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