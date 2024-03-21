#pragma once
#ifndef DOOR_H
#define DOOR_H
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
    void Interact();
    string GetTokenCode();
    void SetConnectedMap(Map* map);
    Map* GetConnectedMap();
    string ToString();
};

#endif
