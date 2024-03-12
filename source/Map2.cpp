#include "Map2.h"


//Default constructor
Map2::Map2(){
        setMapLevel(mapLevel);
        std::string worldName;
        std::string worldTier;
        std::vector<Item *> items;
        std::vector<std::string> characters;
        //New
        std::string characterTier = "";
        std::string itemTier = "";
        }

        void Map2::displaySavedMap(){
                std::cout << "Your Saved Map Contains: " << std::endl;
                std::cout << "World Name: " <<  getWorldName() << "\n";
                std::cout << "World Difficulty: " << getWorldTier() << std::endl;
                
                std::cout << "\nItems: " << std::endl;
                for (const auto& item : items) {
                  if (item != nullptr)
               std::cout << item->toString() << std::endl;
                  }
                  std::cout << "\nCharacters: " << std::endl;
                  for (const auto& character : characters) {
               std::cout << character << std::endl;
                  }

        }

        void Map2::displayMapContents(){
                std::cout << "World Difficulty: " <<  getWorldTier() << "\n";
                std::cout << "Item Tier: " <<  getItemTier() << "\n";
                std::cout << "Character Tier: " <<  getCharacterTier() << std::endl;
        }

