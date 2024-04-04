#pragma once
class Character;
#include <string>
using namespace std;

class CellOccupant
{
public: 
	virtual void Interact();
	virtual void Interact(Character* character);
	virtual string GetTokenCode();
};

