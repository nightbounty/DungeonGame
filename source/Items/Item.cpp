#include "Items/Item.h"


    // Constructor
    Item::Item(const std::string &itemName) : itemName(itemName) {
}
    bool Item::isWeapon() {
        return false;
    }
    bool Item::isArmor() {
        return false;
    }
    bool Item::isShield() {
        return false;
    }


