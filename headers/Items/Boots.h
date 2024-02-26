#ifndef BOOTS_H
#define BOOTS_H

#include <iostream>
#include <string>
#include "Item.h"
#include "CharStats.h"

/**
 * @class Boots
 * @brief Boots Item and its methods
 */
class Boots : public Item {
public:
    CharStats charStats;

    /**
     * @brief Boots Constructor
     * @param itemName Name of the boots
     */
    Boots(const std::string &itemName);

    /**
     * Increases the character's stats
     */
    void IncreaseCharStats();

    /**
     * Displays the stat enhancements of the boots
     */
    void displayEnhancement() override;

    /**
     *  Returns Boot's Item Name
     */
    std::string toString() const override;
};

#endif
