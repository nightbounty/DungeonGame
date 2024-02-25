#ifndef SHIELD_H
#define SHIELD_H

#include <string>
#include "Item.h"
#include "CharStats.h"

class Shield : public Item {
public:
    CharStats charStats;

    // Constructor
    Shield(const std::string &itemName);
    
    // Method that increases charStats
    void IncreaseCharStats();

    // Display playerStats
    void displayEnhancement() override;

    // toString method
    std::string toString() const override;
};

#endif // SHIELD_H