#ifndef ITEM_H
#define ITEM_H

#include <iostream>

class Item
{
public:
    std::string itemName;
    // Constructor
    Item(const std::string &itemName) : itemName(itemName) {}
    // Destructor
    virtual ~Item() = default;

    // Returns Item Name
    virtual std::string getName() const
    {
        return itemName;
    }

    // Returns Item Enhancements and Item Name
    virtual void displayEnhancement() = 0;
    virtual std::string toString() const = 0;
};

#endif