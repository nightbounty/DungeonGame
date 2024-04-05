#ifndef RING_H
#define RING_H

#include <iostream>
#include "Character/CharStats.h"
#include <string>
#include "Item.h"

class Ring : public Item
{

public:
    CharStats charStats;

    // Default Constructor
    Ring();

    // Constructor
    Ring(const std::string &itemName);


    // method that increases charStats
    void IncreaseCharStats();

    // display playerStats
    void displayEnhancement() override;

    std::string toString() const override;
};

#endif