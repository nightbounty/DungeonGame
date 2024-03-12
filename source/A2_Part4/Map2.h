// Map header
//Map object

#ifndef MAP2_H
#define MAP2_H

#include <string>
#include "Item.h"
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

};

#endif