
#include "MapBuilder.h"

// empty constructor
MapBuilder::MapBuilder() {
}
     // Create a Map Object
     Map map;

        void MapBuilder::readFile(const std::string &fileName){
            std::ifstream file(fileName); //reads file and creates an instance of ifstream
            if(!file.is_open()){
               std::cout << "File can't open" << std::endl;
               return;
            }
            std::string fileLine;
            while(std::getline(file, fileLine)){
               mapFileCopy.push_back(fileLine);
            }
        }

         int MapBuilder::importMapLevel(){
            for(std::string line : mapFileCopy){
               if(line.find("Map Level:") == 0){
                  std::string stringMapLvl = line.substr(10);
                  int tempMapLevel = std::stoi(stringMapLvl); //stoi: convert to an int
                  return tempMapLevel;
               }
            }
            return -1;
            // std::cout << "testing to reach here" << std::endl;
         }

         bool MapBuilder::isMapSaved(){
            for(std::string line : mapFileCopy){
               if(line.find("Saved") == 0){
                  return true;
               }
            }
            return false;
         }

          std::string MapBuilder::importWorldName(){
            for(std::string line : mapFileCopy){
               if(line.find("World Name:") == 0){
                  std::string worldName = line.substr(12);
                  return worldName;
               }
            
            }
             return "Nothing";
         }
          std::string MapBuilder::importWorldTier(){
            for(std::string line : mapFileCopy){
               if(line.find("World Tier:") == 0){
                  std::string terrain = line.substr(12);
                  return terrain;
               }
            }
            return "Nothing";
         }
         std::vector<Item*>& MapBuilder::importItems(){
            for(std::string line : mapFileCopy){
               if(line.find("Item:") == 0){
                  std::string item = line.substr(6);
                  ItemSub* itemObject = new ItemSub(item);
                  tempItems.push_back(itemObject);
               }
            }
            return tempItems;
         }

         std::vector<std::string> MapBuilder::importCharacters(){
            for(std::string line : mapFileCopy){
               if(line.find("Character:") == 0){
                  std::string character = line.substr(11);
                  tempChars.push_back(character);
               }
            }
            return tempChars;
         }

         void MapBuilder::createMap(){
            if (isMapSaved()){
               map.setMapLevel(importMapLevel());
               map.setWorldName(importWorldName());
               map.setWorldTier(importWorldTier());
               
               tempChars = importCharacters();
               map.setCharacters(tempChars);
               
               tempItems = importItems();
               map.setItems(tempItems);

               // Display Saved Contents of Map
               map.displaySavedMap();
                 
            }
               
         }

         // addiotional features of the Map
         void MapBuilder::tier1map() {
             map.setWorldTier(importWorldTier());
             map.setCharacterTier("Tier 1");
             map.setItemTier("Common");
             map.setEnemyTier("0-2");
             map.displayMapContents();
         }

         void MapBuilder::tier2map() {
             map.setWorldTier(importWorldTier());
             map.setCharacterTier("Tier 2");
             map.setItemTier("Uncommon");
             map.setEnemyTier("1/4-9");
             map.displayMapContents();
         }

         void MapBuilder::tier3map() {
             map.setWorldTier(importWorldTier());
             map.setCharacterTier("Tier 3");
             map.setItemTier("Rare");
             map.setEnemyTier("1/2-17");
             map.displayMapContents();
         }

         void MapBuilder::tier4map() {
             map.setWorldTier(importWorldTier());
             map.setCharacterTier("Tier 4");
             map.setItemTier("Very Rare");
             map.setEnemyTier("1-20");
             map.displayMapContents();
         }

         void MapBuilder::createMapContents() {
             {
                 std::cout << map.getWorldTier() << std::endl;
                 if (importWorldTier() == "Beginner") {
                     tier1map();
                 }
                 if (importWorldTier() == "Intermediate") {
                     tier2map();
                 }
                 if (importWorldTier() == "Hard") {
                     tier3map();
                 }
                 if (importWorldTier() == "Advanced") {
                     tier4map();
                 }


             }
         }
