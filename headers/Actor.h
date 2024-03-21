#pragma once
#include "CellOccupants/CellOccupant.h"
#include "Vector2.h"
#include "Strategies/TurnStrategy.h"
class Actor :
    public CellOccupant
{
private:
    Vector2* position;
    TurnStrategy* turnStrategy;
    Actor* currentTarget;

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

    virtual void Attack() = 0;
    virtual void TakeDamage() = 0;
    void MoveTowardTarget();
};

