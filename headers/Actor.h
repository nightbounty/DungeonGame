#pragma once
#ifndef ACTOR_H
#define ACTOR_H
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
private:
    Vector2* position;
    TurnStrategy* turnStrategy;
    Actor* currentTarget;
    int totalHitPoints;
    int currentHitPoints;
    Weapon* currentWeapon;
    int armorClass;

public:
    Actor();
    Actor(Vector2* pos, TurnStrategy* ts, Actor* target);

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


    virtual void Attack()=0;
    virtual void TakeDamage(int dmgRoll) = 0;
    void MoveTowardTarget();
    virtual string ToString() = 0;
};

#endif