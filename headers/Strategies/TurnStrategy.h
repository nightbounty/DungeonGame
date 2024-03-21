#pragma once
#include "../headers/Actor.h"
class TurnStrategy
{
public:
	virtual void ExecuteTurn(Actor* actor) = 0;
};

