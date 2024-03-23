#ifndef CHARCONTAINER_H
#define CHARCONTAINER_H


#include <vector>

class Item;
class Character;

class CharContainer{
    public:
        std::vector<Item*> items;


        // void equipItem(Item* item);
        virtual void displayCharInventory() const = 0;
};

#endif