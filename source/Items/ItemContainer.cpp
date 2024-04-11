#include "Items/ItemContainer.h"
#include "Items/Weapon.h"

// Default construtor
ItemContainer::ItemContainer() {
}
ItemContainer::ItemContainer(const std::vector<Item*>& initialItems) : items(initialItems) {};

/**
 * Add item to Container
 * @param item Pointer to the item to add
 */
void ItemContainer::addToContainer(Item* item) {
    items.push_back(item);
}

//Container to save body items to save later in game file
void ItemContainer::saveToBody(Item* item) {
    items.push_back(item);
}

void ItemContainer::addToContainerStart(std::vector<Item*>& initialItems) {
    for (Item* item : initialItems) {
        items.push_back(item);
    }
}



/**
 *Display all items in the container.
 */
void ItemContainer::displayItems() const {
  //  std::cout << "Items inside Inventory: " << std::endl;
    for (const auto& item : items) {
        std::cout << item->getName() << "\n" << std::endl;
    }
}

void ItemContainer::displayBodyContainer() const {
    //  std::cout << "Items inside Inventory: " << std::endl;
    for (const auto& item : items) {
        std::cout << item->getName() << "\n" << std::endl;
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

void ItemContainer::deleteItem(Item* removeItem) {
    auto i = std::remove(items.begin(), items.end(), removeItem);
    items.erase(i, items.end());
}

void ItemContainer::saveCharInventoryToFile() {
    std::ofstream file("CharInventoryItems.txt");

    if (file.is_open()) {
        for (Item* item : items) {
            if (item) {
                file << item->getName() << std::endl;
            }
        }
        file.close();
    }
    else 
        std::cerr << "Unable to open file for writing." << std::endl;

}

void ItemContainer::saveCharBodyItemsToFile() {
    std::ofstream file("CharBodyItems.txt");

    if (file.is_open()) {
        for (Item* item : items) {
            if (item) {
                file << item->getName() << std::endl;
            }
        }
        file.close();
    }
    else
        std::cerr << "Unable to open file for writing." << std::endl;

}