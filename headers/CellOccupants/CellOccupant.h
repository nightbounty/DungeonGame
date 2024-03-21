#pragma once
class Character;

class CellOccupant
{
public: 
	virtual void Interact();
	virtual string GetTokenCode();
};

