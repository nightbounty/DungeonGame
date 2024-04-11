#ifndef ITEMCREATION_H
#define ITEMCREATION_H
//#include "CellOccupants/Chest.h"
#include "Items/ItemContainer.h"
#include <vector>
#include "Items/Belt.h"
#include "Items/Boots.h"
#include "Items/Helmet.h"
#include "Items/Ring.h"
#include "Items/Shield.h"
#include "Items/Weapon.h"
#include "Items/Armor.h"
#include <fstream>
#include <iostream>

class ItemCreation
{
private:
    // Create Chest loot items
    std::vector<Item*> chestLoot = {
   new Shield("Medium Shield"),
     new Weapon("Light Bow", "1d8", 1),
     new Armor("Medium Armor"),
     new Ring("Basic Ring"),
     new Helmet("Medium Helmet"),
     new Belt("Heavy Belt"),
     new Boots("Light Boot"),
    };
    std::vector<Item*> chestLoot2;
    std::vector<Item*> item;
    //Chest* chest;

public:
    ItemCreation();
      std::vector<Item*> startingChestItems();
    static Item* createItem(const std::string& itemName);
    std::vector<Item*> getChestCreation() {
        return chestLoot;
    }
    std::vector<Item*> getItem() {
        return item;
    }
    void saveChestLootToFile(const std::string& filename);
    void readChestLootFromFile(const std::string& filename);
    std::vector<Item*> readItemsFile(const std::string& filename);
    static std::string toLower(const std::string& str);


};
#endif // ITEMCREATION_H