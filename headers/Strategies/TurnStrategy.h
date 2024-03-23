#pragma once
#include <string>
using namespace std;
class Actor;
class TurnStrategy
{
public:
	virtual void ExecuteTurn(Actor* actor) = 0;
	virtual string ToString() = 0;
};

