#pragma once
#ifndef ACTOR_H
#define ACTOR_H

#include <array>

#include "CellOccupants/CellOccupant.h"
#include "Vector2.h"
#include "Strategies/TurnStrategy.h"
#include "GameManager.h"
#include "Items/Weapon.h"
#include "Dice.h"
using namespace std;
class Actor :
    public CellOccupant
{
protected:

    /**
     * Character Stats
     */
    string name;
    int level;
    string characterClass;
    array<int, 6> abilityScores; // Str, Dex, Con, Int, Wis, Cha
    array<int, 6> abilityModifiers;
    int armorClass;
    int attackBonus;
    int damageBonus;

    Vector2* position;
    TurnStrategy* turnStrategy;
    Actor* currentTarget;
    int totalHitPoints;
    int currentHitPoints;
    Weapon* currentWeapon;
    int initiativeBonus;
    int initiativeScore;

public:

    Actor();
    Actor(string name, Vector2* pos, TurnStrategy* ts = NULL, int lvl = 1, string cls = "", Actor* target = NULL);

    /**
     * Display the Character Stats
     */

    void DisplayStats();

    Vector2* GetPosition();
    int GetPositionX();
    int GetPositionY();
    void SetPosition(Vector2* pos);

    TurnStrategy* GetTurnStrategy();
    void SetTurnStrategy(TurnStrategy* ts);
    
    Actor* GetCurrentTarget();
    void SetCurrentTarget(Actor* target);

    void SetTotalHitPoints(int hitPoints);
    int GetTotalHitPoints();

    int GetCurrentHitPoints();
    void SetCurrentHitPoints(int hitPoints);

    int GetArmorClass();

    int GetInitiativeBonus();
    void SetInitiativeBonus(int bonus);
    void RollInitiative();
    void SetCurrentWeapon(Weapon* weapon);
    Weapon* GetCurrentWeapon();

    /**
     * Attackina and damagina.
     */
    virtual void Attack();
    virtual void TakeDamage(int dmgRoll);

    void MoveTowardTarget();
    void MoveActorFromInput();
    virtual string ToString() = 0;
};

#endif