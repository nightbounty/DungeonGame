/** @class Map2 
 * @brief Additional Map features such as
 * World Tier: {"Beginner", "Intermediate", "Hard", "Advance"}
 * Char Tier: {"Tier 1" (lvl 1-4) , "Tier 2" (lvl 5-10), "Tier 3" (11-16), "Tier 4" (17-20)}
 * Item Tier: {"Common", "Uncommon", "Rare", "Very Rare"}
 * Enemy Tier: {"0-2, "1/4 -9", "1/2-17","1-20"}
*/

#ifndef MAP2_H
#define MAP2_H

#include <string>
#include "Items/Item.h"
#include <vector>

class Map2{
    private:
        // attributes of a map
        int mapLevel;
        std::string worldName;
        std::string worldTier;
        std::vector<Item *> items;
        std::vector<std::string> characters;
        //new attributes
        std::string characterTier;
        std::string itemTier;
        std::string enemyTier;
        
    public:
        //Default constructor
        Map2();
        void displaySavedMap();
        void displayMapContents();
        
         // generate getters
         int getMapLevel() const {
        return mapLevel;
    }

    const std::string getWorldName() const {
        return worldName;
    }

    const std::string getWorldTier() const {
        return worldTier;
    }

    const std::vector<Item*> &getItem() const {
        return items;
    }

    const std::vector<std::string> getCharacters() const {
        return characters;
    }
    std::string getCharacterTier() const {
        return characterTier;
    }
    std::string getItemTier() const {
        return itemTier;
    }
    std::string getEnemyTier() const {
        return enemyTier;
    }

    // generate setters
    void setMapLevel(int newMapLevel) {
        mapLevel = newMapLevel;
    }

    void setWorldName(const std::string& newWorldName) {
        worldName = newWorldName;
    }

    void setWorldTier(const std::string& newWorldTier) {
        worldTier = newWorldTier;
    }

    void setItems(const std::vector<Item*>& newItems) {  
    items = newItems; // This line is necessary to actually set the items
    }

    void setCharacters(const std::vector<std::string> newCharacters) {
        characters = newCharacters;
    }
     void setCharacterTier(const std::string& tier) {
        characterTier = tier;
    }
     void setItemTier(const std::string& tier) {
        itemTier = tier;
    }
    void setEnemyTier(const std::string& tier) {
        enemyTier = tier;
    }

};

#endif
