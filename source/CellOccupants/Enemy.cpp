#include <iostream>
using namespace std;
#include "CellOccupants/Enemy.h"

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
            cout << "Missed the attack! :(" << endl;
        }
    }
    else {
        cout << "Enemy is out of range, sorry!" << endl;
    }
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
