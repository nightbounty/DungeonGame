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
    bool isLocked;

public:
    Door();
    void Interact();
    string GetTokenCode();
    void SetConnectedMap(Map* map);
    Map* GetConnectedMap();
    void Unlock();
    bool IsLocked();
    string ToString();
};

#endif
