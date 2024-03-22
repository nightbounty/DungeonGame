#include <iostream>
using namespace std;
#include "CellOccupants/Enemy.h"
#include "Strategies/FriendlyStrategy.h"
Enemy::Enemy(string name) { // TODO make enemy a statblock like player
    this->name = name;
    this->SetCurrentHitPoints(10);
    this->SetTotalHitPoints(10);
    this->attackBonus = 2;
    this->damageBonus = 2;
    this->SetInitiativeBonus(2);
    this->armorClass = 10;
    this->currentWeapon = new Weapon("Sword", "1d8+",1);
    this->SetTurnStrategy(new FriendlyStrategy());
}
/**
 * Method in which the player character will battle the enemy.
 * 
 * \param c the character
 */
void Enemy::Attack() {
    if (std::abs(GetCurrentTarget()->GetPositionY() - GetPositionY()) < currentWeapon->GetRange()
        && std::abs(GetCurrentTarget()->GetPositionX() - GetPositionX()) < currentWeapon->GetRange()) {
        int atkRoll = Dice::rollDice("1d20+" + attackBonus);
        if (atkRoll > GetCurrentTarget()->GetArmorClass()) {
            int dmgRoll = Dice::rollDice(currentWeapon->GetDamageDice() + "+" + std::to_string(damageBonus));
            GetCurrentTarget()->TakeDamage(dmgRoll);
        }
        else {
            cout << "Missed the attack! :D" << endl;
        }
    }
    else {
        cout << "Out of range! It can't attack you" << endl;
    }
}

void Enemy::TakeDamage(int dmgTaken)
{
    SetCurrentHitPoints(GetCurrentHitPoints() - dmgTaken);
}

/**
 * Method which will initiate a battle when the player encounters an enemy
 * \param c The character
 */
void Enemy::Interact() {
	Attack();
}

string Enemy::GetTokenCode() {
	return "E";
}

string Enemy::ToString() {
    return name + " Enemy at (" + 
        std::to_string(GetPositionX()) + ", " + 
        std::to_string(GetPositionY()) + ")";
}
