#ifndef ITEMCONTAINER_H
#define ITEMCONTAINER_H

#include <vector>
#include "Item.h"
#include <iostream>
#include <fstream>
#include "../ItemCreation.h"
// Global items var to keep track of all items used in game
//extern std::vector<Item*> allItems;
////Global var to keep track of equipped body items
//extern std::vector<Item*> bodyItems;
/**
 * @brief Inventory for Items
 */
class ItemContainer{
    std::vector<Item*> items;

public:
    // Default construtor
    ItemContainer();
    // overloaded constructor
    ItemContainer(const std::vector<Item*>& initialItems);
    /**
     * Method to add an Item to Container
     * @param item pointer
     */
    void addToContainer(Item* item);

    // save items equipped to Character body
    void saveToBody(Item* item);

    /**
     * Display all items in the container
     */
    void displayItems() const;

    void displayBodyContainer() const;

    /**
     * Method to take an Item from Container
     * @param itemName Name of Item
     */
    Item* takeItem(const std::string& itemName);
    
    // remove item from container
    void deleteItem(Item* removeItem);

    void addToContainerStart(std::vector<Item*>& initialItems);
    void saveCharInventoryToFile();
    void saveCharBodyItemsToFile();

};

#endif 
