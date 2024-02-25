#pragma once
#include <CellOccupant.h>
#include <iostream>
#include <string>
#include <Map.h>
using namespace std;

class Door :
    public CellOccupant
{
private:
    Map* connectedMap; 

public:
    Door();
    void Interact(Character c);
};
