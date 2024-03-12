#include "Item.h"
#include <string>
#ifndef ITEMSUB_H
#define ITEMSUB_H
class ItemSub : public Item {
public:
    ItemSub(const std::string &itemName) : Item(itemName) {}


    // Returns Item Enhancements and Item Name
     void displayEnhancement(){};
     std::string toString() const{
        return getName();
     };
};

#endif
