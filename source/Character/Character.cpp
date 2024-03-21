#include "../headers/Character/Character.h"
#include "../headers/Character/CharacterObserver.h"

#include <iostream>
#include <random>
#include <cstdlib> // srand()
#include <ctime>   // For time()
#include <algorithm>
#include <Items/Weapon.h>
#include <Dice.h>

using namespace std;

Character::Character(int lvl, string cls) : level(lvl), characterClass(cls) {
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
        abilityModifiers[i] = (abilityScores[i] / 2) - 5 ;
    }

    /**
     * Initialize other attributes based on ability scores and modifiers
     */
    SetTotalHitPoints(abilityModifiers[2] + 10); // Based on constitution modifier and level
    SetCurrentHitPoints(GetCurrentHitPoints());
    armorClass = abilityModifiers[1] + 10; // Based on dexterity modifier
    attackBonus = level + abilityModifiers[0]; // Based on level and strength/dexterity modifiers
    damageBonus = abilityModifiers[0]; // Based on strength modifier
}
/**
 * Wear an item for a character
 */
void Character::wearItem(string item) {
    cout << characterClass << " is wearing " << item << endl;
}
/**
 * Equip a weapon from the player's weapon selection
 */
void Character::EquipWeapon(Weapon* weapon) {
    this->currentWeapon = weapon;
}
/**
 * Display the Character Stats
 */
void Character::displayStats() {
    cout << "--------------------------------------------------" << endl;
    cout << "Character Info:" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Level: " << level << ", Character Class: " << characterClass << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Ability Scores and Modifiers:" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Strength:  " << abilityScores[0] << " (Modifier: " << abilityModifiers[0] << ")" << endl;
    cout << "Dexterity:  " << abilityScores[1] << " (Modifier: " << abilityModifiers[1] << ")" << endl;
    cout << "Constitution:  " << abilityScores[2] << " (Modifier: " << abilityModifiers[2] << ")" << endl;
    cout << "Intelligence:  " << abilityScores[3] << " (Modifier: " << abilityModifiers[3] << ")" << endl;
    cout << "Wisdom:  " << abilityScores[4] << " (Modifier: " << abilityModifiers[4] << ")" << endl;
    cout << "Charisma:  " << abilityScores[5] << " (Modifier: " << abilityModifiers[5] << ")" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Hidden Stats:" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Hit Points: " << GetTotalHitPoints() << endl;
    cout << "Armor Class: " << armorClass << endl;
    cout << "Attack Bonus: " << attackBonus << endl;
    cout << "Damage Bonus: " << damageBonus << endl;
    cout << "--------------------------------------------------" << endl;

}

void Character::attachObserver(CharacterObserver* observer) {
    observers.push_back(observer);
}

void Character::detachObserver(CharacterObserver* observer) {
    observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
}

void Character::notifyObservers() {
    for (CharacterObserver* observer : observers) {
        observer->update(this);
    }
}


void Character::SetCurrentWeapon(Weapon* weapon) {
    this->currentWeapon = weapon;
}

Weapon* Character::GetCurrentWeapon() {
    return this->currentWeapon;
}

void Character::Attack() {
    if (std::abs(GetCurrentTarget()->GetPositionY() - GetPositionY()) < currentWeapon->GetRange()
        && std::abs(GetCurrentTarget()->GetPositionX() - GetPositionX()) < currentWeapon->GetRange()) {
            int atkRoll = Dice::rollDice("1d20+" + attackBonus);
            if (atkRoll > GetCurrentTarget()->GetArmorClass()) {
                int dmgRoll = Dice::rollDice(currentWeapon->GetDamageDice() + "+" + std::to_string(damageBonus));
                GetCurrentTarget()->TakeDamage(dmgRoll);
            }
            else {
                cout << "Missed the attack! :(" << endl;
            }
    }
    else {
        cout << "Enemy is out of range, sorry!" << endl;
    }
}

void Character::TakeDamage(int damageTaken) {
    SetCurrentHitPoints(GetCurrentHitPoints() - damageTaken);
}

string Character::ToString() {
    return characterClass + " at (" +
        std::to_string(GetPositionX()) + ", " +
        std::to_string(GetPositionY()) + ")";
}
string Character::GetTokenCode() {
    return "P";
}


