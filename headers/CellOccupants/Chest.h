#pragma once
#include "CellOccupant.h"
#include <iostream>
#include <string>
using namespace std;

class Chest : public CellOccupant
{
private:
    string contents; // should later be a list of items

public:
    string getContents();
    void setContents(string contents);
    void Interact();
    string GetTokenCode();
};

