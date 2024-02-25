#ifndef HELMET_H
#define HELMET_H

#include <iostream>
#include "CharStats.h"
#include <string>
#include "Item.h"

class Helmet : public Item
{

    // constructor
public:
    CharStats charStats;
    /**
     * Constructor for Helmet.
     * @param itemName The name of the helmetItem.
     */
    Helmet(std::string &itemName);

    // method that increases charStats
    void IncreaseCharStats();

    // display playerStats
    void displayEnhancement() override;

    std::string toString() const override;
};

#endif // HELMET_H