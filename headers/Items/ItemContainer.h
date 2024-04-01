#ifndef ITEMCONTAINER_H
#define ITEMCONTAINER_H

#include <vector>
#include "Item.h"
#include <iostream>

/**
 * @brief Inventory for Items
 */
class ItemContainer {
    std::vector<Item*> items;

public:
    // Default construtor
    ItemContainer();
    // overloaded constructor
    ItemContainer(const std::vector<Item*>& initialItems) : items(initialItems) {};
    /**
     * Method to add an Item to Container
     * @param item pointer
     */
    void addToContainer(Item* item);

    /**
     * Display all items in the container
     */
    void displayItems() const;

    /**
     * Method to take an Item from Container
     * @param itemName Name of Item
     */
    Item* takeItem(const std::string& itemName);
};

#endif 
