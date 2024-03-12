#include "Item.h"
#include <string>
class ItemSub : public Item {
public:
    ItemSub(const std::string &itemName) : Item(itemName) {}


    // Returns Item Enhancements and Item Name
     void displayEnhancement(){};
     std::string toString() const{
        return getName();
     };
};