#include <iostream>
using namespace std;
#include "CellOccupants/Enemy.h"
#include "Strategies/TurnStrategy.h"
#include "Strategies/FriendlyStrategy.h"
#include "Strategies/AggressorStrategy.h"

Enemy::Enemy(string name, Vector2* pos, TurnStrategy* ts, int lvl, string cls, Actor* target) :
    Actor(name, pos, ts, lvl, cls, target) {
    this->name = name;
    this->SetCurrentHitPoints(2);
    this->SetTotalHitPoints(2);
    this->attackBonus = 2;
    this->damageBonus = 0;
    this->SetInitiativeBonus(2);
    this->armorClass = 10;
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

void Enemy::SetIndex(int index) {
    this->index = index;
}
int Enemy::GetIndex() {
    return this->index;
}
