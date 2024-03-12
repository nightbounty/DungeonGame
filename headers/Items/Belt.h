#ifndef BELT_H
#define BELT_H

#include <iostream>
#include <string>
#include "CharStats.h"
#include "Item.h"
#include <sstream>


/**
 * @class Belt
 * @brief Belt Item and its methods
 */
class Belt : public Item {
public:
    CharStats charStats; // Initialize charStats variable

    /**
     * Constructor for Belt
     * @param itemName Belt Item Name
     */
    Belt(const std::string &itemName);

    /**
     * Method that increases char Stats
     */
    void IncreaseCharStats();

    /**
     * Displays the Belt's stats
     */
    void displayEnhancement() override;

    /**
     * A string of the Belt's Name
     */
    std::string toString() const override;
};

#endif
