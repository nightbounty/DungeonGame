#include "Items/ItemContainer.h"

/**
 * Add item to Container
 * @param item Pointer to the item to add
 */
void ItemContainer::addToContainer(Item* item) {
    items.push_back(item);
}

/**
 *Display all items in the container.
 */
void ItemContainer::displayItems() const {
    std::cout << "Items inside container: " << std::endl;
    for (const auto& item : items) {
        std::cout << item->getName() << std::endl;
    }
}

/**
 * Method to take an existing item from Container
 * @param itemName Name of the item to take.
 */
Item* ItemContainer::takeItem(const std::string& itemName) {
    for (auto i = items.begin(); i != items.end(); ++i) {
        if ((*i)->getName() == itemName) {
            Item* item = *i;
            items.erase(i);
            return item;
        }
    }
    return nullptr;
}