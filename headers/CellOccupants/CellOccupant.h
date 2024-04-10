#pragma once
class Character;
#include "Vector2.h"
#include <string>
using namespace std;

class CellOccupant
{
protected:
	Vector2* position;
	string name;

public: 
	CellOccupant(Vector2* position, string name);
	CellOccupant();
	virtual bool Interact(Character* character);
	virtual string GetTokenCode();
	virtual string ToString();

	Vector2* GetPosition();
	int GetPositionX();
	int GetPositionY();
	void SetPosition(Vector2* pos);
};

