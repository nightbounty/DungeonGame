#include <iostream>
#include <CellOccupants/Enemy.h>

/**
 * Method in which the player character will battle the enemy.
 * 
 * \param c the character
 */
void Enemy::Attack() {
	cout << "the battle has begun!" << endl;
}

/**
 * Method which will initiate a battle when the player encounters an enemy
 * \param c The character
 */
void Enemy::Interact(Character c) {
	Attack();
}

string Enemy::GetTokenCode() {
	return "E";
}
