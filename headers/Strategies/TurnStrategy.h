#pragma once
class Actor;
class TurnStrategy
{
public:
	virtual void ExecuteTurn(Actor* actor) = 0;
};

