#pragma once
class Character;
#include "Vector2.h"
#include <string>
using namespace std;

class CellOccupant
{
protected:
	Vector2* position;

public: 
	CellOccupant(Vector2* position);
	CellOccupant();
	virtual bool Interact(Character* character);
	virtual string GetTokenCode();

	Vector2* GetPosition();
	int GetPositionX();
	int GetPositionY();
	void SetPosition(Vector2* pos);
};

