#pragma once
#include "Character/Character.h"

class CellOccupant
{
public: 
	virtual void Interact(Character* c);
	virtual string GetTokenCode();
};

