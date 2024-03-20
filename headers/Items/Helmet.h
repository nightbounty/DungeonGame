#ifndef HELMET_H
#define HELMET_H

#include <iostream>
#include "Character/CharStats.h"
#include "Item.h"
#include <string>
class Helmet : public Item
{

public:
    CharStats charStats;
    std::string helmetType;
    /**
     * Constructor for Helmet.
     * @param itemName The name of the helmetItem.
     */
    Helmet(const std::string &itemName);

    // method that increases charStats
    void IncreaseCharStats();

    // display playerStats
    void displayEnhancement() override;

    std::string toString() const override;
};

#endif
