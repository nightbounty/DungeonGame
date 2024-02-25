#pragma once
#include <iostream>
#include <string>
#include "CellOccupant.h"
#include "Vector2.h"
class Map;

using namespace std;

class Door : public CellOccupant
{
private:
    Map* connectedMap;

public:
    Door();
    void Interact(Character* c);
    string GetTokenCode();
};
